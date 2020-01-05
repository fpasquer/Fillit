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
			L_TOP1 = 0x8,
			L_TOP2 = 0x10,
			L_RIGHT1 = 0x20,
			L_RIGHT2 = 0x40,
			L_BOTTOM1 = 0x80,
			L_BOTTOM2 = 0x100,
			L_LEFT1 = 0x200,
			L_LEFT2 = 0x400,
			LINE_HORIZONTALLY = 0x800,
			LINE_VERTICALLY = 0x1000,
			Z_HORIZONTALLY = 0x2000,
			Z_VERTICALLY = 0x4000,
			T_TOP = 0x8000,
			T_RIGHT = 0x10000,
			T_BOTTOM = 0x20000,
			T_LEFT = 0x40000
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
		bool				isLTop1(t_coordinate const &coordStart) const;
		bool				isLTop2(t_coordinate const &coordStart) const;
		bool				isLRight1(t_coordinate const &coordStart) const;
		bool				isLRight2(t_coordinate const &coordStart) const;
		bool				isLBottom1(t_coordinate const &coordStart) const;
		bool				isLBottom2(t_coordinate const &coordStart) const;
		bool				isLLeft1(t_coordinate const &coordStart) const;
		bool				isLLeft2(t_coordinate const &coordStart) const;
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
