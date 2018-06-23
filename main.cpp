#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "../include/Hash.h"
using namespace std;


int main()
{
    Hash chaveHash;
    //cout<<"Digite o tamanho da tabela Hash: "<<endl;
    //int tamanho;
    //cin>>tamanho;
    //chaveHash.setTamanhoTabela(tamanho);
    chaveHash.setTamanhoTabela(10);
    chaveHash.setElementoTabela(15);
    chaveHash.setElementoTabela(16);
    chaveHash.setElementoTabela(17);
    chaveHash.setElementoTabela(25);
    chaveHash.setElementoTabela(27);
    chaveHash.setElementoTabela(35);
    chaveHash.setElementoTabela(2);
    chaveHash.setElementoTabela(12);
    chaveHash.setElementoTabela(22);
    chaveHash.setElementoTabela(32);
    chaveHash.mostrarTabela();
    chaveHash.excluir(2);
    chaveHash.mostrarTabela();
    chaveHash.excluir(15);
    chaveHash.mostrarTabela();
    chaveHash.excluir(32);
    chaveHash.mostrarTabela();






//    if(chaveHash.buscarElemento(5)){
//        cout<<"Encontrado"<<endl;
//    }else{
//        cout<<"Não encontrado"<<endl;
//    }
//    if(chaveHash.buscarElemento(4)){
//        cout<<"Encontrado"<<endl;
//    }else{
//        cout<<"Não encontrado"<<endl;
//    }

//    if(chaveHash.excluir(2)){
////        cout<<"Excluido"<<endl;
////    }else{
////        cout<<"Não excluído"<<endl;
////    }
////    chaveHash.mostrarTabela();

//   char sair = ' ';
//   while(sair !='s'){
//    cout<<"Insira um Elemento na tabela Hash: "<<endl;
//    int elemento;
//    cin>>elemento;
//    chaveHash.setElementoTabela(elemento);
//    chaveHash.mostrarTabela();
//
//    cout<<"Sair?s/n: "<<endl;
//    cin>>sair;
//   }

}
