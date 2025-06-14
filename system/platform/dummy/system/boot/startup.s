    .syntax unified
    .cpu cortex-m4
    .thumb

    .section .isr_vector, "a", %progbits
    .word _estack
    .word Reset_Handler
    // ... other vectors could go here

    .global Reset_Handler
Reset_Handler:
    ldr sp, =_estack
    bl main
    b .

    .size Reset_Handler, . - Reset_Handler
