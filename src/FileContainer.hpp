/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FileContainer
*/

#pragma once

#include <vector>
#include <string>
#include <map>
#include <regex>
#include <memory>
#include "IComponent.hpp"
#include "ComponentFactory.hpp"

namespace nts
{
    class FileContainer {
        public:
            FileContainer(const std::string &filename);
            ~FileContainer();
            void extractFileContent();

            std::vector<std::string> getChipsets() const;
            std::vector<std::string> getLinks() const;
            std::map<std::string, nts::IComponent *> getMap() const;

            void buildMap(ComponentFactory &factory);
            void setlinks();
        protected:
        private:
            std::string _filename;
            std::vector<std::string> _chipsets;
            std::vector<std::string> _links;
            std::map<std::string, nts::IComponent *> _pins;

            static std::string removeComments(std::string &content) ;
            void extractChipsetsAndLinks(const std::string &content);
            void fillChipsets(std::string &str);
            void fillLinks(std::string &str);
    };
};
