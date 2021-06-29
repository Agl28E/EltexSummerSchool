#include <stdio.h>

int main() {

    int a = 270533154;
    char *ptr;
    ptr = (char *)&a;
    printf("first byte a:%d\n", *ptr);
    ptr++;
    printf("second byte a:%d\n", *ptr);
    ptr++;
    *ptr = *ptr + 255;
    printf("third byte a:%d\n", *ptr);
    ptr++;
    printf("fourth byte a:%d\n", *ptr);
    
    return 0;
}