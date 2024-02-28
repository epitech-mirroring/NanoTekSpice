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
#include "components/composed/C4071Component.hpp"
#include "components/ClockComponent.hpp"
#include "components/TrueComponent.hpp"
#include "components/FalseComponent.hpp"
#include "components/NotComponent.hpp"
#include "components/AndComponent.hpp"
#include "components/XorComponent.hpp"
#include "components/composed/CNandComponent.hpp"
#include "components/composed/CNorComponent.hpp"
#include "components/composed/C4001Component.hpp"
#include "components/composed/C4011Component.hpp"
#include "components/composed/C4030Component.hpp"
#include "Error.hpp"

static void registerComponents(nts::ComponentFactory &factory)
{
    factory.registerComponent("input", new nts::Components::InputComponent());
    factory.registerComponent("or", new nts::Components::OrComponent());
    factory.registerComponent("4071", new nts::Components::C4071Component());
    factory.registerComponent("clock", new nts::Components::ClockComponent());
    factory.registerComponent("true", new nts::Components::TrueComponent());
    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("not", new nts::Components::NotComponent());
    factory.registerComponent("and", new nts::Components::AndComponent());
    factory.registerComponent("xor", new nts::Components::XorComponent());
    factory.registerComponent("nand", new nts::Components::CNandComponent());
    factory.registerComponent("nor", new nts::Components::CNorComponent());
    factory.registerComponent("4001", new nts::Components::C4001Component());
    factory.registerComponent("4011", new nts::Components::C4011Component());
    factory.registerComponent("4030", new nts::Components::C4030Component());
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
