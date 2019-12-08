#ifndef TETROMINO_HPP
#define TETROMINO_HPP

# include <string>
# include <list>
# include <vector>
# include <iostream>
# include "../incs/GlobalException.hpp"

class Tetromino
{
	public:
		static unsigned int
							NUMBER_ROW;
		static unsigned int
							NUMBER_COL;
		static char			EMPTY;
		static char			CHARACTER;

							Tetromino(std::list<std::string> const &tetrominoList, unsigned int const i);
		std::vector<std::vector<char>>
							getTetromino() const;
		friend std::ostream
							&operator << (std::ostream &out, Tetromino const &tetromino);
	private :
		typedef struct		s_coordinate
		{
			unsigned int	x;
			unsigned int	y;
		}					t_coordinate;
		typedef struct		s_checker
		{
			bool			(Tetromino::*f) (t_coordinate const &) const;
		}					t_checker;
		void				checkTetrominoRowCol(std::list<std::string> const &tetrominoList) const;
		t_coordinate const	initTetromino(std::list<std::string> const &tetrominoList);
		bool				isValid(t_coordinate const &coordStart) const;
		bool				isSquare(t_coordinate const &coordStart) const;
		std::vector<std::vector<char>>
							m_tetromino;
		unsigned int		m_i;

};


#endif
