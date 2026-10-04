CC := cc
CFLAGS := -Wall -Wextra -Werror
DEBUG_FLAGS := -g3 -fno-omit-frame-pointer -fsanitize=address,undefined
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
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -Ltarget .tests/*.c -lcriterion -lft -o target/test || true
	@target/test || true
	@$(MAKE) -s fclean OUTDIR=target
	@rm -rf target/test*

run: build
	@target/$(NAME_STEM) || true
	@$(MAKE) -s fclean
	@rm -f target/$(NAME_STEM)

debug: build
	@$(DEBUGGER) target/$(NAME_STEM)
	@rm -rf target/*

build: build-lib
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) target/$(NAME) -o target/$(NAME_STEM)

build-lib:
	@$(MAKE) -s OUTDIR=target CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"

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
