#include <stdio.h>
#include <stdlib.h>

int my_add(int a, int b, int *res){
    *res = a + b;
    return 0;
}
