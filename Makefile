CC=gcc
CFLAGS= -lX11 -lXtst -lXext
all: xremotemouse
xremotemouse: xremotemouse.c
	$(CC) xremotemouse.c $(CFLAGS) -o xremotemouse

install:
	sudo cp xremotemouse /usr/local/bin/

uninstall:
	sudo rm -f /usr/local/bin/xremotemouse

clean:
	rm -f xremotemouse
	rm -f *.o
