#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <map>

using namespace std;
/*
typedef struct dicionario {
	string chave;
	string genero_alemao;
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
		printf("----------------------------\nch:%s\nart:%s\npt:%s\nen:%s\n----------------------------", d.chave, d.genero_alemao, d.portugues, d.ingles);		
	}

	fclose(arq); 		// fecha arquivo

	return 0;
}

*/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <map>

#define PORTUGUES 1
#define INGLES 2
#define ALEMAO 3

using namespace std;

typedef struct dicionario {
	string genero_alemao;
	string genero_portugues;
	string portugues;
	string ingles;
	string alemao;
} DIC;

int main() {	
	ifstream file;
	string filename = "dicionario.txt";	// nome do arquivo
	file.open(filename.c_str());    // abre o arquivo
	int index = 0;			// index do str_chave ou str_buscada
	int op;

	string str_leitura;		// str lida
	string token;			// str lida quebrada em duas
	string lixo;		
	string str_buscada;		// str_buscada do map


	DIC d;

	std::map<string, DIC> mapa;
	
	printf("-------------------\n");
	printf("Idioma de busca\n");
	printf("-------------------\n");
	printf("1 - Portugues\n");
	printf("2 - Ingles\n");
	printf("3 - Alemao\n");
	printf("-------------------\n");

	cin >> op;
	
	// le dicionario
	while(getline(file, str_leitura)) {

		if(str_leitura.empty()) {
			break;
		}


		stringstream sstr(str_leitura);
		
		while(getline(sstr, token, '#')) {	
			if(index == 0) {		// index == 0 --> str_chave
				d.genero_portugues = token; 
				index++;
			} else if(index == 1) {
				d.portugues = token;
				index++;
			} else if(index == 2) {				// index == 0 --> str_buscada
				d.genero_alemao = token;
				index++;
			} else if(index == 3) {
				d.alemao = token;
				index++;
			} else if(index == 4) {
				d.ingles = token;
				if(op == PORTUGUES) {
					mapa.insert(pair<string, DIC>(d.portugues, d));
				} else if(op == INGLES) {
						mapa.insert(pair<string, DIC>(d.ingles, d));
				} else if(op == ALEMAO) {
						mapa.insert(pair<string, DIC>(d.alemao, d));		
				}
 				index = 0;			// zera o index
			}
		}
	}

		
	map<string, DIC>::iterator it;

	getline(cin, lixo);
	
	printf("-------------------\n");
	printf("Buscar: ");
	while(getline(cin, str_leitura)) {

	printf("-------------------\n");
		it = mapa.find(str_leitura);
		
		if(it != mapa.end()) {
			if(op != PORTUGUES) {
				cout << "(" << it->second.genero_portugues << ") ";				// achou imprime resultado
				cout << it->second.portugues << endl;				// achou imprime resultado
			}
			if(op != ALEMAO) {
				cout << "(" << it->second.genero_alemao << ") ";				// achou imprime resultado
				cout << it->second.alemao << endl;				// achou imprime resultado
			}
			if(op != INGLES) {
				cout << it->second.ingles << endl;				// achou imprime resultado
			}
		} else {
			cout << "nao encontrado" << endl;		// nao achou precisa adicionar no dicionario
		}

		printf("-------------------\n");
	}


	file.close(); 		// fecha arquivo

	return 0;
}