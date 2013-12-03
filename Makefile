
PREFIX ?= /usr/local
SOURCES = $(wildcard src/*.c)
SOURCES += $(wildcard deps/*.c)

test: test.c $(SOURCES)
	$(CC) -std=c99 $^ -o test -Isrc -Ideps
	./test

rimraf: bin.c $(SOURCES)
	$(CC) -std=c99 $^ -o rimraf

install: rimraf
	cp -f ./rimraf $(PREFIX)/bin/rimraf

clean:
	rm -rf rimraf test tmp

.PHONY: test clean install
