#include <iostream>
#define MAX 7

using namespace std;

//função que exibe o resultado da busca
void resultado(int b){
    if(b == -1)
        cout << "Valor nao encontrado";
    else
        cout << "Encontrado na posicao: " << b;
}

//função de busca sequencial
int sequencial(int* arr, int x){
    for(int i=0; i<MAX; i++)
        if(arr[i] == x)
            return i;

    return -1;
}

//função de busca binária
int binaria(int* arr, int x, int esq, int dir){
    int meio = (esq + dir) / 2;

    if(esq > dir)
        return -1;
    else if(arr[meio] == x)
        return meio;
    else 
        if(arr[meio] > x)
            binaria(arr,x,esq,meio-1);
        else
            binaria(arr,x,meio+1,dir);
}

int main(){
    int array1[MAX] = {15,32,25,90,50,44,9}; //array p/ busca sequencial
    int array2[MAX] = {9,15,25,32,44,50,90}; //array p/ binaria ou sequencial
    int x = 32; //valor a ser procurado
    
    int busca = sequencial(array1,x);
    cout << "Sequencial -> "; resultado(busca);

    busca = binaria(array2,x,0,MAX-1);
    cout << "\nBinaria -> "; resultado(busca);

    return 0;
}