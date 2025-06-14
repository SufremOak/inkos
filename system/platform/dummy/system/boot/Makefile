CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -Os -ffreestanding -nostdlib
LDFLAGS = -Tlinker.ld

OBJS = startup.o bootloader.o flash_loader.o

all: bootloader.bin

startup.o: startup.s
    $(CC) $(CFLAGS) -c $< -o $@

bootloader.o: bootloader.c
    $(CC) $(CFLAGS) -c $< -o $@

flash_loader.o: flash_loader.c
    $(CC) $(CFLAGS) -c $< -o $@

bootloader.elf: $(OBJS) linker.ld
    $(LD) $(LDFLAGS) $(OBJS) -o $@

bootloader.bin: bootloader.elf
    $(OBJCOPY) -O binary $< $@

clean:
    rm -f *.o *.elf *.bin
