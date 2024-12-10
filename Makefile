CC=clang
ifndef DEBUG
	DEBUG=1
endif
BASE_CFLAGS=-std=gnu11 -g3
ifeq ($(DEBUG),1)
	CFLAGS=$(BASE_CFLAGS) -O0 -fsanitize=address,undefined
else
	CFLAGS=$(BASE_CFLAGS) -O3 -march=native -mtune=native
endif
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