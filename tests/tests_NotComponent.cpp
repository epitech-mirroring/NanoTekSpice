/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/NotComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/InputComponent.hpp"


Test(NotComponent, simple_not)
{
    nts::Components::NotComponent notComp;
    nts::Components::TrueComponent trueComp;

    notComp.setLink(1, trueComp, 1);
    cr_assert_eq(notComp.compute(2), nts::Tristate::FALSE);
}

Test(NotComponent, simple_and2)
{
    nts::Components::NotComponent notComp;
    nts::Components::FalseComponent falseComp;

    notComp.setLink(1, falseComp, 1);
    cr_assert_eq(notComp.compute(2), nts::Tristate::TRUE);
}

Test(NotComponent, undefined2)
{
    nts::Components::NotComponent notComp;
    nts::Components::InputComponent inputComp;

    notComp.setLink(1, inputComp, 1);
    cr_assert_eq(notComp.compute(2), nts::Tristate::UNDEFINED);
}

Test(NotComponent, not_linked)
{
    nts::Components::NotComponent notComp;

    cr_assert_eq(notComp.compute(2), nts::Tristate::UNDEFINED);
}

Test(NotComponent, clone)
{
    nts::Components::NotComponent notComp;

    cr_assert(notComp.clone() != nullptr);
}