/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/composed/C7482Component.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include <criterion/criterion.h>

static void testC7482(short a, short b, bool carry) {
    bool a1 = a & 1;
    bool a2 = a & 2;

    bool b1 = b & 1;
    bool b2 = b & 2;

    bool sum1 = a1 ^ b1 ^ carry;
    bool carry1 = (a1 & b1) | (a1 & carry) | (b1 & carry);
    bool sum2 = a2 ^ b2 ^ carry1;
    bool carry2 = (a2 & b2) | (a2 & carry1) | (b2 & carry1);

    nts::Components::C7482Component *comp = new nts::Components::C7482Component();
    nts::IComponent *a1c;
    nts::IComponent *a2c;

    if (a1) {
        a1c = new nts::Components::TrueComponent();
    } else {
        a1c = new nts::Components::FalseComponent();
    }
    if (a2) {
        a2c = new nts::Components::TrueComponent();
    } else {
        a2c = new nts::Components::FalseComponent();
    }

    nts::IComponent *b1c;
    nts::IComponent *b2c;

    if (b1) {
        b1c = new nts::Components::TrueComponent();
    } else {
        b1c = new nts::Components::FalseComponent();
    }
    if (b2) {
        b2c = new nts::Components::TrueComponent();
    } else {
        b2c = new nts::Components::FalseComponent();
    }

    nts::IComponent *cinc;
    if (carry) {
        cinc = new nts::Components::TrueComponent();
    } else {
        cinc = new nts::Components::FalseComponent();
    }

    comp->setLink(nts::Components::C7482Component::A1, *a1c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C7482Component::A2, *a2c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C7482Component::B1, *b1c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C7482Component::B2, *b2c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C7482Component::CIN, *cinc, nts::Components::FalseComponent::OUT);

    nts::Tristate y1 = comp->compute(nts::Components::C7482Component::Y1);
    nts::Tristate y2 = comp->compute(nts::Components::C7482Component::Y2);
    nts::Tristate cout = comp->compute(nts::Components::C7482Component::COUT);

    cr_assert_eq(y1, sum1 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    cr_assert_eq(y2, sum2 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    cr_assert_eq(cout, carry2 ? nts::Tristate::TRUE : nts::Tristate::FALSE);

    delete comp;
    delete a1c;
    delete a2c;
    delete b1c;
    delete b2c;
    delete cinc;
}

Test(C7482Component, truth_table)
{
    for (short a = 0; a < 8; a++) {
        for (short b = 0; b < 8; b++) {
            for (short carry = 0; carry < 2; carry++) {
                testC7482(a, b, carry == 1);
            }
        }
    }
}