#include"stack.h"

int main(){
    Stack<int> myStack;
    myStack.pushBack(5);
    myStack.pushBack(6);
    myStack.pushBack(30);
    myStack.printStack();
    myStack.popBack();
    myStack.printStack();

    std::cout << "stack.size: " << myStack.size() << std::endl;

    Stack<int> stack2;
    stack2.pushBack(42);
    stack2.pushBack(69);

    myStack.printStack();
    stack2.printStack();

    std::cout << "swapping..." << std::endl;

    myStack.swap(stack2);

    myStack.printStack();
    stack2.printStack();
    std::cout <<"mySize: " << myStack.size() << " | stack2.size: " << stack2.size() << std::endl;

    // --------

    myStack.pushBack(1);
    myStack.pushBack(10);
    myStack.pushBack(100);
    myStack.printStack();
    myStack.reverse();
    myStack.printStack();
    return 0;
}