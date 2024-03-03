/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "LoggerComponent.hpp"
using namespace nts::Components;

LoggerComponent::LoggerComponent() : AbstractComponent(10, "logger")
{
    this->setPinMode(IN_0, PinMode::INPUT);
    this->setPinMode(IN_1, PinMode::INPUT);
    this->setPinMode(IN_2, PinMode::INPUT);
    this->setPinMode(IN_3, PinMode::INPUT);
    this->setPinMode(IN_4, PinMode::INPUT);
    this->setPinMode(IN_5, PinMode::INPUT);
    this->setPinMode(IN_6, PinMode::INPUT);
    this->setPinMode(IN_7, PinMode::INPUT);
    this->setPinMode(CLOCK, PinMode::INPUT);
    this->setPinMode(INHIBIT, PinMode::INPUT);

    this->_lastClock = nts::UNDEFINED;
    this->_file.open("./log.bin");
}

LoggerComponent::LoggerComponent(LoggerComponent const &other) : AbstractComponent(other)
{
    this->_lastClock = other._lastClock;
    this->_file.open("./log.bin");
}

LoggerComponent::~LoggerComponent()
{
    this->_file.close();
}

void LoggerComponent::beforeSimulation(std::size_t tick)
{
    (void) tick;

    nts::Tristate clock = this->computeInput(CLOCK);
    this->_lastClock = clock;
}

void LoggerComponent::internalSimulate(std::size_t tick)
{
    (void) tick;

    nts::Tristate inhibit = this->computeInput(INHIBIT);
    nts::Tristate clock = this->computeInput(CLOCK);
    if (inhibit == nts::TRUE) {
        return;
    }

    nts::Tristate in0 = this->computeInput(IN_0);
    nts::Tristate in1 = this->computeInput(IN_1);
    nts::Tristate in2 = this->computeInput(IN_2);
    nts::Tristate in3 = this->computeInput(IN_3);
    nts::Tristate in4 = this->computeInput(IN_4);
    nts::Tristate in5 = this->computeInput(IN_5);
    nts::Tristate in6 = this->computeInput(IN_6);
    nts::Tristate in7 = this->computeInput(IN_7);
    if (this->_lastClock == nts::FALSE && clock == nts::TRUE) {
        if (in0 == nts::UNDEFINED || in1 == nts::UNDEFINED || in2 == nts::UNDEFINED || in3 == nts::UNDEFINED || in4 == nts::UNDEFINED || in5 == nts::UNDEFINED || in6 == nts::UNDEFINED || in7 == nts::UNDEFINED) {
            return;
        }
        if (this->_file.is_open()) {
            int byte = 0;
            byte |= (in0 == nts::TRUE ? 1 : 0) << 0;
            byte |= (in1 == nts::TRUE ? 1 : 0) << 1;
            byte |= (in2 == nts::TRUE ? 1 : 0) << 2;
            byte |= (in3 == nts::TRUE ? 1 : 0) << 3;
            byte |= (in4 == nts::TRUE ? 1 : 0) << 4;
            byte |= (in5 == nts::TRUE ? 1 : 0) << 5;
            byte |= (in6 == nts::TRUE ? 1 : 0) << 6;
            byte |= (in7 == nts::TRUE ? 1 : 0) << 7;
            this->_file.write(reinterpret_cast<const char *>(&byte), sizeof(byte));
        }
    }
}

std::unique_ptr<nts::IComponent> LoggerComponent::clone() const
{
    return std::make_unique<LoggerComponent>(*this);
}
