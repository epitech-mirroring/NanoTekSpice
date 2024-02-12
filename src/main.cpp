/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ComponentFactory.hpp"
#include "components/InputComponent.hpp"
#include "components/OrComponent.hpp"
#include "components/Composed4071Component.hpp"

static void registerComponents(nts::ComponentFactory &factory)
{
    factory.registerComponent("input", new nts::Components::InputComponent());
    factory.registerComponent("or", new nts::Components::OrComponent());
    factory.registerComponent("4071", new nts::Components::Composed4071Component());
}

int main() {
    nts::ComponentFactory factory;
    registerComponents(factory);

    return 0;
}