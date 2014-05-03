

all: test

test: test.o strbuf.o
	cc -o test -Wall test.o strbuf.o

test.o: test.c strbuf.h
	cc -o test.o -Wall -c test.c

strbuf.o: strbuf.c strbuf.h
	cc -o strbuf.o -Wall -c strbuf.c

