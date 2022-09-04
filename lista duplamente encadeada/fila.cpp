#include <iostream>

using namespace std;

struct no{
    int info;
    struct no *ant, *prox;
};

typedef struct no *noPtr;

void enqueue(noPtr*,noPtr*);
void dequeue(noPtr*,noPtr*);
void listar(noPtr,noPtr);
int menu();

int main(){
    noPtr topo = NULL, fim = NULL;
    int op;
    
    do{
        op = menu();

        switch(op){
            case 0: break;
            case 1: enqueue(&topo,&fim); break;
            case 2: dequeue(&topo,&fim); break;
            case 3: listar(topo,fim); break;
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

    if(*tp == NULL){
        p->ant = NULL;
        *tp = p;
    }else{
        p->ant = *fm;
        (*fm)->prox = p;
    }
    
    p->prox = NULL;
    *fm = p;
    
    cout << "O elemento '" << p->info << "' foi adicionado a lista\n";
}

void dequeue(noPtr *tp, noPtr *fm){
    if(*tp == NULL){
        cout << "Lista Vazia!\n";
    }
    else{
        noPtr p = *tp;

        if((*tp)->prox == NULL){ //verificando se é o único elemento da lista
            *tp = NULL; *fm = NULL;
        }else{
            *tp = (*tp)->prox;
            (*tp)->ant = NULL;
        }
        
        cout << "\nO elemento '" << p->info << "' foi removido da lista\n";
        delete(p);
    }
}

void listar(noPtr tp, noPtr fm){
    if(tp == NULL){
        cout << "Lista vazia!\n";
    }else{
        cout << "\nElementos da lista: \n";
        cout << "INICIO";
        
        while(tp != NULL){
            cout << " --> " << tp->info;
            tp = tp->prox;
        }
        
        cout << " --> NULL\n";

        /* Substituir 'tp' e 'tp->prox' por 'fm' e 'fm->ant' para listar em ordem decrescente */
    }
}

int menu() {
    int x;

    cout << "1. Enfileirar / 2. Desenfileirar / 3. Listar / 0. Sair\n"
        << "Opcao: ";
    cin >> x;

    return x;
}