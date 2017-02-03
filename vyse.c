#include <stdio.h>

static char input[2048];

void prompt_and_respond() {
    puts("Vyse v0.0.1");
    while (1) {
        fputs(">>> ", stdout);
        fgets(input, 2048, stdin);
        printf("No you're a %s", input);
    }
}

int main(int argc, char** argv) {
    prompt_and_respond();
    return 0;
}
