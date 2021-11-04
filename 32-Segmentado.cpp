/**
*	@file 32-Segmentado.cpp
*	@brief Resolução do problema "Segmentado"
*	@author Lucas Gabriel Teodoro Araújo
*/
#include <bits/stdc++.h>
 
#define MAXN 1000005 ///Constante número maximo de nós na arvore de indexação binaria
 
using namespace std;
 
int n; ///número de folhas na BIT
unsigned long long int bit[MAXN]; ///Estrutura de dados que qurdará a árvore
 
/**
void add(int k,unsigned long long int x)
  função que adiciona um valor a um nó folha e propaga a atualização na árvore
  
   @param k inteiro posição do nó folha que receberá o update
   @param x valor que será somado à posição k
   
*/
void add(int k,unsigned long long int x){
	while(k<=n){
		bit[k]+=x;
		k += k&-k;
	}
}
 
/**
unsigned long long int sum(int k)
  Função que retorna a range query dos nós folha do intervalo [1,k]
  
  @param k ultima posição do range que será somada na query
  
  @return soma dos valores das posições entre 1 e k inclusive
  
*/
unsigned long long int sum(int k){
	unsigned long long int s=0;
	while(k>=1){
		s+=bit[k];
		k-=k&-k;
	}
	return s;
}
 
int main(void){
	int m; ///número de querys que serão realizadas na árvore
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){ //lendo o valor dos nós folha e montando a árvore
		unsigned long long int l;
		scanf("%llu",&l);
		add(i,l); //utilizamos o add para construir a BIT
	}
	for(int i=0;i<m;i++){ //fazendo as querys
		int l,r; ///inicio do intervalo e final do intervalo respectivamente
		scanf("%d%d",&l,&r);
		unsigned long long int res = sum(r)-sum(l-1); //subtraimos [0,(l-1)] de [0,r] para obter [l,r] 
		printf("%llu\n",res);
	}
	return 0;
}
