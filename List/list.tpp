#ifndef LIST_TPP
#define LIST_TPP

#include <iostream>

template<typename T>
Node<T>::Node(T initialValue) {
    value = initialValue;
    next = nullptr;
    previous = nullptr;
    std::cout << "new Node" << std::endl;
}

template<typename T>
Node<T>::~Node() {
    std::cout << "delete Node" << std::endl;
}

template<typename T>
List<T>::List() {
    size = 0;
    first = nullptr;
    last = nullptr;
}

template<typename T>
List<T>::~List() {
    Node<T>* tmp = first;
    Node<T>* tmp2;
    while (tmp != nullptr) {
        tmp2 = tmp->next;
        delete tmp;
        tmp = tmp2;
    }
}

template<typename T>
Node<T>* List<T>::getFirstPointer() {
    return first;
}

template<typename T>
Node<T>* List<T>::getLastPointer() {
    return last;
}

template<typename T>
int List<T>::getSize(){
    return size;
}

template<typename T>
void List<T>::printList() {
    Node<T>* tmp = first;
    while (tmp->next != nullptr) {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << tmp->value << std::endl;
    // REVERSED OUTPUT TO VERIFY THAT ALL POINTERS ARE CORRECT
    // tmp = last;
    // while (tmp->previous != nullptr) {
    //     std::cout << tmp->value << " ";
    //     tmp = tmp->previous;
    // }
    // std::cout << tmp->value << "   <- reversed" << std::endl;
}

template<typename T>
void List<T>::pushFront(Node<T>* tmp) {
    if (size++ == 0) {
        last = tmp;
    } else {
        first->previous = tmp;
        tmp->next = first;
        tmp->previous = nullptr;
    }
    first = tmp;
}

template<typename T>
void List<T>::pushFront(T initialValue) {
    Node<T>* tmp = new Node<T>(initialValue);
    pushFront(tmp);
}

template<typename T>
void List<T>::pushBack(Node<T>* tmp) {
    if (size++ == 0) {
        first = tmp;
    } else {
        last->next = tmp;
        tmp->previous = last;
        tmp->next = nullptr;
    }
    last = tmp;
}

template<typename T>
void List<T>::pushBack(T initialValue) {
    Node<T>* tmp = new Node<T>(initialValue);
    pushBack(tmp);
}

template<typename T>
void List<T>::popBack(){
    if(size==0) return;
    if(size==1){
        delete first;
        first = last = nullptr;
    } else {
        last = last->previous;
        delete (last->next);
        last->next = nullptr;
    }
    size--;
}

template<typename T>
void List<T>::popFront(){
    if(size==0) return;
    if(size==1){
        delete first;
        first = last = nullptr;
    } else {
        first = first->next;
        delete (first->previous);
        first->previous = nullptr;
    }
    size--;
}

template<typename T>
void List<T>::insert(Node<T>* position, Node<T>* nodeToBeInserted) {
    if (position == nullptr || nodeToBeInserted == nullptr) return;
    if (position == first) first = nodeToBeInserted;
    nodeToBeInserted->next = position;
    nodeToBeInserted->previous = position->previous;
    position->previous = nodeToBeInserted;
    if (nodeToBeInserted->previous != nullptr) {
        nodeToBeInserted->previous->next = nodeToBeInserted;
    }
    size++;
}

template<typename T>
void List<T>::insert(Node<T>* position, T initialValue) {
    Node<T>* nodeToBeInserted = new Node<T>(initialValue);
    insert(position, nodeToBeInserted);
}

#endif // LIST_TPP