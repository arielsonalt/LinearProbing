#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <locale>
#include "../include/Hash.h"
using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");
    Hash chaveHash;
    int tamanho;
    do
    {
        cout<<"Digite o tamanho da tabela Hash: "<<endl;
        cin>>tamanho;
    }
    while(tamanho<=0);
    chaveHash.setTamanhoTabela(tamanho);

    int sair = 0;
    while(sair !=4)
    {

        cout<<""<<endl;
        cout<<""<<endl;
        chaveHash.mostrarTabela();
        cout<<""<<endl;
        cout<<""<<endl;

        cout<<"                             _______________________LINEAR PROBING______________________"<<endl;
        cout<<"                             ***********************************************************"<<endl;
        cout<<"                             ***********************************************************"<<endl;
        cout<<"                             *                                                         *"<<endl;
        cout<<"                             *   1-> ADICIONAR ELEMENTO                                *"<<endl;
        cout<<"                             *   2-> PESQUISAR ELEMENTO                                *"<<endl;
        cout<<"                             *   3-> EXCLUIR ELEMENTO                                  *"<<endl;
        cout<<"                             *                                             4 -> SAIR   *"<<endl;
        cout<<"                             ***********************************************************"<<endl;
        cout<<"                             ***********************************************************"<<endl;
        cout<<"                                                     OPÇÃO: ";
        cin>>sair;
        cout<<""<<endl;

        if(sair == 1)
        {
            cout<<"Adicionar -> Digite o elemento: "<<endl;
            int elemento;
            cin>>elemento;
            chaveHash.setElementoTabela(elemento);
            system("cls");
        }
        else if(sair == 2)
        {
            cout<<"Pesquisa -> Digite o elemento: "<<endl;
            int elemento;
            cin>>elemento;
            if(chaveHash.buscarElemento(elemento))
            {
                cout<<"Elemento "<<elemento<<" encontrado"<<endl;
                system("pause");
            }
            else
            {
                cout<<"Elemento "<<elemento<<" não encontrado"<<endl;
                system("pause");
            }
            system("cls");
        }
        else if(sair == 3)
        {
            cout<<"Excluir -> Digite o elemento: "<<endl;
            int elemento;
            cin>>elemento;
            if(chaveHash.excluir(elemento))
            {
                cout<<"Elemento "<<elemento<<" excluído"<<endl;
                system("pause");
            }
            else
            {
                cout<<"Elemento "<<elemento<<" não encontrado"<<endl;
                system("pause");
            }
            system("cls");
        }
        else
        {
            system("cls");
        }


    }

}
