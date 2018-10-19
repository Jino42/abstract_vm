#include "FactoryOperand.hpp"
#include <iostream>
#include "MutantStack.tpp"

int		main(void)
{
	FactoryOperand const *fo = FactoryOperand::getInstance();
	IOperand const *a, *b, *c;

	a = fo->createOperand(Int8, "4");
	b = fo->createOperand(Float, "4.42f");

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

	return (0);
}
