/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** execSimulation
*/

#include "Simulation.hpp"
#include "Error.hpp"
#include "components/InputComponent.hpp"
// #include "OutputComponent.hpp"
// This include is in comments since the Output component is not implemented yet
#include <string.h>
#include <signal.h>

nts::Simulation::Simulation(std::map<std::string, IComponent *> pins)
{
    this->_pins = pins;
    this->_exit = false;
    this->_commands["exit\n"] = &nts::Simulation::exit;
    this->_commands["display\n"] = &nts::Simulation::display;
    this->_commands["simulate\n"] = &nts::Simulation::simulate;
    this->_commands["loop\n"] = &nts::Simulation::loop;
    this->_ticks = 0;
}

nts::Simulation::~Simulation()
{
}

void nts::Simulation::execSimulation()
{
    char *line = NULL;
    size_t len = 0;

    while (!this->_exit) {
        std::cout << "> " << std::flush;
        if (getline(&line, &len, stdin) == -1)
            return;
        if (isKnownCommand(line))
            continue;
        else
            std::cout << "Unknown command." << std::endl;
    }
}

void nts::Simulation::stopLoop()
{
    this->_loop = false;
}

bool nts::Simulation::isKnownCommand(char *line)
{
    std::string str = line;
    if (this->_commands[line] != nullptr) {
        (this->*_commands[line])();
        return true;
    }
    return false;
}

void nts::Simulation::exit()
{
    this->_exit = true;
}

void nts::Simulation::display()
{
    std::cout << "tick: " << this->_ticks << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &pin : this->_pins) {
        if (dynamic_cast<nts::Components::InputComponent *>(pin.second) != nullptr)
            std::cout << "  " << pin.first << ": " << pin.second->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    // for (auto &pin : this->_pins) {
    //     if (dynamic_cast<nts::Components::OutputComponent *>(pin.second) == nullptr)
    //         std::cout << "  " << pin.first << ": " << pin.second->compute(1) << std::endl;
    // }
    // This part is in comments since the Output component is not implemented yet
}

void nts::Simulation::simulate()
{
    std::unordered_map<std::string, IComponent *> pins;
    // for (auto &pin : this->_pins) {
    //     if (dynamic_cast<nts::Components::OutputComponent *>(pin.second) != nullptr)
    //         pins.push_back(pin);
    //     else
    //         pin.second->simulate(1);
    // }
    // This part is in comments since the Output component is not implemented yet
    for (auto &pin : pins) {
        pin.second->simulate(1);
    }
    this->_ticks++;
}

static void handleLoop(void *arg)
{
    static nts::Simulation *sim;

    if (arg == NULL && sim == NULL)
        return;
    if (arg != NULL)
        sim = (nts::Simulation *)arg;
    if (arg == NULL)
        sim->stopLoop();
}

static void signalHandler(int signum)
{
    if (signum == SIGINT)
        handleLoop(NULL);
}

void nts::Simulation::loop()
{
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = signalHandler;
    this->_loop = true;
    handleLoop(this);
    while (this->_loop) {
        simulate();
        display();
        sleep(1);
        sigaction(SIGINT, &sigIntHandler, NULL);
    }
}
