/* lista duplamente encadeada circular com inserção ordenada de elementos e função de busca */

#include <iostream>

using namespace std;

struct no{
    int info;
    struct no *ant, *prox;
};

typedef struct no *noPtr;

void inserir(noPtr*,noPtr*,int*);
void remover(noPtr*,noPtr*,int*);
void buscar(noPtr,int);
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
            case 1: inserir(&topo,&fim,&qtde); break;
            case 2: remover(&topo,&fim,&qtde); break;
            case 3: buscar(topo,qtde); break;
            case 4: listar(topo,qtde); break;
            default: cout << "Opcao invalida\n"; break;
        }

        system("pause && cls");
    }while(op != 0);

    return 0;
}

void inserir(noPtr *tp, noPtr *fm, int *qt){
    noPtr p = new no;
    
    cout << "\nValor do elemento: ";
    cin >> p->info;
    
    if(*tp == NULL){
        p->ant = p;
        p->prox = p;
        *tp = p;
        *fm = p;
    }else{
        noPtr antP, proxP = *tp;
        int cont = 0;
        
        while(cont < *qt && p->info > proxP->info){
            antP = proxP;   proxP = proxP->prox;
            cont++;
        }
        
        if(proxP == *tp && p->info < proxP->info){ //elemento é menor do que todos
            p->ant = *fm;
            p->prox = *tp;
            (*tp)->ant = p;
            (*fm)->prox = p;
            *tp = p;
        }else{ //elemento é maior do que todos ou está no meio da lista
            p->ant = antP;
            p->prox = proxP;
            antP->prox = p;
            proxP->ant = p;

            if(cont == *qt) //atualizar o ponteiro fim, caso o novo elemento seja o maior da lista
                *fm = p;
        }
    }

    *qt = *qt + 1;
    cout << "O elemento '" << p->info << "' foi adicionado a lista\n";
}

void remover(noPtr *tp, noPtr *fm, int *qt){
    if(*tp == NULL){
        cout << "Lista vazia!\n";
    }else{
        noPtr p = *tp, antP;
        int x, cont = 0;
        
        cout << "\nRemover elemento: ";
        cin >> x;
        
        while(cont < *qt && p->info != x){
            antP = p;   p = p->prox;
            cont++;
        }

        if(cont == *qt){
            cout << "Elemento nao encontrado\n";
        }else{
            if(p == *tp){
                *tp = (*tp)->prox;
                (*tp)->ant = *fm;
                (*fm)->prox = *tp;
            }else{
                antP->prox = p->prox;
                p->prox->ant = antP;

                if(p == *fm) //atualizando o ponteiro fim, se o último elemento for removido
                    *fm = antP;
            }

            cout << "O elemento '" << p->info << "' foi removido da lista\n";
            delete(p);

            *qt = *qt - 1;

            if(*qt == 0){   //verificando se a lista ficou vazia
                *tp = NULL; *fm = NULL;
            }
        }
    }
}

void buscar(noPtr tp, int qt){
    if(tp == NULL){
        cout << "Lista Vazia!\n";
    }else{
        int x;

        cout << "\nBuscar elemento: ";
        cin >> x;

        while(qt > 0 && tp->info != x){
            tp = tp->prox;
            qt--;
        }
        
        if(qt == 0)
            cout << "Elemento nao encontrado\n";
        else
            cout << "Elemento encontrado\n";
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

    cout << "1. Inserir / 2. Remover / 3. Buscar / 4. Listar / 0. Sair\n"
        << "Opcao: ";
    cin >> x;

    return x;
}