NAME = push_swap
SRC = push_swap.c \
      utils/validate_error.c \
	  utils/utils.c\
	  utils/validate_input.c\
	  utils/ft_strncmp.c\
	  utils/ft_isdigit.c\
	  utils/ft_max.c\
	  utils/ft_split.c\
	  utils/ft_strlen.c\
	  utils/ft_atoi.c\
	  utils/ft_free_split.c\
	  utils/ft_abs.c\
	  sort/sorting.c\
	  sort/sort_utils.c\
	  sort/valid_cheapest.c\
	  sort/push_cheapest.c\
	  sort/target.c\
	  sort/big_small.c\
	  movements/push.c\
	  movements/reverse.c\
	  movements/rotate.c\
	  movements/swap.c\

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
INCLUDES = push_swap.h
%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean fclean all re
