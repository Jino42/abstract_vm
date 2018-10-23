#include <iostream>
#include <string>
#include <sstream>
#include "Ncurses.hpp"
#include "AvmParser.hpp"
#include <iomanip>
#include <exception>

Ncurses::Ncurses(void) :
    _exit(false)
{
    if (Ncurses::_debug)
        std::cout << "Ncurse:: Default constructor called." << std::endl;
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
	try {
		this->_winInstruction = new NcursesWin(Vector2D<int>(0, 0), Vector2D<int>(50, 100));
		this->_winStack = new NcursesWin(Vector2D<int>(50, 0), Vector2D<int>(50, 100));
	} catch (std::exception const &e) {
		this->_clearNcurses();
		throw ;
	}
}

Ncurses::~Ncurses(void)
{
    if (Ncurses::_debug)
        std::cout << "Ncurses:: Destructor called." << std::endl;
		this->_clearNcurses();
}

void Ncurses::_clearNcurses(void)
{
	if (this->_winInstruction)
		delete this->_winInstruction;
	if (this->_winStack)
		delete this->_winStack;
	endwin();
}

void Ncurses::update(void)
{
    int key;

    key = getch();

    if (key == 27)
        this->_exit = true;
	this->_winInstruction->update();
	this->_winStack->update();
}

void		Ncurses::addInstruction(AInstruction const &instruction)
{
	this->_instruction.push_back(instruction.toString());
}

void Ncurses::render(MutantStack<IOperand const *> &stack)
{
	this->_renderInstruction();
	this->_renderStack(stack);
}

void Ncurses::_renderInstruction(void)
{
	unsigned int j = 0;
	std::vector<std::string>::iterator	it;

	it = this->_instruction.begin();
	while (it != this->_instruction.end())
	{
		this->_winInstruction->printString(Vector2D<int>(0, j), *it);
		it++;
		j++;
	}
	this->_winInstruction->render();
}
void Ncurses::_renderStack(MutantStack<IOperand const *> &stack)
{
	unsigned int j = 0;
	MutantStack<IOperand const *>::iterator it;
	it = (stack).begin();
	while (it != (stack).end())
	{
		std::stringstream ss;
		ss << std::fixed << std::setprecision((*it)->getPrecision()) << std::stof((*it)->toString());
		this->_winStack->printString(Vector2D<int>(20, j), ss.str());
		it++;
		j++;
	}
	this->_winStack->render();
}

bool Ncurses::exit(void) const
{
    return (this->_exit);
}

const bool	Ncurses::_debug = 0;
