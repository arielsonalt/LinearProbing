#ifndef HASH_H
#define HASH_H
#include<iostream>
#include<stdio.h>

using namespace std;


class Hash
{
private:
    int tamanhoTabela;
    int tabela[];
public:
    Hash();
    int getTamanhoTabela();
    int getElemento(int index);
    int* getTabela();
    void setTamanhoTabela(int inteiro);
    void setElementoTabela(int inteiro);
    void excluirElemento();
    int buscarElemento(int inteiro);
    void mostrarTabela();
    int excluir(int inteiro);
    int posicaoExclusao(int key,int inteiro);
};

#endif // HASH_H
