
CC = gcc

CFLAGS = -I$(IDIR) -I/ucrt64/include/ncursesw
LDLIBS = -lncursesw

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(wildcard $(SRCDIR)/*.c)

.PHONY: all rogue run clean

all: rogue 

rogue:
	rm -f rogue.exe
	$(CC) $(SOURCES) $(CFLAGS) $(LDLIBS) -o rogue.exe

run:
	./rogue.exe

clean:
	rm -f rogue rogue.exe main.exe