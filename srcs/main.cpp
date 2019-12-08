#include <iostream>
#include "../incs/Tetromino.hpp"
#include "../incs/GlobalException.hpp"
#include "../incs/TetrominoManager.hpp"

void						mainFunction(int argc, char **argv)
{
	if (argc != 2)
	{
		std::string			error(argv[0]);
		error.append(" need config file");
		throw GlobalException(error);
	}
	TetrominoManager		tetrominoManager(argv[1]);
//	for (Tetromino const &tetromino : config.getTetrominos())
//		std::cout << tetromino << std::endl;
}

int							main(int argc, char **argv)
{
	try {
		mainFunction(argc, argv);
	} catch (GlobalException const &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
