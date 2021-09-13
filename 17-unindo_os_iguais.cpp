/**
* @file 17-unindo_os_iguais.cpp
* @brief resolução do problema "Unindo os iguais"
* @author Lucas Gabriel T. Araújo
* @date 10/07/2021
*/

#include <iostream>
#include <stdio.h>
#include <vector> //importação da classe vector do c++ que traz algumas funções para manipular o vetor

#define INF 1000000 //valor que consideraremos como infinito

using namespace std;

/**
int merge_sort(vector<int> &v)
	
	Função de ordenação estável tipo merge sort.
	A funçaõ ordena os valores de v direto no vetor e retorna o número de inversões feitas durante a ordenação.

	@param v vetor da classe vector passado por referência para ser ordenado

	@return valor inteiro, quantidade de inversões entre os valores desordenados 
*/
int merge_sort(vector<int> &v){
	
	if(v.size()==1)return 0; //se o tamanho do vetor for 1 então ele já está ordenado
	
	int inv = 0; ///contador de inversões

	vector<int> u1,u2; //vetores auxiliares
	
	///u1 é o vetor da esquerda [0,v.size()/2[
	///u2 é o vetor da direita [v.size()/2,v.size()-1]
	
	for(unsigned i=0;i<v.size()/2;i++)u1.push_back(v[i]); //preenchendo o vetor auxiliar da esquerda
	for(unsigned i=v.size()/2;i<v.size();i++)u2.push_back(v[i]); //preenchendo o vetor auxiliar da direita

	inv += merge_sort(u1); //recursão para ordenar o vetor auxiliar da esquerda e adicionar as inversões ao contador de inversões
	inv += merge_sort(u2); //recursão para ordenar o vetor auxiliar da direita e adicionar as inversões ao contador de inversões

	//adicinando "infinito" ao final de cada vetor auxiliar (agora  já ordenados) para evitar segmentation fail* 
	u1.push_back(INF);
	u2.push_back(INF);

	int _1=0,_2=0; ///variáveis auxiliares para gerenciar as posições de "inicio" dos vetores auxiliares durante o join

	for(unsigned i=0;i<v.size();i++){ //join
		//verificar se o menor valor está na direita ou na esquerda
		if(u1[_1]<u2[_2]){ // se o menor valor está na esquerda simplesmente colocamos o valor no vetor original na posição i  e somamos (+1) na variável auxiliar
			v[i] = u1[_1];
			_1++;
		}
		else{ //caso contrario também colocamos o valor na posição i do vetor original e somamos (+1) na variável auxiliar, nesse caso contamos as inversões
			v[i] = u2[_2];
			_2++;
			inv += u1.size() - _1 - 1; //o valor em u2[_t] está invertido em relação à todas as posições não percorridas do vetor u1 
		}
	}

	return inv;
} //merge_sort

int main(void){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	int r = merge_sort(v);
	printf("%d\n",r);
	return 0;
}//main

