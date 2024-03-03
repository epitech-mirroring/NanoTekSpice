/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/primitive/P4017Component.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/ClockComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <criterion/criterion.h>

Test(P4017Component, starting_state) {
    nts::Components::P4017Component p4017Component;
    nts::Components::InputComponent mr;
    nts::Components::ClockComponent cp0;
    nts::Components::InputComponent cp1;
    nts::Components::OutputComponent out[10];
    nts::Components::OutputComponent qb59;

    p4017Component.setLink(nts::Components::P4017Component::MR, mr, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CP_0, cp0, nts::Components::ClockComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CPB_1, cp1, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::Q0, out[0], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q1, out[1], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q2, out[2], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q3, out[3], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q4, out[4], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q5, out[5], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q6, out[6], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q7, out[7], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q8, out[8], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q9, out[9], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::QB_5_9, qb59, nts::Components::OutputComponent::IN);

    for (std::size_t i = 0; i < 10; i++) {
        out[i].simulate(0);
    }

    cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    for (std::size_t i = 1; i < 10; i++) {
        cr_assert_eq(out[i].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    }
}

Test(P4017Component, normal_flow) {
    nts::Components::P4017Component p4017Component;
    nts::Components::InputComponent mr;
    nts::Components::ClockComponent cp0;
    nts::Components::InputComponent cp1;
    nts::Components::OutputComponent out[10];
    nts::Components::OutputComponent qb59;

    p4017Component.setLink(nts::Components::P4017Component::MR, mr, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CP_0, cp0, nts::Components::ClockComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CPB_1, cp1, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::Q0, out[0], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q1, out[1], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q2, out[2], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q3, out[3], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q4, out[4], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q5, out[5], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q6, out[6], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q7, out[7], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q8, out[8], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q9, out[9], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::QB_5_9, qb59, nts::Components::OutputComponent::IN);

    cp0.setValue(nts::FALSE);
    cp1.setValue(nts::FALSE);
    mr.setValue(nts::FALSE);
    std::size_t value = 0;
    nts::Tristate lastClk = nts::FALSE;

    for (std::size_t ticks = 0; ticks < 19; ticks++) {
        for (std::size_t i = 0; i < 10; i++) {
            out[i].simulate(ticks);
        }

        nts::Tristate clk = cp0.compute(nts::Components::ClockComponent::OUT);
        if (lastClk == nts::FALSE && clk == nts::TRUE) {
            value++;
        }

        if (value >= 10) {
            value = 0;
        }

        cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), (value == 0) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), (value == 1) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), (value == 2) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), (value == 3) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), (value == 4) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), (value == 5) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), (value == 6) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), (value == 7) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), (value == 8) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), (value == 9) ? nts::TRUE : nts::FALSE);

        if (value >= 5) {
            cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::FALSE);
        } else {
            cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::TRUE);
        }

        lastClk = clk;
    }

    cr_assert_eq(value, 9);
}

Test(P4017Component, overflow) {
    nts::Components::P4017Component p4017Component;
    nts::Components::InputComponent mr;
    nts::Components::ClockComponent cp0;
    nts::Components::InputComponent cp1;
    nts::Components::OutputComponent out[10];
    nts::Components::OutputComponent qb59;

    p4017Component.setLink(nts::Components::P4017Component::MR, mr, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CP_0, cp0, nts::Components::ClockComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CPB_1, cp1, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::Q0, out[0], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q1, out[1], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q2, out[2], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q3, out[3], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q4, out[4], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q5, out[5], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q6, out[6], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q7, out[7], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q8, out[8], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q9, out[9], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::QB_5_9, qb59, nts::Components::OutputComponent::IN);

    cp0.setValue(nts::FALSE);
    cp1.setValue(nts::FALSE);
    mr.setValue(nts::FALSE);
    std::size_t value = 0;
    nts::Tristate lastClk = nts::FALSE;

    for (std::size_t ticks = 0; ticks < 50; ticks++) {
        for (std::size_t i = 0; i < 10; i++) {
            out[i].simulate(ticks);
        }

        nts::Tristate clk = cp0.compute(nts::Components::ClockComponent::OUT);
        if (lastClk == nts::FALSE && clk == nts::TRUE) {
            value++;
        }

        if (value >= 10) {
            value = 0;
        }

        cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), (value == 0) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), (value == 1) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), (value == 2) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), (value == 3) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), (value == 4) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), (value == 5) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), (value == 6) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), (value == 7) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), (value == 8) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), (value == 9) ? nts::TRUE : nts::FALSE);

        if (value >= 5) {
            cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::FALSE);
        } else {
            cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::TRUE);
        }

        lastClk = clk;
    }
}

Test(P4017Component, inverted_flow) {
    nts::Components::P4017Component p4017Component;
    nts::Components::InputComponent mr;
    nts::Components::ClockComponent cp0;
    nts::Components::InputComponent cp1;
    nts::Components::OutputComponent out[10];
    nts::Components::OutputComponent qb59;

    p4017Component.setLink(nts::Components::P4017Component::MR, mr, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CP_0, cp0, nts::Components::ClockComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CPB_1, cp1, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::Q0, out[0], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q1, out[1], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q2, out[2], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q3, out[3], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q4, out[4], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q5, out[5], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q6, out[6], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q7, out[7], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q8, out[8], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q9, out[9], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::QB_5_9, qb59, nts::Components::OutputComponent::IN);

    cp0.setValue(nts::FALSE);
    cp1.setValue(nts::TRUE);
    mr.setValue(nts::FALSE);
    std::size_t value = 0;
    nts::Tristate lastClk = nts::FALSE;

    for (std::size_t ticks = 0; ticks < 19; ticks++) {
        for (std::size_t i = 0; i < 10; i++) {
            out[i].simulate(ticks);
        }

        nts::Tristate clk = cp0.compute(nts::Components::ClockComponent::OUT);
        if (lastClk == nts::TRUE && clk == nts::FALSE) {
            value++;
        }

        if (value >= 10) {
            value = 0;
        }

        cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), (value == 0) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), (value == 1) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), (value == 2) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), (value == 3) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), (value == 4) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), (value == 5) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), (value == 6) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), (value == 7) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), (value == 8) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), (value == 9) ? nts::TRUE : nts::FALSE);

        if (value >= 5) {
            cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::FALSE);
        } else {
            cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::TRUE);
        }

        lastClk = clk;
    }

    cr_assert_eq(value, 9);
}

Test(P4017Component, reset_half_way) {
    nts::Components::P4017Component p4017Component;
    nts::Components::InputComponent mr;
    nts::Components::ClockComponent cp0;
    nts::Components::InputComponent cp1;
    nts::Components::OutputComponent out[10];
    nts::Components::OutputComponent qb59;

    p4017Component.setLink(nts::Components::P4017Component::MR, mr, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CP_0, cp0, nts::Components::ClockComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::CPB_1, cp1, nts::Components::InputComponent::OUT);
    p4017Component.setLink(nts::Components::P4017Component::Q0, out[0], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q1, out[1], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q2, out[2], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q3, out[3], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q4, out[4], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q5, out[5], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q6, out[6], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q7, out[7], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q8, out[8], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::Q9, out[9], nts::Components::OutputComponent::IN);
    p4017Component.setLink(nts::Components::P4017Component::QB_5_9, qb59, nts::Components::OutputComponent::IN);

    cp0.setValue(nts::FALSE);
    cp1.setValue(nts::FALSE);
    mr.setValue(nts::FALSE);
    std::size_t value = 0;
    nts::Tristate lastClk = nts::FALSE;

    for (std::size_t ticks = 0; ticks < 19; ticks++) {
        if (ticks == 10) {
            mr.setValue(nts::TRUE);
        }

        for (std::size_t i = 0; i < 10; i++) {
            out[i].simulate(ticks);
        }

        nts::Tristate clk = cp0.compute(nts::Components::ClockComponent::OUT);
        if (lastClk == nts::FALSE && clk == nts::TRUE) {
            value++;
        }

        if (value >= 10) {
            value = 0;
        }

        if (ticks == 10) {
            value = 0;
            mr.setValue(nts::FALSE);
        }

        cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), (value == 0) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), (value == 1) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), (value == 2) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), (value == 3) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), (value == 4) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), (value == 5) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), (value == 6) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), (value == 7) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), (value == 8) ? nts::TRUE : nts::FALSE);
        cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), (value == 9) ? nts::TRUE : nts::FALSE);

        if (value >= 5) {
            cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::FALSE);
        } else {
            cr_assert_eq(qb59.compute(nts::Components::OutputComponent::IN), nts::TRUE);
        }

        lastClk = clk;
    }

    cr_assert_eq(value, 4);
}