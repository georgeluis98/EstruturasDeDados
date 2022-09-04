#include <iostream>

using namespace std;

struct no{
    int info;
    struct no *prox;
};

typedef struct no* noPtr;

void push(noPtr*);
void pop(noPtr*);
void listar(noPtr);
int menu();

int main(){
    noPtr topo = NULL;
    int op;
    
    do{
        op = menu();

        switch(op){
            case 0: break;
            case 1: push(&topo); break;
            case 2: pop(&topo); break;
            case 3: listar(topo); break;
            default: cout << "Opcao invalida\n"; break;
        }

        system("pause && cls");
    }while(op != 0);

    return 0;
}

void push(noPtr *tp){
    noPtr p = new no;

    cout << "\nValor do elemento: ";
    cin >> p->info;

    p->prox = *tp;
    *tp = p;

    cout << "O elemento '" << p->info << "' foi adicionado a lista\n";
}

void pop(noPtr *tp){
    if(*tp == NULL){
        cout << "Lista Vazia!\n";
    }else{
        noPtr p = *tp;
        *tp = (*tp)->prox;

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

    cout << "1. Empilhar / 2. Desempilhar / 3. Listar / 0. Sair\n"
        << "Opcao: ";
    cin >> x;

    return x;
}