NAME = fileReplacer
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC = main.cpp FileReplacer_Lifecycle.cpp FileReplacer_error.cpp FileReplacer_main.cpp FileReplacer_utils.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test