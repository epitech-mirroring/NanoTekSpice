/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/primitive/P4514Component.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <criterion/criterion.h>

Test(P4514Component, starting_state) {
    nts::Components::P4514Component p4514component;
    nts::Components::InputComponent store;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent d;
    nts::Components::InputComponent inhibit;
    nts::Components::OutputComponent out[16];

    p4514component.setLink(nts::Components::P4514Component::STORE, store, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_A, a, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_B, b, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_C, c, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_D, d, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::S0, out[0], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S1, out[1], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S2, out[2], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S3, out[3], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S4, out[4], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S5, out[5], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S6, out[6], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S7, out[7], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S8, out[8], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S9, out[9], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S10, out[10], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S11, out[11], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S12, out[12], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S13, out[13], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S14, out[14], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S15, out[15], nts::Components::OutputComponent::IN);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(0);
    }

    for (std::size_t i = 0; i < 16; i++) {
        cr_assert_eq(out[i].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    }
}

Test(P4514Component, basic_test) {
    nts::Components::P4514Component p4514component;
    nts::Components::InputComponent store;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent d;
    nts::Components::InputComponent inhibit;
    nts::Components::OutputComponent out[16];

    p4514component.setLink(nts::Components::P4514Component::STORE, store, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_A, a, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_B, b, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_C, c, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_D, d, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::S0, out[0], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S1, out[1], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S2, out[2], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S3, out[3], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S4, out[4], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S5, out[5], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S6, out[6], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S7, out[7], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S8, out[8], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S9, out[9], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S10, out[10], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S11, out[11], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S12, out[12], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S13, out[13], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S14, out[14], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S15, out[15], nts::Components::OutputComponent::IN);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(0);
    }

    store.setValue(nts::TRUE);
    a.setValue(nts::TRUE);
    b.setValue(nts::FALSE);
    c.setValue(nts::FALSE);
    d.setValue(nts::FALSE);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(1);
    }

    cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[10].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[11].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[12].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[13].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[14].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[15].compute(nts::Components::OutputComponent::IN), nts::FALSE);
}

Test(P4514Component, changing_in_state_without_store) {
    nts::Components::P4514Component p4514component;
    nts::Components::InputComponent store;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent d;
    nts::Components::InputComponent inhibit;
    nts::Components::OutputComponent out[16];

    p4514component.setLink(nts::Components::P4514Component::STORE, store, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_A, a, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_B, b, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_C, c, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_D, d, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::S0, out[0], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S1, out[1], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S2, out[2], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S3, out[3], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S4, out[4], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S5, out[5], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S6, out[6], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S7, out[7], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S8, out[8], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S9, out[9], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S10, out[10], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S11, out[11], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S12, out[12], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S13, out[13], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S14, out[14], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S15, out[15], nts::Components::OutputComponent::IN);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(0);
    }

    for (std::size_t i = 0; i < 16; i++) {
        cr_assert_eq(out[i].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    }

    store.setValue(nts::TRUE);
    a.setValue(nts::TRUE);
    b.setValue(nts::FALSE);
    c.setValue(nts::FALSE);
    d.setValue(nts::FALSE);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(1);
    }

    cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[10].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[11].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[12].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[13].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[14].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[15].compute(nts::Components::OutputComponent::IN), nts::FALSE);

    store.setValue(nts::FALSE);
    b.setValue(nts::TRUE);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(2);
    }

    cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[10].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[11].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[12].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[13].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[14].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[15].compute(nts::Components::OutputComponent::IN), nts::FALSE);
}

Test(P4514Component, inhibit_basic) {
    nts::Components::P4514Component p4514component;
    nts::Components::InputComponent store;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent d;
    nts::Components::InputComponent inhibit;
    nts::Components::OutputComponent out[16];

    p4514component.setLink(nts::Components::P4514Component::STORE, store, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_A, a, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_B, b, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_C, c, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_D, d, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::S0, out[0], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S1, out[1], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S2, out[2], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S3, out[3], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S4, out[4], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S5, out[5], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S6, out[6], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S7, out[7], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S8, out[8], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S9, out[9], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S10, out[10], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S11, out[11], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S12, out[12], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S13, out[13], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S14, out[14], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S15, out[15], nts::Components::OutputComponent::IN);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(0);
    }

    store.setValue(nts::TRUE);
    a.setValue(nts::TRUE);
    b.setValue(nts::FALSE);
    c.setValue(nts::FALSE);
    d.setValue(nts::FALSE);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(1);
    }

    cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), nts::TRUE);
    cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[10].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[11].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[12].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[13].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[14].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[15].compute(nts::Components::OutputComponent::IN), nts::FALSE);

    store.setValue(nts::FALSE);
    inhibit.setValue(nts::TRUE);
    a.setValue(nts::FALSE);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(2);
    }

    cr_assert_eq(out[0].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[1].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[2].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[3].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[4].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[5].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[6].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[7].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[8].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[9].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[10].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[11].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[12].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[13].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[14].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    cr_assert_eq(out[15].compute(nts::Components::OutputComponent::IN), nts::FALSE);
}

Test(P4514Component, inhibit_at_starting_state) {
    nts::Components::P4514Component p4514component;
    nts::Components::InputComponent store;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent d;
    nts::Components::InputComponent inhibit;
    nts::Components::OutputComponent out[16];

    p4514component.setLink(nts::Components::P4514Component::STORE, store, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_A, a, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_B, b, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_C, c, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::IN_D, d, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    p4514component.setLink(nts::Components::P4514Component::S0, out[0], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S1, out[1], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S2, out[2], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S3, out[3], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S4, out[4], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S5, out[5], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S6, out[6], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S7, out[7], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S8, out[8], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S9, out[9], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S10, out[10], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S11, out[11], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S12, out[12], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S13, out[13], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S14, out[14], nts::Components::OutputComponent::IN);
    p4514component.setLink(nts::Components::P4514Component::S15, out[15], nts::Components::OutputComponent::IN);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(0);
    }

    for (std::size_t i = 0; i < 16; i++) {
        cr_assert_eq(out[i].compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    }

    inhibit.setValue(nts::TRUE);

    for (std::size_t i = 0; i < 16; i++) {
        out[i].simulate(1);
    }

    for (std::size_t i = 0; i < 16; i++) {
        cr_assert_eq(out[i].compute(nts::Components::OutputComponent::IN), nts::FALSE);
    }
}