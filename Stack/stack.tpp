#ifndef STACK_TPP
#define STACK_TPP

#include"stack.h"

template<typename T>
StackNode<T>::StackNode(T initialValue){
    next = nullptr;
    value = initialValue;
    std::cout << "new StackNode" << std::endl;
}

template<typename T>
StackNode<T>::~StackNode(){
    std::cout << "delete StackNode" << std::endl;
}

template<typename T>
Stack<T>::Stack(){
    top = nullptr;
    stackSize = 0;
}

template<typename T>
Stack<T>::~Stack(){
    while(stackSize > 0){   // != 0 would be sufficient
        this->popBack();
    }
}

template<typename T>
void Stack<T>::pushBack(StackNode<T>* tmp){
    if(stackSize++ == 0){
        tmp->next = nullptr;
    } else {
        tmp->next = top;
    }
    top = tmp;
}

template<typename T>
void Stack<T>::pushBack(T initialValue){
    this->pushBack(new StackNode<T>(initialValue));
}

template<typename T>
void Stack<T>::popBack(){
    if(stackSize == 0) return;
    StackNode<T>* tmp = top;
    if(stackSize-- == 1){
        top = nullptr;
    } else {
        top = top->next;
    }
    delete tmp;
}

template<typename T>
StackNode<T>* Stack<T>::topPointer(){
    return top;
}

template<typename T>
T Stack<T>::topValue(){
    return top->value;
}

template<typename T>
int Stack<T>::size(){
    return stackSize;
}

template<typename T>
void Stack<T>::printStack(){
    StackNode<T>* tmp = top;
    for(int i = 0; i < this->stackSize; i++){
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

template<typename T>
void Stack<T>::swap(Stack &other){
    int tmpSize = stackSize;
    StackNode<T>* tmpTop = top;
    stackSize = other.stackSize;
    top = other.top;
    other.stackSize = tmpSize;
    other.top = tmpTop;
}

template<typename T>
void Stack<T>::reverse(){
    int origSize = this->stackSize;
    T *arr = new T[stackSize];
    for(int i = 0; i < origSize; i++){
        arr[i] = this->topValue();
        this->popBack();
    }
    for(int i = 0; i < origSize; i++){
        this->pushBack(arr[i]);
    }
    delete[] arr;
}

#endif // STACK_TPP