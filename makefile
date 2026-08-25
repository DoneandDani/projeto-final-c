
CC = gcc

CFLAGS = -I$(IDIR) -I/ucrt64/include/ncursesw
LDLIBS = -lncursesw

IDIR = ./include/
SRCDIR = ./scr/

SOURCES = $(wildcard $(SRCDIR)/*.c)

.PHONY: all rogue run clean

all: rogue 

rogue:
	rm -f rogue.exe
	$(CC) $(SOURCES) $(CFLAGS) $(LDLIBS) -o $@

run:
	./rogue

clean:
	rm rogue