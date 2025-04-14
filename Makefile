# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 14:01:51 by jlaine            #+#    #+#              #
#    Updated: 2024/08/12 17:22:02 by jlaine           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFT		= ./libft/libft.a
INCLUDES	= ./include

CC			= cc
RM			= rm -fr
CFLAGS		= -Wall -Wextra -Werror -g3

MLX 		= ./mlx
MLX_FLAGS	= -L $(MLX) -lmlx -lXext -lX11 -lm

SRC			= ./srcs/utils/init.c \
			  ./srcs/utils/error.c \
			  ./srcs/utils/destroy.c \
			  ./srcs/checks/map_check.c \
			  ./srcs/checks/path_check.c \
			  ./srcs/game/game_display.c \
			  ./srcs/checks/map_values.c \
			  ./srcs/game/game_movement.c \
			  ./srcs/checks/walls_check.c \
			  ./srcs/checks/extension_check.c \

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) main.c $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME) -I $(INCLUDES) -I ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C $(MLX)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
