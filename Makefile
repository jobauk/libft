CC := cc
CFLAGS := -Wall -Wextra -Werror -c
NAME := libft.a
TARGETS := $(wildcard *.c)
OBJS := $(TARGETS:.c=.o)

all: libft.a

libft.a: $(OBJS)
	ar rcs $(NAME) $^

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
