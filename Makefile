# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psigfry <psigfry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 14:11:13 by ccriston          #+#    #+#              #
#    Updated: 2020/03/02 15:22:05 by psigfry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = gcc -Wall -Werror -Wextra

INC = include/fdf.h include/libft/libft.h

SRC = draw/draw_line.c draw/move.c draw/rotate.c draw/scale.c draw/tracer.c \
	draw/centring.c draw/gradient.c\
	validation/convert.c validation/valid.c validation/error.c \
	visualization/create_data.c visualization/hooker.c visualization/mouse_hooks.c\
	main.c

OBJECTS = draw_line.o move.o rotate.o scale.o tracer.o centring.o gradient.o\
	convert.o valid.o error.o \
	create_data.o hooker.o mouse_hooks.o\
	main.o

all: lib $(NAME)

$(NAME) : $(OBJECTS)
		@$(FLAGS) $(OBJECTS) -I include -L include/libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJECTS) : $(SRC) $(INC)
		@$(FLAGS) -c $(SRC) -I include

lib:
	@make -C include/libft

clean: 
		@rm -rf $(OBJECTS)
		@make -C ./include/libft clean

fclean: clean
		@rm -f $(NAME)
		@make -C ./include/libft fclean

re: fclean all

.PHONY: clean all fclean re
