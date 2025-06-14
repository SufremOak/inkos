#include <stdint.h>

extern uint32_t _sdata, _edata, _sbss, _ebss;
extern void inkos_load_and_jump(void);

void main(void) {
    uint32_t *src, *dst;

    // Zero BSS
    for (dst = &_sbss; dst < &_ebss; ++dst) {
        *dst = 0;
    }

    // Copy DATA
    src = (uint32_t*)&_edata;
    for (dst = &_sdata; dst < &_edata; ++dst) {
        *dst = *src++;
    }

    // Load InkOS from Flash and jump
    inkos_load_and_jump();

    // Shouldn't reach here
    for (;;);
}
