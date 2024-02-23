/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Error
*/

#pragma once

#include <iostream>

namespace nts {
    class Error : public std::exception {
        public:
            Error(const std::string &msg);
            ~Error() = default;
            const char* what() const noexcept;
        private:
            std::string _msg;
    };

    void checkArgs(int argc, char **argv);
}
