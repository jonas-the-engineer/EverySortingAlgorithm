#ifndef LIST_H
#define LIST_H

template<typename T>
class Node {
public:
    T value;
    Node<T>* next;
    Node<T>* previous;

    Node(T initialValue);
    ~Node();
};

template<typename T>
class List {
private:
    int size;
    Node<T>* first;
    Node<T>* last;

public:
    List();
    ~List();

    Node<T>* getFirstPointer();
    Node<T>* getLastPointer();
    int getSize();
    void printList();

    void pushFront(Node<T>* tmp);
    void pushFront(T initialValue);
    void popFront();

    void pushBack(Node<T>* tmp);
    void pushBack(T initialValue);
    void popBack();

    void insert(Node<T>* position, Node<T>* nodeToBeInserted);
    void insert(Node<T>* position, T initialValue);
    void erase(Node<T>* position);
};

// Implementieren von Template-Klassen in der Header-Datei nötig
#include "List.tpp"

#endif // LIST_H
