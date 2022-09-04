/* lista duplamente encadeada com inserção ordenada de elementos e função de busca */

#include <iostream>

using namespace std;

struct no{
    int info;
    struct no* ant, * prox;
};

typedef struct no *noPtr;

void inserir(noPtr*,noPtr*);
void remover(noPtr*,noPtr*);
void buscar(noPtr);
void listar(noPtr,noPtr);
int menu();

int main(){
    noPtr topo = NULL, fim = NULL;
    int op;
    
    do{
        op = menu();

        switch(op){
            case 0: break;
            case 1: inserir(&topo,&fim); break;
            case 2: remover(&topo,&fim); break;
            case 3: buscar(topo); break;
            case 4: listar(topo,fim); break;
            default: cout << "Opcao invalida\n"; break;
        }

        system("pause && cls");
    }while(op != 0);

    return 0;
}

void inserir(noPtr *tp, noPtr *fm){
    noPtr p = new no;     
    
    cout << "\nValor do elemento: ";
    cin >> p->info;
    
    if(*tp == NULL){
        p->ant = NULL;
        p->prox = NULL;
        *tp = p;
        *fm = p;
    }else{
        noPtr antP, proxP = *tp;
        
        while(proxP != NULL && p->info > proxP->info){ //verificar posição para inserção
            antP = proxP;
            proxP = proxP->prox;
        }
        
        if(proxP == *tp){ //elemento é menor do que todos
            p->ant = NULL;
            p->prox = *tp;
            (*tp)->ant = p;
            *tp = p;
        }else{ //elemento é maior do que todos ou está no meio da lista
            p->ant = antP;
            p->prox = proxP;
            antP->prox = p;
            
            if(proxP != NULL) //se estiver no meio da lista
                proxP->ant = p;
            else //se for o último elemento, atualizar o ponteiro fim
                *fm = p;
        }
    }

    cout << "O elemento '" << p->info << "' foi adicionado a lista\n";
}

void remover(noPtr *tp, noPtr *fm){
    if(*tp == NULL){
        cout << "Lista vazia!\n";
    }else{
        noPtr p = *tp;
        int x;

        cout << "\nRemover elemento: ";
        cin >> x;

        while(p != NULL && p->info != x) //buscando o elemento
            p = p->prox;
        
        if(p == NULL){
            cout << "Elemento nao encontrado\n";
        }else{
            if(p->ant == NULL){ //se for o primeiro elemento
                if(p->prox == NULL){ //unico elemento da lista
                    *tp = NULL; *fm = NULL;
                }else{ //apenas o primeiro elemento
                    *tp = (*tp)->prox;
                    (*tp)->ant = NULL;
                }
            }else{ //se o elemento estiver no meio ou fim da lista
                noPtr antP = p->ant, proxP = p->prox;

                if(p->prox == NULL){ //ultimo elemento
                    antP->prox = NULL;
                    *fm = antP;
                }else{ //elemento no meio da lisata
                    antP->prox = proxP;
                    proxP->ant = antP;
                }
            }

            cout << "O elemento --> " << p->info << " <-- foi retirado da lista!\n";
            delete(p);
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

void listar(noPtr tp, noPtr fm){
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
        
        /* Substituir 'tp' e 'tp->prox' por 'fm' e 'fm->ant' para listar em ordem decrescente */
    }
}

int menu() {
    int x;

    cout << "1. Inserir / 2. Remover / 3. Buscar / 4. Listar / 0. Sair\n"
        << "Opcao: ";
    cin >> x;

    return x;
}