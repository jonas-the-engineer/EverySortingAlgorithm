#include<iostream>
using namespace std;

template<typename T>
void insertionSort(T* arr, int size){
    T tmp;
    bool inserted;
    for(int i = 1; i < size; i++){
        tmp = *(arr+i);
        inserted = false;
        for(int j = i; j >= 1; j--){
            if(tmp < arr[j-1]){
                arr[j] = arr[j-1];
            } else {
                arr[j] = tmp;
                inserted = true;
                break;
            }
        }
        // if there has not been any insertion before, the tmp element has to be inserted at the front
        if(!inserted){
            arr[0] = tmp;
        }
    }
}

int main(){
    int arr[10] = {9, 4, 2, 1, 8, 4, 3, 5, 3, 5};
    insertionSort<int>(arr, 10);
    for(int i = 0; i < 10; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
    return 0;
}