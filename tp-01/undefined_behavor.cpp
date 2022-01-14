#include <iostream>

int main(void) {
    int i = 0;

    long l = 0xffffffffffff;

    i = (int)l;

    std::cout << i << std::endl;

    return 0;
}