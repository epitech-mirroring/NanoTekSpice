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
#include "components/composed/C4069Component.hpp"
#include "components/composed/C4081Component.hpp"
#include "components/OutputComponent.hpp"
#include "Error.hpp"
#include "Simulation.hpp"
#include "components/composed/C7482Component.hpp"
#include "components/composed/C4008Component.hpp"
#include "components/primitive/P4013Component.hpp"
#include "components/primitive/P4040Component.hpp"
#include "components/primitive/P4514Component.hpp"

static void registerComponents(nts::ComponentFactory &factory)
{
    factory.registerComponent("input", new nts::Components::InputComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
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
    factory.registerComponent("4069", new nts::Components::C4069Component());
    factory.registerComponent("4081", new nts::Components::C4081Component());
    factory.registerComponent("7482", new nts::Components::C7482Component());
    factory.registerComponent("4008", new nts::Components::C4008Component());
    factory.registerComponent("4013", new nts::Components::P4013Component());
    factory.registerComponent("4040", new nts::Components::P4040Component());
    factory.registerComponent("4514", new nts::Components::P4514Component());
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
        nts::Simulation simulation(fileContainer.getMap());
        simulation.execSimulation();
    } catch (nts::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
