/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FileContainer
*/

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <regex>
#include "IComponent.hpp"
#include "ComponentFactory.hpp"

namespace nts
{
    class FileContainer {
        public:
            FileContainer(const std::string &filename);
            ~FileContainer() = default;
            void extractFileContent();

            std::vector<std::string> getChipsets(void) const;
            std::vector<std::string> getLinks(void) const;
            std::unordered_map<std::string, IComponent *> getMap(void) const;

            void buildMap(ComponentFactory &factory);
            void setlinks(void);
        protected:
        private:
            std::string _filename;
            std::vector<std::string> _chipsets;
            std::vector<std::string> _links;
            std::unordered_map<std::string, IComponent *> _pins;

            std::string removeComments(std::string &content) const;
            void extractChipsetsAndLinks(const std::string &content);
            void fillChipsets(std::string &str);
            void fillLinks(std::string &str);
            bool isComponentType(const std::string &str);
            bool isPinExist(const std::string &str);
    };

    static std::vector<std::string> componentType = {
        "input", "or", "4071"};
        // "input", "output", "clock", "true", "false", "and", "or", "xor", "not", "4001", "4008", "4011", "4013", "4017", "4030", "4040", "4069", "4071", "4081", "4094", "4514", "4801", "end"};
};
