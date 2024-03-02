/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/composed/C4030Component.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <criterion/criterion.h>

static nts::Tristate xorTruthTable(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::FALSE && b == nts::FALSE)
        return nts::FALSE;
    if (a == nts::FALSE && b == nts::TRUE)
        return nts::TRUE;
    if (a == nts::FALSE && b == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (a == nts::TRUE && b == nts::FALSE)
        return nts::TRUE;
    if (a == nts::TRUE && b == nts::TRUE)
        return nts::FALSE;
    if (a == nts::TRUE && b == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (a == nts::UNDEFINED && b == nts::FALSE)
        return nts::UNDEFINED;
    if (a == nts::UNDEFINED && b == nts::TRUE)
        return nts::UNDEFINED;
    if (a == nts::UNDEFINED && b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::UNDEFINED;
}

static void test(nts::Tristate a[4], nts::Tristate b[4])
{
    nts::Components::C4030Component c4081component;
    nts::Components::InputComponent inputs[8];
    nts::Components::OutputComponent outputs[4];
    c4081component.setLink(nts::Components::C4030Component::A1, inputs[0], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4030Component::B1, inputs[4], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4030Component::A2, inputs[1], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4030Component::B2, inputs[5], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4030Component::A3, inputs[2], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4030Component::B3, inputs[6], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4030Component::A4, inputs[3], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4030Component::B4, inputs[7], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4030Component::Y1, outputs[0], nts::Components::OutputComponent::IN);
    c4081component.setLink(nts::Components::C4030Component::Y2, outputs[1], nts::Components::OutputComponent::IN);
    c4081component.setLink(nts::Components::C4030Component::Y3, outputs[2], nts::Components::OutputComponent::IN);
    c4081component.setLink(nts::Components::C4030Component::Y4, outputs[3], nts::Components::OutputComponent::IN);

    for (int i = 0; i < 4; i++) {
        inputs[i].setValue(a[i]);
        inputs[i + 4].setValue(b[i]);
    }

    for (int i = 0; i < 4; i++) {
        outputs[i].simulate(0);
        nts::Tristate expected = xorTruthTable(a[i], b[i]);
        nts::Tristate actual = outputs[i].compute(nts::Components::OutputComponent::IN);
        cr_assert_eq(expected, actual, "Expected %d, got %d", expected, actual);
    }
}

static nts::Tristate intToTristate(int i)
{
    if (i == 0)
        return nts::FALSE;
    if (i == 1)
        return nts::TRUE;
    return nts::UNDEFINED;
}

Test(C4030Component, test_all_combinations) {
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    for (int e = 0; e < 4; e++) {
                        for (int f = 0; f < 4; f++) {
                            for (int g = 0; g < 4; g++) {
                                for (int h = 0; h < 4; h++) {
                                    nts::Tristate aTristate[4] = {intToTristate(a), intToTristate(b), intToTristate(c), intToTristate(d)};
                                    nts::Tristate bTristate[4] = {intToTristate(e), intToTristate(f), intToTristate(g), intToTristate(h)};
                                    test(aTristate, bTristate);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
