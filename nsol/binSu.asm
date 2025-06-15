; binSu.asm - NSOL Bridge Boot Stub
; Assembles with: nasm -f bin binSu.asm -o binSu.bin

[org 0x7C00]           ; Bootloader origin
bits 16

start:
    ; BIOS loads this to 0x7C00, we start execution here
    cli                 ; Disable interrupts
    xor ax, ax
    mov ds, ax
    mov es, ax
    sti                 ; Enable interrupts

    ; Print boot message
    mov si, boot_msg
    call print_string

    ; Simulate lazy handoff
    mov si, lazy_msg
    call print_string

    jmp $               ; Hang (NSOL doesn't boot anything on its own)

print_string:
.next_char:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    int 0x10
    jmp .next_char
.done:
    ret

boot_msg db "binSu: NSOL Boot Bridge Loaded!", 0
lazy_msg db 13,10, "Waiting for PupListener... (lazy mode)", 0

times 510-($-$$) db 0
dw 0xAA55               ; Boot signature
