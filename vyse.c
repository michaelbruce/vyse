#include <stdio.h>
#include <string.h>

// XXX objective, print all the operands and operator for the following sexp
// (+ 40 90 30)

char* replace(char* original, char* search, char* replacement) {
    static char buffer[4096];
    strncpy(buffer, original, strlen(original));

    char* match = strstr(original, search);

    if (!match) {
        return buffer;
    } else {
        strncpy(buffer, original, match - original);
        buffer[match - original] = '\0';

        sprintf(buffer+(match - original), "%s%s", replacement, match + strlen(search));
    }
    return buffer;
}

int main(int argc, char** argv) {
    printf("%s\n", replace("a lot of text", "lot", "little bit"));
    return 0;
}
