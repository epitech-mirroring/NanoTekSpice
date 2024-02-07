/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** main
*/

#include "FileContainer.hpp"
#include "ComponentFactory.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    nts::FileContainer fileContainer;
    nts::ComponentFactory factory;

    fileContainer.extractFileContent(argv[1]);
    (void) argc;
    return 0;
}
