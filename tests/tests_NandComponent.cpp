/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/composed/CNandComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/InputComponent.hpp"


Test(CNandCOmponent, simple_cnand)
{
    nts::Components::CNandComponent cnandComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::FalseComponent falseComp;

    cnandComp.setLink(1, trueComp, 1);
    cnandComp.setLink(2, falseComp, 1);
    cr_assert_eq(cnandComp.compute(3), nts::Tristate::TRUE);
}

Test(CNandCOmponent, simple_cnand2)
{
    nts::Components::CNandComponent cnandComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::TrueComponent trueComp2;

    cnandComp.setLink(1, trueComp, 1);
    cnandComp.setLink(2, trueComp2, 1);
    cr_assert_eq(cnandComp.compute(3), nts::Tristate::FALSE);
}

Test(CNandCOmponent, simple_cnand3)
{
    nts::Components::CNandComponent cnandComp;
    nts::Components::FalseComponent falseComp;
    nts::Components::FalseComponent falseComp2;

    cnandComp.setLink(1, falseComp, 1);
    cnandComp.setLink(2, falseComp2, 1);
    cr_assert_eq(cnandComp.compute(3), nts::Tristate::TRUE);
}

Test(CNandCOmponent, clone)
{
    nts::Components::CNandComponent cnandComp;

    cr_assert(cnandComp.clone() != nullptr);
}