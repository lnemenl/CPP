# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 18:20:03 by rkhakimu          #+#    #+#              #
#    Updated: 2025/06/12 12:18:27 by rkhakimu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= ex00
CC					= c++
CFLAGS				= -Wall -Wextra -Werror -std=c++20
SRC_FILES			= main.cpp Animal.cpp Dog.cpp Cat.cpp
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