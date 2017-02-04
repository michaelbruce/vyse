#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <editline/readline.h>

int character_position(char* content, char character) {
    char* substring_from_character = strchr(content, character);
    if (substring_from_character != NULL) {
        return (int)(substring_from_character - content);
    } else {
        return -1;
    }

}

void extract_sexp(char* input_code) {
    int sexp_start = character_position(input_code, '(');
    int sexp_end = character_position(input_code, ')');
    printf("DEBUG: start - %d\n", sexp_start);
    printf("DEBUG: end - %d\n", sexp_end);
    if (sexp_start != -1 && sexp_end != -1) {
        char substring[sexp_end + 1 ];
        strncpy(substring, input_code, sexp_end + 1);
        printf("%s\n", substring);
    }
}

void evaluate(char* input) {
    if (strstr(input, "hello") != NULL) {
        printf("How do you do my friend?\n");
    } else {
        printf("What is this '%s' you speak of?\n", input);
    }
}

void prompt_and_respond() {
    puts("Vyse v0.0.1");
    while (1) {
        char* input = readline(">>> ");
        if (!input) {
            printf("\n");
            break;
        }
        add_history(input);
        extract_sexp(input);
        evaluate(input);
        free(input);
    }
}

int main(int argc, char** argv) {
    prompt_and_respond();
    return 0;
}
