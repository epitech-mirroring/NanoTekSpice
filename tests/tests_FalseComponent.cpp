/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/FalseComponent.hpp"

Test(FalseComponent, simple_false)
{
    nts::Components::FalseComponent trueComp;

    cr_assert_eq(trueComp.compute(1), nts::Tristate::FALSE);
}

Test(FalseComponent, clone)
{
    nts::Components::FalseComponent falseComp;

    std::unique_ptr<nts::IComponent> clone = falseComp.clone();
    cr_assert_eq(clone->compute(1), nts::Tristate::FALSE);
}