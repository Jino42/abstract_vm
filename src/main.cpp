#include "FactoryOperand.hpp"
#include "FactoryInstruction.hpp"
#include <iostream>
#include "MutantStack.tpp"
#include "AvmCore.hpp"

int		main(int argc, char **argv)
{
	{
		if (argc == 2)
		{
			AvmCore core(argv[1],  new Ncurses(Vector2D<int>(0, 0), Vector2D<int>(50, 50)));
			core.printInstruction();
			core.execute();
			core.printStack();
		}
		else
		{
			AvmCore core(nullptr);
			core.printInstruction();
			core.execute();
			core.printStack();
		}
	}
	return (0);
}
