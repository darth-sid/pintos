#include "lib/readline.h"
#include "devices/input.h"
#include <stdio.h>

void readline(char* buf, size_t size){
    if (!buf || size == 0) return;

    size_t i = 0;
    char c;
    while (i < size-1){
        c = input_getc();
        c = c == '\r' ? '\n' : c;
        putchar(c);

        if (c == '\n') break;

        if (c == '\b'){
            --i;
            putchar(' ');
            putchar('\b');
        } else buf[i++] = c;

    }
    buf[i] = '\0';

}
