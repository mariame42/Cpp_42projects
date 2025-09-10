NAME = MATERIA
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = AMateria.cpp Ice.cpp Cure.cpp main.cpp
OBJ_FILE = obj/
OBJ = $(SRC:%.cpp=$(OBJ_FILE)/%.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_FILE)/%.o : %.cpp | $(OBJ_FILE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_FILE) :
	mkdir -p $(OBJ_FILE)

clean :
	$(RM) $(OBJ_FILE)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re