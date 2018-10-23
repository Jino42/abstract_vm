#ifndef AVMCORE_HPP
# define AVMCORE_HPP

#include "MutantStack.tpp"
#include "IOperand.hpp"
#include "AvmParser.hpp"
#include "Ncurses.hpp"

class AvmCore {

public:

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

	AvmCore(std::string const &path, Ncurses *ncurses);
	AvmCore(Ncurses *ncurses);
	~AvmCore(void);

	MutantStack< IOperand const * >	&getStack(void);

	void	setExit(bool);

	void		printInstruction(void);
	void		printStack(void);
	void		execute(void);
	void		printError(std::string const &str);

private:
	Ncurses								*_ncurses;
	bool								_exit;
	AvmParser							_parser;
	MutantStack< AInstruction const * >	_instruction;
	MutantStack< IOperand const * >		_stack;
	std::string const					_path;



	AvmCore(AvmCore const &src);
	AvmCore		&operator=(AvmCore const &rhs);
	AvmCore(void);

	static const bool	_debug;
};

#endif
