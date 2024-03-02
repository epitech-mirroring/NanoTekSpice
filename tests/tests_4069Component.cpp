/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../src/components/composed/C4069Component.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include <criterion/criterion.h>

static nts::Tristate notTruthTable(nts::Tristate a)
{
    return !a;
}

static void test(nts::Tristate a[4])
{
    nts::Components::C4069Component c4081component;
    nts::Components::InputComponent inputs[6];
    nts::Components::OutputComponent outputs[6];
    c4081component.setLink(nts::Components::C4069Component::IN_1, inputs[0], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4069Component::IN_2, inputs[1], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4069Component::IN_3, inputs[2], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4069Component::IN_4, inputs[3], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4069Component::IN_5, inputs[4], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4069Component::IN_6, inputs[5], nts::Components::InputComponent::OUT);
    c4081component.setLink(nts::Components::C4069Component::OUT_1, outputs[0], nts::Components::OutputComponent::IN);
    c4081component.setLink(nts::Components::C4069Component::OUT_2, outputs[1], nts::Components::OutputComponent::IN);
    c4081component.setLink(nts::Components::C4069Component::OUT_3, outputs[2], nts::Components::OutputComponent::IN);
    c4081component.setLink(nts::Components::C4069Component::OUT_4, outputs[3], nts::Components::OutputComponent::IN);
    c4081component.setLink(nts::Components::C4069Component::OUT_5, outputs[4], nts::Components::OutputComponent::IN);
    c4081component.setLink(nts::Components::C4069Component::OUT_6, outputs[5], nts::Components::OutputComponent::IN);

    for (int i = 0; i < 6; i++) {
        inputs[i].setValue(a[i]);
    }

    for (int i = 0; i < 6; i++) {
        outputs[i].simulate(0);
        nts::Tristate expected = notTruthTable(a[i]);
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

Test(C4069Component, test_all_combinations) {
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    for (int e = 0; e < 4; e++) {
                        for (int f = 0; f < 4; f++) {
                            nts::Tristate inputs[6] = {intToTristate(a), intToTristate(b), intToTristate(c), intToTristate(d), intToTristate(e), intToTristate(f)};
                            test(inputs);
                        }
                    }
                }
            }
        }
    }
}
