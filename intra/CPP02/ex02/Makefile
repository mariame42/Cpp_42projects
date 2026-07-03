# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meid <meid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 19:59:38 by meid              #+#    #+#              #
#    Updated: 2025/09/04 20:35:29 by meid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed
CXX = c++
CFLAGSXX = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CFLAGSXX) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CFLAGSXX) -c $< -o $@
	

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

PHONY : all clean fclean re