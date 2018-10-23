#include "FactoryOperand.hpp"
#include "FactoryInstruction.hpp"
#include <iostream>
#include "MutantStack.tpp"
#include "AvmCore.hpp"

int		main(int argc, char **argv)
{
	try
	{
		if (argc == 2)
		{
			AvmCore core(argv[1],
				//nullptr
				new Ncurses()
			);
			//core.printInstruction();
			core.execute();
			//core.printStack();
		}
		else
		{
			AvmCore core(nullptr);
			//core.printInstruction();
			core.execute();
			//core.printStack();
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
