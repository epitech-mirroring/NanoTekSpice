/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/composed/CNorComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/InputComponent.hpp"


Test(CNorCOmponent, simple_cnor)
{
    nts::Components::CNorComponent cnorComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::FalseComponent falseComp;

    cnorComp.setLink(1, trueComp, 1);
    cnorComp.setLink(2, falseComp, 1);
    cr_assert_eq(cnorComp.compute(3), nts::Tristate::FALSE);
}

Test(CNorCOmponent, simple_cnor2)
{
    nts::Components::CNorComponent cnorComp;
    nts::Components::TrueComponent trueComp;
    nts::Components::TrueComponent trueComp2;

    cnorComp.setLink(1, trueComp, 1);
    cnorComp.setLink(2, trueComp2, 1);
    cr_assert_eq(cnorComp.compute(3), nts::Tristate::FALSE);
}

Test(CNorCOmponent, simple_cnor3)
{
    nts::Components::CNorComponent cnorComp;
    nts::Components::FalseComponent falseComp;
    nts::Components::FalseComponent falseComp2;

    cnorComp.setLink(1, falseComp, 1);
    cnorComp.setLink(2, falseComp2, 1);
    cr_assert_eq(cnorComp.compute(3), nts::Tristate::TRUE);
}


Test(CNorCOmponent, clone)
{
    nts::Components::CNorComponent cnorComp;

    cr_assert(cnorComp.clone() != nullptr);
}