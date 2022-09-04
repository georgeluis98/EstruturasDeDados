#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 10

using namespace std;

void heap(int*);
void heapsort(int*);
void descer(int*,int,int);
void troca(int*,int*);
void imprimir(int*);

int main(){
    int array[MAX];

    srand(time(NULL));

    for(int i=0; i<MAX; i++)  //array de numeros aleatorios desordenado
        array[i] = rand() % 100;
    
    cout << "Desordenado: "; imprimir(array);

    heapsort(array); //heapSort

    cout << "\nHeapsort: "; imprimir(array);
}

void heapsort(int *arr){
    heap(arr); //transformando o array num heap

    cout << "\nHeap: "; imprimir(arr);

    //ordenação
    for(int i=(MAX-1); i >= 1; i--){
        troca(&arr[0],&arr[i]);
        descer(arr,0,i);
    }
}

void heap(int *arr){
    for(int i=(MAX/2); i >= 0; i--)
        descer(arr,i,MAX);
}

void descer(int *arr, int i, int q){
    int d = 2*i + 2;
    int e = 2*i + 1;
    int maior = i;
    
    // verificar se tem filhos e comparar com d(direita) e (esquerda).
    if(d < q && arr[d] > arr[i])
        maior = d;
    if(e < q && arr[e] > arr[maior])
        maior = e;

    if(maior != i){
        //trocar com o maior dos filhos e chamar função novamente
        troca(&arr[i], &arr[maior]);
        descer(arr,maior,q);
    }
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void imprimir(int *arr){
    for(int i=0; i<MAX; i++)
        cout << arr[i] << "\t";
    cout << endl;
}