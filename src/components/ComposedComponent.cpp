/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ComposedComponent.hpp"

using namespace nts::Components;

ComposedComponent::ComposedComponent(std::size_t nbPins, const std::string& name, std::size_t nbInternals) : AbstractComponent(nbPins, name) {
    this->_internal.reserve(nbInternals);
}

ComposedComponent::~ComposedComponent() {
    for (auto &internal : this->_internal) {
        delete internal.second;
    }
}

void ComposedComponent::setInternalLink(std::size_t pin, nts::IComponent &other,
                                std::size_t otherPin) {
    // Check that the pin exists
    if (!this->hasPin(pin) || isLinkedTo(pin, &other)) {
        // throw error
        return;
    }

    // Link the pins
    std::get<1>(this->_pins.at(pin)).push_back(std::make_tuple(&other, otherPin, true));

    // Link the other component's pin
    other.setLink(otherPin, *this, pin);
}