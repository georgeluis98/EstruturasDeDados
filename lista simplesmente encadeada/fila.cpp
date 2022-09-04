#include <iostream>

using namespace std;

struct no{
  int info;
  struct no *prox;
};

typedef struct no *noPtr;

void enqueue(noPtr*,noPtr*);
void dequeue(noPtr*,noPtr*);
void listar(noPtr);
int menu();

int main(){
    noPtr topo = NULL, fim = NULL;
    int op;
    
    do{
        op = menu();

        switch (op){
            case 0: break;
            case 1: enqueue(&topo,&fim); break;
            case 2: dequeue(&topo,&fim); break;
            case 3: listar(topo); break;
            default: cout << "Opcao invalida\n"; break;
        }

        system("pause && cls");
    }while(op != 0);

    return 0;
}

void enqueue(noPtr *tp, noPtr *fm){
    noPtr p = new no;

    cout << "\nValor do elemento: ";
    cin >> p->info;

    if(*tp == NULL)
        *tp = p;
    else
        (*fm)->prox = p;

    p->prox = NULL;
    *fm = p;

    cout << "O elemento '" << p->info << "' foi adicionado a lista\n";
}

void dequeue(noPtr *tp, noPtr *fm){
    if(*tp == NULL){
        cout << "Lista Vazia!\n";
    }else{
        noPtr p = *tp;
        *tp = (*tp)->prox;
        
        if(*tp == NULL) //verificando se a lista ficou vazia
            *fm = NULL;

        cout << "\nO elemento '" << p->info << "' foi removido da lista\n";
        delete p;
    }
}

void listar(noPtr tp){
    if(tp == NULL){
        cout << "Lista Vazia!\n";
    }else{
        cout << "\nElementos da lista:\n";
        cout << "INICIO";
        
        while(tp != NULL){
            cout << " --> " << tp->info;
            tp = tp->prox;
        }

        cout << " --> NULL\n";
    }
}

int menu(){
    int x;

    cout << "1. Enfileirar / 2. Desenfileirar / 3. Listar / 0. Sair\n"
        << "Opcao: ";
    cin >> x;

    return x;
}