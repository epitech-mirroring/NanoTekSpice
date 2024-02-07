/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ComponentFactory.hpp"
#include "components/InputComponent.hpp"

int main() {
    nts::ComponentFactory factory;
    factory.registerComponent("input", new nts::Components::InputComponent());

    return 0;
}