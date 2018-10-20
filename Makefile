.PHONY: all clean fclean re

#==========EXECUTABLES==========#

EXE= avm

#=======COMPILER AND FLAGS======#

CXX= clang++
CXXFLAGS= -Wall -Wextra -Werror -Wvla -std=c++11

#============HEADERS============#

HEADER= include/

HEADERIN = $(addprefix $(HEADER), $(HEADER_NAME))

HEADER_NAME = IOperand.hpp Operand.tpp FactoryOperand.hpp AvmCore.hpp AvmPars.hpp IInstruction.hpp

#============COLORS=============#

RED=\033[1;31m
GREEN=\033[1;32m
EOC=\033[0m

#==============SRC=============#

SRC_DIR = ./src/

SRC_FILE= main.cpp \
FactoryOperand.cpp \
instruction/osef.cpp

SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))


OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))
OBJ_FILE= ${SRC_FILE:.cpp=.o}

#=============RULES=============#

all: $(EXE)


$(EXE): $(OBJ_DIR) $(OBJ)
	@echo "\t$(EXE)'s objects compiled"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXE)
	@echo "executable $(GREEN)$(EXE)$(EOC) created"
	@echo "$(GREEN)---------->>>$(EOC)"

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/instruction

$(OBJ_DIR)%.o: $(addprefix $(SRC_DIR), %.cpp) Makefile $(HEADERIN)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(HEADER)
	@printf "$(GREEN)+$(EOC)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[x]$(EOC) $(EXE)'s objects cleaned"

fclean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[x]$(EOC) $(EXE)'s objects cleaned"
	@rm -f $(EXE)
	@echo "executable $(RED)$(EXE)$(EOC) removed"
	@echo "$(RED)<<<----------$(EOC)"

re: fclean all
