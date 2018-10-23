#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "NcursesWin.hpp"

class Ncurses {
    public:

        Ncurses(void);
        ~Ncurses(void);

        bool            exit(void) const;


		void		addInstruction(AInstruction const &instruction);
		void		render(MutantStack<IOperand const *> &stack);
        void        update(void);

    private:
        bool						_exit;
		std::vector<std::string>	_instruction;
		NcursesWin					*_winInstruction;
		NcursesWin					*_winStack;

		void		_clearNcurses(void);
		void        _renderInstruction(void);
		void		_renderStack(MutantStack<IOperand const *> &stack);

        Ncurses(Ncurses const &src);
        Ncurses      &operator=(Ncurses const &rhs);

		static const bool	_debug;
};

#endif
