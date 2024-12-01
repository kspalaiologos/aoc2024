CC=gcc
CFLAGS=-g3 -std=gnu11
LDFLAGS=-lm
SOURCES=$(wildcard d[0-9][0-9].c)
PROGRAMS=$(SOURCES:.c=.out)
all: aoc $(PROGRAMS)
clean:
	rm -f aoc $(PROGRAMS)
%.out: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
aoc: aoc.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) -lcurl
.PHONY: all clean