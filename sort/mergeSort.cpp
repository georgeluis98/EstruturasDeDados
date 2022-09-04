#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 10

using namespace std;

void merge(int*,int,int);
void intercala(int*,int,int,int);
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
    merge(array,0,MAX-1); //mergeSort

    //array ordenado
    for(int i=0; i<MAX; i++)
        cout << array[i] << "\t";

    return 0;
}

void merge(int* arr, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio+fim) / 2;
        merge(arr,inicio,meio);
        merge(arr,meio+1,fim);
        intercala(arr,inicio,meio,fim);
    }
}

void intercala(int* arr, int inicio, int meio, int fim){
    int i = inicio, j = meio+1, k = 0;
    int tamanho = fim-inicio+1;
    int *temp = new int[tamanho];

    while(k < tamanho){
        if(i <= meio && j <= fim){
            if(arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }else{
            if(i <= meio)
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
    }

    for(j=0, k=inicio; j<tamanho; j++, k++)
        arr[k] = temp[j];
    
    delete []temp;
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}