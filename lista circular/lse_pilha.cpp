#include <iostream>

using namespace std;

struct no{
    int info;
    struct no *prox;
};

typedef struct no *noPtr;

void push(noPtr*,noPtr*,int*);
void pop(noPtr*,noPtr*,int*);
void listar(noPtr,int);
int menu();

int main(){
    noPtr topo = NULL, fim = NULL;
    int op, qtde = 0;

    do{
        cout << "--> A lista possui '" << qtde << "' no(s) <--\n";
        op = menu();

        switch(op){
            case 0: break;
            case 1: push(&topo,&fim,&qtde); break;
            case 2: pop(&topo,&fim,&qtde); break;
            case 3: listar(topo,qtde); break;
            default: cout << "Opcao invalida\n"; break;
        }

        system("pause && cls");
    }while(op != 0);
}

void push(noPtr *tp, noPtr *fm, int *qt){
    noPtr p = new no;
    
    cout << "\nValor do elemento: ";
    cin >> p->info;
    
    if(*tp == NULL){
        p->prox = p;
        *tp = p;
        *fm = p;
    }else{
        p->prox = *tp;
        *tp = p;
        (*fm)->prox = p;
    }

    *qt = *qt + 1;
    cout << "O elemento '" << p->info << "' foi adicionado a lista\n";
}

void pop(noPtr *tp, noPtr *fm, int *qt){
    if(*tp == NULL){
        cout << "Lista vazia!\n";
    }else{
        noPtr p = *tp;

        if(p == p->prox){ //único elemento da lista
            *tp = NULL; *fm = NULL;
        }else{
            *tp = (*tp)->prox;
            (*fm)->prox = *tp;
        }
        
        cout << "O elemento '" << p->info << "' foi removido da lista\n";
        delete(p);

        *qt = *qt - 1;
    }
}

void listar(noPtr tp, int qt){
    if(tp == NULL){
        cout << "Lista vazia!\n";
    }else{
        cout << "\nElementos da lista:\n";
        cout << "INICIO";
        
        for(int i=0; i < qt; i++){
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