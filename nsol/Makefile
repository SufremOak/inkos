CC := gcc
NASM := nasm
CFLAGS := -Os -Wall
TARGET := lazyness
ASM := binSu.asm
ASM_OUT := binSu.bin

.PHONY: fullinstall fis clean

fullinstall:
	@echo "[NSOL Build] Fullinstall mode. Choose target architecture:"
	@read -p "Arch (e.g. x86_64, armv7, riscv64): " ARCH && \
	$(CC) $(CFLAGS) -march=$$ARCH lazyness.c -o $(TARGET)_$$ARCH.bin && \
	echo "[NSOL] Built: $(TARGET)_$$ARCH.bin"

fis:
	@echo "[NSOL Build] Building full bootable NSOL kernel (with binSu)"
	$(NASM) -f bin $(ASM) -o $(ASM_OUT)
	$(CC) $(CFLAGS) lazyness.c -o $(TARGET).elf
	cat $(ASM_OUT) $(TARGET).elf > bootable_nsol.bin
	@echo "[NSOL] Built: bootable_nsol.bin"

clean:
	rm -f *.o *.bin *.elf $(TARGET)_*.bin
	@echo "[NSOL] Cleaned build files."
