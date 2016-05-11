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

*/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <map>
#include <tchar.h>

using namespace std;

typedef struct dicionario {
	string artigo_alemao;
	string portugues;
	string ingles;
} DIC;

int main() {	
	ifstream file;
	string filename = "dicionario.txt";	// nome do arquivo
	file.open(filename.c_str());    // abre o arquivo

	int index = 0;			// index do str_chave ou str_buscada
	
	string str_leitura;		// str lida
	string token;			// str lida quebrada em duas
	string str_chave;		// str_chave do map
	string str_buscada;		// str_buscada do map


	DIC d;


	std::map<string, DIC> mapa;
	
	// le dicionario
	while(getline(file, str_leitura)) {

		if(str_leitura.empty()) {
			break;
		}


		stringstream sstr(str_leitura);
		
		while(getline(sstr, token, '#')) {		
			if(index == 0) {		// index == 0 --> str_chave
				str_chave = token;
				index++;
			} else if(index == 1) {				// index == 0 --> str_buscada
				d.artigo_alemao = token;
				index++;
			} else if(index == 2) {
				d.ingles = token;
				index++;
			} else {
				d.portugues = token; 
				mapa.insert(pair<string, DIC>(str_chave, d));
				index = 0;			// zera o index
			}
		}
	}

		
	map<string, DIC>::iterator it;
	
	while(getline(cin, str_leitura)) {
		it = mapa.find(str_leitura);
		
		if(it != mapa.end()) {
			cout << it->second.artigo_alemao << endl;				// achou imprime resultado
			cout << it->second.ingles << endl;				// achou imprime resultado
			cout << it->second.portugues << endl;				// achou imprime resultado
		} else {
			cout << "nao encontrado" << endl;		// nao achou precisa adicionar no dicionario
		}

	}


	file.close(); 		// fecha arquivo

	return 0;
}