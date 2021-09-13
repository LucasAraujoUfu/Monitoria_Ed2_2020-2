/**
*	@file 21-chaves_magicas.cpp
	@brief resolução do exercicio "Chaves Magicas"
	@author Lucas Gabriel Teodoro Araújo
	@date 31/08/2021
*/
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	char l;							///caracter que será usado na leitura
	string p = "";					///string que servirá de pilha
	bool f = true;					///flag que responde se a integridade da pilha foi mantida
	int n;							///número de linhas no codigo do input
	
	scanf("%d",&n);

	while(scanf("%c",&l)!=EOF){		// lendo caracter por caracter do stdin
		if(l=='{'){					// se for um '{' empilhamos
			p+=l;
		}
		else if(l=='}'){			// se for um '}'
			if(p.size()>0){			// se tiver um '{' para desempilhar, desempilhamos
				p.pop_back();
			}
			else{					// caso contrario a integridade da pilha seria quebrada, logo as chaves estão desbalanceadas
				f=false;
			}
		}
	}
	if(f==false||p.size()>0){		// se a pilha não está integra ou ainda existir chaves abertas as chaves estão desbalanceadas
		puts("N");
	}
	else{							// caso contrario o codigo está com as chaves balanceadas
		puts("S");
	}
	return 0;
}
