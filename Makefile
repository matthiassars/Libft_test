CC =		cc
CFLAGS =	-Wall -Wextra -I./libft
TARGETS =	test_part1 \
			test_part2 \
			test_part3
LDFLAGS =	-L./libft
LDLIBS =	-lft -lbsd

# Default rule
all: $(TARGETS)

# Generic rule for all targets
# $@ = Name of the target (e.g., test_part1)
# $< = Name of the first dependency (e.g., test_part1.c)
test_%: test_%.c test_utils.h libft/libft.a
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

libft/libft.a: libft/*.c libft/libft.h
	$(MAKE) -C libft

clean:
	rm -f $(TARGETS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
