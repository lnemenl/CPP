# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhakimu <rkhakimu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 14:29:39 by rkhakimu          #+#    #+#              #
#    Updated: 2025/05/16 12:21:31 by rkhakimu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= phonebook
CC					= c++
CFLAGS				= -Wall -Wextra -Werror -std=c++20
SRC_FILES			= main.cpp PhoneBook.cpp Contact.cpp
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