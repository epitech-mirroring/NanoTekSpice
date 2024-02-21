/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Error
*/

#include "Error.hpp"
#include <regex>
#include <fcntl.h>
#include <unistd.h>

nts::Error::Error(const std::string &msg) : _msg(msg) {}

const char *nts::Error::what() const noexcept
{
    return _msg.c_str();
}

static void checkFileExtension(char *filename)
{
    std::regex reg(".*\\.nts");
    std::smatch match;
    std::string str(filename);

    if (!std::regex_search(str, match, reg))
        throw nts::Error("Invalid file extension.");
}

static void checkFileExistence(char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
        throw nts::Error("File does not exist.");
    close(fd);
}

void nts::checkArgs(int argc, char **argv)
{
    if (argc != 2)
        throw nts::Error("Invalid number of arguments.");
    checkFileExtension(argv[1]);
    checkFileExistence(argv[1]);
}
