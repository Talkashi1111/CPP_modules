NAME := RPN
INCLUDE_DIR :=
FILES :=  main.cpp RPN.cpp
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	LEAK_TOOL := leaks -atExit --
else
	LEAK_TOOL := valgrind --leak-check=full
endif
IFLAGS :=
OBJECTS := $(FILES:.cpp=.o)
CC := c++

.PHONY: all clean fclean re leak

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

leak: $(NAME)
	$(LEAK_TOOL) ./$(NAME)
