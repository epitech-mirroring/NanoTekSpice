/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/OutputComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/InputComponent.hpp"


Test(OutputComponent, simple_output)
{
    nts::Components::OutputComponent outputComp;

    cr_assert_eq(outputComp.compute(1), nts::Tristate::UNDEFINED);
}

Test(OutputComponent, wrong_pin)
{
    nts::Components::OutputComponent outputComp;

    cr_assert_eq(outputComp.compute(2), nts::Tristate::UNDEFINED);
}

Test(OutputComponent, simple_output2)
{
    nts::Components::OutputComponent outputComp;
    nts::Components::TrueComponent trueComp;

    outputComp.setLink(1, trueComp, 1);
    outputComp.simulate(1);
    cr_assert_eq(outputComp.compute(1), nts::Tristate::TRUE);
}

Test(OutputComponent, simple_output3)
{
    nts::Components::OutputComponent outputComp;
    nts::Components::FalseComponent falseComp;

    outputComp.setLink(1, falseComp, 1);
    outputComp.simulate(1);
    cr_assert_eq(outputComp.compute(1), nts::Tristate::FALSE);
}

Test(OutputComponent, clone)
{
    nts::Components::OutputComponent outputComp;

    cr_assert(outputComp.clone() != nullptr);
}
