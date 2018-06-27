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
        for(int j=chave; j<tamanhoTabela; j++)
        {
            if(tabela[j]== NULL)
            {
                tabela[j]=inteiro;
                cont++;
                break;
            }
            else if(j==tamanhoTabela-1)
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

    // Verifica se existe o número que será excluído
    if(buscarElemento(inteiro))
    {
        //guarda a posição do numero que será excluido
        int posicao = posicaoExclusao(chave,inteiro);

        //guarda a posição seguinte a posição da exclusão
        int controle = posicao+1;
        int cont=0;

        if(posicao < chave)
        {
            while(controle < chave)
            {
                // se o numero seguinte a posição de exclusão é da mesma chave que o numero excluído
                if((tabela[controle] % tamanhoTabela) == chave)
                {
                    // se a posição de exclusão está vazia
                    if(tabela[controle-1]==NULL)
                    {
                        //move o numero seguinte a exclusão para uma posição anterior
                        tabela[controle-1]=tabela[controle];
                        tabela[controle]=NULL;
                    }

                }
                controle++;
            }
            return 1;
        }

        // enquanto a posição seguinte a exclusão for menor que o tamanho do vetor menos 1
        // percorre o vedor da posição seguinte da exclusão até o fim do vetor
        while(controle<=tamanhoTabela-1)
        {
            // se o numero seguinte a posição de exclusão é da mesma chave que o numero excluído
            if((tabela[controle] % tamanhoTabela) == chave)
            {
                // se a posição de exclusão está vazia
                if(tabela[controle-1]==NULL)
                {
                    //move o numero seguinte a exclusão para uma posição anterior
                    tabela[controle-1]=tabela[controle];
                    tabela[controle]=NULL;
                }
                else
                {
                    // da posição atual até a posição da chave
                    for(int j=controle-1; j>=posicao; j--)
                    {
                        // se um local estiver NULL e a posição seguinte a essa for não NULL
                        // então este local é o imediatamente vazio após posições ocupadas
                        if(tabela[j]==NULL && tabela[j+1]!=NULL)
                        {
                            // adiciono no local vazio encontrado o numero de chave correspondente
                            // a chave da exclusão
                            tabela[j]=tabela[controle];
                            tabela[controle] =NULL;
                        }
                    }
                }
            }
            controle++;
        }

        // Após varrer o vetor para a direita o algorítmo deve verificar
        // as posições do lado oposto do vetor até antes a posição da chave
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
                    int cont2 = cont;
                    int encontrou =0;
                    while(cont2>=0 && cont2 != chave)
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

        return 1;

    }
    else
    {
        return 0;
    }
}
int Hash::posicaoExclusao(int key, int inteiro)
{
    // Encontra o numero e o exclui
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






