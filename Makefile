CC=gcc
CFLAGS= -lX11 -lXtst -lXext
all: dep_install xremotemouse
xremotemouse: xremotemouse.c
	$(CC) xremotemouse.c $(CFLAGS) -o xremotemouse
dep_install:
	sudo apt install libx11-dev libxtst-dev

install:
	sudo cp xremotemouse /usr/local/bin/

uninstall:
	sudo rm -f /usr/local/bin/xremotemouse

clean:
	rm -f xremotemouse
	rm -f *.o
