NAME = fillit

SRC_NAME = $(sort main.cpp GlobalException.cpp Tetromino.cpp TetrominoManager.cpp TetrominoChecker.cpp)

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./incs/
OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

CC = g++
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -std=c++11 -g
LDFLAGS = $(addprefix -L,)
LDLIBS =

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_TOOL)
	@printf "%-50s" "create executable "$(notdir $@)...
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(OBJ_TOOL) -o $(NAME) $(LDLIBS)
	@printf "[OK]\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@printf "%-50s" "compiling "$(notdir $<)...
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@printf "[OK]\n"

clean:
	@printf "%-50s" "deleting objects..."
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_TOOL)
	@printf "[OK]\n"

fclean: clean
	@printf "%-50s" "deleting executable..."
	@$(RM) $(NAME)
	@printf "[OK]\n"

re: fclean all

