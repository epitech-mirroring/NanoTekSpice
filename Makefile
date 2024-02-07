##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## This is the Makefile for the NanoTekSpice project
## It job is to compile, clean and tests the project
##

# All the source files
CXX_SOURCES	=	src/main.cpp				\
				src/Error.cpp

# Compiler and linker settings
NAME 		= nanotekspice
XX			= g++
XXFLAGS		= -W -Wall -Wextra -I./include -std=c++20
LDFLAGS		= -shared
BUILD_DIR	= .output
CXX_OBJS	= $(addprefix $(BUILD_DIR)/, $(CXX_SOURCES:.cpp=.o))
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

$(CXX_OBJS): $(BUILD_DIR)/%.o: %.cpp
# Create the .output folder if it doesn't exist
		@printf "$(RUNNING) $(YELLOW) 📁  Creating $(BUILD_DIR)$(RESET)" \
		&& mkdir -p $(BUILD_DIR) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
# Compile the source file
		@printf "$(RUNNING) $(BLUE) 🔨  $$(basename $<)$(RESET)"
		@$(XX) -o $@ -c $< $(XXFLAGS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

$(NAME):	$(CXX_OBJS)
# Link the object files
		@printf "$(RUNNING) $(BLUE) 🔗  Linking$(RESET)"
		@$(XX) -o $(NAME) $(CXX_OBJS) $(XXFLAGS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
# Check if the binary was created
		@if [ -f $(NAME) ]; then \
			printf "$(SUCCESS)$(GREEN)  🎉  $(NAME) built successfully$(RESET)\n";\
		else \
			printf "$(FAILURE)$(RED)  🚨  $(NAME) build failed$(RESET)\n"; \
			cat $(LOG); \
		fi

all:		$(NAME)

clean:
# Clean the build folder but keep the folder
		@printf "$(RUNNING) $(RED) 🗑️   Cleaning $(BUILD_DIR) folder$(RESET)"
		@rm -f $(CXX_OBJS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

fclean: clean
# Delete the build folder
		@printf "$(RUNNING) $(RED) 🗑️   Deleting $(BUILD_DIR) folder$(RESET)"
		@rm -rf $(BUILD_DIR) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
# Delete the binary
		@printf "$(RUNNING) $(RED) 🗑️   Deleting $(NAME)$(RESET)"
		@rm -f $(NAME) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
# Delete the log file
		@printf "$(RUNNING) $(RED) 🗑️   Deleting $(LOG)$(RESET)"
		@rm -f $(LOG) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

re:			fclean all
