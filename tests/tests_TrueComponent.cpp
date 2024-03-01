/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../src/components/TrueComponent.hpp"

Test(TrueComponent, simple_true)
{
    nts::Components::TrueComponent trueComp;

    cr_assert_eq(trueComp.compute(1), nts::Tristate::TRUE);
}

Test(TrueComponent, clone)
{
    nts::Components::TrueComponent trueComp;

    std::unique_ptr<nts::IComponent> clone = trueComp.clone();
    cr_assert_eq(clone->compute(1), nts::Tristate::TRUE);
}