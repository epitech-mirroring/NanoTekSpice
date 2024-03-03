/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/primitive/P4512Component.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <criterion/criterion.h>

Test(P4512Component, starting_state) {
    nts::Components::P4512Component c4512component;
    nts::Components::InputComponent inhibit;
    nts::Components::InputComponent oe;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent x[8];
    nts::Components::OutputComponent z;

    c4512component.setLink(nts::Components::P4512Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::OE, oe, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::A, a, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::B, b, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::C, c, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X0, x[0], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X1, x[1], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X2, x[2], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X3, x[3], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X4, x[4], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X5, x[5], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X6, x[6], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X7, x[7], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::Z, z, nts::Components::OutputComponent::IN);

    z.simulate(0);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
}

Test(P4512Component, all_normal_outputs) {
    nts::Components::P4512Component c4512component;
    nts::Components::InputComponent inhibit;
    nts::Components::InputComponent oe;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent x[8];
    nts::Components::OutputComponent z;

    c4512component.setLink(nts::Components::P4512Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::OE, oe, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::A, a, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::B, b, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::C, c, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X0, x[0], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X1, x[1], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X2, x[2], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X3, x[3], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X4, x[4], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X5, x[5], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X6, x[6], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X7, x[7], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::Z, z, nts::Components::OutputComponent::IN);

    inhibit.setValue(nts::FALSE);
    oe.setValue(nts::FALSE);
    a.setValue(nts::FALSE);
    b.setValue(nts::FALSE);
    c.setValue(nts::FALSE);
    for (int i = 0; i < 8; i++)
        x[i].setValue(nts::FALSE);

    x[0].setValue(nts::TRUE);
    z.simulate(0);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    x[0].setValue(nts::FALSE);
    z.simulate(1);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    a.setValue(nts::TRUE);
    x[1].setValue(nts::TRUE);
    z.simulate(2);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    x[1].setValue(nts::FALSE);
    z.simulate(3);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    a.setValue(nts::FALSE);
    b.setValue(nts::TRUE);
    x[2].setValue(nts::TRUE);
    z.simulate(4);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    x[2].setValue(nts::FALSE);
    z.simulate(5);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    a.setValue(nts::TRUE);
    x[3].setValue(nts::TRUE);
    z.simulate(6);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    x[3].setValue(nts::FALSE);
    z.simulate(7);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    a.setValue(nts::FALSE);
    b.setValue(nts::FALSE);
    c.setValue(nts::TRUE);
    x[4].setValue(nts::TRUE);
    z.simulate(8);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    x[4].setValue(nts::FALSE);
    z.simulate(9);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    a.setValue(nts::TRUE);
    x[5].setValue(nts::TRUE);
    z.simulate(10);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    x[5].setValue(nts::FALSE);
    z.simulate(11);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    a.setValue(nts::FALSE);
    b.setValue(nts::TRUE);
    x[6].setValue(nts::TRUE);
    z.simulate(12);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    x[6].setValue(nts::FALSE);
    z.simulate(13);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);

    a.setValue(nts::TRUE);
    x[7].setValue(nts::TRUE);
    z.simulate(14);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::TRUE);
    x[7].setValue(nts::FALSE);
    z.simulate(15);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);
}

Test(P4512Component, inhibit) {
    nts::Components::P4512Component c4512component;
    nts::Components::InputComponent inhibit;
    nts::Components::InputComponent oe;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent x[8];
    nts::Components::OutputComponent z;

    c4512component.setLink(nts::Components::P4512Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::OE, oe, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::A, a, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::B, b, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::C, c, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X0, x[0], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X1, x[1], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X2, x[2], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X3, x[3], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X4, x[4], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X5, x[5], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X6, x[6], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X7, x[7], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::Z, z, nts::Components::OutputComponent::IN);

    oe.setValue(nts::FALSE);
    inhibit.setValue(nts::TRUE);
    a.setValue(nts::TRUE);
    b.setValue(nts::TRUE);
    c.setValue(nts::TRUE);
    z.simulate(0);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::FALSE);
}

Test(P4512Component, output_disabled) {
    nts::Components::P4512Component c4512component;
    nts::Components::InputComponent inhibit;
    nts::Components::InputComponent oe;
    nts::Components::InputComponent a;
    nts::Components::InputComponent b;
    nts::Components::InputComponent c;
    nts::Components::InputComponent x[8];
    nts::Components::OutputComponent z;

    c4512component.setLink(nts::Components::P4512Component::INHIBIT, inhibit, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::OE, oe, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::A, a, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::B, b, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::C, c, nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X0, x[0], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X1, x[1], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X2, x[2], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X3, x[3], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X4, x[4], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X5, x[5], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X6, x[6], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::X7, x[7], nts::Components::InputComponent::OUT);
    c4512component.setLink(nts::Components::P4512Component::Z, z, nts::Components::OutputComponent::IN);

    oe.setValue(nts::TRUE);
    inhibit.setValue(nts::FALSE);
    a.setValue(nts::TRUE);
    b.setValue(nts::TRUE);
    c.setValue(nts::TRUE);
    z.simulate(0);

    cr_assert_eq(z.compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
}
