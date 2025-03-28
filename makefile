CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LDFLAGS = 
SRCDIR = testing
OBJDIR = obj
TARGETDIR = bin
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
TARGETMAIN = $(TARGETDIR)/main

all: $(TARGETMAIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGETMAIN): $(OBJS) | $(TARGETDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(OBJDIR)
	rm -rf $(TARGETDIR)

count:
	cloc csl testing

run:
	./bin/main
