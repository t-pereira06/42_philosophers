# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:07:55 by tsodre-p          #+#    #+#              #
#    Updated: 2023/05/16 11:10:40 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc -g
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = main.c libft_functions.c creating.c utils.c running.c monitoring.c

OBJ = $(FILES:%.c=%.o)
FILES_O = main.o libft_functions.o creating.o utils.o running.o monitoring.o

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -pthread -fsanitize=thread -o philo

clean:
		@$(RM) $(FILES_O)

fclean: clean
		@$(RM) $(NAME)

re: fclean all
