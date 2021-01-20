main.hex : main.o
	avr-objcopy -j .text -j .data -O ihex  main.o  main.hex
	avr-size main.hex
main.o : init_library.c common_library.c button_handler_library.c main.c 
	avr-gcc -mmcu=atmega8 -Os main.c init_library.c common_library.c button_handler_library.c -o main.o
program : main.hex
	avrdude -c usbasp -p m8 -P usb -U flash:w:main.hex
