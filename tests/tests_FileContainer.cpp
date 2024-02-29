/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/FileContainer.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <iostream>

Test(FileContainer, all_filecontainer)
{
    nts::FileContainer file("tests/valid_file.nts");
    nts::ComponentFactory factory;

    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
    file.extractFileContent();
    cr_assert_eq(file.getChipsets().size(), 2);
    cr_assert_eq(file.getLinks().size(), 1);
    file.buildMap(factory);
    cr_assert_eq(file.getMap().size(), 2);
}
