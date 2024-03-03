/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/primitive/P4094Component.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/ClockComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <criterion/criterion.h>

Test(P4094Component, output_disabled)
{
    nts::Components::P4094Component p4094component;
    nts::Components::InputComponent data;
    nts::Components::ClockComponent clock;
    nts::Components::InputComponent strobe;
    nts::Components::InputComponent oe;
    nts::Components::OutputComponent q[8];
    nts::Components::OutputComponent qs;
    nts::Components::OutputComponent qs_prime;

    p4094component.setLink(nts::Components::P4094Component::OE, oe, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::DATA, data, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::CLOCK, clock, nts::Components::ClockComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::STROBE, strobe, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::Q1, q[0], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q2, q[1], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q3, q[2], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q4, q[3], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q5, q[4], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q6, q[5], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q7, q[6], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q8, q[7], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::QS, qs, nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::QS_PRIME, qs_prime, nts::Components::OutputComponent::IN);

    oe.setValue(nts::FALSE);
    data.setValue(nts::FALSE);
    clock.setValue(nts::FALSE);
    strobe.setValue(nts::FALSE);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(0);
        cr_assert_eq(q[i].compute(nts::Components::OutputComponent::IN),
                     nts::UNDEFINED);
    }
}

Test(P4094Component, normal_flow)
{
    nts::Components::P4094Component p4094component;
    nts::Components::InputComponent data;
    nts::Components::ClockComponent clock;
    nts::Components::InputComponent strobe;
    nts::Components::InputComponent oe;
    nts::Components::OutputComponent q[8];
    nts::Components::OutputComponent qs;
    nts::Components::OutputComponent qs_prime;

    p4094component.setLink(nts::Components::P4094Component::OE, oe, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::DATA, data, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::CLOCK, clock, nts::Components::ClockComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::STROBE, strobe, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::Q1, q[0], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q2, q[1], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q3, q[2], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q4, q[3], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q5, q[4], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q6, q[5], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q7, q[6], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q8, q[7], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::QS, qs, nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::QS_PRIME, qs_prime, nts::Components::OutputComponent::IN);

    oe.setValue(nts::TRUE);
    data.setValue(nts::TRUE);
    clock.setValue(nts::FALSE);
    strobe.setValue(nts::TRUE);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(0);
    }
    qs.simulate(0);
    qs_prime.simulate(0);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(1);
    }
    qs.simulate(1);
    qs_prime.simulate(1);
    data.setValue(nts::FALSE);
    cr_assert_eq(clock.compute(nts::Components::ClockComponent::OUT), nts::TRUE);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(2);
    }
    qs.simulate(2);
    qs_prime.simulate(2);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(3);
    }
    qs.simulate(3);
    qs_prime.simulate(3);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(4);
    }
    qs.simulate(4);
    qs_prime.simulate(4);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(5);
    }
    qs.simulate(5);
    qs_prime.simulate(5);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(6);
    }
    qs.simulate(6);
    qs_prime.simulate(6);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(7);
    }
    qs.simulate(7);
    qs_prime.simulate(7);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(8);
    }
    qs.simulate(8);
    qs_prime.simulate(8);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(9);
    }
    qs.simulate(9);
    qs_prime.simulate(9);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(10);
    }
    qs.simulate(10);
    qs_prime.simulate(10);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(11);
    }
    qs.simulate(11);
    qs_prime.simulate(11);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(12);
    }
    qs.simulate(12);
    qs_prime.simulate(12);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(13);
    }
    qs.simulate(13);
    qs_prime.simulate(13);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(14);
    }
    qs.simulate(14);
    qs_prime.simulate(14);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(15);
    }
    qs.simulate(15);
    qs_prime.simulate(15);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(16);
    }
    qs.simulate(16);
    qs_prime.simulate(16);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(17);
    }
    qs.simulate(17);
    qs_prime.simulate(17);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(18);
    }
    qs.simulate(18);
    qs_prime.simulate(18);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::FALSE);
}

Test(P4094Component, disable_strobe)
{
    nts::Components::P4094Component p4094component;
    nts::Components::InputComponent data;
    nts::Components::ClockComponent clock;
    nts::Components::InputComponent strobe;
    nts::Components::InputComponent oe;
    nts::Components::OutputComponent q[8];
    nts::Components::OutputComponent qs;
    nts::Components::OutputComponent qs_prime;

    p4094component.setLink(nts::Components::P4094Component::OE, oe, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::DATA, data, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::CLOCK, clock, nts::Components::ClockComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::STROBE, strobe, nts::Components::InputComponent::OUT);
    p4094component.setLink(nts::Components::P4094Component::Q1, q[0], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q2, q[1], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q3, q[2], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q4, q[3], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q5, q[4], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q6, q[5], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q7, q[6], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::Q8, q[7], nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::QS, qs, nts::Components::OutputComponent::IN);
    p4094component.setLink(nts::Components::P4094Component::QS_PRIME, qs_prime, nts::Components::OutputComponent::IN);

    oe.setValue(nts::TRUE);
    data.setValue(nts::TRUE);
    clock.setValue(nts::FALSE);
    strobe.setValue(nts::TRUE);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(0);
    }
    qs.simulate(0);
    qs_prime.simulate(0);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(1);
    }
    qs.simulate(1);
    qs_prime.simulate(1);
    data.setValue(nts::FALSE);
    cr_assert_eq(clock.compute(nts::Components::ClockComponent::OUT), nts::TRUE);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(2);
    }
    qs.simulate(2);
    qs_prime.simulate(2);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    strobe.setValue(nts::FALSE);
    for (std::size_t i = 0; i < 8; i++) {
        q[i].simulate(3);
    }
    qs.simulate(3);
    qs_prime.simulate(3);

    cr_assert_eq(q[0].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(q[1].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[2].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[3].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[4].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[5].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[6].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(q[7].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qs_prime.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
}