/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/InputComponent.hpp"
#include <criterion/criterion.h>

Test(InputComponent, create_input)
{
    nts::Components::InputComponent *comp = new nts::Components::InputComponent();
    cr_assert_not_null(comp);

    delete comp;
}

Test(InputComponent, compute_input)
{
    nts::Components::InputComponent *comp = new nts::Components::InputComponent();
    cr_assert_not_null(comp);
    comp->setValue(nts::TRUE);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::UNDEFINED);
    comp->setValue(nts::FALSE);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::UNDEFINED);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::FALSE);
    comp->setValue(nts::TRUE);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::FALSE);
    comp->simulate(10);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::TRUE);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::TRUE);
    comp->setValue(nts::UNDEFINED);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::TRUE);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::UNDEFINED);
    delete comp;
}

Test(InputComponent, no_change_but_simulate)
{
    nts::Components::InputComponent *comp = new nts::Components::InputComponent();
    cr_assert_not_null(comp);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::UNDEFINED);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::UNDEFINED);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::InputComponent::OUT), nts::UNDEFINED);
    delete comp;
}