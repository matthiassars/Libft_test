CC =		cc
CFLAGS =	-Wall -Wextra -lbsd
TARGETS =	test_part1 test_part2 test_part2 test_part3
LIB =		libft/libft.a

# Default rule
all: $(TARGETS)

# Generic rule for all targets
# $@ = Name of the target (e.g., test_part1)
# $< = Name of the first dependency (e.g., test_part1.c)
test_part%: test_part%.c $(LIB)
	$(CC) -o $@ $< $(LIB) $(CFLAGS)

clean:
	rm -f $(TARGETS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
