NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincls
SRC = src/main.cpp src/RPN.cpp src/utils/PrintWithColor.cpp
RM = rm -rf
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean :
	$(RM) $(OBJ_DIR)

fclean :clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

