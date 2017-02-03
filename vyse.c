#include <stdio.h>

void hello_world_n_times(int times) {
    for (int x = 0; x < times; x++) {
        puts("Greetings my dude!");
    }
}

int main(int argc, char** argv) {
    hello_world_n_times(5);
    return 0;
}
