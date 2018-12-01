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
const char *_FNAME = "registros.txt";
const char *_ORDEREDNAME = "ordenado.txt";
bool quiet = false;

typedef struct {
	
} Tape;

int cmpfunc (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

// MAIN
int main(int argc,char **argv){
	int tape_qty = 0;
	int mem_cap = 0;

	if (argc < 4) {
		printf("Argumentos insuficientes.\nEx: main arquivo.txt capacidade_de_registros_da_memoria numero_de_fitas");

	} else {
		_FNAME = argv[1];
		sscanf(argv[2], "%d", &mem_cap);
		sscanf(argv[3], "%d", &tape_qty);

		printf ("Arquivo: %s\n"
			    "Registros maximos na memoria: %d\n"
			    "Fitas disponiveis: %d\n\n",
			     _FNAME, mem_cap, tape_qty);
		FILE *d_file = fopen(_FNAME, "r");
		char buffer[4] = "";

		fgets(buffer, sizeof(char) * 4, d_file);		
		qsort(buffer, 3, sizeof(char), cmpfunc);
	}
}
