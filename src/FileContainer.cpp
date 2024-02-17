/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FileContainer
*/

#include "FileContainer.hpp"
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
        this->_pins[name]->setLink(std::stoi(pin), *this->_pins[name2], std::stoi(pin2));
    }
}

void nts::FileContainer::buildMap(ComponentFactory &factory)
{
    char *name = NULL;
    char *type = NULL;

    for (size_t i = 1; i < this->_chipsets.size() - 1; i++) {
        name = strtok((char *)this->_chipsets[i].c_str(), " ");
        type = strtok(NULL, " ");
        this->_pins[name] = factory.createComponent(type);
    }
}

std::string nts::FileContainer::removeComments(std::string &content) const
{
    std::regex reg("#.*\n");

    content = std::regex_replace(content, reg, "");
    return content;
}

void nts::FileContainer::extractChipsetsAndLinks(const std::string &content)
{
    std::regex reg("(\\.chipsets:\n([a-zA-Z0-9_ ]+\n?)+)\n*(\\.links:\n([a-zA-Z0-9_: ]+\n?)+)");
    std::smatch match;
    std::string str1;
    std::string str2;

    if (std::regex_search(content, match, reg)) {
        str1 = match[1].str();
        this->fillChipsets(str1);
        str2 = match[3].str();
        this->fillLinks(str2);
    }
}

void nts::FileContainer::fillChipsets(std::string &str)
{
    std::regex reg("^([a-zA-Z0-9]+)\\s+(\\w+)$");
    std::smatch match2;
    char *token;
    std::string str2;

    token = strtok((char *)str.c_str(), "\n");
    token = strtok(NULL, "\n");
    while (token != NULL) {
        str2 = std::string(token);
        if (std::regex_search(str2, match2, reg)) {
            str2 = match2[1].str() + " " + match2[2].str();
            this->_chipsets.push_back(str2);
        } else {
            return;
        }
        token = strtok(NULL, "\n");
    }
}

void nts::FileContainer::fillLinks(std::string &str)
{
    std::regex reg("^([a-zA-Z0-9_]+):([0-9]+)\\s+([a-zA-Z0-9]+):([0-9]+)$");
    std::smatch match2;
    char *token;
    std::string str2;

    token = strtok((char *)str.c_str(), "\n");
    token = strtok(NULL, "\n");
    while (token != NULL) {
        str2 = std::string(token);
        if (std::regex_search(str2, match2, reg)) {
            str2 = match2[1].str() + " " + match2[2].str() + " " + match2[3].str() + " " + match2[4].str();
            this->_links.push_back(str2);
        } else {
            return;
        }
        token = strtok(NULL, "\n");
    }
}
