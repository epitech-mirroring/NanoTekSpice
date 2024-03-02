/*
** EPITECH PROJECT, 2024
** NorTekSpice
** File description:
** No file there , just orepitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/OrComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/InputComponent.hpp"


Test(OrComponent, True_False)
{
    nts::Components::OrComponent orComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::FalseComponent falseComp;

    orComp.setLink(1, trueComp, 1);
    orComp.setLink(2, falseComp, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::TRUE);
}

Test(OrComponent, True_True)
{
    nts::Components::OrComponent orComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::TrueComponent trueComp2;

    orComp.setLink(1, trueComp, 1);
    orComp.setLink(2, trueComp2, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::TRUE);
}

Test(OrComponent, False_False)
{
    nts::Components::OrComponent orComp;
    nts::Components::FalseComponent falseComp;
    nts::Components::FalseComponent falseComp2;

    orComp.setLink(1, falseComp, 1);
    orComp.setLink(2, falseComp2, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::FALSE);
}

Test(OrComponent, not_linked)
{
    nts::Components::OrComponent orComp;

    cr_assert_eq(orComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(OrComponent, undefined)
{
    nts::Components::OrComponent orComp;
    nts::Components::InputComponent inputComp;
    nts::Components::InputComponent inputComp2;

    orComp.setLink(1, inputComp, 1);
    orComp.setLink(2, inputComp2, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(OrComponent, clone)
{
    nts::Components::OrComponent orComp;

    cr_assert(orComp.clone() != nullptr);
}

Test(OrComponent, True_notLinked)
{
    nts::Components::OrComponent orComp;
    nts::Components::TrueComponent trueComp;

    orComp.setLink(1, trueComp, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::TRUE);
}

Test(OrComponent, notLinked_True)
{
    nts::Components::OrComponent orComp;
    nts::Components::TrueComponent trueComp;

    orComp.setLink(2, trueComp, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::TRUE);
}

Test(OrComponent, False_notLinked)
{
    nts::Components::OrComponent orComp;
    nts::Components::FalseComponent falseComp;

    orComp.setLink(1, falseComp, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(OrComponent, notLinked_False)
{
    nts::Components::OrComponent orComp;
    nts::Components::FalseComponent falseComp;

    orComp.setLink(2, falseComp, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::UNDEFINED);
}

Test(OrComponent, out_of_range_pin)
{
    nts::Components::OrComponent orComp;
    nts::Components::FalseComponent falseComp;

    orComp.setLink(1, falseComp, 1);
    cr_assert_eq(orComp.compute(4), nts::Tristate::UNDEFINED);
}
