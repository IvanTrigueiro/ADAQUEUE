#include <iostream>
#include <string.h>
using namespace std;

struct No{
    int conteudo;
    No * prox;
    No * ant;

    No(){
        prox = NULL;
        ant = NULL;
    }
    No(int valor){
        conteudo = valor;
        prox = NULL;
        ant = NULL;
    }
}; //Criacao do nó

struct adalista{
    int ehReverso;
    No * cabeca;
    No * cauda;

    adalista(){
        ehReverso = false;
        cabeca = NULL;
        cauda = NULL;
    }

    void ppush_front(int valor){

        if(cauda == 0 || cabeca == 0){          //Se nao tiver elementos
            cabeca = new No(valor);             //Adiciona um novo pela cabeca
            cauda = cabeca;
        } else {
                No* novoNo = new No(valor);     //Guarda novoNó
                cabeca->ant = novoNo;           //Adiciona novoNo na frente da cabeca
                novoNo->prox = cabeca;          //Linka o novoNo na lista na frente da cabeca
                cabeca = novoNo;                //Cabeca agora eh o novoNo
        }
    }
    void ppush_back(int valor){

        if(cauda == 0 || cabeca == 0){          //Se nao tiver elementos
            cauda = new No(valor);              //Adiciona um novo pela cauda
            cabeca = cauda;
        } else {
                No* novoNo = new No(valor);     //Guarda novoNó
                cauda->prox = novoNo;           //Adiciona novoNo na atras da cauda
                novoNo->ant = cauda;            //Linka o novoNo na lista atras da cabeca
                cauda = novoNo;                 //Cauda agora eh o novoNo
        }
    }
    int bback(){
        if(cauda == NULL)
            return -1;

        int conteudo = cauda->conteudo; // Pega o conteudo do ultimo nó
        cauda = cauda->ant;             // O ultimo nó recebe o anterior

        if(cauda == NULL)               // Se o ultimo for o unico nó
            cabeca = NULL;              // Eh igual a cabeca
        else
            cauda->prox = NULL;         //Se nao for, prox do ultimo recebe 0

        return conteudo;
    }
    int ffront(){
        if(cabeca == NULL)
            return -1;

        int conteudo = cabeca->conteudo;// Pega o conteudo do primeiro nó
        cabeca = cabeca->prox;          // Primeiro nó recebe o proximo

        if(cabeca == NULL)              // Se o primeiro for o unico nó
            cauda = NULL;              // Eh igual a cauda
        else
            cabeca->ant = NULL;         //Se nao for, anterior do primeiro recebe 0

        return conteudo;
    }
    void toFront(int valor){
        if(!ehReverso)
            ppush_front(valor);
        else
            ppush_back(valor);
    }
    void push_back(int valor){
        if(!ehReverso)
            ppush_back(valor);
        else
            ppush_front(valor);
    }
    void reverse(){
        ehReverso = !ehReverso;
    }
    int front(){
        if(!ehReverso)
            return ffront();
        else
            return bback();
    }
    int back(){
        if(!ehReverso)
            return bback();
        else
            return ffront();
    }
    void print(){
        No* aux = cabeca;
        while(aux != NULL){
            cout << aux->conteudo << "";
            aux = aux->prox;
        }
        cout << "$$$$" << ehReverso << endl;
    }

};


int main()
{
    int Q, k;
    cin >> Q;

    string s;
    adalista lista;

    while(Q--){
            cin >> s;

            if(s == "back")
            {
                k = lista.back();
                if(k >= 0)
                    cout << k <<endl;
                else
                    cout << "No job for Ada?\n";
            }
            else if(s == "front")
            {
                k = lista.front();
                if(k >= 0)
                    cout << k << endl;
                else
                    cout << "No job for Ada?\n";
            }
            else if(s == "reverse")
            {
                lista.reverse();
            }
            else if(s == "toFront")
            {
                cin >> k;
                lista.toFront(k);
            }
            else if(s == "push_back")
            {
                cin >> k;
                lista.push_back(k);
            }
    }
    return 0;
}
