##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## This is the Makefile for the NanoTekSpice project
## It job is to compile, clean and tests the project
##

# All the source files
CXX_SOURCES	= src/main.cpp								\
			  src/IComponent.cpp						\
			  src/ComponentFactory.cpp					\
			  src/components/AbstractComponent.cpp		\
			  src/components/ComposedComponent.cpp		\
			  src/components/InputComponent.cpp			\
			  src/components/OrComponent.cpp			\
			  src/components/composed/C4071Component.cpp\
			  src/components/ClockComponent.cpp			\
			  src/components/TrueComponent.cpp			\
			  src/components/FalseComponent.cpp			\
			  src/components/NotComponent.cpp			\
			  src/components/AndComponent.cpp			\
			  src/components/XorComponent.cpp			\
			  src/FileContainer.cpp						\
			  src/Error.cpp								\
			  src/components/composed/C4001Component.cpp\
			  src/components/composed/CNorComponent.cpp	\
			  src/components/composed/CNandComponent.cpp\
			  src/components/composed/C4011Component.cpp\
			  src/components/composed/C4030Component.cpp\
			  src/components/composed/C4069Component.cpp\
			  src/Simulation.cpp						\
			  src/components/OutputComponent.cpp		\
			  src/components/composed/C4081Component.cpp\
			  src/components/composed/C7482Component.cpp\
			  src/components/composed/C4008Component.cpp\
			  src/components/primitive/P4013Component.cpp\
			  src/components/primitive/P4040Component.cpp\
			  src/components/primitive/P4514Component.cpp\
			  src/components/primitive/P4017Component.cpp\
			  src/components/primitive/P4512Component.cpp\
			  src/components/primitive/P4094Component.cpp\

CXX_TESTS	=	tests/tests_Error.cpp						\
				tests/tests_IComponent.cpp					\
				tests/tests_ComponentFactory.cpp			\
				tests/tests_FileContainer.cpp				\
				tests/tests_Simulation.cpp					\
				tests/tests_TrueComponent.cpp				\
				tests/tests_FalseComponent.cpp				\
				tests/tests_AndComponent.cpp				\
				tests/tests_NotComponent.cpp				\
				tests/tests_OrComponent.cpp					\
				tests/tests_XorComponent.cpp				\
				tests/tests_InputComponent.cpp				\
				tests/tests_OutputComponent.cpp				\
				tests/tests_ClockComponent.cpp				\
				tests/tests_NorComponent.cpp				\
				tests/tests_NandComponent.cpp				\
				tests/tests_4008Component.cpp				\
				tests/tests_7482Component.cpp				\
				tests/tests_4081Component.cpp				\
				tests/tests_4071Component.cpp				\
				tests/tests_4011Component.cpp				\
				tests/tests_4030Component.cpp				\
				tests/tests_4069Component.cpp				\
				tests/tests_4001Component.cpp				\
				tests/tests_4013Component.cpp				\
				tests/tests_4040Component.cpp				\
				tests/tests_4514Component.cpp				\
				tests/tests_4017Component.cpp				\
				tests/tests_4512Component.cpp				\

# Compiler and linker settings
NAME 			= nanotekspice
XX				= g++
XXFLAGS			= -W -Wall -Wextra -std=c++20 --coverage
CXX_OBJS		= $(CXX_SOURCES:.cpp=.o)
CXX_TESTS_OBJS	= $(CXX_TESTS:.cpp=.o)
LOG				= ./build.log

.PHONY: $(NAME) all clean fclean re tests_run clean_test

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

fclean: clean clean_test
# Delete the binary
		@printf "$(RUNNING) $(RED) 🗑️   Deleting $(NAME)$(RESET)"
		@rm -f $(NAME) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
# Delete the log file
		@printf "$(RUNNING) $(RED) 🗑️   Deleting $(LOG)$(RESET)"
		@rm -f $(LOG) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

re:			fclean all

$(CXX_TESTS_OBJS):	%.o: %.cpp
		@printf "$(RUNNING) $(BLUE) 🔨  $$(basename $<)$(RESET)"
		@$(XX) -o $@ -c $< $(XXFLAGS) >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"

tests_run: fclean $(CXX_OBJS) $(CXX_TESTS_OBJS)
	@printf "$(RUNNING) $(BLUE) 🔗  Linking$(RESET)"
	@$(XX) -o tests.out $(filter-out src/main.o, $(CXX_OBJS)) \
	$(CXX_TESTS_OBJS) $(XXFLAGS) -lcriterion --coverage >> $(LOG) 2>&1 \
	-lcriterion >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n";
	@printf "$(RUNNING)$(BLUE)  🧪  Running tests$(RESET)" \
	&& ./tests.out --xml=criterion.xml --ignore-warnings >> tests.log 2>&1 \
	&& printf "\r$(SUCCESS)\n" \
	|| printf "\r$(FAILURE)\n";
	@cat tests.log;
	@printf "$(RUNNING)$(YELLOW)  📥 Prepare functional tests$(RESET)" \
	&& pip3 install -r requirements.txt --user >> build.log 2>&1 \
	&& printf "\r$(SUCCESS)\n" \
	|| (printf "\r$(FAILURE)\n" && tail -n 10 build.log);
	@printf "$(RUNNING)$(YELLOW)  🧪 Running functionnal tests$(RESET)"
	@$(XX) -o $(NAME) $(CXX_OBJS) $(XXFLAGS) >> $(LOG) 2>&1 \
	&&python3 ./tester.py >> functests.log 2>&1 \
	&& printf "\r$(SUCCESS)\n" \
	|| printf "\r$(FAILURE)\n";
	@rm -f nanotekspice;
	@cat functests.log;
	@printf "$(RUNNING)$(YELLOW)  📊  Generating coverage$(RESET)" \
	&& gcovr --exclude tests/ >> coverage.log 2>&1 \
	&& printf "\r$(SUCCESS)\n" \
	|| printf "\r$(FAILURE)\n";
	@cat coverage.log;

clean_test:
	@printf "$(RUNNING) $(RED) 🗑️   Deleting tests.out$(RESET)"
	@rm -f tests.out >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting coverage$(RESET)"
	@rm -f coverage* >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting tests/*.o$(RESET)"
	@rm -f $(CXX_TESTS_OBJS) >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting *.gcda$(RESET)"
	@find ./ -name "*.gcda" -delete >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting *.gcno$(RESET)"
	@find ./ -name "*.gcno" -delete >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting criterion.xml$(RESET)"
	@rm -f criterion.xml >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting cobertura.xml$(RESET)"
	@rm -f cobertura.xml >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting functests.xml$(RESET)"
	@rm -f functests.xml >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting tests.log$(RESET)"
	@rm -f tests.log >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting coverage.log$(RESET)"
	@rm -f coverage.log >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@printf "$(RUNNING) $(RED) 🗑️   Deleting functests.log$(RESET)"
	@rm -f functests.log >> $(LOG) 2>&1 \
	&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"
	@if [ -d .cache/ ]; then \
		printf "$(RUNNING) $(RED) 🗑️   Deleting .cache/$(RESET)"; \
		rm -rf .cache >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	fi
	@if [ -d .local/ ]; then \
		printf "$(RUNNING) $(RED) 🗑️   Deleting .local/$(RESET)"; \
		rm -rf .local >> $(LOG) 2>&1 \
		&& printf "\r$(SUCCESS)\n" || printf "\r$(FAILURE)\n"; \
	fi
