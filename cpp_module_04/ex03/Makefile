# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meid <meid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 21:10:50 by meid              #+#    #+#              #
#    Updated: 2025/09/10 22:08:07 by meid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MATERIA
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

A = abstract/
D = derived/
I = Interface/

SRC = $(A)AMateria.cpp \
	$(D)Ice.cpp $(D)Cure.cpp \
	main.cpp
# $(I)ICharacter.cpp $(I)IMateriaSource.cpp

OBJ_FILE = obj
OBJ = $(SRC:%.cpp=$(OBJ_FILE)/%.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_FILE) :
	mkdir -p $(OBJ_FILE)/$(A)
	mkdir -p $(OBJ_FILE)/$(D)
	mkdir -p $(OBJ_FILE)/Interface/

$(OBJ_FILE)/%.o : %.cpp | $(OBJ_FILE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ_FILE)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re