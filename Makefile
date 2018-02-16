PREFIX = /usr
CC=gcc
CC_FLAGS=-Wall

all:
	make clean
	$(CC) $(CC_FLAGS) -o no no.c
	@echo Now run \'make install\'

install:
	cp -p no $(DESTDIR)$(PREFIX)/bin

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/no
clean:
	rm -rf no
