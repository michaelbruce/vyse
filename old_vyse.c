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

    // XXX current aim is to read ONE sexp before building on this.
    // XXX expand by if output contains '(' then your work is not yet done.
    if (sexp_start != -1 && sexp_end != -1) {
        // XXX why is strdup neccessary aren't parameters recreated as local parameters?
        char* string = strdup(input_code);
        strsep(&string, "(");
        char* inside_sexp = strsep(&string, ")");

        if (character_position(input_code, '(') != -1) {
            char* operator = strsep(&inside_sexp, " ");
            int total = 0;
            char* operand;

            while ((operand = strsep(&inside_sexp, " ")) != NULL) {
                total = total + atoi(operand);
            }

            printf("%s\n", operator);
            printf("%d\n", total);
        } else {
            int sexp_start = character_position(input_code, '(');
            int sexp_end = character_position(input_code, ')');
            strsep(&string, "(");
            char* inside_inner_sexp = strsep(&string, ")");
        }
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
    puts("Vyse v0.0.2");
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
