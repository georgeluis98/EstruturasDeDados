/* lista simplesmente encadeada com inserção ordenada de elementos e função de busca */

#include <iostream>

using namespace std;

struct no {
    int info;
    struct no *prox;
};

typedef struct no *noPtr;

void inserir(noPtr*);
void remover(noPtr*);
void buscar(noPtr);
void listar(noPtr);
int menu();

int main(){
    noPtr topo = NULL;
    int op;
    
    do{
        op = menu();

        switch(op){
            case 0: break;
            case 1: inserir(&topo); break;
            case 2: remover(&topo); break;
            case 3: buscar(topo); break;
            case 4: listar(topo); break;
            default: cout << "Opcao invalida\n"; break;
        }

        system("pause && cls");
    }while(op != 0);

    return 0;
}

void inserir(noPtr *tp){
    noPtr p = new no;     
    
    cout << "\nValor do elemento: ";
    cin >> p->info;
    
    if(*tp == NULL){ 
        p->prox = NULL;
        *tp = p;
    }else{
        noPtr antP, proxP = *tp;
        
        while(proxP != NULL && p->info > proxP->info){ //verificar posição para inserção
            antP = proxP;
            proxP = proxP->prox;
        }
        
        if(proxP == *tp){ //elemento é menor do que todos
            p->prox = *tp;
            *tp = p;
        }else{ //elemento é maior do que todos ou está no meio da lista
            antP->prox = p;
            p->prox = proxP;
        }
    }

    cout << "O elemento '" << p->info << "' foi adicionado a lista\n";
}

void remover(noPtr *tp){
    if(*tp == NULL){
        cout << "Lista Vazia!\n";
    }else{
        noPtr p = *tp, antP;
        int x;

        cout << "\nRemover elemento: ";
        cin >> x;

        while(p != NULL && p->info != x){ //buscando o elemento
            antP = p;
            p = p->prox;
        }
        
        if(p == NULL){
            cout << "Elemento nao encontrado\n";
        }else{
            if(p == *tp)
                *tp = (*tp)->prox;
            else
                antP->prox = p->prox;
            
            cout << "O elemento '" << p->info << "' foi removido da lista\n";
            delete p;
        }
    }
}

void buscar(noPtr tp){
    if(tp == NULL){
        cout << "Lista Vazia!\n";
    }else{
        int x;

        cout << "\nBuscar elemento: ";
        cin >> x;

        while(tp != NULL && tp->info != x)
            tp = tp->prox;
        
        if(tp == NULL)
            cout << "Elemento nao encontrado\n";
        else
            cout << "Elemento encontrado\n";
    }
}

void listar(noPtr tp){
    if(tp == NULL){
        cout << "Lista vazia!\n";
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

    cout << "1. Inserir / 2. Remover / 3. Buscar / 4. Listar / 0. Sair\n"
        << "Opcao: ";
    cin >> x;

    return x;
}