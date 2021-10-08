/**
*	@file 28-ygdrasil.cpp
*	@brief Resolução do problema "Ygdrasil"
*	@author Lucas Gabriel Teodoro Araújo
*	@date 15/09/2021
*/
#include <stdio.h>
#include <iostream>

using namespace std;

/**Definição da estrutura de nó da árvore*/
struct no{
	char val;		/*< caracter armazenado pelo nó*/
	struct no *esq;	/*< ponteiro para o nó filho da esquerda*/
	struct no *dir;	/*< ponteiro para o nó filho da direita*/
};

/**
void inserir(char v,no *pai)
	Função que insere um novo no em uma árvore de busca binaria

	@param v caractere que será inserido na árvore
	@param pai ponteiro para raiz, ou nó pai, da árvore

*/
void inserir(char v,no *pai){
	if(v<pai->val){
		if(pai->esq==NULL){
			pai->esq = (no*) malloc(sizeof(no));
			pai->esq->val = v;
			pai->esq->esq = NULL;
			pai->esq->dir = NULL;
		}
		else inserir(v,pai->esq);
	}
	else if(v>pai->val){
		if(pai->dir==NULL){
			pai->dir = (no*) malloc(sizeof(no));
			pai->dir->val = v;
			pai->dir->esq = NULL;
			pai->dir->dir = NULL;
		}
		else inserir(v,pai->dir);
	}
}

/**
bool busca(char v,no *pai)
	Função que busca um caracter em uma árvore binaria de busca

	@param v caracter que será buscado na árvore
	@param pai ponteiro para raiz, ou nó pai, da árvore

	@return true, caso encontre o caracter na árvore, false caso contrario

*/
bool busca(char v,no *pai){
	if(v == pai->val)return true;
	else if(pai->esq!=NULL&&v<pai->val)return busca(v,pai->esq);
	else if(pai->dir!=NULL&&v>pai->val)return busca(v,pai->dir);
	else return false;
}

/**
string pre(no *pai)
	Função que retorna uma string contendo a árvore no formato prefixa

	@param pai ponteiro para raiz, ou nó pai, da árvore

	@return árvore no formato prefixo
*/
string pre(no *pai){
	string r="";
	r = pai->val;
	if(pai->esq!=NULL)r+=pre(pai->esq);
	if(pai->dir!=NULL)r+=pre(pai->dir);
	return r;
}
/**
string pre(no *pai)
	Função que retorna uma string contendo a árvore no formato infixa

	@param pai ponteiro para raiz, ou nó pai, da árvore

	@return árvore no formato infixo
*/
string inf(no *pai){
	string r = "";
	if(pai->esq!=NULL)r+=inf(pai->esq);
	r+=pai->val;
	if(pai->dir!=NULL)r+=inf(pai->dir);
	return r;
}

/**
string pos(no *pai)
	Função que retorna uma string contendo a árvore no formato posfixa

	@param pai ponteiro para raiz, ou nó pai, da árvore

	@return árvore no formato posfixo
*/
string pos(no *pai){
	string r="";
	if(pai->esq!=NULL)r+=pos(pai->esq);
	if(pai->dir!=NULL)r+=pos(pai->dir);
	r+=pai->val;
	return r;
}

int main(void){
	no *pai = NULL;	///ponteiro para a rtaiz da árvore
	string s;		///string para leitura
	while(getline(cin,s)){	//lendo até o EOF
		if(s[1]==' '){		//se a segunda posição for um espaço a instrução será um 'I' ou um 'P'
			if(s[0]=='I'){	//se for um 'I'
				if(pai==NULL){	//se ainda não tiver um nó pai criamos um
					pai = (no*)malloc(sizeof(no));
					pai->val = s[2];
					pai->esq = NULL;
					pai->dir = NULL;
				}
				else{	//se já tiver um nó pai chamamos a função para inserir
					inserir(s[2],pai);
				}
			}
			else{	//se não for uma instrução 'I' será um 'P' então usamos função de busca
				if(busca(s[2],pai))printf("%c existe\n",s[2]);
				else printf("%c nao existe\n",s[2]);
			}
		}
		else if(s=="INFIXA"){
			string s = inf(pai);
			for(unsigned int i=0;i<s.size();i++){
				if(i!=0)printf(" ");
				printf("%c",s[i]);
			}
			printf("\n");
		}
		else if(s=="PREFIXA"){
			string s = pre(pai);
			for(unsigned int i=0;i<s.size();i++){
				if(i!=0)printf(" ");
				printf("%c",s[i]);
			}
			printf("\n");
		}
		else if(s=="POSFIXA"){
			string s = pos(pai);
			for(unsigned int i=0;i<s.size();i++){
				if(i!=0)printf(" ");
				printf("%c",s[i]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
