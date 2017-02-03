#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <editline/readline.h>

void prompt_and_respond() {
    puts("Vyse v0.0.1");
    while (1) {
        char* input = readline(">>> ");
        if (!input) {
            printf("\n");
            break;
        }
        add_history(input);
        // __typeof__ (input);
        if (strstr(input, "hello") != NULL) {
            printf("How do you do my friend?\n");
        } else {
            printf("What is this '%s' you speak of?\n", input);
        }
        free(input);
    }
}

int main(int argc, char** argv) {
    prompt_and_respond();
    return 0;
}
