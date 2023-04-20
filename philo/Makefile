# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:07:55 by tsodre-p          #+#    #+#              #
#    Updated: 2023/04/20 09:26:54 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

LIBFT = libft/libft.a

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = philo/main.c

OBJ = $(FILES:%.c=%.o)
FILES_O = philo/main.c

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) philo

clean:
		@$(MAKE) clean -C ./libft
		@$(RM) $(FILES_O)

fclean: clean
		@$(MAKE) fclean -C ./libft

re: fclean all
