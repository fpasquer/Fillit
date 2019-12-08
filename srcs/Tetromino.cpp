#include "../incs/Tetromino.hpp"

unsigned int				Tetromino::NUMBER_ROW = 4;
unsigned int				Tetromino::NUMBER_COL = 4;
char						Tetromino::EMPTY = '.';
char						Tetromino::CHARACTER = '#';

							Tetromino::Tetromino(std::list<std::string> const &tetrominoList, unsigned int const i):
		m_tetrominoList(tetrominoList),
		m_i(i)
{
	if (this->m_tetrominoList.size() != Tetromino::NUMBER_ROW)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": One tetromino must be composed by " + std::to_string(Tetromino::NUMBER_ROW) + " row(s)");
	for (std::string rowTetromino : this->m_tetrominoList)
	{
		if (rowTetromino.length() != Tetromino::NUMBER_COL)
			throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": Each tetromino's row must be composed by " + std::to_string(Tetromino::NUMBER_COL) + " characters");
	}
	if (this->isValid() == false)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": does not exist");
}

std::list<std::string>		Tetromino::getTetromino(void) const
{
	return this->m_tetrominoList;
}

std::ostream &operator		<<(std::ostream &out, Tetromino const &tetromino)
{
	for (std::string rowTetromino : tetromino.getTetromino())
		out << rowTetromino << std::endl;
    return out;
}

bool						Tetromino::isValid(void) const
{
	unsigned int			count = 0;
	t_coordinate			coordStart;
	t_coordinate			coord;

	coordStart.y = 0xFFFFFFFF;
	coordStart.x = 0xFFFFFFFF;
	coord.y = 0;
	for (std::string const &rowTetromino : this->m_tetrominoList)
	{
		coord.x = 0;
		for (char const &c : rowTetromino)
		{
			if (c == Tetromino::CHARACTER)
			{
				coordStart.y = coordStart.y == 0xFFFFFFFF ? coord.y : coordStart.y;
				coordStart.x = coordStart.x == 0xFFFFFFFF ? coord.x : coordStart.x;
				count ++;
			}
			else if (c != Tetromino::EMPTY)
				throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": character : " + std::to_string(c) + " not available");
			coord.x++;
		}
		coord.y++;
	}
	if (count != 4)
		throw GlobalException("Tetromino " + std::to_string(this->m_i) + ": must have 4 " + std::to_string(Tetromino::CHARACTER));
	return this->searchIfTetrominoExist(coordStart);
}

bool						Tetromino::searchIfTetrominoExist(t_coordinate const &coordStart) const
{
	Tetromino::t_checker const
							checkers[] = {
		{&Tetromino::isSquare},
		//{&Tetromino::isS},
		//{&Tetromino::isLTop},
	};

	for (t_checker const &checker : checkers)
		if ((*(this).*checker.f)(coordStart) == true)
			return true;
	return false;
}

bool						Tetromino::isSquare(t_coordinate const &coordStart) const
{
	t_coordinate const		square[] = {
		{coordStart.x, coordStart.y},
		{coordStart.x + 1, coordStart.y},
		{coordStart.x, coordStart.y + 1},
		{coordStart.x + 1, coordStart.y + 1}
	};

	for (t_coordinate const &checker : square)
		if (checker.y >= Tetromino::NUMBER_ROW || checker.x >= Tetromino::NUMBER_COL)
		{
			return false;
			std::cout << checker.y << "-" << checker.x << std::endl;
		}
	return true;
}
