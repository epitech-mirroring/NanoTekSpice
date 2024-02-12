/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** main
*/

#include "FileContainer.hpp"
#include "ComponentFactory.hpp"
#include "components/InputComponent.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    nts::FileContainer fileContainer;
    nts::ComponentFactory factory;
    factory.registerComponent("input", new nts::Components::InputComponent());

    fileContainer.extractFileContent(argv[1]);
    (void) argc;
    return 0;
}
