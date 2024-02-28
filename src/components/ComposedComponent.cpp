/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ComposedComponent.hpp"

using namespace nts::Components;

ComposedComponent::ComposedComponent(std::size_t nbPins, std::size_t nbInternals) : AbstractComponent(nbPins) {
    this->_internal.reserve(nbInternals);
}

ComposedComponent::~ComposedComponent() {
    for (auto &internal : this->_internal) {
        delete internal.second;
    }
}
