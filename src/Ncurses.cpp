#include <iostream>
#include <string>
#include <sstream>
#include "Ncurses.hpp"
#include "AvmParser.hpp"
#include <iomanip>

Ncurses::Ncurses(Vector2D<int> const &position, Vector2D<int> const &percentSize) :
    _exit(false)
{
    if (Ncurses::_debug)
        std::cout << "Ncurse:: Default constructor called." << std::endl;
	if (!Ncurses::_nbInstances)
    	initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, FALSE);
    cbreak();
    noecho();
    start_color();
    curs_set(0);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_GREEN);
    init_pair(7, COLOR_MAGENTA, COLOR_WHITE);

    this->_position = position;
    this->_winSize  = Vector2D<int>(COLS * percentSize.getX() / 100,
            LINES * percentSize.getY() / 100);
    this->_offset  = Vector2D<int>(1, 1);
    this->_mapSize = Vector2D<int>(this->_winSize.getX() - 2, this->_winSize.getY() - 2);

    this->_win = newwin(this->_winSize.getY(), this->_winSize.getX(), position.getY(),
            position.getX());
    box(this->_win, 0, 0);
	Ncurses::_nbInstances++;
}

Ncurses::~Ncurses(void)
{
	Ncurses::_nbInstances--;
    if (Ncurses::_debug)
        std::cout << "Ncurses:: Destructor called." << std::endl;
    delwin(this->_win);
	if (!Ncurses::_nbInstances)
    	endwin();
}

Vector2D<int>       Ncurses::getMapSize(void) const
{
    return (this->_mapSize);
}

Vector2D<int>       Ncurses::getPosition(void) const
{
    return (this->_position);
}

Vector2D<int>       Ncurses::getWinSize(void) const
{
    return (this->_winSize);
}

WINDOW              * Ncurses::getWin(void) const
{
    return (this->_win);
}

void Ncurses::update(void)
{
    int key;

    key = getch();

    if (key == 27)
        this->_exit = true;
	werase(this->_win);
}

void Ncurses::render(MutantStack<AInstruction const *> &instruction,
						MutantStack<IOperand const *> &stack,
						unsigned int i)
{
	{
		MutantStack<AInstruction const *>::iterator	it;

		it = instruction.begin();
		for (unsigned int j = 0; j < i; j++)
		{
			this->printString(Vector2D<int>(0, j), (*it)->toString());
			it++;
		}
	}
	{
		unsigned int j = 0;
		MutantStack<IOperand const *>::iterator it;
		it = (stack).begin();
		while (it != (stack).end())
		{
			std::stringstream ss;
			ss << std::fixed << std::setprecision((*it)->getPrecision()) << std::stof((*it)->toString());
			this->printString(Vector2D<int>(20, j), ss.str());
			it++;
			j++;
		}
	}

    box(this->_win, 0, 0);
    wrefresh(this->_win);
}

void Ncurses::printString(Vector2D<int> position, std::string const &string)
{
    mvwprintw(this->_win, position.getY() + this->_offset.getY(),
      position.getX() + this->_offset.getX(), string.c_str());
}

bool Ncurses::_inWin(Vector2D<int> const &renderPosition) const
{
    if (renderPosition.getY() > 0 &&
      renderPosition.getY() < this->_winSize.getY() &&
      renderPosition.getX() > 0 &&
      renderPosition.getX() < this->_winSize.getX())
    {
        return (true);
    }
    return (false);
}

bool Ncurses::_inWin(Vector2D<int> const &renderPosition,
					Vector2D<int> const &renderSize) const
{
    if (renderPosition.getY() >= 0 &&
      renderPosition.getY() + renderSize.getY() < this->_winSize.getY() - 1 &&
      renderPosition.getX() >= 0 &&
      renderPosition.getX() + renderSize.getX() < this->_winSize.getX() - 1)
    {
        return (true);
    }
    return (false);
}

bool Ncurses::exit(void) const {
    return (this->_exit);
}

const bool	Ncurses::_debug = 0;
int			Ncurses::_nbInstances = 0;
