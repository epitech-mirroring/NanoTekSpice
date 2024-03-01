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
    this->_pins = std::map<std::string, nts::IComponent *>();
}

nts::FileContainer::~FileContainer()
{
    for (auto &pin : this->_pins) {
        delete pin.second;
    }
}

void nts::FileContainer::extractFileContent()
{
    ssize_t count;
    char *buffer;
    struct stat st{};
    int fd;
    std::string content;

    fd = open(this->_filename.c_str(), O_RDONLY);
    if (fd == -1)
        throw nts::Error("File does not exist.");
    stat(this->_filename.c_str(), &st);
    buffer = new char[st.st_size + 1];
    count = read(fd, buffer, st.st_size);
    if (count == -1) {
        close(fd);
        throw nts::Error("Error while reading file.");
    }
    content = std::string(buffer, count);
    content = removeComments(content);
    this->extractChipsetsAndLinks(content);
    close(fd);
    delete[] buffer;
}

std::vector<std::string> nts::FileContainer::getChipsets() const
{
    return _chipsets;
}

std::vector<std::string> nts::FileContainer::getLinks() const
{
    return _links;
}

std::map<std::string, nts::IComponent *> nts::FileContainer::getMap() const
{
    return _pins;
}

void nts::FileContainer::buildMap(ComponentFactory &factory)
{
    char *name = nullptr;
    char *type = nullptr;

    for (const auto & _chipset : this->_chipsets) {
        type = strtok((char *)_chipset.c_str(), " ");
        name = strtok(nullptr, " ");
        if (name == nullptr || type == nullptr)
            throw nts::Error("Invalid file format in the chipset section.");
        if (!factory.isRegistered(type))
            throw nts::Error("Component type: " + std::string(name) + " does not exist.");
        if (this->_pins.find(name) != this->_pins.end())
            throw nts::Error("Component name: " + std::string(name) + " already exists.");
        this->_pins[name] = factory.createComponent(type).release();
    }
}

void nts::FileContainer::setlinks()
{
    char *name = nullptr;
    char *pin = nullptr;
    char *name2 = nullptr;
    char *pin2 = nullptr;

    for (const auto & _link : this->_links) {
        name = strtok((char *)_link.c_str(), " ");
        pin = strtok(nullptr, " ");
        name2 = strtok(nullptr, " ");
        pin2 = strtok(nullptr, " ");
        if (name == nullptr || pin == nullptr || name2 == nullptr || pin2 == nullptr)
            throw nts::Error("Invalid file format in the links section.");
        if (this->_pins.find(name) == this->_pins.end())
            throw nts::Error("First component name: " + std::string(name) + " does not exist.");
        if (this->_pins[name2] == nullptr)
            throw nts::Error("Second component name: " + std::string(name2) + " does not exist.");
        this->_pins[name]->setLink(std::stoi(pin), *this->_pins[name2], std::stoi(pin2));
    }
}

std::string nts::FileContainer::removeComments(std::string &content)
{
    std::regex reg("#.*");

    while (std::regex_search(content, reg))
        content = std::regex_replace(content, reg, "");
    return content;
}

void nts::FileContainer::extractChipsetsAndLinks(const std::string &content)
{
    std::regex reg("(\\.chipsets:\n([a-zA-Z0-9_ #]+\n?)+\n)\n*(\\.links:\n([a-zA-Z0-9_: #]+\n?)+)(\n+)?$");
    std::smatch match;
    std::string str1;
    std::string str2;

    if (std::regex_search(content, match, reg)) {
        str1 = match[1].str();
        this->fillChipsets(str1);
        str2 = match[3].str();
        this->fillLinks(str2);
    } else {
        throw nts::Error("Invalid file format in the chipset and/or links section.");
    }
}

void nts::FileContainer::fillChipsets(std::string &str)
{
    std::regex reg(R"(^\s*([a-zA-Z0-9]+)\s+(\w+)\s*(#.*)?$)");
    std::smatch match2;
    char *token;
    std::string str2;

    token = strtok((char *)str.c_str(), "\n");
    token = strtok(nullptr, "\n");
    if (token == nullptr)
        throw nts::Error("Invalid file format in the chipset section.");
    while (token != nullptr) {
        str2 = std::string(token);
        if (std::regex_search(str2, match2, reg)) {
            str2 = match2[1].str() + " " + match2[2].str();
            this->_chipsets.push_back(str2);
        } else {
            throw nts::Error("Invalid file format in the chipset section.");
        }
        token = strtok(nullptr, "\n");
    }
}

void nts::FileContainer::fillLinks(std::string &str)
{
    std::regex reg(R"(^\s*([a-zA-Z0-9_]+)\s*:\s*([0-9]+)\s+([a-zA-Z0-9_]+)\s*:\s*([0-9]+)\s*(#.*)?$)");
    std::smatch match2;
    char *token;
    std::string str2;

    token = strtok((char *)str.c_str(), "\n");
    token = strtok(nullptr, "\n");
    if (token == nullptr)
        throw nts::Error("Invalid file format in the links section.");
    while (token != nullptr) {
        str2 = std::string(token);
        if (std::regex_search(str2, match2, reg)) {
            str2 = match2[1].str() + " " + match2[2].str() + " " + match2[3].str() + " " + match2[4].str();
            this->_links.push_back(str2);
        } else {
            throw nts::Error("Invalid file format in the links section.");
        }
        token = strtok(nullptr, "\n");
    }
}
