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
#include "IComponent.hpp"
#include "ComponentFactory.hpp"

namespace nts
{
    class FileContainer {
        public:
            FileContainer();
            ~FileContainer() = default;
            void extractFileContent(const std::string &filename);
            std::string removeComments(std::string &content);
            void extractChipsetsAndLinks(const std::string &content);

            std::string getChipsets(void) const;
            std::string getLinks(void) const;

            void buildMap(ComponentFactory &factory);
        protected:
        private:
            std::string _chipsets;
            std::string _links;
            std::unordered_map<std::string, IComponent *> _pins;
    };
};
