/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/primitive/P4040Component.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include "../src/components/ClockComponent.hpp"
#include <criterion/criterion.h>

Test(P4040Component, no_reset)
{
    nts::Components::P4040Component p4040component;
    nts::Components::ClockComponent clock;
    nts::Components::InputComponent reset;
    nts::Components::OutputComponent q[12];

    p4040component.setLink(nts::Components::P4040Component::CLK, clock, nts::Components::ClockComponent::OUT);
    p4040component.setLink(nts::Components::P4040Component::RS, reset, nts::Components::InputComponent::OUT);
    p4040component.setLink(nts::Components::P4040Component::Q1, q[0], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q2, q[1], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q3, q[2], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q4, q[3], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q5, q[4], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q6, q[5], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q7, q[6], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q8, q[7], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q9, q[8], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q10, q[9], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q11, q[10], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q12, q[11], nts::Components::OutputComponent::IN);

    std::size_t tick = 0;
    std::size_t value = 0;

    // There is one tick for the falling edge and one for the rising edge
    // Since we start from low on tick 0, first rising edge is on tick 1
    // We count up to 4096, so we need 8192 ticks
    clock.setValue(nts::FALSE);
    nts::Tristate oldClock = nts::FALSE;

    for (std::size_t i = 0; i < 8192; i++) {
        for (std::size_t j = 0; j < 12; j++) {
            q[j].simulate(tick);
        }

        // Increment the value on the falling edge
        if (oldClock == nts::TRUE && clock.compute(nts::Components::ClockComponent::OUT) == nts::FALSE) {
            value++;
        }

        // Check the value of each output
        for (std::size_t j = 0; j < 12; j++) {
            cr_assert_eq(q[j].compute(nts::Components::OutputComponent::IN), (value & (1 << j)) ? nts::FALSE : nts::TRUE);
        }

        oldClock = clock.compute(nts::Components::ClockComponent::OUT);
    }
}

Test(P4040Component, no_reset_overflow)
{
    nts::Components::P4040Component p4040component;
    nts::Components::ClockComponent clock;
    nts::Components::InputComponent reset;
    nts::Components::OutputComponent q[12];

    p4040component.setLink(nts::Components::P4040Component::CLK, clock, nts::Components::ClockComponent::OUT);
    p4040component.setLink(nts::Components::P4040Component::RS, reset, nts::Components::InputComponent::OUT);
    p4040component.setLink(nts::Components::P4040Component::Q1, q[0], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q2, q[1], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q3, q[2], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q4, q[3], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q5, q[4], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q6, q[5], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q7, q[6], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q8, q[7], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q9, q[8], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q10, q[9], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q11, q[10], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q12, q[11], nts::Components::OutputComponent::IN);

    std::size_t tick = 0;
    std::size_t value = 0;

    // There is one tick for the falling edge and one for the rising edge
    // Since we start from low on tick 0, first rising edge is on tick 1
    // We count up to 4096, so we need 8192 ticks
    clock.setValue(nts::FALSE);
    nts::Tristate oldClock = nts::FALSE;

    for (; tick < 8192; tick++) {
        for (std::size_t j = 0; j < 12; j++) {
            q[j].simulate(tick);
        }

        // Increment the value on the falling edge
        if (oldClock == nts::TRUE && clock.compute(nts::Components::ClockComponent::OUT) == nts::FALSE) {
            value++;
        }

        // Check the value of each output
        for (std::size_t j = 0; j < 12; j++) {
            cr_assert_eq(q[j].compute(nts::Components::OutputComponent::IN), (value & (1 << j)) ? nts::FALSE : nts::TRUE);
        }

        oldClock = clock.compute(nts::Components::ClockComponent::OUT);
    }

    for (std::size_t i = 0; i < 12; i++) {
        q[i].simulate(tick);
    }

    // The value should be 0
    for (std::size_t i = 0; i < 12; i++) {
        cr_assert_eq(q[i].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    }
}

Test(P4040Component, reset_half_way)
{
    nts::Components::P4040Component p4040component;
    nts::Components::ClockComponent clock;
    nts::Components::InputComponent reset;
    nts::Components::OutputComponent q[12];

    p4040component.setLink(nts::Components::P4040Component::CLK, clock, nts::Components::ClockComponent::OUT);
    p4040component.setLink(nts::Components::P4040Component::RS, reset, nts::Components::InputComponent::OUT);
    p4040component.setLink(nts::Components::P4040Component::Q1, q[0], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q2, q[1], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q3, q[2], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q4, q[3], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q5, q[4], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q6, q[5], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q7, q[6], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q8, q[7], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q9, q[8], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q10, q[9], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q11, q[10], nts::Components::OutputComponent::IN);
    p4040component.setLink(nts::Components::P4040Component::Q12, q[11], nts::Components::OutputComponent::IN);

    std::size_t tick = 0;
    std::size_t value = 0;

    // There is one tick for the falling edge and one for the rising edge
    // Since we start from low on tick 0, first rising edge is on tick 1
    // We count up to 4096, so we need 8192 ticks
    clock.setValue(nts::FALSE);
    nts::Tristate oldClock = nts::FALSE;

    for (;tick < 8192; tick++) {
        if (tick == 4096) {
            reset.setValue(nts::TRUE);
        }

        for (std::size_t j = 0; j < 12; j++) {
            q[j].simulate(tick);
        }

        // Increment the value on the falling edge
        if (oldClock == nts::TRUE && clock.compute(nts::Components::ClockComponent::OUT) == nts::FALSE) {
            value++;
        }

        if (tick == 4096) {
            reset.setValue(nts::FALSE);
            value = 0;
        }

        // Check the value of each output
        for (std::size_t j = 0; j < 12; j++) {
            cr_assert_eq(q[j].compute(nts::Components::OutputComponent::IN), (value & (1 << j)) ? nts::FALSE : nts::TRUE);
        }

        oldClock = clock.compute(nts::Components::ClockComponent::OUT);
    }
}
