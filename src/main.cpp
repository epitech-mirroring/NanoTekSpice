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
#include "components/ClockComponent.hpp"
#include "components/TrueComponent.hpp"
#include "components/FalseComponent.hpp"
#include "components/NotComponent.hpp"
#include "components/AndComponent.hpp"
#include "components/XorComponent.hpp"

static void registerComponents(nts::ComponentFactory &factory)
{
    factory.registerComponent("input", new nts::Components::InputComponent());
    factory.registerComponent("or", new nts::Components::OrComponent());
    factory.registerComponent("4071", new nts::Components::Composed4071Component());
    factory.registerComponent("clock", new nts::Components::ClockComponent());
    factory.registerComponent("true", new nts::Components::TrueComponent());
    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("not", new nts::Components::NotComponent());
    factory.registerComponent("and", new nts::Components::AndComponent());
    factory.registerComponent("xor", new nts::Components::XorComponent());
}

int main() {
    nts::ComponentFactory factory;
    registerComponents(factory);

    return 0;
}