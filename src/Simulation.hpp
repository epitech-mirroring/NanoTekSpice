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
                Simulation(std::map<std::string, IComponent *>);
                ~Simulation();

                void execSimulation();
                void stopLoop(void);
        protected:
        private:
                std::map<std::string, IComponent *> _pins;
                std::unordered_map<std::string, void (nts::Simulation::*)()> _commands;
                bool _exit;
                size_t _ticks;
                bool _loop;

                bool isKnownCommand(char *line);
                void exit(void);
                void display(void);
                void simulate(void);
                void loop(void);

                void handleInputs(char *line);
                void setValues(std::string name, std::string value);
    };
};
