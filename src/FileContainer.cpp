/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FileContainer
*/

#include "FileContainer.hpp"
#include <fstream>
#include <regex>
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
        return;
    fd = open(this->_filename.c_str(), O_RDONLY);
    if (fd == -1)
        return;
    buffer = new char[st.st_size + 1];
    count = read(fd, buffer, st.st_size);
    if (count == -1 || buffer == nullptr) {
        close(fd);
        return;
    }
    content = std::string(buffer, count);
    content = this->removeComments(content);
    this->extractChipsetsAndLinks(content);
    close(fd);
}

std::string nts::FileContainer::removeComments(std::string &content)
{
    std::regex reg("#.*\n");

    content = std::regex_replace(content, reg, "");
    return content;
}

void nts::FileContainer::extractChipsetsAndLinks(const std::string &content)
{
    std::regex reg("(\\.chipsets:\n([a-zA-Z0-9_ ]+\n?)+)\n*(\\.links:\n([a-zA-Z0-9_: ]+\n?)+)");
    std::smatch match;

    if (std::regex_search(content, match, reg)) {
        _chipsets = match[1];
        _links = match[3];
    }
}

std::string nts::FileContainer::getChipsets(void) const
{
    return _chipsets;
}

std::string nts::FileContainer::getLinks(void) const
{
    return _links;
}

void nts::FileContainer::buildMap(ComponentFactory &factory)
{
    char *token;
    char *str = strdup(_chipsets.c_str());
    char *type;
    char *name;

    token = strtok(str, "\n");
    while (token != NULL) {
        if (token[0] == '.') {
            token = strtok(NULL, "\n");
            continue;
        }
        type = strtok(token, " \t");
        name = strtok(NULL, " \t");
        _pins[name] = factory.createComponent(type);
        token = strtok(NULL, "\n");
    }
    free(str);
}
