/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "AbstractComponent.hpp"

using namespace nts::Components;

AbstractComponent::AbstractComponent(std::size_t nbPins) {
    this->_pins = std::unordered_map<std::size_t, std::tuple<IComponent *, PinMode, std::size_t>>();
    for (std::size_t i = 1; i <= nbPins; i++) {
        this->_pins[i] = std::make_tuple(nullptr, INPUT, 0);
    }
}

void AbstractComponent::simulate(std::size_t tick) {
    // Simulate the component
}

void AbstractComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    // Check that the pin exists and is not already linked
    if (!this->hasPin(pin) || this->isLinked(pin)) {
        // throw error
        return;
    }

    // Link the pins
    PinMode mode = this->getPinMode(pin);
    this->_pins.at(pin) = std::make_tuple(&other, mode, otherPin);

    // Link the other component's pin
    other.setLink(otherPin, *this, pin);
}

bool AbstractComponent::hasPin(std::size_t pin) const {
    return this->_pins.find(pin) != this->_pins.end();
}

PinMode AbstractComponent::getPinMode(std::size_t pin) const {
    return std::get<1>(this->_pins.at(pin));
}

bool AbstractComponent::isLinked(std::size_t pin) const {
    return std::get<0>(this->_pins.at(pin)) != nullptr;
}


void AbstractComponent::getLink(std::size_t pin) const {
    // Check that the pin exists, it is linked and it is an output
    if (!this->hasPin(pin) || !this->isLinked(pin) || this->getPinMode(pin) != OUTPUT) {
        // throw error
        return;
    }

    // Execute the linked component's compute method
    std::get<0>(this->_pins.at(pin))->compute(std::get<2>(this->_pins.at(pin)));
}

void AbstractComponent::setPinMode(std::size_t pin, PinMode type) {
    if (this->hasPin(pin)) {
        std::get<1>(this->_pins.at(pin)) = type;
    }
}

std::size_t AbstractComponent::getParentPin(std::size_t pin) const {
    return std::get<2>(this->_pins.at(pin));
}

nts::IComponent *AbstractComponent::getLinkedComponent(std::size_t pin) const {
    if (!this->isLinked(pin)) {
        return nullptr;
    }
    return std::get<0>(this->_pins.at(pin));
}
