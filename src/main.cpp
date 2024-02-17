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
#include "Error.hpp"

static void registerComponents(nts::ComponentFactory &factory)
{
    factory.registerComponent("input", new nts::Components::InputComponent());
    factory.registerComponent("or", new nts::Components::OrComponent());
    factory.registerComponent("4071", new nts::Components::Composed4071Component());
}

int main(int argc, char **argv) {
    nts::ComponentFactory factory;

    registerComponents(factory);
    try {
        nts::checkArgs(argc, argv);
        nts::FileContainer fileContainer(argv[1]);
        fileContainer.extractFileContent();
        fileContainer.buildMap(factory);
        fileContainer.setlinks();
    } catch (nts::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
