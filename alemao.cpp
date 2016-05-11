#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <map>

using namespace std;


typedef struct dicionario {
	string chave;
	string artigo_alemao;
	string portugues;
	string ingles;
} DIC;

int main() {	
	FILE *arq = fopen("dicionario.bin", "rb");
	
	if(arq == NULL) {
		return 1;
	}

	

	DIC d;
	if(!feof(arq)) {
		fread(&d, 1, sizeof(DIC), arq);
		printf("----------------------------\nch:%s\nart:%s\npt:%s\nen:%s\n----------------------------", d.chave, d.artigo_alemao, d.portugues, d.ingles);		
	}

	fclose(arq); 		// fecha arquivo

	return 0;
}
