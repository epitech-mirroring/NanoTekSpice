/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** main
*/

#include "FileContainer.hpp"
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

int main(int argc, char **argv) {
    nts::ComponentFactory factory;
    nts::FileContainer fileContainer(argv[1]);
    registerComponents(factory);

    fileContainer.extractFileContent();
    // fileContainer.buildMap(factory);
    // fileContainer.setlinks();
    // Crashs if the components types of the given file are not implemented yet
    // Because the error handling is not yet implemented
    (void) argc;
    return 0;
}
