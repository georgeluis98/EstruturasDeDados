#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 8

using namespace std;

void imprimir(int *arr){
    for(int i=0; i<MAX; i++)
        cout << arr[i] << "\t";
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void subir(int *arr, int i){
    if(i > 0){
        int j = i/2;

        if(i % 2 == 0)
            j = j - 1;

        if(j >= 0)
            if (arr[i] > arr[j]){
                troca(&arr[i],&arr[j]);
                subir(arr,j);
            }
    }
}

void descer(int *arr, int i, int q){
    int d = 2 * i + 2;
    int e = 2 * i + 1;
    
    int maior = i;
    
    // verificar se tem filhos e comparar com d(direita) e (esquerda).
    if(d < q && arr[d] > arr[i])
        maior = d;
    if(e < q && arr[e] > arr[maior])
        maior = e;
    if(maior != i){
        //trocar com o maior dos filhos e chamar função novamente
        troca(&arr[i],&arr[maior]);
        descer(arr,maior,q);
    }
}

int main(){
    int array[MAX] = {90,58,83,35,12,65,79,20}; //é um heap

    cout << "Heap: ";   imprimir(array);
    
    array[5] = 99; /*alteração de prioridade na posição 5 */
    subir(array,5); //subida

    cout << "\nSubida: ";   imprimir(array);

    array[0] = 40; /*alteração de prioridade na posição 0 */
    descer(array,0,MAX); //descida

    cout << "\nDescida: ";   imprimir(array);
    
    return 0;
}