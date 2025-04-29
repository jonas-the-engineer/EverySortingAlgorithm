#include<iostream>
using namespace std;

template<typename T>
void doubleSelectionSort(T *arr, int size){
    if(size==0) return;
    T min, max;
    T *minPointer, *maxPointer;
    T tmp;
    T* tmpPointer;
    for(int i = 0; i < (size >> 1); i++){
        minPointer = arr+i;
        maxPointer = arr+size-1-i;
        min = *minPointer; max = *maxPointer;
        for(int j = i; j < size-i; j++){  // check all elements (the smallest/largest element could hide at the end/start)
            tmpPointer = arr + j;
            tmp = *tmpPointer;
            if(tmp > max){
                maxPointer = tmpPointer;
                max = tmp;
            } else if(tmp < min){
                minPointer = tmpPointer;
                min = tmp;
            }
        }
        cout << "Min: " << min << " | " << "Max: " << max << endl;
        if(maxPointer == arr+i || minPointer == arr+size-1-i){
            if(maxPointer == arr+i && minPointer == arr+size-1-i){
                *maxPointer = min;
                *minPointer = max;
            } else if(maxPointer == arr+i){
                *maxPointer = arr[size-1-i];
                arr[size-1-i] = max;
                *minPointer = arr[i];
                arr[i] = min;
            } else { // if (minPointer == arr+size-1-i)
                *minPointer = arr[i];
                arr[i] = min;
                *maxPointer = arr[size-1-i];
                arr[size-1-i] = max;
            }
        } else {
            *minPointer = arr[i];
            arr[i] = min;
            *maxPointer = arr[size-1-i];
            arr[size-1-i] = max;
        }
    }
}

int main(){
    int arr[10] = {4, 9, 2, 1, 8, 4, 3, 5, 3, 5};
    doubleSelectionSort<int>(arr, 10);
    for(int i = 0; i < 10; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}