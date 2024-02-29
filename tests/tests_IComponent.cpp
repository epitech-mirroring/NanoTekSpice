/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** tests_IComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/IComponent.hpp"
#include <iostream>

void redirect_all_stdout(void);

Test(not_operator, undefined)
{
    nts::Tristate tristate = nts::UNDEFINED;

    cr_assert_eq(!tristate, nts::UNDEFINED);
}

Test(not_operator, true)
{
    nts::Tristate tristate = nts::TRUE;

    cr_assert_eq(!tristate, nts::FALSE);
}

Test(not_operator, false)
{
    nts::Tristate tristate = nts::FALSE;

    cr_assert_eq(!tristate, nts::TRUE);
}

Test(print_operator, undefined, .init = redirect_all_stdout)
{
    nts::Tristate tristate = nts::UNDEFINED;

    std::cout << tristate << std::flush;
    cr_assert_stdout_eq_str("O");
}

Test(print_operator, true, .init = redirect_all_stdout)
{
    nts::Tristate tristate = nts::TRUE;

    std::cout << tristate << std::flush;
    cr_assert_stdout_eq_str("1");
}

Test(print_operator, false, .init = redirect_all_stdout)
{
    nts::Tristate tristate = nts::FALSE;

    std::cout << tristate << std::flush;
    cr_assert_stdout_eq_str("0");
}
