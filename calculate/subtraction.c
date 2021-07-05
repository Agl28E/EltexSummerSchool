#include <stdio.h>
#include <stdlib.h>

int msub(int a, int b, int *res){
    *res = a - b;
    return 0;
}
