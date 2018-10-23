#include "FactoryOperand.hpp"
#include "FactoryInstruction.hpp"
#include <iostream>
#include "MutantStack.tpp"
#include "AvmCore.hpp"

int		main(int argc, char **argv)
{
	try
	{
		if (argc == 3 && !strcmp(argv[1], "-d"))
		{
			AvmCore core(argv[2], new Ncurses());
			core.execute();
		}
		else if (argc == 2)
		{
			AvmCore core(argv[1], nullptr);
			core.execute();
		}
		else if (argc == 1)
		{
			AvmCore core(nullptr);
			core.execute();
		}
		else
			std::cout << "usage: avm [-d] file.avm" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
