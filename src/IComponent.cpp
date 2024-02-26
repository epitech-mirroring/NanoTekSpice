/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "IComponent.hpp"

nts::Tristate nts::operator!(Tristate const &tristate)
{
    if (tristate == UNDEFINED)
        return UNDEFINED;
    return (tristate == TRUE) ? FALSE : TRUE;
}

std::ostream &operator<<(std::ostream &os, nts::Tristate const &a)
{
    if (a == nts::UNDEFINED)
        os << "U";
    else if (a == nts::TRUE)
        os << "1";
    else
        os << "0";
    return os;
}