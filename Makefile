# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 14:55:59 by adeburea          #+#    #+#              #
#    Updated: 2021/07/01 17:48:43 by adeburea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME	=	fractol
CC		=	clang
FLAGS	=	-O3 -Wall -Wextra -Werror
INC		=	incs
OBJ		=	objs
SRC		=	srcs
LIBFT	=	libft
LIBMLX	=	libmlx
INCS	=	$(addprefix $(INC)/, fractol.h)
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS 	=	main.c \
			julia.c \
			mandelbrot.c \
			sierpinski.c \
			mlx_utils.c \
			color.c \
			hook.c \
			exit.c

all: bonus $(NAME)

bonus:
	mkdir -p $(OBJ)
	make -C $(LIBFT)
	make -C $(LIBMLX)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

$(OBJ)/%.o: $(SRC)/%.c $(INCS)
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)/libft.a

re: fclean all
