##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## This is the Makefile for the NanoTekSpice project
## It job is to compile, clean and tests the project
##

# All the source files
CXX_SOURCES	= src/main.cpp							\
			  src/ComponentFactory.cpp				\
			  src/Components/AbstractComponent.cpp	\

# Compiler and linker settings
NAME 		= nanotekspice
XX			= g++
XXFLAGS		= -W -Wall -Wextra -std=c++20
CXX_OBJS	= $(CXX_SOURCES:.cpp=.o)
LOG			= ./build.log

.PHONY: $(NAME) all clean fclean re

# Colors and formatting
GREEN =		\033[1;32m
YELLOW =	\033[1;33m
RED =		\033[1;31m
BLUE =		\033[1;36m
GOLD =		\033[1;33m
RESET =		\033[0m

RUNNING = [$(YELLOW)~$(RESET)]
SUCCESS = [$(GREEN)✔$(RESET)]
FAILURE = [$(RED)✘$(RESET)]

all:		$(NAME)

$(NAME):	$(CXX_OBJS)
# Link the object files
		@printf "$(RUNNING) $(BLUE) 🔗  Linking$(RESET)"
		@$(XX) -o $(NAME) $(CXX_OBJS) $(XXFLAGS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
# Check if the binary was created
		@if [ -f $(NAME) ]; then \
			printf \
			"$(SUCCESS)$(GREEN)  🎉  $(NAME) built successfully$(RESET)\n";\
		else \
			printf "$(FAILURE)$(RED)  🚨  $(NAME) build failed$(RESET)\n"; \
			cat $(LOG); \
		fi

$(CXX_OBJS):	%.o: %.cpp
# Compile the source file
		@printf "$(RUNNING) $(BLUE) 🔨  $$(basename $<)$(RESET)"
		@$(XX) -o $@ -c $< $(XXFLAGS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

clean:
# Delete all the object files
		@for file in $(CXX_OBJS); do \
			printf "$(RUNNING) $(RED) 🗑️   Deleting $$file$(RESET)"; \
			rm -f $$file >> $(LOG) 2>&1 \
			&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
		done

fclean: clean
# Delete the binary
		@printf "$(RUNNING) $(RED) 🗑️   Deleting $(NAME)$(RESET)"
		@rm -f $(NAME) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
# Delete the log file
		@printf "$(RUNNING) $(RED) 🗑️   Deleting $(LOG)$(RESET)"
		@rm -f $(LOG) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

re:			fclean all
