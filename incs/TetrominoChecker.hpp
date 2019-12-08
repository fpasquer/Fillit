#ifndef TETROMINO_CHECKER_HPP
# define TETROMINO_CHECKER_HPP



# include <string>
# include <list>
# include <vector>
# include <iostream>
# include "../incs/GlobalException.hpp"

class TetrominoChecker
{
	public:
		static unsigned int const
							NUMBER_ROW;
		static unsigned int const
							NUMBER_COL;
		static char const	EMPTY;
		static char const	CHARACTER;

							TetrominoChecker(std::list<std::string> const &tetrominoList, unsigned int const i);
	protected :
		std::vector<std::vector<char>>
							m_tetromino;
		unsigned int		m_i;
	private :
		typedef struct		s_coordinate
		{
			unsigned int	x;
			unsigned int	y;
		}					t_coordinate;
		typedef struct		s_checker
		{
			bool			(TetrominoChecker::*f) (t_coordinate const &) const;
		}					t_checker;
		void				checkTetrominoRowCol(std::list<std::string> const &tetrominoList) const;
		t_coordinate const	initTetromino(std::list<std::string> const &tetrominoList);
		bool				isValid(t_coordinate const &coordStart) const;
		bool				checkerFunction(std::vector<t_coordinate> const & coordExpected) const;
		bool				isSquare(t_coordinate const &coordStart) const;
		bool				isSHorizontally(t_coordinate const &coordStart) const;
		bool				isSVetically(t_coordinate const &coordStart) const;
		bool				isLTop(t_coordinate const &coordStart) const;
		bool				isLRight(t_coordinate const &coordStart) const;
		bool				isLBottom(t_coordinate const &coordStart) const;
		bool				isLLeft(t_coordinate const &coordStart) const;
		bool				isLineHorizontally(t_coordinate const &coordStart) const;
		bool				isLineVertically(t_coordinate const &coordStart) const;
};

#endif
