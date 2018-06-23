#include "Hash.h"
#include<iostream>
#include<stdio.h>
#include <math.h>
#include <ctype.h>
using namespace std;
Hash::Hash()
{

}
int posicaoExclusao(int key);
int Hash::getTamanhoTabela()
{

    return tamanhoTabela;
}


int* Hash::getTabela()
{
    return tabela;
}

void Hash::setTamanhoTabela(int inteiro)
{
    tamanhoTabela = inteiro;
    for(int i=0; i<tamanhoTabela; i++)
    {
        tabela[i]=NULL;
    }
}

void Hash::setElementoTabela(int inteiro)
{
    int chave;
    chave = inteiro%tamanhoTabela;
    if(tabela[chave] == NULL)
    {
        tabela[chave] = inteiro;
    }
    else
    {
        int cont=0;
        for(int j=chave+1; j<tamanhoTabela; j++)
        {
            if(tabela[j]== NULL)
            {
                tabela[j]=inteiro;
                cont++;
                break;
            }
            if(j==tamanhoTabela-1)
            {
                for(int k=0; k<chave; k++)
                {
                    if(tabela[k]==NULL)
                    {
                        tabela[k]=inteiro;
                        cont++;
                        break;
                    }
                }
                if(cont==0)
                {
                    cout<< "Tabela Hash cheia"<<endl;
                }
            }
        }
    }

}

void Hash::excluirElemento()
{

}

int Hash::buscarElemento(int inteiro)
{
    int chave;
    chave = inteiro%tamanhoTabela;
    for(int i=chave; i<tamanhoTabela; i++)
    {
        if(tabela[i]==NULL)
        {
            break;
        }
        if(tabela[i]==inteiro)
        {
            return 1;
        }
    }
    for(int j=0; j<chave; j++)
    {
        if(tabela[j]==NULL)
        {
            break;
        }
        if(tabela[j]==inteiro)
        {
            return 1;
        }
    }

    return 0;
}
void Hash::mostrarTabela()
{
    int *tabela2;
    tabela2 = getTabela();
    for(int i=0; i<getTamanhoTabela(); i++)
    {
        cout<<tabela2[i]<<" - ";
    }
    cout<<" "<<endl;
}
int Hash::excluir(int inteiro)
{
    int chave;
    chave = inteiro%tamanhoTabela;

    if(buscarElemento(inteiro))
    {
        int posicao = posicaoExclusao(chave,inteiro);
        int controle = posicao+1;
        int cont=0;
        while(controle<=tamanhoTabela-1)
        {

            if((tabela[controle] % tamanhoTabela) == chave)
            {
                if(tabela[controle-1]==NULL)
                {
                    tabela[controle-1]=tabela[controle];
                    tabela[controle]=NULL;
                }
                else
                {
                    for(int j=controle-1; j>=posicao; j--)
                    {

                        if(tabela[j]==NULL && tabela[j+1]!=NULL)
                        {
                            tabela[j]=tabela[controle];
                            tabela[controle] =NULL;
                        }
                    }
                }
            }
            controle++;
        }
        cont=0;
        while(cont<(tabela[posicao]%tamanhoTabela))
        {
            if((tabela[cont] % tamanhoTabela) == chave)
            {
                if(tabela[cont-1]==NULL)
                {
                    tabela[cont-1]=tabela[cont];
                    tabela[cont]=NULL;
                }
                else if((cont -1) == -1)
                {
                    if(tabela[tamanhoTabela-1]==NULL)
                    {
                        tabela[tamanhoTabela-1]=tabela[cont];
                        tabela[cont]=NULL;
                    }
                    else
                    {
                        int aux2=tamanhoTabela-1;
                        while(aux2 > posicao && tabela[aux2] != NULL)
                        {

                            if(tabela[aux2-1]==NULL)
                            {
                                tabela[aux2-1]=tabela[cont];
                                tabela[cont]=NULL;
                            }
                            aux2--;
                        }
                    }
                }
                else if(tabela[cont-1]!=NULL)
                {
                    int cont2 =cont;
                    int encontrou =0;
                    while(cont2>=0)
                    {
                        if(tabela[cont2]==NULL)
                        {
                            tabela[cont2]=tabela[cont];
                            tabela[cont2]=NULL;
                            encontrou=1;
                            break;
                        }

                        cont2--;
                    }
                    if(encontrou == 0)
                    {
                        cont2=tamanhoTabela-1;
                        while(cont2>posicao)
                        {
                            if(tabela[cont2]==NULL)
                            {
                                tabela[cont2]=tabela[cont];
                                tabela[cont]=NULL;
                                encontrou =1;
                            }
                            cont2--;
                        }
                        if(encontrou==0)
                        {
                            cout<<"Tabela Hash cheia"<<endl;
                        }
                    }

                }

            }
            cont++;
        }
    }
}
int Hash::posicaoExclusao(int key, int inteiro)
{
    for(int i=key; i<tamanhoTabela; i++)
    {
        if(tabela[i]==NULL)
        {
            break;
        }
        if(tabela[i]==inteiro)
        {
            tabela[i]=NULL;
            return i;
        }
    }
    for(int j=0; j<key; j++)
    {
        if(tabela[j]==NULL)
        {
            break;
        }
        if(tabela[j]==inteiro)
        {
            tabela[j]=NULL;
            return j;
        }
    }
}






