/*
[ Trabalho ORI - T1 2018/11/07 ]
	Autores:
		743571 - Luiz Guilherme Duarte
		726578 - Pedro Henrique Lara Campos
		619680 - Lucas Yuji Aciole
*/

// Usando a Ordenação Balanceada de Varios Caminhos com (num_fitas - 1) fitas

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

bool insert (TapeItem *base, TapeItem *new_node) {
	while (base->next != NULL) {
		base = base->next;
	}

	base->next = new_node;
	return true;
}

void add_block_on_tape(TapeItem** tapes, int tape_number, char * block, int block_size) {	
	TapeItem *new_block = malloc(sizeof(TapeItem));
	new_block->next = NULL;
	new_block->value = malloc(sizeof(char) * block_size);
	memcpy(new_block->value, block, block_size);

	if (tapes[tape_number] == NULL) {
		tapes[tape_number] = new_block;
	} else {		
		insert(tapes[tape_number], new_block);
	}

}

void print_tapes(TapeItem **tapes, int tape_qty) {
	TapeItem * buffer;
	for (int i = 0; i< tape_qty; i++) {
		buffer = tapes[i];
		printf("Fita #%d : ", i);
		if (buffer == NULL) {
			printf("\n");
			continue;
		} else {			
			printf("%s", buffer->value);
			while (buffer->next != NULL) {
				buffer = buffer->next;
				printf(" %s", buffer->value);
			};
			printf("\n");
		}
	}
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

		int tape_number = 0;
		TapeItem **tapes = malloc(sizeof(TapeItem *) * tape_qty);

		// Initialize tapes as empty;
		for (int i = 0; i < tape_qty; i++) {
			tapes[i] = NULL;
		}


		// Open file and setup buffer size equal to memory size
		FILE *d_file = fopen(filename, "r");
		int buffer_size = (mem_cap + 1);
		char *buffer = malloc(sizeof(char) * buffer_size);

		// Populate tapes with all entries found on file; We're using tape_qty - 1 in this phase
		while (fgets(buffer, sizeof(char) * buffer_size, d_file) != NULL) {
			qsort(buffer, mem_cap, sizeof(char), cmpfunc);
			add_block_on_tape(tapes, tape_number, buffer, buffer_size);
			tape_number = (tape_number + 1) % (tape_qty - 1);
		};

		// Print intermediate step
		print_tapes(tapes, tape_qty);




		printf("Done.\n");
	}
}
