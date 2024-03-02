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
#include "../src/components/InputComponent.hpp"
#include "../src/components/composed/C4008Component.hpp"
#include "../src/Error.hpp"
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

Test(FileContainer, invalid_file)
{
    nts::FileContainer file("tests/invalid_file.nts");
    cr_assert_throw(file.extractFileContent(), nts::Error);
}

Test(FileContainer, invalid_name)
{
    nts::FileContainer file("tests/wrong_name_file.nts");
    nts::ComponentFactory factory;

    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
    file.extractFileContent();
    cr_assert_throw(file.buildMap(factory), nts::Error);
}

Test(FileContainer, invalid_type)
{
    nts::FileContainer file("tests/wrong_type_file.nts");
    nts::ComponentFactory factory;

    file.extractFileContent();
    cr_assert_throw(file.buildMap(factory);, nts::Error);
}

Test(FileContainer, invalid_link)
{
    nts::FileContainer file("tests/wrong_link_file.nts");
    nts::ComponentFactory factory;

    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
    file.extractFileContent();
    file.buildMap(factory);
    cr_assert_throw(file.setlinks(), nts::Error);
}

Test(FileContainer, invalid_link2)
{
    nts::FileContainer file("tests/wrong_link_file2.nts");
    nts::ComponentFactory factory;

    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
    file.extractFileContent();
    file.buildMap(factory);
    cr_assert_throw(file.setlinks(), nts::Error);
}

Test(FileContainer, normal_file)
{
    nts::FileContainer file("tests/valid_file.nts");
    nts::ComponentFactory factory;

    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
    file.extractFileContent();
    file.buildMap(factory);
    cr_assert_no_throw(file.setlinks(), nts::Error);
}

Test(FileContainer, regex_failed)
{
    nts::FileContainer file("tests/regex_failed.nts");
    cr_assert_throw(file.extractFileContent(), nts::Error);

    nts::FileContainer file2("tests/regex_failed2.nts");
    cr_assert_throw(file2.extractFileContent(), nts::Error);

    nts::FileContainer file3("tests/regex_failed3.nts");
    cr_assert_throw(file3.extractFileContent(), nts::Error);
}

Test(FileContainer, not_failing)
{
    nts::FileContainer file("tests/long_valid_file.nts");
    nts::ComponentFactory factory;

    factory.registerComponent("input", new nts::Components::InputComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
    factory.registerComponent("4008", new nts::Components::C4008Component());
    file.extractFileContent();
    file.buildMap(factory);
    cr_assert_no_throw(file.setlinks(), nts::Error);
}
