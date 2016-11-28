# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:01:35 by adenis            #+#    #+#              #
#    Updated: 2016/11/28 12:16:39 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_EXEC = libft.a
LIB_DIR = ./libft/
SRCS = fillit.c main.c various_ft.c
HEADER = fillit.h

all: $(NAME)

$(NAME): $(LIB_EXEC)
	$(CC) $(CFLAGS) $(SRCS) $(HEADER) $(LIB_DIR)$(LIB_EXEC)

$(LIB_EXEC):
	@(cd $(LIB_DIR) && $(MAKE))
	@$(CC) $(CFLAGS) $(SRCS) $(HEADER) $(LIB_DIR)$(LIB_EXEC)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)

fclean:
	@(cd $(LIB_DIR) && $(MAKE) $@)

re : 
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@$(CC) $(CFLAGS) $(SRCS) $(HEADER) $(LIB_DIR)$(LIB_EXEC)