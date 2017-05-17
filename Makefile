# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mulzega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 14:44:05 by mulzega           #+#    #+#              #
#    Updated: 2017/05/16 15:58:20 by mulzega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = Sources/ft_julia.c Sources/ft_init.c Sources/ft_mandelbrot.c \
Sources/ft_sierpinski.c Sources/burningship.c Sources/main.c

OBJ = $(SRC:.c=.o)

CF = gcc -Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

$(NAME): $(OBJ)
	@make -C Libs/libft
	@make -C Libs/minilibx_macos
	@$(CF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo fractol well compiled

all: $(NAME)

%.o: %.c
	gcc -o $@ -c $<
#	$(CF) -o $@ -c $<

clean:
	@make clean -C Libs/libft
	@make clean -C Libs/minilibx_macos
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C Libs/libft
	@rm -f $(NAME)

re: fclean all
