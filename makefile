CC = clang
CFLAGS = -Wall -Wextra -pedantic -std=c11 -g -I/home/crative/dev/c/csl/csl/
LDFLAGS = -lm
SRCDIR = testing
OBJDIR = obj
TARGETDIR = bin
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
TARGETMAIN = $(TARGETDIR)/main

all: clean $(TARGETMAIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGETDIR):
	@mkdir -p $(TARGETDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(TARGETMAIN): $(OBJS) | $(TARGETDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	@rm -f $(OBJS) $(TARGET)
	@rm -rf $(OBJDIR)
	@rm -rf $(TARGETDIR)

count:
	cloc csl testing

check-for-leaks:
	valgrind -s --leak-check=full --show-leak-kinds=all $(TARGETMAIN)

render-readme:
	pandoc README.md | lynx -stdin

run:
	./bin/main
