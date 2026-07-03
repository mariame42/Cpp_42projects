NAME = account
COMPILE = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMPILE) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(COMPILE) $(CFLAGS) test_compare.cpp -o test_compare
	./test_compare

clean:
	rm -f $(OBJ)
	rm -f test_compare.o
	rm -f test_compare
	rm -f my_output.log

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test