//
// Created by Martin on 25-Oct-21.
//
#include <iostream>
#include "XLList.h"

int main(int argc, char **argv) {
    XLList<int> *list = new XLList<int>();
    std::cout<<list->getSize()<<std::endl;
    delete list;
    return 0;
}
