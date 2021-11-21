//
// Created by Martin on 24-Oct-21.
//

#include <gtest/gtest.h>
#include "XLList.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>

// static funcitons

// tests

/*
TEST(xLListTest, testXORFunction) {
    //arrange
    Node<int> beforeNode;
    Node<int> afterNode;
    Node<int> *beforeNodePtr = &beforeNode;
    Node<int> *afterNodePtr = &afterNode;
    //act
    Node<int> *linkNode = XLList<int>::Iterator::xorNodes(beforeNodePtr, afterNodePtr);
    Node<int> *linkNodeReverse = XLList<int>::Iterator::xorNodes(afterNodePtr, beforeNodePtr);
    Node<int> *beforeNodeCalculated = XLList<int>::Iterator::xorNodes(afterNodePtr, linkNode);
    Node<int> *afterNodeCalculated = XLList<int>::Iterator::xorNodes(linkNode, beforeNodePtr);
    //assert
    ASSERT_EQ(linkNode,linkNodeReverse);
    ASSERT_EQ(beforeNodePtr,beforeNodeCalculated);
    ASSERT_EQ(afterNodePtr,afterNodeCalculated);
}

TEST(xLListTest, testObjectConstruction) {
    //arrange
    int afterCreationSize;
    int afterCreationBytes;
    int afterDeletionBytes;
    //act
    XLList<int> *list = new XLList<int>();
    afterCreationSize = list->getSize();
    afterCreationBytes = sizeof(*list);
    XLList<int>::Iterator begin = list->begin();
    XLList<int>::Iterator end = list->end();
    delete list;
    //assert
    ASSERT_EQ(0,afterCreationSize);
    ASSERT_EQ(24,afterCreationBytes);
}

TEST(xLListTest, testAddingOneElement) {
    //arrange
    int listSizeAfterAddingOneElement = 0;
    //act
    XLList<int> *list = new XLList<int>();
    list->pushBack(1);
    listSizeAfterAddingOneElement = list->getSize();
    XLList<int>::Iterator begin = list->begin();
    begin++;
    XLList<int>::Iterator end = list->end();
    delete list;
    //assert
    ASSERT_EQ(1,listSizeAfterAddingOneElement);
    ASSERT_EQ(begin, end);
}

TEST(xLListTest, testAddingMultipleElementsAtTheEndOfTheList) {
    //arrange
    int listSizeAfterAddingMultipleElements = 0;
    int numberOfElementsToAdd = 987;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    XLList<int>::Iterator begin = list->begin();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        begin++;
    }
    listSizeAfterAddingMultipleElements = list->getSize();
    XLList<int>::Iterator end = list->end();
    delete list;
    //assert
    ASSERT_EQ(numberOfElementsToAdd,listSizeAfterAddingMultipleElements);
    ASSERT_EQ(begin, end);
}

TEST(xLListTest, testAddingMultipleElementsAtTheBeginingOfTheList) {
    //arrange
    int listSizeAfterAddingMultipleElements = 0;
    int numberOfElementsToAdd = 987;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushFront(iter);
    }
    XLList<int>::Iterator begin = list->begin();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        begin++;
    }
    listSizeAfterAddingMultipleElements = list->getSize();
    XLList<int>::Iterator end = list->end();
    delete list;
    //assert
    ASSERT_EQ(numberOfElementsToAdd,listSizeAfterAddingMultipleElements);
    ASSERT_EQ(begin, end);
}
TEST(xLListTest, testAddingMultipleElementsInTheMiddleOfTheList) {
    //arrange
    int listSizeAfterAddingMultipleElements = 0;
    int numberOfElementsToAdd = 987;
    srand (time(NULL));
    //act
    XLList<int> *list = new XLList<int>();
    list->pushBack(-1); // The begining of the list
    list->pushBack(-2); // The end of the list
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        int index = rand() % (list->getSize()-1) + 1;
        list->addElement(iter, index);
    }
    XLList<int>::Iterator begin = list->begin();
    for (int iter=0;iter<(numberOfElementsToAdd+2);++iter){
        begin++;
    }
    listSizeAfterAddingMultipleElements = list->getSize();
    XLList<int>::Iterator end = list->end();
    delete list;
    //assert
    ASSERT_EQ(numberOfElementsToAdd+2,listSizeAfterAddingMultipleElements);
    ASSERT_EQ(begin, end);
}

TEST(xLListTest, testRemovingElementsAtTheFrontOfTheList) {
    //arrange
    int listSizeAfterAddingAndRemovingMultipleElements = 0;
    int numberOfElementsToAdd = 987;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    for (int iter=0;iter<(numberOfElementsToAdd-1);++iter){
        list->popFront();
    }
    listSizeAfterAddingAndRemovingMultipleElements = list->getSize();
    XLList<int>::Iterator begin = list->begin();
    begin++;
    XLList<int>::Iterator end = list->end();
    delete list;
    //assert
    ASSERT_EQ(1,listSizeAfterAddingAndRemovingMultipleElements);
    ASSERT_EQ(begin, end);
}

TEST(xLListTest, testRemovingMultipleElementsInTheMiddleOfTheList) {
    //arrange
    int listSizeAfterAddingAndRemovingMultipleElements = 0;
    int numberOfElementsToAdd = 987;
    srand (time(NULL));
    //act
    XLList<int> *list = new XLList<int>();
    list->pushBack(-1); // The begining of the list
    list->pushBack(-2); // The end of the list
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        int index = rand() % (list->getSize()-1) + 1;
        list->addElement(iter, index);
    }
    for (int iter=0;iter<(numberOfElementsToAdd+1);++iter){
        int index = rand() % (list->getSize()-1) + 1;
        list->removeElement(index);
    }
    XLList<int>::Iterator begin = list->begin();
    begin++;
    XLList<int>::Iterator end = list->end();
    listSizeAfterAddingAndRemovingMultipleElements = list->getSize();
    delete list;
    //assert
    ASSERT_EQ(1,listSizeAfterAddingAndRemovingMultipleElements);
    ASSERT_EQ(begin, end);
}

TEST(xLListTest, testRemovingElementsAtTheEndOfTheList) {
    //arrange
    int listSizeAfterAddingAndRemovingMultipleElements = 0;
    int numberOfElementsToAdd = 987;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    for (int iter=0;iter<(numberOfElementsToAdd-1);++iter){
        list->popBack();
    }
    listSizeAfterAddingAndRemovingMultipleElements = list->getSize();
    XLList<int>::Iterator begin = list->begin();
    begin++;
    XLList<int>::Iterator end = list->end();
    delete list;
    //assert
    ASSERT_EQ(1,listSizeAfterAddingAndRemovingMultipleElements);
    ASSERT_EQ(begin, end);
}

TEST(xLListTest, testFetchingElementAtTheFrontOfTheList) {
    //arrange
    int numberOfElementsToAdd = 67;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    int frontElement = list->getElement(0);
    delete list;
    //assert
    ASSERT_EQ(0, frontElement);
}

TEST(xLListTest, testFetchingElementAtTheEndtOfTheList) {
    //arrange
    int numberOfElementsToAdd = 67;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    int endElement = list->getElement(list->getSize()-1);
    delete list;
    //assert
    ASSERT_EQ(66, endElement);
}

TEST(xLListTest, testFetchingElementInTheMiddleOfTheList) {
    //arrange
    int numberOfElementsToAdd = 67;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    int middleElement = list->getElement(numberOfElementsToAdd/2);
    delete list;
    //assert
    ASSERT_EQ(numberOfElementsToAdd/2, middleElement);
}

TEST(xLListTest, testAddingOutOfBounds) {
    //arrange
    int numberOfElementsToAdd = 67;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    bool shouldBeFalseBecauseLessThanZero = list->addElement(13,-1);
    bool shouldBeFalseBecauseGreaterThanSize = list->addElement(13,numberOfElementsToAdd+1);
    delete list;
    //assert
    ASSERT_FALSE(shouldBeFalseBecauseLessThanZero);
    ASSERT_FALSE(shouldBeFalseBecauseGreaterThanSize);
}

TEST(xLListTest, testRemovingOutOfBounds) {
    //arrange
    int numberOfElementsToAdd = 67;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    bool shouldBeFalseBecauseLessThanZero = list->removeElement(-1);
    bool shouldBeFalseBecauseGreaterThanSize = list->removeElement(numberOfElementsToAdd+1);
    delete list;
    //assert
    ASSERT_FALSE(shouldBeFalseBecauseLessThanZero);
    ASSERT_FALSE(shouldBeFalseBecauseGreaterThanSize);
}

TEST(xLListTest, testFetchingOutOfBounds) {
    //arrange
    int numberOfElementsToAdd = 67;
    //act
    XLList<int> *list = new XLList<int>();
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        list->pushBack(iter);
    }
    bool shouldBeFalseBecauseLessThanZero = list->getElement(-1);
    bool shouldBeFalseBecauseGreaterThanSize = list->getElement(numberOfElementsToAdd+1);
    delete list;
    //assert
    ASSERT_FALSE(shouldBeFalseBecauseLessThanZero);
    ASSERT_FALSE(shouldBeFalseBecauseGreaterThanSize);
}

TEST(xLListTest, testForLoop) {
    //arrange
    int numberOfElementsToAdd = 864;
    //act
    XLList<int> *list = new XLList<int>();
    std::vector<int> elements;
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        int elementToAdd = rand()%1000;
        list->pushBack(elementToAdd);
        elements.push_back(elementToAdd);
    }
    //assert
    int index = 0;
    for (auto iter: *list){
        ASSERT_EQ(elements[index], iter.getValue());
        index++;
    }
    delete list;
}


TEST(xLListTest, testGoingBackwards) {
    //arrange
    int numberOfElementsToAdd = 864;
    //act
    XLList<int> *list = new XLList<int>();
    std::vector<int> elements;
    for (int iter=0;iter<numberOfElementsToAdd;++iter){
        int elementToAdd = rand()%1000;
        list->pushBack(elementToAdd);
        elements.push_back(elementToAdd);
    }
    XLList<int>::Iterator endIter = list->end();
    XLList<int>::Iterator beginIter = list->begin();
    for (int i=0;i<numberOfElementsToAdd;i++){
        endIter--;
    }
    bool isTrue = endIter == beginIter;
    delete list;
    //assert
    ASSERT_TRUE(isTrue);
}
*/

TEST(xLListTest, testBasicIteratorLoop){
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
    XLList<int>::Iterator begin = list->begin();
    XLList<int>::Iterator end = list->end();
    XLList<int>::Iterator iter;
    iter=begin+1;
    for (;iter!=end;++iter){}
    ASSERT_EQ(iter,end);
}

/*TEST(xLListTest, testSortingList) {
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
        shouldBeTrueIfListIsSorted = shouldBeTrueIfListIsSorted && (iter.getValue()==elements[index]);
        index++;
    }
    delete list;
    //assert
    ASSERT_TRUE(shouldBeTrueIfListIsSorted);
}*/


