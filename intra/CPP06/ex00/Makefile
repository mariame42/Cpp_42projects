# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meid <meid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 17:25:20 by meid              #+#    #+#              #
#    Updated: 2025/11/07 17:31:11 by meid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScalarConverter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp ScalarConverter.cpp input_type.cpp convert_to.cpp convert_from.cpp 
RM = rm -rf
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean :
	$(RM) $(OBJ_DIR)

fclean :clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

