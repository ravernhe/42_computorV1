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

CC = clang
CFLAG = -Wall -Wextra

SRC_PATH	= ./srcs/
INC_PATH	= ./includes/
OBJ_PATH	= ./obj/

LFT_PATH		= ./libft/
LIBFT_FLAG	= -L$(LFT_PATH) -lft
LIBFT				= $(LFT_PATH)libft.a
INCLIBFT  	= $(LFT_PATH)includes

OBJ_FILE = $(SRC_FILE:.c=.o)
SRC_FILE = 	main.c\
						compute_core.c\
						first_member.c\
						second_member.c\

OBJ      = $(addprefix $(OBJ_PATH),$(OBJ_FILE))

all: libft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(CFLAG) -lm $(LIBFT_FLAG) -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile includes/computerv1.h
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CFLAG) -I $(INC_PATH) -I $(INCLIBFT) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):   $(LFT_PATH)
		@make -C $(LFT_PATH)

sdl: $(LIBSDL)

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -rf $(NAME)

re: fclean all
