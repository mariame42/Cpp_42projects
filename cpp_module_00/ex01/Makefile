NAME = phonebook
COMPILE = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp cpp_files/utils.cpp cpp_files/PhoneBook.cpp cpp_files/Contact.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMPILE) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re