# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:01:35 by adenis            #+#    #+#              #
#    Updated: 2016/12/01 14:22:50 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_EXEC = libft.a
EXEC = fillit.a
LIB_DIR = ./libft/
SRCS = fillit.c main.c various_ft.c ft_check_tetri.c checks.c grid.c resolution.c
OBJS = $(SRCS:.c=.o)
HEADER = fillit.h
NAME = fillit

all: $(NAME)

$(NAME): lib
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rcs $(EXEC) $(OBJS)
	@$(CC) $(CFLAGS) $(EXEC) $(LIB_DIR)$(LIB_EXEC) -o $(NAME)

clean : libclean
	@rm -rf $(OBJS) $(EXEC)

fclean : clean libfclean
	@rm -rf $(NAME)

re : fclean $(NAME)

lib:
	@(cd $(LIB_DIR) && $(MAKE))

libclean:
	@(cd $(LIB_DIR) && $(MAKE) clean)

libfclean:
	@(cd $(LIB_DIR) && $(MAKE) fclean)

libre : libfclean lib
