# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:07:55 by tsodre-p          #+#    #+#              #
#    Updated: 2023/04/19 09:07:43 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx_Linux.a

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = mandatory/so_long.c mandatory/args.c mandatory/map.c \
		mandatory/map_path.c mandatory/map_errors.c mandatory/map_utils.c \
		mandatory/free.c mandatory/window.c mandatory/events.c mandatory/moves.c \
		mandatory/moves_utils.c

FILES_BONUS = bonus/so_long.c bonus/args.c bonus/map.c \
		bonus/map_path.c bonus/map_errors.c bonus/map_utils.c \
		bonus/free.c bonus/window.c bonus/events.c bonus/moves.c \
		bonus/moves_utils.c bonus/enemies.c bonus/enemies_utils.c bonus/sprites.c

OBJ = $(FILES:%.c=%.o)
OBJ_BONUS = $(FILES_BONUS:%.c=%.o)
FILES_O = mandatory/so_long.o mandatory/args.o mandatory/map.o \
		mandatory/map_path.o mandatory/map_errors.o mandatory/map_utils.o  \
		mandatory/free.o mandatory/window.o mandatory/events.o mandatory/moves.o \
		mandatory/moves_utils.o

FILES_O_BONUS = bonus/so_long.o bonus/args.o bonus/map.o \
		bonus/map_path.o bonus/map_errors.o bonus/map_utils.o  \
		bonus/free.o bonus/window.o bonus/events.o bonus/moves.o \
		bonus/moves_utils.o bonus/enemies.o bonus/enemies_utils.o bonus/sprites.o
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJ) $(LIBFT) $(MLX)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -o so_long

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MLX)
		@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX) -lXext -lX11 -o so_long_bonus

bonus: $(NAME_BONUS)

clean:
		@$(MAKE) clean -C ./libft
		@$(MAKE) clean -C ./minilibx-linux
		@$(RM) $(FILES_O) $(FILES_O_BONUS)

fclean: clean
		@$(MAKE) fclean -C ./libft
		@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
