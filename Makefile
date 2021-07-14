# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 17:25:22 by ravernhe          #+#    #+#              #
#    Updated: 2020/03/09 12:14:20 by ravernhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

CC = g++
CFLAG = -Wall -Wextra

SRC_PATH	= ./srcs/
INC_PATH	= ./includes/
OBJ_PATH	= ./obj/

OBJ_FILE = $(SRC_FILE:.cpp=.o)
SRC_FILE = 	main.cpp\

OBJ      = $(addprefix $(OBJ_PATH),$(OBJ_FILE))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(CFLAG) -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp Makefile includes/computerv1.hpp
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CFLAG) -I $(INC_PATH) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
