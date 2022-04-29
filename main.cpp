//
//  main.cpp
//  F4_Queue_Node
//
//  Created by Eduardo Bouhid Neto on 11/09/21.
//

#include <iostream>
#include "Fila.hpp"

using namespace::std;

void imprime(Fila* f);
void inverte(Fila* f);

int main(int argc, const char * argv[]) {
    //Declarações iniciais
    char x;
    bool deuCerto;
    //Criando uma fila
    Fila* f1 = new Fila();
    
    //Manipulado a fila
    int controle = 0;
    while (controle != 4) {
        cout << "O que deseja fazer?" << endl;
        cout << "1. Adicionar um elemento na fila" << endl;
        cout << "2. Remover um elemento da fila" << endl;
        cout << "3. Inverter a fila" << endl;
        cout << "4. Encerrar a manipulação" << endl;
        cin >> controle;
        switch (controle) {
            case 1:
                cout << "Informe o elemento que deseja adicionar: ";
                cin >> x;
                f1->Insere(f1, x, &deuCerto);
                if (deuCerto) {
                    cout << "Insercao realizada com sucesso" << endl;
                } else {
                    cout << "Erro; Fila cheia" << endl;
                }
                break;
            case 2:
                f1->Retira(f1, &x, &deuCerto);
                if (deuCerto) {
                    cout << "O elemento retirado foi: " << x << endl;
                } else {
                    cout << "Erro; Fila vazia" << endl;
                }
                break;
            case 3:
                inverte(f1);
                break;
            case 4:
                cout << "Encerrando a manipulacao." << endl;
                break;
            default:
                cout << "Comando invalido." << endl;
                break;
        }
        cout << "A fila encontra-se assim:" << endl;
        imprime(f1);
    }
}
    
/*Funções não-primitivas*/
void imprime (Fila* f)
{
    char x;
    bool deuCerto;
    Fila* filaAux = new Fila();
    
    f->Retira(f, &x, &deuCerto);
    if (deuCerto) {
        cout << "(COMECO) ";
        while (deuCerto) {
            /*Guardando os elementos da fila apontada por f na fila
             apontada por "filaAux"*/
            filaAux->Insere(filaAux, x, &deuCerto);
            cout << x << " ";
            f->Retira(f, &x, &deuCerto);
        }
        cout << "(FIM)" << endl;
        /*Reinserindo os elementos em "f"*/
        filaAux->Retira(filaAux, &x, &deuCerto);
        while (deuCerto) {
            f->Insere(f, x, &deuCerto);
            filaAux->Retira(filaAux, &x, &deuCerto);
        }
    } else {
        cout << "(Fila vazia)" << endl;
    }
}
void inverte (Fila* f)
{
    int tam = 0;
    char x;
    bool deuCerto;
    
    /*Contando quantos elementos há na fila*/
    Fila* aux = new Fila();
    f->Retira(f, &x, &deuCerto);
    while (deuCerto) {
        /*Guardando em aux*/
        aux->Insere(aux, x, &deuCerto);
        tam++;
        f->Retira(f, &x, &deuCerto);
    }
    
    /*Mais uma passagem, agora para inserir os elementos
     em um vetor.*/
    char elem[tam];
    int posAppend = 0;
    
    aux->Retira(aux, &x, &deuCerto);
    while (deuCerto) {
        elem[posAppend] = x;
        aux->Retira(aux, &x, &deuCerto);
        posAppend++;
    }
    
    //Inserindo em f na ordem invertida
    for (int i = posAppend - 1; i >= 0; i--) {
        f->Insere(f, elem[i], &deuCerto);
    }
}

