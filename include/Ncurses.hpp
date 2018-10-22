#ifndef NCURSES_HPP
#define NCURSES_HPP

#include <curses.h>
#include <vector>
#include "Vector2D.tpp"
#include "MutantStack.tpp"
#include "AInstruction.hpp"
#include "IOperand.hpp"

class Ncurses {
    public:

        Ncurses(Vector2D<int> const &position, Vector2D<int> const &percentSize);
        Ncurses(void);
        virtual ~Ncurses(void);

        bool            exit(void) const;
        Vector2D<int>   getMapSize(void) const;
        Vector2D<int>   getPosition(void) const;
        Vector2D<int>   getWinSize(void) const;
        WINDOW			*getWin(void) const;

        void        render(void);
		void		render(MutantStack<AInstruction const *> &instruction, MutantStack<IOperand const *> &stack, unsigned int i);
        void        update(void);

        void        printString(Vector2D<int> position, std::string const &string);

    private:
        bool _exit;
        WINDOW * _win;
        Vector2D<int> _position;
        Vector2D<int> _winSize;
        Vector2D<int> _offset;
        Vector2D<int> _mapSize;

        bool        _inWin(Vector2D<int> const &renderPosition) const;
        bool        _inWin(Vector2D<int> const &renderPosition,
            				Vector2D<int> const &renderSize) const;

        Ncurses(Ncurses const &src);
        Ncurses      &operator=(Ncurses const &rhs);

		static const bool	_debug;
        static int			_nbInstances;
};

#endif // ifndef Ncurses_HPP
