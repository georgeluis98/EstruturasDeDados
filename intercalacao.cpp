#include <iostream>
#define T1 5
#define T2 3
#define T3 T1+T2

using namespace std;

int main(){
    int arr1[T1] = {2,7,16,25,30};
    int arr2[T2] = {4,11,12};
    int arr3[T3];

    int i = 0, j = 0, k = 0;

    while(k < T3){
        if(i < T1  && j < T2){
            if(arr1[i] < arr2[j])
                arr3[k++] = arr1[i++];
            else
                arr3[k++] = arr2[j++];
        }else{
            if (i < T1)
                arr3[k++] = arr1[i++];
            else
                arr3[k++] = arr2[j++];
        }
    }
    
    for(int i=0; i<T3; i++)
        cout << arr3[i] << "\t";

    return 0;
}