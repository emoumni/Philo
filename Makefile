NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = check_args.c initialize.c main.c mtx_initialize.c utils.c 
OBJ = $(SRC:.c=.o)
INCLUDE = philo.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re