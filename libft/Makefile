# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 16:45:23 by adenis            #+#    #+#              #
#    Updated: 2016/11/28 14:13:25 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 
EXEC = libft.a
NAME = libft.a
INCLUDESDIR = .
SRCS =	ft_atoi.c ft_strlcat.c ft_strncmp.c ft_strnstr.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_bzero.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c ft_putchar.c \
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
		ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncpy.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		ft_lstiter.c ft_lstmap.c ft_lstsplit.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) -I $(INCLUDESDIR) $(SRCS) 
	@ar rcs $(EXEC) $(OBJS)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(EXEC)

re : fclean all
