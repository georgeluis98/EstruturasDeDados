#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 10

using namespace std;

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void sort(int *arr){
    for(int i=0; i<MAX; i++){
        int pos = i;
        
        while(pos > 0 && arr[pos] < arr[pos-1]){
            troca(&arr[pos],&arr[pos-1]);
            pos--;
        }
    }
}

int main(){
    int array[MAX];

    srand(time(NULL));

    //array de numeros aleatorios desordenado
    for(int i=0; i<MAX; i++){
        array[i] = rand() % 100;
        cout << array[i] << "\t";
    }
    
    cout << endl;
    sort(array); //insertionSort

    //array ordenado
    for(int i=0; i<MAX; i++)
        cout << array[i] << "\t";

    return 0;
}