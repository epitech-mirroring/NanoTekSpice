/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** No file there , just an epitech header example.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/ComponentFactory.hpp"
#include "../src/components/InputComponent.hpp"
#include "../src/components/OutputComponent.hpp"
#include "../src/components/TrueComponent.hpp"
#include "../src/components/FalseComponent.hpp"
#include "../src/components/ClockComponent.hpp"
#include "../src/components/AndComponent.hpp"
#include "../src/components/OrComponent.hpp"
#include "../src/components/XorComponent.hpp"
#include "../src/components/NotComponent.hpp"
#include "../src/components/composed/C4081Component.hpp"
#include "../src/components/composed/C4071Component.hpp"
#include "../src/components/composed/C4011Component.hpp"
#include "../src/components/composed/C4001Component.hpp"
#include "../src/components/composed/C4030Component.hpp"
#include "../src/components/composed/C4069Component.hpp"

Test(ComponentFactory, all_factory)
{
    nts::ComponentFactory factory;
    factory.registerComponent("input", new nts::Components::InputComponent());

    cr_assert_eq(factory.isRegistered("input"), true);
    cr_assert_eq(factory.isRegistered("output"), false);
    std::unique_ptr<nts::IComponent> input = factory.createComponent("input");
    input = factory << "input";
    factory.unregisterComponent("input");
    cr_assert_eq(factory.isRegistered("input"), false);
}

Test(ComponentFactory, all_basics)
{
    nts::ComponentFactory factory;
    factory.registerComponent("input", new nts::Components::InputComponent());
    factory.registerComponent("output", new nts::Components::OutputComponent());
    factory.registerComponent("true", new nts::Components::TrueComponent());
    factory.registerComponent("false", new nts::Components::FalseComponent());
    factory.registerComponent("clock", new nts::Components::ClockComponent());

    cr_assert_eq(factory.isRegistered("input"), true);
    cr_assert_eq(factory.isRegistered("output"), true);
    cr_assert_eq(factory.isRegistered("true"), true);
    cr_assert_eq(factory.isRegistered("false"), true);
    cr_assert_eq(factory.isRegistered("clock"), true);

    std::unique_ptr<nts::IComponent> input = factory.createComponent("input");
    std::unique_ptr<nts::IComponent> output = factory.createComponent("output");
    std::unique_ptr<nts::IComponent> trueComp = factory.createComponent("true");
    std::unique_ptr<nts::IComponent> falseComp = factory.createComponent("false");
    std::unique_ptr<nts::IComponent> clock = factory.createComponent("clock");

    cr_assert_eq(input->compute(nts::Components::InputComponent::OUT), nts::UNDEFINED);
    cr_assert_eq(output->compute(nts::Components::OutputComponent::IN), nts::UNDEFINED);
    cr_assert_eq(trueComp->compute(nts::Components::TrueComponent::OUT), nts::TRUE);
    cr_assert_eq(falseComp->compute(nts::Components::FalseComponent::OUT), nts::FALSE);
    cr_assert_eq(clock->compute(nts::Components::ClockComponent::OUT), nts::UNDEFINED);
}

Test(ComponentFactory, all_elementary)
{
    nts::ComponentFactory factory;
    factory.registerComponent("and", new nts::Components::AndComponent());
    factory.registerComponent("or", new nts::Components::OrComponent());
    factory.registerComponent("xor", new nts::Components::XorComponent());
    factory.registerComponent("not", new nts::Components::NotComponent());

    cr_assert_eq(factory.isRegistered("and"), true);
    cr_assert_eq(factory.isRegistered("or"), true);
    cr_assert_eq(factory.isRegistered("xor"), true);
    cr_assert_eq(factory.isRegistered("not"), true);

    std::unique_ptr<nts::IComponent> andC = factory.createComponent("and");
    std::unique_ptr<nts::IComponent> orC = factory.createComponent("or");
    std::unique_ptr<nts::IComponent> xorC = factory.createComponent("xor");
    std::unique_ptr<nts::IComponent> notC = factory.createComponent("not");

    cr_assert_not_null(andC.get());
    cr_assert_not_null(orC.get());
    cr_assert_not_null(xorC.get());
    cr_assert_not_null(notC.get());
}

Test(ComponentFactory, all_gates)
{
    nts::ComponentFactory factory;
    factory.registerComponent("4081", new nts::Components::C4081Component());
    factory.registerComponent("4071", new nts::Components::C4071Component());
    factory.registerComponent("4011", new nts::Components::C4011Component());
    factory.registerComponent("4001", new nts::Components::C4001Component());
    factory.registerComponent("4030", new nts::Components::C4030Component());
    factory.registerComponent("4069", new nts::Components::C4069Component());

    cr_assert_eq(factory.isRegistered("4081"), true);
    cr_assert_eq(factory.isRegistered("4071"), true);
    cr_assert_eq(factory.isRegistered("4011"), true);
    cr_assert_eq(factory.isRegistered("4001"), true);
    cr_assert_eq(factory.isRegistered("4030"), true);
    cr_assert_eq(factory.isRegistered("4069"), true);

    std::unique_ptr<nts::IComponent> c4081 = factory.createComponent("4081");
    std::unique_ptr<nts::IComponent> c4071 = factory.createComponent("4071");
    std::unique_ptr<nts::IComponent> c4011 = factory.createComponent("4011");
    std::unique_ptr<nts::IComponent> c4001 = factory.createComponent("4001");
    std::unique_ptr<nts::IComponent> c4030 = factory.createComponent("4030");
    std::unique_ptr<nts::IComponent> c4069 = factory.createComponent("4069");

    cr_assert_not_null(c4081.get());
    cr_assert_not_null(c4071.get());
    cr_assert_not_null(c4011.get());
    cr_assert_not_null(c4001.get());
    cr_assert_not_null(c4030.get());
    cr_assert_not_null(c4069.get());
}
