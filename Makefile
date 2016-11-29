# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:01:35 by adenis            #+#    #+#              #
#    Updated: 2016/11/29 11:15:37 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_EXEC = libft.a
EXEC = fillit.a
LIB_DIR = ./libft/
SRCS = fillit.c main.c various_ft.c ft_check_tetri.c checks.c
OBJS = $(SRCS:.c=.o)
HEADER = fillit.h
NAME = fillit

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rcs $(EXEC) $(OBJS)
	@$(CC) $(CFLAGS) $(EXEC) $(LIB_DIR)$(LIB_EXEC) -o $(NAME)

clean :
	@rm -rf $(OBJS) $(EXEC)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

lib:
	@(cd $(LIB_DIR) && $(MAKE))

libclean:
	@(cd $(LIB_DIR) && $(MAKE) clean)

libfclean:
	@(cd $(LIB_DIR) && $(MAKE) fclean)

libre : libfclean lib
