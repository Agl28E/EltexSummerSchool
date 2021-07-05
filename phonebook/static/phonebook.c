#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 5

struct phonebook{
	short int id;
	char name[16];
	char surename[16];
	long int number;
};

char* NameBase[] = {

	"Kate",
	"Anna",
	"Daniel",
	"Alex",
	"Elizabet"
};

char* SurenameBase[] = {

	"Swon",
	"Mercer",
	"Sheprd",
	"Brado",
	"Broke"
};



char* getSurename(int i){
	srandom(i);
	return SurenameBase[rand() % 5];
};

char* getName(int i){
	
	srandom(i);
	return NameBase[rand() % 5];
	
};

unsigned long getNumber(int i){
	srandom(i);
	return 80000000000 + random() % 10000000000;
}

int main() {
	
	int size = N;
	struct phonebook book[size];
	//book[0].id = 1;
	//strcpy(book[0].name, "Addi");
	//strcpy(book[0].surename, "Broke");
	//book[0].number = 89137433570;
	//book.name[0] = 'A';
	//printf("%s", book[0].name);
	
	for (int i = 0; i < size; i++){
		
		book[i].id = i;
		strcpy(book[i].name, getName(i));
		strcpy(book[i].surename, getSurename(i));
		printf("%d %s %s\n", book[i].id, book[i].name, book[i].surename);
	}	


	return 0;
}
