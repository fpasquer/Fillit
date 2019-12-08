#ifndef TETROMINO_HPP
#define TETROMINO_HPP

# include <string>
# include <list>
# include <vector>
# include <iostream>
# include "../incs/TetrominoChecker.hpp"

class Tetromino : public TetrominoChecker
{
	public:
							Tetromino(std::list<std::string> const &tetrominoList, unsigned int const i);
		std::vector<std::vector<char>>
							getTetromino() const;
		friend std::ostream
							&operator << (std::ostream &out, Tetromino const &tetromino);
};

#endif
