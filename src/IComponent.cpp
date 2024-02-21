/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "IComponent.hpp"

using namespace nts;

Tristate nts::operator!(Tristate const &tristate)
{
    if (tristate == UNDEFINED)
        return UNDEFINED;
    return (tristate == TRUE) ? FALSE : TRUE;
}