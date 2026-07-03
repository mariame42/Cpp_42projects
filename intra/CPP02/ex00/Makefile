# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meid <meid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 19:59:11 by meid              #+#    #+#              #
#    Updated: 2025/09/21 14:12:48 by meid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed
CXX = c++
CFLAGSXX = -Wall -Wextra -Werror -std=c++98
SRCS = Fixed.cpp main.cpp
OBJ = $(SRCS:.cpp=.o)
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CFLAGSXX) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CFLAGSXX) -c $< -o $@

# $< = the source file (%.cpp)
# $@ = the target file (%.o)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
	