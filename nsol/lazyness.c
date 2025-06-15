// lazyness.c - Full NSOL Kernel Implementation
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

// Simulated context structure
struct NSOLContext {
    const char* input;
    char* screen;
    size_t screen_size;
    bool idle_mode;
    int laziness_level;
};

// Boot message
void nsol_boot(struct NSOLContext* ctx) {
    if (!ctx || !ctx->screen) return;
    snprintf(ctx->screen, ctx->screen_size, "[NSOL] Kernel booted in lazy mode (%d)\n", ctx->laziness_level);
    printf("%s", ctx->screen);
}

// Detect if input is BridgeHex (hex string only)
bool is_bridgehex(const char* input) {
    if (!input) return false;
    for (size_t i = 0; input[i]; i++) {
        if (!isxdigit(input[i])) return false;
    }
    return true;
}

// Decode BridgeHex (prints decoded bytes for now)
void process_bridgehex(const char* input, struct NSOLContext* ctx) {
    size_t len = strlen(input);
    if (len % 2 != 0) {
        snprintf(ctx->screen, ctx->screen_size, "[NSOL] Invalid BridgeHex length.\n");
        printf("%s", ctx->screen);
        return;
    }

    snprintf(ctx->screen, ctx->screen_size, "[NSOL] Decoded BridgeHex bytes:\n");
    printf("%s", ctx->screen);

    for (size_t i = 0; i < len; i += 2) {
        char byte_str[3] = { input[i], input[i+1], '\0' };
        unsigned int byte_val;
        sscanf(byte_str, "%x", &byte_val);
        printf(" 0x%02X", byte_val);
    }
    printf("\n");
}

// Main lazy event handler
void nsol_run(struct NSOLContext* ctx) {
    if (!ctx || !ctx->input || !ctx->screen) return;

    if (is_bridgehex(ctx->input)) {
        process_bridgehex(ctx->input, ctx);
        return;
    }

    if (ctx->laziness_level > 5) {
        snprintf(ctx->screen, ctx->screen_size, "[NSOL] Too lazy to process input. Try again later.\n");
    } else {
        snprintf(ctx->screen, ctx->screen_size, "[NSOL] You said: '%s'. Cute.\n", ctx->input);
    }

    printf("%s", ctx->screen);
}

// Background lazy maintenance task
void nsol_idle(struct NSOLContext* ctx) {
    if (!ctx) return;
    printf("[NSOL] *yawn*... still alive. Laziness level: %d\n", ctx->laziness_level);
    ctx->laziness_level++;
    if (ctx->laziness_level > 10) ctx->laziness_level = 1;
}

// PupSimulator main loop
int main() {
    struct NSOLContext ctx;
    char screen_buffer[256];
    ctx.screen = screen_buffer;
    ctx.screen_size = sizeof(screen_buffer);
    ctx.laziness_level = 3;
    ctx.idle_mode = false;

    nsol_boot(&ctx);

    while (1) {
        printf("\n> Enter command or BridgeHex (or 'idle', 'exit'): ");
        char input[128];

        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0; // Trim newline

        if (strcmp(input, "exit") == 0) {
            printf("[NSOL] Going back to sleep... bye.\n");
            break;
        } else if (strcmp(input, "idle") == 0) {
            nsol_idle(&ctx);
            continue;
        }

        ctx.input = input;
        nsol_run(&ctx);
    }

    return 0;
}