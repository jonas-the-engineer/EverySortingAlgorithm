#ifndef STACK_H
#define STACK_H

#include<iostream>

template<typename T>
class StackNode{
    public:
        StackNode<T>* next;
        T value;

        StackNode(T initialValue);
        ~StackNode();

};

template<typename T>
class Stack{
    private:
        StackNode<T>* top;
        int stackSize;
    public:
        Stack();
        ~Stack();

        void pushBack(StackNode<T>* tmp);
        void pushBack(T initialValue);
        void popBack();

        StackNode<T>* topPointer();
        T topValue();

        int size();
        void printStack();

        void swap(Stack &other);
        void reverse();
};

#include"stack.tpp"

#endif // STACK_H