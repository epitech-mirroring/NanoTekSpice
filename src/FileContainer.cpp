/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FileContainer
*/

#include "FileContainer.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

nts::FileContainer::FileContainer() {}

void nts::FileContainer::extractFileContent(const std::string &filename)
{
    ssize_t count;
    char *buffer;
    struct stat st;
    int fd = open(filename.c_str(), O_RDONLY);
    std::string content;

    if (stat(filename.c_str(), &st) == -1)
        return;
    if (fd == -1)
        return;
    buffer = new char[st.st_size];
    count = read(fd, buffer, st.st_size);
    if (count == -1)
        return;
    content = buffer;  // Casts the buffer to a string
    content = this->removeComments(content);
    this->extractChipsetsAndLinks(content);
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

