#include "FactoryOperand.hpp"
#include "FactoryInstruction.hpp"
#include <iostream>
#include "MutantStack.tpp"
#include "AvmCore.hpp"

int		main(int argc, char **argv)
{
	{
		static_cast<void>(argc);

		FactoryOperand const *fo = FactoryOperand::getInstance();
		IOperand const *a, *b, *c;

		a = fo->createOperand(Int8, "4", 0);
		b = fo->createOperand(Float, "4.42f", 2);

		c = *a * *b;

		std::cout << c->toString() << std::endl;

		FactoryOperand::deleteInstance();


		MutantStack<int> ma;

		ma.push(1);
		ma.push(2);

		for (MutantStack<int>::iterator i = ma.begin(); i != ma.end(); i++)
			std::cout << *i << std::endl;

		MutantStack<int> mb;
		mb = ma;

		for (MutantStack<int>::iterator i = mb.begin(); i != mb.end(); i++)
			std::cout << *i << std::endl;

		FactoryInstruction fi;
		(void)fi;
		fi.createInstruction(Pop);
		fi.createInstruction(Dump);

		AvmCore core(argv[1]);

		core.printInstruction();
		core.execute();
		core.printStack();
	}
	return (0);
}
