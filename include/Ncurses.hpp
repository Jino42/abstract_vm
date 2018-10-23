#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "NcursesWin.hpp"

class Ncurses {
    public:

        Ncurses(void);
        ~Ncurses(void);

        bool            exit(void) const;


		void		addInstruction(std::string const &str);
		void		addException(std::string const &str);
		void		render(MutantStack<IOperand const *> &stack);
        void        update(void);

		typedef struct		s_printInstruction {
			std::string		string;
			bool			isException;
		}					t_printInstruction;

    private:
        bool							_exit;
		std::vector<t_printInstruction>	_instruction;
		NcursesWin						*_winInstruction;
		NcursesWin						*_winStack;

		void		_clearNcurses(void);
		void        _renderInstruction(void);
		void		_renderStack(MutantStack<IOperand const *> &stack);

        Ncurses(Ncurses const &src);
        Ncurses      &operator=(Ncurses const &rhs);

		static const bool	_debug;
};

#endif
