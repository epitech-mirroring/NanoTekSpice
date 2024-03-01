/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/ClockComponent.hpp"


Test(ClockComponent, create_clock)
{
    nts::Components::ClockComponent *comp = new nts::Components::ClockComponent();
    cr_assert_not_null(comp);

    delete comp;
}

Test(ClockComponent, compute_clock)
{
    nts::Components::ClockComponent *comp = new nts::Components::ClockComponent();
    cr_assert_not_null(comp);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::UNDEFINED);
    comp->setValue(nts::TRUE);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::UNDEFINED);
    comp->setValue(nts::FALSE);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::UNDEFINED);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::FALSE);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::TRUE);
    comp->setValue(nts::TRUE);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::TRUE);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::TRUE);
    comp->setValue(nts::UNDEFINED);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::TRUE);
    comp->simulate(1);
    cr_assert_eq(comp->compute(nts::Components::ClockComponent::OUT), nts::UNDEFINED);
    delete comp;
}

Test(ClockComponent, clone_clock)
{
    nts::Components::ClockComponent *comp = new nts::Components::ClockComponent();
    cr_assert_not_null(comp);
    auto newComp = comp->clone();
    cr_assert_not_null(newComp);
    delete comp;
}
