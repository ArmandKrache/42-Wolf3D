# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clevaill <clevaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 17:35:15 by akrache           #+#    #+#              #
#    Updated: 2019/05/22 15:16:56 by clevaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = main.c hooks/key_hook.c hooks/move.c hooks/move2.c parse/parse.c ray/display.c ray/draw.c \
		texture/texture.c parse/check.c error/error.c error/error2.c

OBJECT = $(SRCS:.c=.o)

LIBFT = libft/libft.a

CLEAR_LINE = \033[2K\c

all : $(NAME)

$(LIBFT): libft/libft.h
	@make -C libft

$(NAME) : $(LIBFT) $(OBJECT)
		@echo "\nCreating $@"
		@$(CC) $(FLAGS) -I/usr/local/include $(LIBFT) $(OBJECT) -o $(NAME) -L/usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

%.o: %.c wolf.h libft/libft.h
		@echo "$(CLEAR_LINE)"
		@echo "Compiling $<\r\c"
		@$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJECT)
	@make clean -C libft

fclean: clean
	/bin/rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: clean fclean all re