#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

void prompt_and_respond() {
    puts("Vyse v0.0.1");
    while (1) {
        char* input = readline(">>> ");
        add_history(input);
        printf("No you're a %s", input);
        free(input);
    }
}

int main(int argc, char** argv) {
    prompt_and_respond();
    return 0;
}
