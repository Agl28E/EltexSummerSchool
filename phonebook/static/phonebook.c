#include <stdio.h>
#define N 50

struct phonebook{
    short int id;
    char name[24];
    char surename[24];
    long int number;
};

int main() {

    struct phonebook book;
    book.name[0] = 'A';
    printf("%s", book.name);

    
    return 0;
}
