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

void split_on_whitespace(char* input) {
    char input_copy[256];
    strcpy(input_copy, input);

    int counter = 0;
    char *p = strtok(input_copy, " ");
    static char *output[10] = { NULL };

    while (p != NULL) {
        output[counter++] = p;
        p = strtok(NULL, " ");
    }

    for (int x = 0; x < sizeof(output); x++) {
        if (output[x] != NULL) {
            printf("%s\n", output[x]);
        } else {
            break;
        }
    }
}

void extract_sexp(char* input_code) {
    int sexp_start = character_position(input_code, '(');
    int sexp_end = character_position(input_code, ')');
    printf("DEBUG: start - %d\n", sexp_start);
    printf("DEBUG: end - %d\n", sexp_end);

    char input_copy[256];
    char *output;

    // XXX expand by if output contains '(' then your work is not yet done.
    if (sexp_start != -1 && sexp_end != -1) {
        strcpy(input_copy, input_code);
        if (sexp_start == 0) {
            strcpy(input_copy, input_copy + 1);
            output = strtok(input_copy, ")");
        } else {
            output = strtok(input_copy, "(");
            output = strtok(NULL, ")");
        }
        split_on_whitespace(output);
        printf("%s\n", output);
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
