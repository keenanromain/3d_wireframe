# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kromain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 15:05:07 by kromain           #+#    #+#              #
#    Updated: 2017/04/28 14:28:58 by kromain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = \
		fdf.c		\
		output.c	\
		math.c

all: $(NAME)

$(NAME): lib mlx
	@cd srcs && clang -Wall -Wextra -Werror -c $(SRCS) -g
	cd srcs && clang $(SRCS:.c=.o) -g -L../minilibx -lmlx -framework OpenGL -framework Appkit -L../libft -lft -o $(NAME)
	mv srcs/fdf .

lib:
	@cd libft && make

mlx:
	@cd minilibx && make

clean:
	@cd libft && make clean
	@cd srcs && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@cd minilibx && make clean
	@/bin/rm -f $(NAME)

re: fclean all
