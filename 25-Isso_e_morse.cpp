/**
*	@file 
*	@brief Resolução do problema "Isso é morse?"
*	@author Lucas Gabriel Teodoro Araújo
*	@date 27/08/2021
*/
#include <stdio.h>
#include <iostream>
#include <map>																				/// classe que implementa o map(ou dicionario)

using namespace std;

int main(void){
	map<string,char> M;																		/// Mapa para quardar a cifra de cada letra
	
	M["=.==="]='a';M["===.=.=.="]='b';M["===.=.===.="]='c';M["===.=.="]='d';
	M["="]='e';M["=.=.===.="]='f';M["===.===.="]='g';M["=.=.=.="]='h';M["=.="]='i';
	M["=.===.===.==="]='j';M["===.=.==="]='k';M["=.===.=.="]='l';M["===.==="]='m';
	M["===.="]='n';M["===.===.==="]='o';M["=.===.===.="]='p';M["===.===.=.==="]='q';
	M["=.===.="]='r';M["=.=.="]='s';M["==="]='t';M["=.=.==="]='u';M["=.=.=.==="]='v';
	M["=.===.==="]='w';M["===.=.=.==="]='x';M["===.=.===.==="]='y';M["===.===.=.="]='z';	/// preenchendo o mapa com a tradução de cada letra

	int n;																					///número de casos de teste

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		string s,k="";																		//string para leitura e string auxiliar, para guardar o caracter cifrado
		int ct=0;																			//contador de '.'(pontos)
		cin>>s;																				//ler a string em morse
		for(unsigned int j=0;j<s.size();j++){												//percorrendo a string cifrada
			if(s[j]=='.')ct++;																//se for um ponto adicionamos ele ao contador
			else{																			//se não for um ponto
				if(ct>=3){																	//se tivermos mais de 3 pontos printamos o caracter na descoberto antes da seraparação de caracter
					printf("%c",M[k]);
					k="";																	//resetamos a string auxiliar
				}
				else if(ct==1)k+='.';														//se só tiver um ponto adicionamos ela à string auxiliar 
				if(ct==7)printf(" ");														//se forem 7 espaços alem de printar o caracter na string auxiliar printamos um espaço

				ct=0;																		//zeramos o contador de espaços
				k+= s[j];																	//adicionamos o caracter na string auxiliar
			}
		}
		printf("%c\n",M[k]);																// ao final precisamos printar o ultimo caracter da string em morse
	}
	return 0;
}
