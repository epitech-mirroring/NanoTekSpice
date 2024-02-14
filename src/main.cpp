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

static void registerComponents(nts::ComponentFactory &factory)
{
    factory.registerComponent("input", new nts::Components::InputComponent());
    factory.registerComponent("or", new nts::Components::OrComponent());
    factory.registerComponent("4071", new nts::Components::Composed4071Component());
}

int main(int argc, char **argv) {
    nts::ComponentFactory factory;
    nts::FileContainer fileContainer;
    registerComponents(factory);

    fileContainer.extractFileContent(argv[1]);
    // fileContainer.buildMap(factory);
    // Crashs if the components types of the given file are not implemented yet
    // Because the error handling is not yet implemented
    (void) argc;
    return 0;
}
