# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 16:19:07 by rkhakimu          #+#    #+#              #
#    Updated: 2025/04/28 16:20:34 by rkhakimu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= megaphone
CC					= g++
CFLAGS				= -Wall -Wextra -Werror

SRC_FILES			= cleanup.c \

OBJ_FILES			= $(SRC_FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "Compiled executable: $(NAME)"

%.o: %.c philosophers.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	@echo "Object files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Executable removed"

re: fclean all