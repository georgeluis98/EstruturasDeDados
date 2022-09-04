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
    bool loop = true;
    int auxMAX = MAX;

    while(loop){
        loop = false;
        auxMAX--;

        for(int i=0; i < auxMAX; i++){
            if(arr[i] > arr[i+1]){
                troca(&arr[i],&arr[i+1]);
                loop = true;
            }
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
    sort(array); //bubbleSort

    //array ordenado
    for(int i=0; i<MAX; i++)
        cout << array[i] << "\t";

    return 0;
}