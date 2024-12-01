CC=gcc
CFLAGS=-g3 -std=gnu11
LDFLAGS=-lm
SOURCES=$(wildcard *.c)
PROGRAMS=$(SOURCES:.c=.out)
all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)
%.out: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
.PHONY: all clean