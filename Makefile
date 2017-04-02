PREFIX = /usr

all:
	make clean
	g++ -o no no.cpp
	@echo Now run \'make install\'

install:
	cp -p no $(DESTDIR)$(PREFIX)/bin

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/no
clean:
	rm -rf no
