/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/primitive/P4013Component.hpp"
#include "../src/components/ClockComponent.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <criterion/criterion.h>

Test(P4013Component, basic_test_ff1)
{
    nts::Components::P4013Component p4013component;
    nts::Components::ClockComponent clock;
    nts::Components::InputComponent data;
    nts::Components::InputComponent set;
    nts::Components::InputComponent reset;
    nts::Components::OutputComponent q;
    nts::Components::OutputComponent qn;


    p4013component.setLink(nts::Components::P4013Component::CLK1, clock, nts::Components::ClockComponent::OUT);
    p4013component.setLink(nts::Components::P4013Component::D1, data, nts::Components::InputComponent::OUT);
    p4013component.setLink(nts::Components::P4013Component::S1, set, nts::Components::InputComponent::OUT);
    p4013component.setLink(nts::Components::P4013Component::RS1, reset, nts::Components::InputComponent::OUT);
    p4013component.setLink(nts::Components::P4013Component::Q1, q, nts::Components::OutputComponent::IN);
    p4013component.setLink(nts::Components::P4013Component::Q1B, qn, nts::Components::OutputComponent::IN);

    // First tick
    clock.setValue(nts::FALSE);
    data.setValue(nts::FALSE);
    set.setValue(nts::FALSE);
    reset.setValue(nts::FALSE);

    q.simulate(0);
    qn.simulate(0);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    // Second tick (rising edge) (reset)
    reset.setValue(nts::TRUE);

    q.simulate(1);
    qn.simulate(1);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Third tick (falling edge) (reset off)
    reset.setValue(nts::FALSE);

    q.simulate(2);
    qn.simulate(2);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Fourth tick (rising edge) (data change)
    data.setValue(nts::TRUE);

    q.simulate(3);
    qn.simulate(3);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    // Fifth tick (falling edge) (data off)
    data.setValue(nts::FALSE);

    q.simulate(4);
    qn.simulate(4);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    // Sixth tick (rising edge) (no change)
    q.simulate(5);
    qn.simulate(5);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Seventh tick (falling edge) (reset)
    reset.setValue(nts::TRUE);

    q.simulate(6);
    qn.simulate(6);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Eighth tick (rising edge) (reset off)
    reset.setValue(nts::FALSE);

    q.simulate(7);
    qn.simulate(7);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Ninth tick (falling edge) (set)
    set.setValue(nts::TRUE);

    q.simulate(8);
    qn.simulate(8);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    // Tenth tick (rising edge) (set off)
    set.setValue(nts::FALSE);

    q.simulate(9);
    qn.simulate(9);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Eleventh tick (falling edge) (reset & set)
    reset.setValue(nts::TRUE);
    set.setValue(nts::TRUE);

    q.simulate(10);
    qn.simulate(10);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Twelfth tick (rising edge) (set && reset off)
    reset.setValue(nts::FALSE);

    q.simulate(11);
    qn.simulate(11);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::FALSE);
}

Test(P4013Component, basic_test_ff2)
{
    nts::Components::P4013Component p4013component;
    nts::Components::ClockComponent clock;
    nts::Components::InputComponent data;
    nts::Components::InputComponent set;
    nts::Components::InputComponent reset;
    nts::Components::OutputComponent q;
    nts::Components::OutputComponent qn;


    p4013component.setLink(nts::Components::P4013Component::CLK2, clock, nts::Components::ClockComponent::OUT);
    p4013component.setLink(nts::Components::P4013Component::D2, data, nts::Components::InputComponent::OUT);
    p4013component.setLink(nts::Components::P4013Component::S2, set, nts::Components::InputComponent::OUT);
    p4013component.setLink(nts::Components::P4013Component::RS2, reset, nts::Components::InputComponent::OUT);
    p4013component.setLink(nts::Components::P4013Component::Q2, q, nts::Components::OutputComponent::IN);
    p4013component.setLink(nts::Components::P4013Component::Q2B, qn, nts::Components::OutputComponent::IN);

    // First tick
    clock.setValue(nts::FALSE);
    data.setValue(nts::FALSE);
    set.setValue(nts::FALSE);
    reset.setValue(nts::FALSE);

    q.simulate(0);
    qn.simulate(0);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);

    // Second tick (rising edge) (reset)
    reset.setValue(nts::TRUE);

    q.simulate(1);
    qn.simulate(1);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Third tick (falling edge) (reset off)
    reset.setValue(nts::FALSE);

    q.simulate(2);
    qn.simulate(2);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Fourth tick (rising edge) (data change)
    data.setValue(nts::TRUE);

    q.simulate(3);
    qn.simulate(3);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    // Fifth tick (falling edge) (data off)
    data.setValue(nts::FALSE);

    q.simulate(4);
    qn.simulate(4);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    // Sixth tick (rising edge) (no change)
    q.simulate(5);
    qn.simulate(5);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Seventh tick (falling edge) (reset)
    reset.setValue(nts::TRUE);

    q.simulate(6);
    qn.simulate(6);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Eighth tick (rising edge) (reset off)
    reset.setValue(nts::FALSE);

    q.simulate(7);
    qn.simulate(7);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Ninth tick (falling edge) (set)
    set.setValue(nts::TRUE);

    q.simulate(8);
    qn.simulate(8);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    // Tenth tick (rising edge) (set off)
    set.setValue(nts::FALSE);

    q.simulate(9);
    qn.simulate(9);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Eleventh tick (falling edge) (reset & set)
    reset.setValue(nts::TRUE);
    set.setValue(nts::TRUE);

    q.simulate(10);
    qn.simulate(10);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::TRUE);

    // Twelfth tick (rising edge) (set && reset off)
    reset.setValue(nts::FALSE);

    q.simulate(11);
    qn.simulate(11);

    cr_assert_eq(q.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qn.compute(nts::Components::OutputComponent::IN), nts::FALSE);
}
