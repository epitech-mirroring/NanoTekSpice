/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "AbstractComponent.hpp"

using namespace nts::Components;

AbstractComponent::AbstractComponent(std::size_t nbPins, const std::string &name) : _name(name) {
    this->_pins = std::unordered_map<std::size_t, Pin>();
    this->_oldValues = std::unordered_map<std::size_t, nts::Tristate>();
    this->_computed = std::unordered_map<std::size_t, bool>();
    for (std::size_t i = 1; i <= nbPins; i++) {
        this->_pins[i] = std::make_pair(INPUT, std::vector<Link>());
        this->_oldValues[i] = UNDEFINED;
        this->_computed[i] = false;
    }
}

AbstractComponent::~AbstractComponent() {
    // Delete the pins
    this->_pins.clear();
    this->_oldValues.clear();
    this->_computed.clear();
}

void AbstractComponent::simulate(std::size_t tick) {
    if (this->_lastSimulationTick == tick) {
        return;
    }
    this->_lastSimulationTick = tick;

    // Simulate connected input components
    for (std::size_t i = 1; i <= this->_pins.size(); i++) {
        if (this->getPinMode(i) == INPUT) {
            std::vector<Link> links = std::get<1>(this->_pins.at(i));
            for (auto &link : links) {
                if (std::get<0>(link) != nullptr) {
                    std::get<0>(link)->simulate(tick);
                }
            }
        }
    }

    // Reset computed values
    for (std::size_t i = 1; i <= this->_pins.size(); i++) {
        this->_computed[i] = false;
    }

    // Simulate the component
    this->internalSimulate(tick);
}

bool AbstractComponent::isLinkedTo(std::size_t pin, IComponent *component) const {
    if (!this->hasPin(pin)) {
        return false;
    }
    Pin pinData = this->_pins.at(pin);
    std::vector<Link> links = std::get<1>(pinData);
    for (auto &link : links) {
        if (std::get<0>(link) == component) {
            return true;
        }
    }
    return false;
}

void AbstractComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    // Check that the pin exists
    if (!this->hasPin(pin) || isLinkedTo(pin, &other)) {
        // throw error
        return;
    }

    // Link the pins
    std::get<1>(this->_pins.at(pin)).push_back(std::make_tuple(&other, otherPin, false));

    // Link the other component's pin
    other.setLink(otherPin, *this, pin);
}

bool AbstractComponent::hasPin(std::size_t pin) const {
    return this->_pins.find(pin) != this->_pins.end();
}

PinMode AbstractComponent::getPinMode(std::size_t pin) const {
    Pin pinData = this->_pins.at(pin);
    return std::get<0>(pinData);
}

bool AbstractComponent::isLinked(std::size_t pin) const {
    if (!this->hasPin(pin)) {
        return false;
    }
    Pin pinData = this->_pins.at(pin);
    std::vector<Link> links = std::get<1>(pinData);
    return !links.empty();
}


void AbstractComponent::getLink(std::size_t pin) const {
    // Check that the pin exists, it is linked and it is an output
    if (!this->hasPin(pin) || !this->isLinked(pin) || this->getPinMode(pin) != OUTPUT) {
        // throw error
        return;
    }

    // Execute the linked component's compute method
    Pin pinData = this->_pins.at(pin);
    std::vector<Link> links = std::get<1>(pinData);
    for (auto &link : links) {
        if (std::get<0>(link) != nullptr) {
            std::get<0>(link)->compute(std::get<1>(link));
        }
    }
}

void AbstractComponent::setPinMode(std::size_t pin, PinMode type) {
    if (this->hasPin(pin)) {
        Pin pinData = this->_pins.at(pin);
        std::get<0>(pinData) = type;
        this->_pins.at(pin) = pinData;
    }
}

std::size_t AbstractComponent::getParentPin(std::size_t pin, std::size_t link) const {
    if (!this->hasPin(pin)) {
        return 0;
    }
    Pin pinData = this->_pins.at(pin);
    std::vector<Link> links = std::get<1>(pinData);
    if (link >= links.size()) {
        return 0;
    }

    return std::get<1>(links.at(link));
}

nts::IComponent *AbstractComponent::getLinkedComponent(std::size_t pin, std::size_t link) const {
    if (!this->isLinked(pin)) {
        return nullptr;
    }
    Pin pinData = this->_pins.at(pin);
    std::vector<Link> links = std::get<1>(pinData);
    if (link >= links.size()) {
        return nullptr;
    }
    return std::get<0>(links.at(link));
}

nts::Tristate AbstractComponent::computeInput(std::size_t pin) const {
    if (!this->hasPin(pin) || this->getPinMode(pin) != INPUT) {
        return UNDEFINED;
    }
    Pin pinData = this->_pins.at(pin);
    std::vector<Link> links = std::get<1>(pinData);
    if (links.empty()) {
        return UNDEFINED;
    }

    if (this->isLinkedTo(pin, (IComponent *) this)) {
        return this->_oldValues.at(pin);
    }

    Tristate value = UNDEFINED;
    bool hasValue = false;
    for (auto &link : links) {
        if (dynamic_cast<AbstractComponent *>(std::get<0>(link)) != nullptr) {
            auto *component = dynamic_cast<AbstractComponent *>(std::get<0>(link));
            if (component->getPinMode(std::get<1>(link)) == OUTPUT) {
                value = value || component->compute(std::get<1>(link));
                hasValue = true;
            }
        }
    }
    if (!hasValue) {
        for (auto &link : links) {
            if (dynamic_cast<AbstractComponent *>(std::get<0>(link)) != nullptr) {
                auto *component = dynamic_cast<AbstractComponent *>(std::get<0>(link));
                bool isInternal = std::get<2>(link);
                if (!isInternal) {
                    value = value || component->compute(std::get<1>(link));
                    hasValue = true;
                }
            }
        }
    }
    if (!hasValue) {
        return UNDEFINED;
    }
    return value;
}

nts::Tristate AbstractComponent::compute(std::size_t pin) {
    if (!this->hasPin(pin)) {
        return UNDEFINED;
    }
    if (this->_computed[pin]) {
        return _oldValues[pin];
    }
    if (this->getPinMode(pin) == INPUT) {
        return this->computeInput(pin);
    }

    _computed[pin] = true;
    Tristate n = this->internalCompute(pin);
    _oldValues[pin] = n;
    return n;
}

void AbstractComponent::setOldValue(std::size_t pin, nts::Tristate value) {
    if (this->hasPin(pin)) {
        this->_oldValues[pin] = value;
    }
}

void AbstractComponent::internalSimulate(std::size_t tick) {
    (void)tick;
}
