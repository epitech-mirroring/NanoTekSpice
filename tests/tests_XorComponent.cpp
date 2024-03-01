/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/XorComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/InputComponent.hpp"


Test(XorComponent, simple_and)
{
    nts::Components::XorComponent andComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::FalseComponent falseComp;

    andComp.setLink(1, trueComp, 1);
    andComp.setLink(2, falseComp, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::TRUE);
}

Test(XorComponent, simple_and2)
{
    nts::Components::XorComponent andComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::TrueComponent trueComp2;

    andComp.setLink(1, trueComp, 1);
    andComp.setLink(2, trueComp2, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::FALSE);
}

Test(XorComponent, simple_and3)
{
    nts::Components::XorComponent andComp;
    nts::Components::FalseComponent falseComp;
    nts::Components::FalseComponent falseComp2;

    andComp.setLink(1, falseComp, 1);
    andComp.setLink(2, falseComp2, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::FALSE);
}

Test(XorComponent, not_linked)
{
    nts::Components::XorComponent andComp;

    cr_assert_eq(andComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(XorComponent, undefined)
{
    nts::Components::XorComponent andComp;
    nts::Components::InputComponent inputComp;
    nts::Components::InputComponent inputComp2;

    andComp.setLink(1, inputComp, 1);
    andComp.setLink(2, inputComp2, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(XorComponent, clone)
{
    nts::Components::XorComponent andComp;

    cr_assert(andComp.clone() != nullptr);
}