.PHONY: all clean fclean re

#==========EXECUTABLES==========#

EXE= avm

#=======COMPILER AND FLAGS======#

CXX= clang++
CXXFLAGS= -Wall -Wextra -Werror -Wvla -std=c++11

#============HEADERS============#

HEADER= include/

HEADERIN = $(addprefix $(HEADER), $(HEADER_NAME))

HEADER_NAME = IOperand.hpp Operand.tpp FactoryOperand.hpp

#============COLORS=============#

RED=\033[1;31m
GREEN=\033[1;32m
EOC=\033[0m

#==============SRC=============#

SRCIN = $(addprefix ./src/, $(SRC))

SRC= main.cpp \
FactoryOperand.cpp

OBJ= ${SRCIN:.cpp=.o}

#=============RULES=============#

all: $(EXE)

%.o: %.cpp Makefile $(HEADERIN)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(HEADER)
	@printf "$(GREEN)+$(EOC)"

$(EXE): $(OBJ)
	@echo "\t$(EXE)'s objects compiled"
	@$(CXX) $(CXXFLAGS) $^ -o $(EXE)
	@echo "executable $(GREEN)$(EXE)$(EOC) created"
	@echo "$(GREEN)---------->>>$(EOC)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)[x]$(EOC) $(EXE)'s objects cleaned"

fclean:
	@rm -f $(OBJ)
	@echo "$(RED)[x]$(EOC) $(EXE)'s objects cleaned"
	@rm -f $(EXE)
	@echo "executable $(RED)$(EXE)$(EOC) removed"
	@echo "$(RED)<<<----------$(EOC)"

re: fclean all
