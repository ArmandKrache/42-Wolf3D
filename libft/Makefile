# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrache <akrache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:30:18 by akrache           #+#    #+#              #
#    Updated: 2019/05/02 20:43:22 by akrache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -I ./

CC = gcc

CLEAR_LINE = \033[2K\c

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/string/ft_strdup.c srcs/string/ft_strlen.c srcs/ft_isdigit.c \
		srcs/ft_isalpha.c srcs/ft_isalnum.c srcs/mem/ft_memset.c srcs/mem/ft_memcpy.c srcs/mem/ft_memccpy.c \
		srcs/mem/ft_memmove.c srcs/mem/ft_memchr.c srcs/mem/ft_memcmp.c srcs/string/ft_strcpy.c srcs/string/ft_strncpy.c \
		srcs/string/ft_strcat.c srcs/string/ft_strncat.c srcs/string/ft_strlcat.c srcs/string/ft_strchr.c srcs/string/ft_strrchr.c \
		srcs/string/ft_strstr.c srcs/string/ft_strnstr.c srcs/string/ft_strcmp.c srcs/string/ft_strncmp.c srcs/ft_atoi.c \
		srcs/ft_isascii.c srcs/ft_isprint.c srcs/ft_toupper.c srcs/ft_tolower.c srcs/ft_bzero.c \
		srcs/ft_putendl.c srcs/ft_putnbr.c srcs/mem/ft_memalloc.c srcs/mem/ft_memdel.c srcs/string/ft_strnew.c \
		srcs/string/ft_strdel.c srcs/string/ft_strclr.c srcs/string/ft_striter.c srcs/string/ft_striteri.c srcs/string/ft_strmap.c \
		srcs/string/ft_strmapi.c srcs/string/ft_strequ.c srcs/string/ft_strnequ.c srcs/string/ft_strsub.c srcs/string/ft_strjoin.c \
		srcs/string/ft_strtrim.c srcs/string/ft_strsplit.c srcs/ft_itoa.c srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c \
		srcs/ft_putnbr_fd.c srcs/ft_putendl_fd.c srcs/list/ft_lstadd.c srcs/list/ft_lstdel.c srcs/list/ft_lstdelone.c \
		srcs/list/ft_lstiter.c srcs/list/ft_lstmap.c srcs/list/ft_lstnew.c srcs/ft_nb_digit.c srcs/ft_swap.c srcs/string/ft_strrev.c \
		srcs/list/ft_lstlen.c srcs/list/ft_lstiteri.c srcs/list/ft_lstaddback.c srcs/string/ft_strndup.c srcs/get_next_line.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@echo "\nCreating $@"
		@ar -rc $(NAME) $(OBJS)
		@ranlib $(NAME)

%.o: %.c libft.h
		@echo "$(CLEAR_LINE)"
		@echo "Compiling $<\r\c"
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
