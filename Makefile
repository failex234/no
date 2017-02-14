PREFIX = /usr

all:
	make clean
	gcc -o no -std=c99 main.c
	@echo Now run \'make install\'

install:
	cp -p no $(DESTDIR)$(PREFIX)/bin

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/no
clean:
	rm -rf no
