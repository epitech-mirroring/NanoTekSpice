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


Test(ClockComponent, undefined)
{
    nts::Components::ClockComponent clockComp;

    cr_assert_eq(clockComp.compute(1), nts::Tristate::UNDEFINED);
}

Test(ClockComponent, simple_clock)
{
    nts::Components::ClockComponent clockComp;

    clockComp.simulate(1);
    cr_assert_eq(clockComp.compute(1), nts::Tristate::UNDEFINED);
}

Test(ClockComponent, simple_clock2)
{
    nts::Components::ClockComponent clockComp;

    clockComp.setValue(nts::Tristate::TRUE);
    cr_assert_eq(clockComp.compute(1), nts::Tristate::TRUE);
    clockComp.simulate(1);
    cr_assert_eq(clockComp.compute(1), nts::Tristate::FALSE);
}

Test(ClockComponent, not_linked)
{
    nts::Components::ClockComponent clockComp;

    cr_assert_eq(clockComp.compute(1), nts::Tristate::UNDEFINED);
}

Test(ClockComponent, clone)
{
    nts::Components::ClockComponent clockComp;

    cr_assert(clockComp.clone() != nullptr);
}