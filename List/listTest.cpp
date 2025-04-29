#include<iostream>
#include"list.h"
using namespace std;

int main(){
    List<int> myList;
    myList.pushBack(5);
    myList.pushBack(9);
    myList.pushFront(1);

    Node<int>* tmp = myList.getFirstPointer();
    tmp = tmp->next;
    tmp = tmp->next;

    myList.insert(tmp, new Node<int>(42));
    myList.pushBack(99);
    myList.printList();
    std::cout << myList.getSize() << std::endl;

    myList.popBack();
    myList.printList();
    std::cout << myList.getSize() << std::endl;

    myList.popFront();
    myList.printList();
    std::cout << myList.getSize() << std::endl;

    return 0;
}