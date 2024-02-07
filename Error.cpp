/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Error
*/

#include "Error.hpp"

nts::Error::Error(const std::string &msg) : _msg(msg) {}

const char *nts::Error::what() const noexcept
{
    return _msg.c_str();
}
