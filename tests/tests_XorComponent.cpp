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


Test(XorComponent, True_False)
{
    nts::Components::XorComponent xorComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::FalseComponent falseComp;

    xorComp.setLink(1, trueComp, 1);
    xorComp.setLink(2, falseComp, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::TRUE);
}

Test(XorComponent, True_True)
{
    nts::Components::XorComponent xorComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::TrueComponent trueComp2;

    xorComp.setLink(1, trueComp, 1);
    xorComp.setLink(2, trueComp2, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::FALSE);
}

Test(XorComponent, False_False)
{
    nts::Components::XorComponent xorComp;
    nts::Components::FalseComponent falseComp;
    nts::Components::FalseComponent falseComp2;

    xorComp.setLink(1, falseComp, 1);
    xorComp.setLink(2, falseComp2, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::FALSE);
}

Test(XorComponent, not_linked)
{
    nts::Components::XorComponent xorComp;

    cr_assert_eq(xorComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(XorComponent, undefined)
{
    nts::Components::XorComponent xorComp;
    nts::Components::InputComponent inputComp;
    nts::Components::InputComponent inputComp2;

    xorComp.setLink(1, inputComp, 1);
    xorComp.setLink(2, inputComp2, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(XorComponent, clone)
{
    nts::Components::XorComponent xorComp;

    cr_assert(xorComp.clone() != nullptr);
}

Test(XorComponent, True_notLinked)
{
    nts::Components::XorComponent xorComp;
    nts::Components::TrueComponent trueComp;

    xorComp.setLink(1, trueComp, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(XorComponent, notLinked_True)
{
    nts::Components::XorComponent xorComp;
    nts::Components::TrueComponent trueComp;

    xorComp.setLink(2, trueComp, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(XorComponent, False_notLinked)
{
    nts::Components::XorComponent xorComp;
    nts::Components::FalseComponent falseComp;

    xorComp.setLink(1, falseComp, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(XorComponent, notLinked_False)
{
    nts::Components::XorComponent xorComp;
    nts::Components::FalseComponent falseComp;

    xorComp.setLink(2, falseComp, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::UNDEFINED);
}
