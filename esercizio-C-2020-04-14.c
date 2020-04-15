/*
riprendiamo l'esercizio esercizio-C2020-04-03
https://github.com/marcotessarotto/esercizio-C-2020-04-03

***
è dato il tipo dati contact_type, dovrebbe servire ad implementare una rubrica telefonica molto semplice:

#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

sono già date le seguenti funzioni (riutilizzare quelle già sviluppate):

// crea un oggetto di tipo contact_type e lo inizializza con name e phone
contact_type * create_contact(char * name, char * phone);

// scrive su stdout i contenuti dell'oggetto
void print_contact(contact_type * person);

******

scrivere le seguenti nuove funzioni e variabili:

#define ADDRESS_BOOK_SIZE 256

// la rubrica telefonica contiene al massimo 256 nominativi
contact_type * address_book[ADDRESS_BOOK_SIZE]; // global variable
// è un array di puntatori a contact_type
// se address_book[i] == NULL, vuole dire che la cella è utilizzabile per conservare l'indirizzo di un contatto


// confronta due contatti:
// due contatti sono uguali se e solo se c1->name è uguale a c2->name e c1->phone è uguale a c2->phone
// return value:
// 0: contatti uguali
// < 0: se *c1 è ordinato prima di *c2
// > 0: se *c1 è ordinato dopo di *c2
// ovvero FATE COME FA STRCMP (vedete man strcmp)
// NOTA BENE: se c1 == NULL or c2 == NULL, restituisce -1
int compare_contacts(contact_type * c1, contact_type * c2);


// aggiunge il contatto c all'array address_book array
// la funzione NON controlla se il contatto è già presente; ma cerca la prima cella libero nell'array
// return value:
// >=0: posizione nell'array address_book dove è stato inserito c
// -1: errore (i.e. non c'è più spazio in address_book o c == NULL)
int add_to_address_book(contact_type * c);

// rimuovi il contatto c da address_book (setta a NULL la posizione dove si trova c)
// return value:
// >= 0: posizione dove si trovava c
// -1: non ho trovato c, quindi non ho cancellato nessun contatto
int remove_from_address_book(contact_type * c);


// cerca il contatto c nell'array address_book
// cercare un contatto: confronta c con ogni contatto memorizzato in address_book
// DOVETE USARE compare_contacts()
// return value:
// >= 0: posizione dove si trova il primo contatto uguale a c
// -1: contatto c non trovato
int search_in_address_book(contact_type * c);


// funzione che fa il sort dei contatti in address_book, utilizzando compare_contacts()
void sort_by_name();


scrivete un main() faccia le cose seguenti:

1 - creare gli oggetti di tipo contact_type a partire dai seguenti nominativi e numeri di telefono
ed inserirli in address_book utilizzando la funzione add_to_address_book

creare ed inserire in rubrica i contatti in questo ordine:

"dino","+391237"
"filippo", "+391239"
"barbara","+391235"
"antonio","+391234"
"enrico","+391238"
"chiara","+391236"

2 - cercare il contatto "antonio","+391234"
e se trovato, rimuoverlo

3 - creare ed aggiungere il contatto "pino","+399999"
e scrivere a video tutta la rubrica telefonica (non le celle vuote)

4 - aggiungere di nuovo dil contatto "antonio","+391234"

5 - fare il sort di tutta la rubrica

6 - scrivere a video tutta la rubrica telefonica (non le celle vuote)
il risultato deve essere ordinato

FINE */




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20
#define ADDRESS_BOOK_SIZE 256

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

contact_type * create_contact(char * name, char * phone);
void print_contact(contact_type * person);
int compare_contacts(contact_type * c1, contact_type * c2);
int add_to_address_book(contact_type * c);
int remove_from_address_book(contact_type * c);
int search_in_address_book(contact_type * c);
void sort_by_name();

int IDused = 0;
int size = 1;

contact_type * address_book[ADDRESS_BOOK_SIZE];
// è un array di puntatori a contact_type
// se address_book[i] == NULL, vuole dire che la cella è utilizzabile per conservare l'indirizzo di un contatto


int main(int argc, char *argv[]) {
	// [ 1 ]
	printf(" [ 1 ] \n");
	contact_type *dino = create_contact("dino", "+391237");
	add_to_address_book(dino);
	print_contact(dino);

	contact_type *filippo = create_contact("filippo", "+391239");
	add_to_address_book(filippo);
	print_contact(filippo);

	contact_type *barbara = create_contact("barbara", "+391235");
	add_to_address_book(barbara);
	print_contact(barbara);

	contact_type *antonio = create_contact("antonio", "+391234");
	add_to_address_book(antonio);
	print_contact(antonio);

	contact_type *enrico = create_contact("enrico", "+391238");
	add_to_address_book(enrico);
	print_contact(enrico);

	contact_type *chiara = create_contact("chiara", "+391236");
	add_to_address_book(chiara);
	print_contact(chiara);
	printf("\n\n");

	// [ 2 ]
	printf(" [ 2 ] \n");
	if(search_in_address_book(antonio) != -1){
		remove_from_address_book(antonio);
	}
	printf("\n\n");


	// [ 3 ]
	printf(" [ 3 ] \n");
	contact_type *pino = create_contact("pino", "+399999");
	add_to_address_book(pino);
	print_contact(pino);

	printf("\n");

	for(int i=0; i<ADDRESS_BOOK_SIZE; i++){
		if(address_book[i] != NULL){
			printf("ID: %d, Nome: %s, Telefono: %s\n", address_book[i]->id, address_book[i]->name, address_book[i]->phone);
		}
	}
	printf("\n\n");


	// [ 4 ]
	printf(" [ 4 ] \n");
	antonio = create_contact("antonio", "+391234");
	add_to_address_book(antonio);
	print_contact(antonio);
	printf("\n\n");


	// [ 5 ]	SORT
	printf(" [ 5 ] \n");
	printf("\n\n");


	// [ 6 ]	OUTPUT ORDINATO
	printf(" [ 6 ] \n");
	printf("\n\n");


	return 0;
}


// crea un oggetto di tipo contact_type e lo inizializza con name e phone
contact_type * create_contact(char * name, char * phone){
	contact_type *user = calloc(size, sizeof(contact_type));

	user[size-1].id = IDused;
	memcpy(user[size-1].name, name, (NAME_LEN + 1) * sizeof(char));
	memcpy(user[size-1].phone, phone, (PHONE_LEN + 1) * sizeof(char));

	IDused++;

	return user;
}


// scrive su stdout i contenuti dell'oggetto
void print_contact(contact_type * person){
	printf("person: id=%d, name='%s', phone='%s'\n", person->id, person->name, person->phone);
}


// confronta due contatti
int compare_contacts(contact_type * c1, contact_type * c2){
	if((c1 == NULL) || (c2 == NULL)){
		return -1;
	}

	if((c1->name == c2->name) && (c1->phone == c2->phone)){
		return 0;
	}

	if(c1->id < c2->id){
		return -2;
	}

	if(c1->id > c2->id){
		return 2;
	}

	return 1;
}

// aggiunge il contatto c all'array address_book array
int add_to_address_book(contact_type * c){
	int control = -1;

	if(c == NULL){
		printf("ERRORE: Il contatto che si vuole inserire è nullo\n");

		return -1;
	}

	for(int i=0; i<ADDRESS_BOOK_SIZE; i++){
		if(address_book[i] == NULL){
			address_book[i] = c;
			control = i;
			break;
		}
	}

	if(control == -1){
		printf("ERRORE: Non c'è più spazio nell'array\n");

		return -1;
	}
	else{
		printf("Contatto inserito alla posizione %d\n", control);

		return control;
	}
}

// rimuovi il contatto c da address_book (setta a NULL la posizione dove si trova c)
int remove_from_address_book(contact_type * c){
	for(int i=0; i<ADDRESS_BOOK_SIZE; i++){
		if(address_book[i] == c){
			address_book[i] = NULL;
			printf("Il contatto è stato eliminato con successo!\n");
			return i;
		}
	}

	printf("Non è stato possibile rimuovere il contatto perchè non è statp trovato nell'elenco\n");

	return -1;
}

// cerca il contatto c nell'array address_book
int search_in_address_book(contact_type * c){
	for(int i=0; i<ADDRESS_BOOK_SIZE; i++){
		if(compare_contacts(address_book[i], c) == 0){
			return i;
		}
	}

	printf("Il contatto richiesto non è stato trovato nell'elenco\n");

	return -1;
}


// funzione che fa il sort dei contatti in address_book, utilizzando compare_contacts()
void sort_by_name(){

}
