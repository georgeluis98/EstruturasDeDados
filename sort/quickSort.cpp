#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 10

using namespace std;

void quick(int*,int,int);
int particiona(int*,int,int);
void troca(int*,int*);

int main(){
    int array[MAX];

    srand(time(NULL));

    //array de numeros aleatorios desordenado
    for(int i=0; i<MAX; i++){
        array[i] = rand() % 100;
        cout << array[i] << "\t";
    }
    
    cout << endl;
    quick(array,0,MAX-1); //quickSort

    //array ordenado
    for(int i=0; i<MAX; i++)
        cout << array[i] << "\t";

    return 0;
}

void quick(int* arr, int esq, int dir){
    if(esq < dir){
        int p = particiona(arr,esq,dir);
        quick(arr,esq,p-1);
        quick(arr,p+1,dir);
    }
}

int particiona(int* arr, int esq, int dir){
    int cont = esq;

    for(int i = esq+1; i <= dir; i++){
        if(arr[i] < arr[esq]){
            cont++;
            troca(&arr[i],&arr[cont]);
        }
    }

    troca(&arr[esq],&arr[cont]);

    return cont;
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}