CC = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m0 -mthumb -Wall
LDFLAGS = -specs=nosys.specs

all: main.elf

main.elf: main.o
	$(CC) main.o -o main.elf $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f *.o main.elf
