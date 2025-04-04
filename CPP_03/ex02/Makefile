NAME := ex02
INCLUDE_DIR := includes
FILES := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	LEAK_TOOL := leaks -atExit --
	HOSTNAME := $(shell whoami)
else
	LEAK_TOOL := valgrind --leak-check=full
endif
IFLAGS := -I$(INCLUDE_DIR)
OBJECTS := $(FILES:.cpp=.o)
CC := c++
#color codes
END := \033[0m
WHITE := \033[1;37m
NC := \033[0m
PINK := \033[1;35m
GREEN := \033[32m
BOLD := \033[1m
L_PURPLE :=\033[38;5;55m

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
