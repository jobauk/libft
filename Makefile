# Compiler
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Compiler debug
LD_FLAGS := -fsanitize=address,undefined
DEBUG_CFLAGS := $(CFLAGS) -g3 -O0 -fno-omit-frame-pointer $(LD_FLAGS)

# Library
NAME := libft.a
NAME_STEM := $(basename $(NAME))

OUTDIR := .
DEBUG_OUTDIR := target

# Source
SRCS := $(wildcard *.c)
OBJS := $(SRCS:%.c=$(OUTDIR)/%.o)

DEBUG_OBJS := $(SRCS:%.c=$(DEBUG_OUTDIR)/%.o)

TEST_SRCS := $(wildcard .tests/*.c)
TEST_OBJS := $(TEST_SRCS:.tests/%.c=$(DEBUG_OUTDIR)/tests/%.o)

# Output
TEST_BIN := $(DEBUG_OUTDIR)/test
RUN_BIN := $(DEBUG_OUTDIR)/$(NAME_STEM)

# Debugger
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	DEBUGGER := lldb
else
	DEBUGGER := gdb
endif

# Criterion
CRITERION_CFLAGS := $(shell pkg-config --cflags criterion)
CRITERION_LIBS := $(shell pkg-config --libs criterion)

# Default
all: $(OUTDIR)/$(NAME)

# Utility commands
test: $(TEST_BIN)
	@./$(TEST_BIN) $(if $(FILTER), --filter "'$(FILTER)'")

run: $(RUN_BIN)
	@./$(RUN_BIN)

debug: $(RUN_BIN)
	@$(DEBUGGER) $(RUN_BIN)

$(DEBUG_OUTDIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(DEBUG_CFLAGS) -c $< -o $@

$(DEBUG_OUTDIR)/tests/%.o: .tests/%.c Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(DEBUG_CFLAGS) $(CRITERION_CFLAGS) -c $< -o $@

$(TEST_BIN): $(DEBUG_OBJS) $(TEST_OBJS)
	@$(CC) $(LD_FLAGS) $^ $(CRITERION_LIBS) -o $@

$(RUN_BIN): $(DEBUG_OBJS)
	@$(CC) $(LD_FLAGS) $^ -o $@

# Required commands
$(OUTDIR)/$(NAME): $(OBJS) | $(OUTDIR)
	ar rcs $@ $(OBJS)

$(OUTDIR)/%.o: %.c | $(OUTDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR):
	mkdir -p $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUTDIR)/$(NAME)

re: fclean all
