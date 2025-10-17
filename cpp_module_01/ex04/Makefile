# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meid <meid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 11:04:24 by meid              #+#    #+#              #
#    Updated: 2025/10/17 14:20:59 by meid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fileReplacer
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp FileReplacer_Lifecycle.cpp FileReplacer_error.cpp FileReplacer_main.cpp
OBJ_FILE = obj
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

.PHONY : all fclean clean re