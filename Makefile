CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
OUTDIR := .
UNAME_S := $(shell uname -s)
NAME := libft.a
NAME_STEM := $(basename $(NAME))
TARGETS := $(wildcard *.c)
OBJS := $(TARGETS:%.c=$(OUTDIR)/%.o)

ifeq ($(UNAME_S),Darwin)
	DEBUGGER := lldb
else
	DEBUGGER := gdb
endif

all: $(OUTDIR)/$(NAME)

# Debugging
test: build-lib
	@$(CC) $(CFLAGS) -Ltarget .tests/*.c -lcriterion -lft -o target/test || true
	@target/test || true
	@$(MAKE) -s fclean OUTDIR=target
	@rm -rf target/test*

run: build
	@target/$(NAME_STEM) || true
	@$(MAKE) -s fclean
	@rm -f target/$(NAME_STEM)

debug: build
	@$(DEBUGGER) target/$(NAME_STEM)

build: build-lib
	@$(CC) $(CFLAGS) target/$(NAME) -o target/$(NAME_STEM)

build-lib:
	@$(MAKE) -s OUTDIR=target

# Required
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
