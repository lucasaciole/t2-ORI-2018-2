/*
[ Trabalho ORI - T1 2018/11/07 ]
	Autores:
		743571 - Luiz Guilherme Duarte
		726578 - Pedro Henrique Lara Campos
		619680 - Lucas Yuji Aciole
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// Globais
const char *_ORDEREDFNAME = "ordenado.txt";
bool quiet = false;

typedef struct titem {
	char * value;
	struct titem  *next;
} TapeItem;

int cmpfunc (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

void add_block_on_tape(TapeItem* tapes, int tape_number, char * block) {
	TapeItem *tape = malloc(sizeof(TapeItem));
	strcpy(tape->value, block);
	//TODO
}

// MAIN
int main(int argc,char **argv){
	char * filename;
	int tape_qty = 0;
	int mem_cap = 0;

	if (argc < 4) {
		printf("Argumentos insuficientes.\nEx: main arquivo.txt capacidade_de_registros_da_memoria numero_de_fitas");

	} else {
		filename = argv[1];
		sscanf(argv[2], "%d", &mem_cap);
		sscanf(argv[3], "%d", &tape_qty);

		printf ("Arquivo: %s\n"
			    "Registros maximos na memoria: %d\n"
			    "Fitas disponiveis: %d\n\n",
			     filename, mem_cap, tape_qty);

		TapeItem *tapes = malloc(sizeof(TapeItem) * tape_qty);

		FILE *d_file = fopen(filename, "r");
		int buffer_size = (mem_cap + 1);
		char *buffer = malloc(sizeof(char) * buffer_size);
		printf(buffer);
		int tape_number = 0;

		while (fgets(buffer, sizeof(char) * mem_cap, d_file) != NULL) {
			qsort(buffer, mem_cap, sizeof(char), cmpfunc);
			//add_block_on_tape(tapes, tape_number, buffer);
			tape_number = tape_number++ % tape_qty;
		}
	}
}
