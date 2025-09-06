
Name = ClapTrap
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SEC = main.cpp ClapTrap.cpp
OBJ = $(SEC:.cpp=.o)

all : $(Name)

$(NAME) : $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(Name)

re : fclean all

.PHONY : all clean fclean re
