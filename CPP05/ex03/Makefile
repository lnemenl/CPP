NAME				= 	ex03
CC					= 	c++
CFLAGS				= 	-Wall -Wextra -Werror
SRC_FILES			=	main.cpp \
						Bureaucrat.cpp \
						AForm.cpp \
						PresidentialPardonForm.cpp \
						RobotomyRequestForm.cpp \
						ShrubberyCreationForm.cpp \
						Intern.cpp
						
OBJ_FILES			= 	$(SRC_FILES:.cpp=.o)

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