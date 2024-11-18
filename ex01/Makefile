GXX = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98

NAME = fixed

SRC = main.cpp \
		Fixed.cpp

HEADER = Fixed.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GXX) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(GXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re