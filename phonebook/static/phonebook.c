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
	"Elizabet",
	"Dana",
	"James",
	"Amaya",
	"Kolett",
	"Anton"
};

char* SurenameBase[] = {

	"Swon",
	"Mercer",
	"Sheprd",
	"Brado",
	"Broke",
	"Heller",
	"Kening",
	"Ruks",
	"Raily",
	"Guera"
};



char* getSurename(int i){
	rand();
	return SurenameBase[rand() % 10];
};

char* getName(int i){
	
	rand();
	return NameBase[rand() % 10];
	
};

unsigned long getNumber(int i){
	rand();
	return 80000000000 + rand() % 10000000000;
};

void delete(struct phonebook book[N]){
	printf("Enter the id of the subscriber you want to delete :\n");
	int id;
	scanf("%d", &id);
	strcpy(book[id].name, "0");
	strcpy(book[id].surename, "0");
	book[id].number = 0;	
};

void showAll(struct phonebook book[N]){
	for (int i = 0; i < N; i++){
	printf("%d %s %s %ld\n", book[i].id, book[i].name, book[i].surename, book[i].number);
	}
};

void add(struct phonebook book[N]){
	int id;
	long int number;
	char name[16];
	printf("Enter id what you want to add:\n");
	scanf("%d", &id);
	printf("Enter Name:");
	scanf("%s", book[id].name);
	printf("Enter Surename:");
        scanf("%s", book[id].surename);
	printf("Enter number:");
	scanf("%ld", &number);
        book[id].number = number;

};



int main() {
	
	srand(time(NULL));
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
		book[i].number = getNumber(i);
		printf("%d %s %s %ld\n", book[i].id, book[i].name, book[i].surename, book[i].number);
	}

	delete(book);

	showAll(book);

	add(book);	

	showAll(book);

	return 0;
}
