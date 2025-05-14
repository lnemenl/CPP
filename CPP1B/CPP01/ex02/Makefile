# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:03:16 by rkhakimu          #+#    #+#              #
#    Updated: 2025/05/14 14:08:00 by rkhakimu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= shlyapa
CC					= c++
CFLAGS				= -Wall -Wextra -Werror -std=c++20
SRC_FILES			= main.cpp
OBJ_FILES			= $(SRC_FILES:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "Compiled executable: $(NAME)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	@echo "Object files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Executable removed"

re: fclean all