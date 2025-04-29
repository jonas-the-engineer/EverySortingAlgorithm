#include<iostream>
using namespace std;

template<typename T>
void selectionSort(T *arr, int size){
    if(size==0) return;
    T min;
    T *minPointer;
    T tmp;
    for(int i = 0; i < size-1; i++){
        min = arr[i];
        minPointer = arr+i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < min){
                min = arr[j];
                minPointer = arr+j;
            }
        }
        tmp = arr[i];
        arr[i] = min;
        *minPointer = tmp;
    }
}

int main(){
    int arr[10] = {4, 9, 2, 1, 8, 4, 3, 5, 3, 5};
    selectionSort<int>(arr, 10);
    for(int i = 0; i < 10; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}