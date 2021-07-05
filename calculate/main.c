#include <stdio.h>
#include <stdlib.h>
#include "add.h"
#include "subtraction.h"
//#include "mmul.h"
#include "division.h"


int main()
{
    int *res;
    my_add(3, 5, res);
    printf("%d\n", *res);
    my_sub(5, 3, res);
    printf("%d\n", *res);
    return 0;
}
