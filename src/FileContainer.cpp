/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FileContainer
*/

#include "FileContainer.hpp"
#include "Error.hpp"
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <cstring>

nts::FileContainer::FileContainer(const std::string &filename)
{
    this->_filename = filename;
    this->_chipsets = std::vector<std::string>();
    this->_links = std::vector<std::string>();
    this->_pins = std::unordered_map<std::string, IComponent *>();
}

void nts::FileContainer::extractFileContent()
{
    ssize_t count;
    char *buffer;
    struct stat st;
    int fd;
    std::string content;

    if (stat(this->_filename.c_str(), &st) == -1)
        throw nts::Error("File does not exist.");
    fd = open(this->_filename.c_str(), O_RDONLY);
    if (fd == -1)
        throw nts::Error("File does not exist.");
    buffer = new char[st.st_size + 1];
    count = read(fd, buffer, st.st_size);
    if (count == -1 || buffer == nullptr) {
        close(fd);
        throw nts::Error("Error while reading file.");
    }
    content = std::string(buffer, count);
    content = removeComments(content);
    this->extractChipsetsAndLinks(content);
    close(fd);
}

std::vector<std::string> nts::FileContainer::getChipsets(void) const
{
    return _chipsets;
}

std::vector<std::string> nts::FileContainer::getLinks(void) const
{
    return _links;
}

std::unordered_map<std::string, nts::IComponent *> nts::FileContainer::getMap(void) const
{
    return _pins;
}

void nts::FileContainer::buildMap(ComponentFactory &factory)
{
    char *name = NULL;
    char *type = NULL;

    for (size_t i = 0; i < this->_chipsets.size(); i++) {
        type = strtok((char *)this->_chipsets[i].c_str(), " ");
        name = strtok(NULL, " ");
        if (name == NULL || type == NULL)
            throw nts::Error("Invalid file format.");
        if (!factory.isRegistered(name))
            throw nts::Error("Component type does not exist.");
        if (this->_pins.find(name) != this->_pins.end())
            throw nts::Error("Component name already exists.");
        this->_pins[name] = factory.createComponent(type);
    }
}

void nts::FileContainer::setlinks(void)
{
    char *name = NULL;
    char *pin = NULL;
    char *name2 = NULL;
    char *pin2 = NULL;

    for (size_t i = 0; i < this->_links.size(); i++) {
        name = strtok((char *)this->_links[i].c_str(), " ");
        pin = strtok(NULL, " ");
        name2 = strtok(NULL, " ");
        pin2 = strtok(NULL, " ");
        if (name == NULL || pin == NULL || name2 == NULL || pin2 == NULL)
            throw nts::Error("Invalid file format.");
        if (this->_pins.find(name) == this->_pins.end())
            throw nts::Error("First component name does not exist.");
        if (this->_pins[name2] == NULL)
            throw nts::Error("Second component name does not exist.");
        this->_pins[name]->setLink(std::stoi(pin), *this->_pins[name2], std::stoi(pin2));
        // The `setLink` method already has a check for the pin existence and if it is already linked
    }
}

std::string nts::FileContainer::removeComments(std::string &content) const
{
    std::regex reg("#.*");

    while (std::regex_search(content, reg))
        content = std::regex_replace(content, reg, "");
    return content;
}

void nts::FileContainer::extractChipsetsAndLinks(const std::string &content)
{
    std::regex reg("(\\.chipsets:\n([a-zA-Z0-9_ #]+\n?)+\n)\n*(\\.links:\n([a-zA-Z0-9_: #]+\n?)+\n+)$");
    std::smatch match;
    std::string str1;
    std::string str2;

    if (std::regex_search(content, match, reg)) {
        str1 = match[1].str();
        this->fillChipsets(str1);
        str2 = match[3].str();
        this->fillLinks(str2);
    } else {
        throw nts::Error("Invalid file format.");
    }
}

void nts::FileContainer::fillChipsets(std::string &str)
{
    std::regex reg("^\\s*([a-zA-Z0-9]+)\\s+(\\w+)\\s*(#.*)?$");
    std::smatch match2;
    char *token;
    std::string str2;

    token = strtok((char *)str.c_str(), "\n");
    token = strtok(NULL, "\n");
    if (token == NULL)
        throw nts::Error("Invalid file format.");
    while (token != NULL) {
        str2 = std::string(token);
        if (std::regex_search(str2, match2, reg)) {
            str2 = match2[1].str() + " " + match2[2].str();
            this->_chipsets.push_back(str2);
        } else {
            throw nts::Error("Invalid file format.");
        }
        token = strtok(NULL, "\n");
    }
}

void nts::FileContainer::fillLinks(std::string &str)
{
    std::regex reg("^\\s*([a-zA-Z0-9_]+)\\s*:\\s*([0-9]+)\\s+([a-zA-Z0-9_]+)\\s*:\\s*([0-9]+)\\s*(#.*)?$");
    std::smatch match2;
    char *token;
    std::string str2;

    token = strtok((char *)str.c_str(), "\n");
    token = strtok(NULL, "\n");
    if (token == NULL)
        throw nts::Error("Invalid file format.");
    while (token != NULL) {
        str2 = std::string(token);
        if (std::regex_search(str2, match2, reg)) {
            str2 = match2[1].str() + " " + match2[2].str() + " " + match2[3].str() + " " + match2[4].str();
            this->_links.push_back(str2);
        } else {
            throw nts::Error("Invalid file format.");
        }
        token = strtok(NULL, "\n");
    }
}

bool nts::FileContainer::isPinExist(const std::string &str)
{
    for (size_t i = 0; i < this->_chipsets.size(); i++) {
        if (this->_chipsets[i] == str)
            return true;
    }
    return false;
}
