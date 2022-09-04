/* lista duplamente encadeada circular - fila */

#include <iostream>

using namespace std;

struct no{
    int info;
    struct no *ant, *prox;
};

typedef struct no *noPtr;

void enqueue(noPtr*,noPtr*,int*);
void dequeue(noPtr*,noPtr*,int*);
void listar(noPtr,int);
bool listaVazia(noPtr);
int menu();

int main(){
    noPtr topo = NULL, fim = NULL;
    int op, qtde = 0;
    
    do{
        cout << "--> A lista possui '" << qtde << "' no(s) <--\n";
        op = menu();

        switch(op){
            case 0: break;
            case 1: enqueue(&topo,&fim,&qtde); break;
            case 2: dequeue(&topo,&fim,&qtde); break;
            case 3: listar(topo,qtde); break;
            default: cout << "Opcao invalida\n"; break;
        }

        system("pause && cls");
    }while(op != 0);

    return 0;
}

void enqueue(noPtr *tp, noPtr *fm, int *qt){
    noPtr p = new no;
    
    cout << "\nValor do elemento: ";
    cin >> p->info;
    
    if(*tp == NULL){
        p->ant = p;
        p->prox = p;
        *tp = p;
    }else{
        p->ant = *fm;
        p->prox = *tp;
        (*tp)->ant = p;
        (*fm)->prox = p;
    }

    *fm = p;
    *qt = *qt + 1;
    cout << "O elemento '" << p->info << "' foi adicionado a lista\n";
}

void dequeue(noPtr *tp, noPtr *fm, int *qt){
    if(*tp == NULL){
        cout << "Lista vazia!\n";
    }else{
        noPtr p = *tp;

        if(*tp == *fm){ //único elemento na lista
            *tp = NULL; *fm = NULL;
        }else{
            *tp = (*tp)->prox;
            (*tp)->ant = *fm;
            (*fm)->prox = *tp;
        }
        
        cout << "\nO elemento '" << p->info << "' foi removido da lista\n";
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

    cout << "1. Enfileirar / 2. Desenfileirar / 3. Listar / 0. Sair\n"
        << "Opcao: ";
    cin >> x;

    return x;
}