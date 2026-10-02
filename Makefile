CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
OUTDIR := .
NAME := libft.a
TARGETS := $(wildcard *.c)
OBJS := $(TARGETS:%.c=$(OUTDIR)/%.o)

all: $(OUTDIR)/$(NAME)

test:
	@$(MAKE) -s OUTDIR=build
	@$(CC) $(CFLAGS) -Lbuild .tests/*.c -lcriterion -lft -o build/test || true
	@build/test || true
	@$(MAKE) -s fclean OUTDIR=build
	@rm -rf build/*

run: $(NAME)
	$(CC) $(CFLAGS) libft.a ||true
	./a.out || true
	$(MAKE) fclean
	rm -f a.out

$(OUTDIR)/$(NAME): $(OBJS) | $(OUTDIR)
	ar rcs $@ $?

$(OUTDIR)/%.o: %.c | $(OUTDIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUTDIR):
	mkdir -p $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUTDIR)/$(NAME)

re: fclean all
