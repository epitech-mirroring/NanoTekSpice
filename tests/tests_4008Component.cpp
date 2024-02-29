/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/composed/C4008Component.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include <criterion/criterion.h>

static void testC4008(short a, short b, bool carry) {
    bool a1 = a & 1;
    bool a2 = a & 2;
    bool a3 = a & 4;
    bool a4 = a & 8;

    bool b1 = b & 1;
    bool b2 = b & 2;
    bool b3 = b & 4;
    bool b4 = b & 8;

    bool sum1 = a1 ^ b1 ^ carry;
    bool carry1 = (a1 & b1) | (a1 & carry) | (b1 & carry);
    bool sum2 = a2 ^ b2 ^ carry1;
    bool carry2 = (a2 & b2) | (a2 & carry1) | (b2 & carry1);
    bool sum3 = a3 ^ b3 ^ carry2;
    bool carry3 = (a3 & b3) | (a3 & carry2) | (b3 & carry2);
    bool sum4 = a4 ^ b4 ^ carry3;
    bool carry4 = (a4 & b4) | (a4 & carry3) | (b4 & carry3);

    nts::Components::C4008Component *comp = new nts::Components::C4008Component();
    nts::IComponent *a1c;
    nts::IComponent *a2c;
    nts::IComponent *a3c;
    nts::IComponent *a4c;

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
    if (a3) {
        a3c = new nts::Components::TrueComponent();
    } else {
        a3c = new nts::Components::FalseComponent();
    }
    if (a4) {
        a4c = new nts::Components::TrueComponent();
    } else {
        a4c = new nts::Components::FalseComponent();
    }

    nts::IComponent *b1c;
    nts::IComponent *b2c;
    nts::IComponent *b3c;
    nts::IComponent *b4c;

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
    if (b3) {
        b3c = new nts::Components::TrueComponent();
    } else {
        b3c = new nts::Components::FalseComponent();
    }
    if (b4) {
        b4c = new nts::Components::TrueComponent();
    } else {
        b4c = new nts::Components::FalseComponent();
    }

    nts::IComponent *cinc;
    if (carry) {
        cinc = new nts::Components::TrueComponent();
    } else {
        cinc = new nts::Components::FalseComponent();
    }

    comp->setLink(nts::Components::C4008Component::A1, *a1c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::A2, *a2c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::A3, *a3c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::A4, *a4c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::B1, *b1c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::B2, *b2c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::B3, *b3c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::B4, *b4c, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::CIN, *cinc, nts::Components::FalseComponent::OUT);

    nts::Tristate y1 = comp->compute(nts::Components::C4008Component::Y1);
    nts::Tristate y2 = comp->compute(nts::Components::C4008Component::Y2);
    nts::Tristate y3 = comp->compute(nts::Components::C4008Component::Y3);
    nts::Tristate y4 = comp->compute(nts::Components::C4008Component::Y4);
    nts::Tristate cout = comp->compute(nts::Components::C4008Component::COUT);

    cr_assert_eq(y1, sum1 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    cr_assert_eq(y2, sum2 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    cr_assert_eq(y3, sum3 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    cr_assert_eq(y4, sum4 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
    cr_assert_eq(cout, carry4 ? nts::Tristate::TRUE : nts::Tristate::FALSE);

    delete comp;
    delete a1c;
    delete a2c;
    delete a3c;
    delete a4c;
    delete b1c;
    delete b2c;
    delete b3c;
    delete b4c;
    delete cinc;
}

Test(C4008Component, truth_table)
{
    for (short a = 0; a < 16; a++) {
        for (short b = 0; b < 16; b++) {
            for (short carry = 0; carry < 2; carry++) {
                testC4008(a, b, carry == 1);
            }
        }
    }
}