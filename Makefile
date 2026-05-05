CC      = cc
CFLAGS  = -Wall -Wextra -Werror -lbsd
LIBFT   = Libft/libft.a
INC     = -ILibft

TARGETS = test_part1 test_part2 test_part3

# Default rule
all: $(TARGETS)

# This rule ensures the library is built first by calling make inside the Libft folder
$(LIBFT):
	$(MAKE) -C Libft

# Generic rule for all targets
# $@ = Name of the target (e.g., test_part1)
# $< = Name of the first dependency (e.g., test_part1.c)
test_part%: test_part%.c $(LIBFT)
	$(CC) $(CFLAGS) $(INC) -o $@ $< $(LIBFT)

clean:
	rm -f $(TARGETS)
	$(MAKE) -C Libft clean

fclean: clean
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
