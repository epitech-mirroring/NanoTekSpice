/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/ComponentFactory.hpp"
#include "../src/components/InputComponent.hpp"

Test(ComponentFactory, all_factory)
{
    nts::ComponentFactory factory;
    factory.registerComponent("input", new nts::Components::InputComponent());

    cr_assert_eq(factory.isRegistered("input"), true);
    cr_assert_eq(factory.isRegistered("output"), false);
    std::unique_ptr<nts::IComponent> input = factory.createComponent("input");
    input = factory << "input";
    factory.unregisterComponent("input");
    cr_assert_eq(factory.isRegistered("input"), false);
}
