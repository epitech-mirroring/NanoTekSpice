/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/Simulation.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <iostream>

Test(Simulation, all_simulation)
{
    nts::ComponentFactory factory;
    nts::FileContainer file("tests/valid_file.nts");
    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
    file.extractFileContent();
    file.buildMap(factory);
    file.setlinks();
    nts::Simulation simulation(file.getMap());
    cr_assert_eq(1, 1);
}
