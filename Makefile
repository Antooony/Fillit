# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:01:35 by adenis            #+#    #+#              #
#    Updated: 2016/11/26 15:42:13 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c 
WFLAGS = -Wall -Wextra -Werror
NAME = fillit

LIB_EXEC = libft.a
LIB_NAME = libft.a
LIB_DIR = ./libft/
LIB_C =	ft_atoi.c ft_strlcat.c ft_strncmp.c ft_strnstr.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_bzero.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c ft_putchar.c \
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
		ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncpy.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		ft_lstiter.c ft_lstmap.c ft_lstsplit.c
LIB_O =	$(LIB_SRCS:.c=.o)
LIB_SRC = $(addprefix $(LIB_DIR)/,$(LIB_C))
LIB_OBJ = $(addprefix $(LIB_DIR)/,$(LIB_O))

SRCS = fillit.c fillit.h various_ft.c main.c

all : $(NAME)

# $(NAME) : $(LIB)
# 	$(CC) $(WFLAGS) $(SRCS) $(LIB_EXEC) -o $(NAME)

# $(LIB) :
$(NAME) : 
	$(CC) $(WFLAGS) $(CFLAGS) $(LIB_SRC) 
	ar rcs $(LIB_EXEC) $(LIB_OBJ)

clean :
	rm -rf $(LIB_O)

fclean : clean
	rm -rf $(LIB_EXEC)

re : fclean all
