/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** tests_Error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/Error.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(checkArgs, wrong_argument_number, .init = redirect_all_stdout)
{
    char *argv[] = {(char *)"./nanotekspice", (char *)"tests/404.nts"};
    int argc = 3;

    cr_assert_throw(nts::checkArgs(argc, argv), nts::Error);
}

Test(checkArgs, wrong_argument_number2, .init = redirect_all_stdout)
{
    char *argv[] = {(char *)"./nanotekspice"};
    int argc = 1;

    cr_assert_throw(nts::checkArgs(argc, argv), nts::Error);
}

Test(checkArgs, wrong_file_extension, .init = redirect_all_stdout)
{
    char *argv[] = {(char *)"./nanotekspice", (char *)"tests/404.txt"};
    int argc = 2;

    cr_assert_throw(nts::checkArgs(argc, argv), nts::Error);
}

Test(checkArgs, file_does_not_exist, .init = redirect_all_stdout)
{
    char *argv[] = {(char *)"./nanotekspice", (char *)"tests/404.nts"};
    int argc = 2;

    cr_assert_throw(nts::checkArgs(argc, argv), nts::Error);
}

Test(Error, what)
{
    nts::Error error("test");

    cr_assert_str_eq(error.what(), "test");
}

Test(Error, normal_file)
{
    char *argv[] = {(char *)"./nanotekspice", (char *)"tests/valid_file.nts"};
    int argc = 2;

    cr_assert_no_throw(nts::checkArgs(argc, argv), nts::Error);
}
