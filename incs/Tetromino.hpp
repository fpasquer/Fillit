#ifndef TETROMINO_HPP
#define TETROMINO_HPP

# include <string>
# include <list>
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
		std::list<std::string>
							getTetromino() const;
		friend std::ostream
							&operator << (std::ostream &out, Tetromino const &tetromino);
	private:
		typedef struct		s_coordinate
		{
			unsigned int	x;
			unsigned int	y;
		}					t_coordinate;
		typedef struct		s_checker
		{
			bool			(Tetromino::*f) (t_coordinate const &) const;
		}					t_checker;
		bool				isValid(void) const;
		bool				searchIfTetrominoExist(t_coordinate const &coordStart) const;
		bool				isSquare(t_coordinate const &coordStart) const;
		//bool				isS(char const **tetromino2Dim, t_coordinate const coord) const;
		//bool				isLTop(char const **tetromino2Dim, t_coordinate const coord) const;
		std::list<std::string>
							m_tetrominoList;
		unsigned int		m_i;
};


#endif
