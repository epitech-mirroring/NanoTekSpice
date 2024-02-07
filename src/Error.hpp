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

            static void check_args_number(int argc);
            static void check_file_extension(char *filename);
            static void check_file_existence(char *filename);
        private:
            std::string _msg;
    };
}
