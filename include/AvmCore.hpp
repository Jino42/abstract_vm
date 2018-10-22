#ifndef AVMCORE_HPP
# define AVMCORE_HPP

#include "MutantStack.tpp"
#include "IOperand.hpp"
#include "AvmParser.hpp"

class AvmCore {

public:

	class StackTooSmall : public std::logic_error {
	public:
		StackTooSmall(void) throw();
		StackTooSmall(std::string) throw();
		virtual const char* what() const throw();
		~StackTooSmall(void) throw();
		StackTooSmall(StackTooSmall const &src) throw();
	private:
		StackTooSmall &operator=(StackTooSmall const &rhs) throw();
		std::string			_error;
	};
	class NoExitInstruction : public std::runtime_error {
	public:
		NoExitInstruction(void) throw();
		NoExitInstruction(std::string) throw();
		virtual const char* what() const throw();
		~NoExitInstruction(void) throw();
		NoExitInstruction(NoExitInstruction const &src) throw();
	private:
		NoExitInstruction &operator=(NoExitInstruction const &rhs) throw();
		std::string			_error;
	};

	AvmCore(std::string const &path);
	~AvmCore(void);

	MutantStack< IOperand const * >	&getStack(void);

	void	setExit(bool);

	void	printInstruction(void);
	void	printStack(void);
	void	execute(void);

private:
	bool								_exit;
	AvmParser							_parser;
	MutantStack< IInstruction const * >	_instruction;
	MutantStack< IOperand const * >			_stack;
	std::string const					_path;

	AvmCore(void);
	AvmCore(AvmCore const &src);
	AvmCore		&operator=(AvmCore const &rhs);

	static const bool	_debug;
};

#endif
