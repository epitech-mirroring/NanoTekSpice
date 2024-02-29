/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/composed/C4008Component.hpp"
#include "../src/components/FalseComponent.hpp"
#include <criterion/criterion.h>

Test(C4008Component, test0_0)
{
    nts::Components::C4008Component *comp = new nts::Components::C4008Component();
    // Add 0000 + 0000 + 0 = 0000
    nts::Components::FalseComponent *a1 = new nts::Components::FalseComponent();
    nts::Components::FalseComponent *a2 = new nts::Components::FalseComponent();
    nts::Components::FalseComponent *a3 = new nts::Components::FalseComponent();
    nts::Components::FalseComponent *a4 = new nts::Components::FalseComponent();

    comp->setLink(nts::Components::C4008Component::A1, *a1, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::A2, *a2, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::A3, *a3, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::A4, *a4, nts::Components::FalseComponent::OUT);

    nts::Components::FalseComponent *b1 = new nts::Components::FalseComponent();
    nts::Components::FalseComponent *b2 = new nts::Components::FalseComponent();
    nts::Components::FalseComponent *b3 = new nts::Components::FalseComponent();
    nts::Components::FalseComponent *b4 = new nts::Components::FalseComponent();

    comp->setLink(nts::Components::C4008Component::B1, *b1, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::B2, *b2, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::B3, *b3, nts::Components::FalseComponent::OUT);
    comp->setLink(nts::Components::C4008Component::B4, *b4, nts::Components::FalseComponent::OUT);

    nts::Components::FalseComponent *cin = new nts::Components::FalseComponent();

    comp->setLink(nts::Components::C4008Component::CIN, *cin, nts::Components::FalseComponent::OUT);

    cr_assert(comp->isLinkedTo(nts::Components::C4008Component::CIN, cin));

    nts::Tristate y1 = comp->compute(nts::Components::C4008Component::Y1);
    nts::Tristate y2 = comp->compute(nts::Components::C4008Component::Y2);
    nts::Tristate y3 = comp->compute(nts::Components::C4008Component::Y3);
    nts::Tristate y4 = comp->compute(nts::Components::C4008Component::Y4);
    nts::Tristate cout = comp->compute(nts::Components::C4008Component::COUT);

    cr_assert_eq(y1, nts::Tristate::FALSE, "Expected %d but got %d", nts::Tristate::FALSE, y1);
    cr_assert_eq(y2, nts::Tristate::FALSE);
    cr_assert_eq(y3, nts::Tristate::FALSE);
    cr_assert_eq(y4, nts::Tristate::FALSE);
    cr_assert_eq(cout, nts::Tristate::FALSE);

    delete comp;
    delete a1;
    delete a2;
    delete a3;
    delete a4;
    delete b1;
    delete b2;
    delete b3;
    delete b4;
    delete cin;
}