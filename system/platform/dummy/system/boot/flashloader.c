#include <stdint.h>

#define INKOS_FLASH_BASE  0x08020000U
#define INKOS_LOAD_ADDR   0x20002000U

typedef void (*entry_t)(void);

void inkos_load_and_jump(void) {
    uint32_t *src = (uint32_t*) INKOS_FLASH_BASE;
    uint32_t *dst = (uint32_t*) INKOS_LOAD_ADDR;
    uint32_t word;

    // Simple copy loop (assumes InkOS size < RAM)
    while ((word = *src++) != 0xFFFFFFFFU) {
        *dst++ = word;
    }

    // Jump to InkOS
    entry_t inkos = (entry_t)INKOS_LOAD_ADDR;
    inkos();
}
