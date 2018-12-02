CFLAGS=-Wno-discarded-qualifiers -g -I./include -O0
CC=gcc

bin/main.exe: src/*.c
	${CC} -g src/*.c ${CFLAGS} -o $@

.PHONY: clean

all: bin/main.exe

clean:
	-rm bin/main.exe