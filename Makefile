CC    =sdcc
all : main.bin

main.bin : main.hex
	objcopy -I ihex -O binary main.hex main.bin
	
main.hex : main.ihx
	packihx main.ihx > main.hex

main.ihx : main.rel delay.rel timer.rel
	$(CC) main.rel delay.rel timer.rel

main.rel : main.c delay.h timer.h
	$(CC) -c main.c

delay.rel : delay.c
	$(CC) -c delay.c

timer.rel : timer.c 
	$(CC) -c timer.c

cleanall:
	rm -rf *.lk *.bin *.asm *.lst *.mem *.rst *.lnk *.rel *.sym *.ihx *.hex *.map

clean:
	rm -rf *.asm *.lst *.mem *.rst *.lnk *.rel *.sym *.ihx *.map *.lk *.bin