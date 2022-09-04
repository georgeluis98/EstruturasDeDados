/* Árvore binária de busca */

#include <iostream>

using namespace std;

struct no {
    int info;
    struct no *esq, *dir;
};

typedef struct no *noPtr;

void inserir(noPtr*,int);
void remover(noPtr*,int);
void buscar(noPtr, int);
noPtr maior(noPtr*);
void listarEmOrdem(noPtr);
void listarPreOrdem(noPtr);
void listarPosOrdem(noPtr);
bool enderecoVazio(noPtr);
int listarNos();
int menu();


int main(){
    int op1, op2, x;
    noPtr raiz = NULL;
    
    do{
        op1 = menu();
        
        switch(op1){
            case 1: cout << "\nValor do elemento: ";
                    cin >> x;
                    inserir(&raiz,x);
                    break;
            case 2: cout << "\nRemover elemento: ";
                    cin >> x;
                    remover (&raiz,x);
                    break;
            case 3: op2 = listarNos();
                    cout << endl;
                    if (op2 == 1)
                        listarEmOrdem(raiz);
                    if (op2 == 2)
                        listarPreOrdem(raiz);
                    if (op2 == 3)
                        listarPosOrdem(raiz);
                    cout << endl;
                    break;
            case 4: cout << "\nBuscar elemento: ";
                    cin >> x;
                    buscar(raiz, x);
        }

        system("pause && cls");
    }while(op1 != 0);

    return 0;
}

void inserir(noPtr *p, int x) {
    if(enderecoVazio(*p)){
        *p = new no;
        (*p)->info = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;

        cout << "O elemento '" << (*p)->info << "' foi adicionado a arvore\n";
    }else{
        if (x < ((*p)->info))
            inserir(&((*p)->esq), x);
        else
            inserir(&((*p)->dir), x);
    }
}

void remover(noPtr *p, int x){
    noPtr aux;
    
    if(!enderecoVazio(*p)){
        if (x == ((*p)->info)){
            aux = *p;
            
            if(((*p)->esq) == NULL)
                *p = (*p)->dir;
            else
                if(((*p)->dir) == NULL)
                    *p = (*p)->esq;
                else{
                    aux = maior(&((*p)->esq));
                    (*p)->info = aux->info;
                }

            delete(aux);
            cout << "\nO elemento foi removido\n";
        }else{
            if((x < ((*p)->info)))
                remover(&((*p)->esq), x);
            else
                remover(&((*p)->dir), x);
        }
    }
}

noPtr maior(noPtr *p){
    noPtr t = *p;

    if ((t->dir) == NULL){
        *p = (*p)->esq;
        return(t);
    }else
        return (maior(&((*p)->dir)));
}

void buscar(noPtr p, int x){
    if(enderecoVazio(p)){
        cout << "\nArvore nao possui elementos" << endl;
    }else{
        if (x == (p->info)){
            cout << "\nO elemento: " << p->info << " foi encontrado!\n";
        }else{
            if (x < (p->info) && p->esq != NULL)
                buscar((p->esq), x);
            else if(p->dir != NULL)
                buscar((p->dir), x);
            else
                cout << "Elemento nao encontrado";
        }
    }
}

void listarEmOrdem(noPtr p) {
    if (!enderecoVazio(p)){
        listarEmOrdem(p->esq);
        cout << "\t" << p->info;
        listarEmOrdem(p->dir);
    }
}

void listarPreOrdem(noPtr p) {
    if (!enderecoVazio(p)) {
        cout << "\t" << p->info;
        listarPreOrdem(p->esq);
        listarPreOrdem(p->dir);
    }
}

void listarPosOrdem(noPtr p) {
    if (!enderecoVazio(p)) {
        listarPosOrdem(p->esq);
        listarPosOrdem(p->dir);
        cout << "\t" << p->info;
    }
}

bool enderecoVazio(noPtr p){
    if (p)
        return false;
    else
        return true;
}

int listarNos(){
    int x;
    
    cout << "\nTipos de listagem: 1. Em Ordem / 2. Pre Ordem / 3. Pos Ordem"
        << "\nOpcao: ";
    cin >> x;

    return x;
}

int menu(){
    int x;

    cout << "1. Inserir / 2. Remover / 3. Listar / 4. Buscar / 0. Sair"
        << "\nOpcao: ";
    cin >> x;

    return x;
}