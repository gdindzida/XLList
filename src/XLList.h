#ifndef XLLIST_XLLIST_H
#define XLLIST_XLLIST_H

#include <iostream>

template<typename DataType>
struct Node {
    DataType data;
    Node *link;
};

template<typename T>
class XLList {
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    // Constructors and destructors
    XLList();
    XLList(const XLList<T>& other) = delete;
    XLList(XLList<T>&& other) = delete;
    ~XLList();

    // Inner class iterator
    class Iterator {
        friend class XLList;

    private:
        Node<T> *nodePtrBefore;
        Node<T> *nodePtrCurrent;

        Iterator(Node<T> *newNodePtrBefore, Node<T> *newNodePtrCurrent) : nodePtrBefore(newNodePtrBefore),
                                                                          nodePtrCurrent(newNodePtrCurrent) {};
        Node<T> *getNextPointer() const;

        Node<T> *getPreviousPointer() const;

        Node<T>* xorNodes(Node<T> *first, Node<T> *second) const;

    public:
        Iterator() : nodePtrBefore(nullptr), nodePtrCurrent(nullptr) {};

        bool operator!=(const Iterator &comparingIterator) const;

        bool operator==(const Iterator &comparingIterator) const;

        T &operator*() const;

        Iterator operator++();

        Iterator operator++(int);

        Iterator operator--();

        Iterator operator--(int);
    };

    // Public methods
    XLList<T>& operator=(const XLList<T>& other) = delete;
    XLList<T>& operator=(XLList<T>&& other) = delete;

    Iterator begin() const;
    Iterator end() const;
    bool addElement(T newElement, int index);
    bool removeElement(int index);
    T getElement(int index);
    bool pushFront(T newElement);
    bool pushBack(T newElement);
    T popFront();
    T popBack();
    int getSize();
};

#endif //XLLIST_XLLIST_H
