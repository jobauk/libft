CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
NAME := libft.a
TARGETS := $(wildcard *.c)
OBJS := $(TARGETS:.c=.o)

all: $(NAME)

test: $(NAME)
	$(CC) $(CFLAGS) -L. .tests/*.c -lcriterion -lft -o .tests/test || true
	.tests/test || true
	$(MAKE) fclean
	rm -f .tests/test

run: $(NAME)
	$(CC) $(CFLAGS) libft.a ||true
	./a.out || true
	$(MAKE) fclean
	rm -f a.out

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
