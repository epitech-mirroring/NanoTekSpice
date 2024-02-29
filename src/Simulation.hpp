/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Simulation
*/

#pragma once

#include "FileContainer.hpp"

namespace nts {
    class Simulation {
    public:
        Simulation(std::map<std::string, nts::IComponent *> pins);
        ~Simulation();

        void execSimulation();
        void stopLoop();
    protected:
    private:
        std::map<std::string, nts::IComponent *> _pins;
        std::unordered_map<std::string, void (nts::Simulation::*)()> _commands;
        bool _exit;
        size_t _ticks;
        bool _loop;

        bool isKnownCommand(const char *line);
        void exit();
        void display();
        void simulate();
        void loop();

        void handleInputs(const char *line);
        void setValues(const std::string& name, const std::string& value);
    };
};
