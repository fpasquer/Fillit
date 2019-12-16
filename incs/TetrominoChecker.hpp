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
		typedef enum		e_tetrominoIndex
		{
			NONE = 0x0,
			SQUARE = 0x1,
			S_HORIZONTALLY = 0x2,
			S_VERTICALLY = 0x4,
			L_TOP = 0x8,
			L_RIGHT = 0x10,
			L_BOTTOM = 0x20,
			L_LEFT = 0x40,
			LINE_HORIZONTALLY = 0x80,
			LINE_VERTICALLY = 0x100,
			Z_HORIZONTALLY = 0x200,
			Z_VERTICALLY = 0x400,
			T_TOP = 0x800,
			T_RIGHT = 0x1000,
			T_BOTTOM = 0x2000,
			T_LEFT = 0x4000
		}					t_tetrominoIndex;
		static unsigned int const
							NUMBER_ROW;
		static unsigned int const
							NUMBER_COL;
		static char const	EMPTY;
		static char const	CHARACTER;

							TetrominoChecker(std::list<std::string> const &tetrominoList, unsigned int const i);
		t_tetrominoIndex	getTetrominoIndex(void) const;
	protected :
		std::vector<std::vector<char>>
							m_tetromino;
		unsigned int		m_i;
		t_tetrominoIndex	m_index;
	private :
		typedef struct		s_coordinate
		{
			unsigned int	x;
			unsigned int	y;
		}					t_coordinate;
		typedef struct		s_checker
		{
			t_tetrominoIndex
							tetrominoIndex;
			bool			(TetrominoChecker::*f) (t_coordinate const &) const;
		}					t_checker;
		void				checkTetrominoRowCol(std::list<std::string> const &tetrominoList) const;
		t_coordinate const	initTetromino(std::list<std::string> const &tetrominoList);
		t_tetrominoIndex	isValid(t_coordinate const &coordStart) const;
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
		bool				isZHorizontally(t_coordinate const &coordStart) const;
		bool				isZVertically(t_coordinate const &coordStart) const;
		bool				isTTop(t_coordinate const &coordStart) const;
		bool				isTRight(t_coordinate const &coordStart) const;
		bool				isTBottom(t_coordinate const &coordStart) const;
		bool				isTLeft(t_coordinate const &coordStart) const;
};

#endif
