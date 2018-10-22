.PHONY: all clean fclean re

#==========EXECUTABLES==========#

EXE= avm

#=======COMPILER AND FLAGS======#

CXX= clang++
CXXFLAGS= -Wall -Wextra -Werror -Wvla -std=c++11 -fsanitize=address -g3 -MMD

#============HEADERS============#

HEADER_DIR= include/
HEADER_ALL_DIR= include/ include/instruction

HEADER = $(addprefix $(HEADER_DIR), $(HEADER_FILE))

HEADER_FILE = IOperand.hpp \
Operand.tpp \
FactoryOperand.hpp \
AvmCore.hpp \
IInstruction.hpp \
FactoryInstruction.hpp \
AvmParser.hpp \
instruction/InstructionAdd.hpp \
instruction/InstructionDiv.hpp \
instruction/InstructionDump.hpp \
instruction/InstructionExit.hpp \
instruction/InstructionMod.hpp \
instruction/InstructionMul.hpp \
instruction/InstructionPop.hpp \
instruction/InstructionPrint.hpp \
instruction/InstructionPush.hpp \
instruction/InstructionSub.hpp \
instruction/InstructionAssert.hpp \

#============COLORS=============#

RED=\033[1;31m
GREEN=\033[1;32m
EOC=\033[0m

#==============SRC=============#

SRC_DIR = ./src/

SRC_FILE= main.cpp \
FactoryOperand.cpp \
AvmCore.cpp \
AvmParser.cpp \
FactoryInstruction.cpp \
instruction/InstructionAdd.cpp \
instruction/InstructionDiv.cpp \
instruction/InstructionDump.cpp \
instruction/InstructionExit.cpp \
instruction/InstructionMod.cpp \
instruction/InstructionMul.cpp \
instruction/InstructionPop.cpp \
instruction/InstructionPrint.cpp \
instruction/InstructionPush.cpp \
instruction/InstructionSub.cpp \
instruction/InstructionAssert.cpp

SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))


OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))
OBJ_FILE= $(SRC_FILE:.cpp=.o)

DEPENDS= $(OBJ:.o=.d)

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

$(OBJ_DIR)%.o: $(addprefix $(SRC_DIR), %.cpp) Makefile
	@$(CXX) $(CXXFLAGS) -c $< -o $@ $(addprefix -I, $(HEADER_ALL_DIR))
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

-include $(DEPENDS)
