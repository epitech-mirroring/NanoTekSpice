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

            void setlinks(void);

            void buildMap(ComponentFactory &factory);
        protected:
        private:
            std::string _filename;
            std::vector<std::string> _chipsets;
            std::vector<std::string> _links;
            std::unordered_map<std::string, IComponent *> _pins;

            std::string removeComments(std::string &content) const;
            void extractChipsetsAndLinks(const std::string &content);
            void fillChipsets(std::smatch &match);
            void fillLinks(std::smatch &match);
    };
};