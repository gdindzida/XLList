//
// Created by Martin on 25-Oct-21.
//
#include <iostream>
#include <vector>
#include "XLList.h"



int main(int argc, char **argv) {
    using xllist::swap;
    //arrange
    int numberOfElementsToAdd = 10;
    //act
    XLList<int> *list = new XLList<int>();
    std::vector<int> elements;
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        int elementToAdd = rand()%1000;
        list->pushBack(elementToAdd);
        elements.push_back(elementToAdd);
        std::cout<< elementToAdd<<std::endl;
    }
    std::cout<< "Sortiram..."<<std::endl;
    struct NodeComparator {
        bool operator()(Node<int> firstNode, Node<int> secondNode) { return firstNode.getValue() < secondNode.getValue(); }
    } nodeComparator;


    XLList<int>::Iterator begin = list->begin();
    XLList<int>::Iterator end = list->end();
    std::sort(begin, end, nodeComparator);
    std::sort(elements.begin(), elements.end());
    bool shouldBeTrueIfListIsSorted = true;
    int index = 0;
    for (auto iter: *list){
        std::cout<<iter.getValue()<<" "<<elements[index]<<" "<<(iter.getValue()==elements[index])<<std::endl;
        index++;
    }
    delete list;
    //assert
}
