/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** main
*/

#include "Error.hpp"

int main(int argc, char **argv)
{
    try {
        nts::Error::check_args_number(argc);
        nts::Error::check_file_extension(argv[1]);
        nts::Error::check_file_existence(argv[1]);
    } catch (nts::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
