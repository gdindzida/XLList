#ifndef XLLIST_XLLIST_H
#define XLLIST_XLLIST_H

#include <iostream>


// Declaration

template<typename DataType>
struct Node {
    DataType data;
    Node *link;

    Node(){
        link = nullptr;
    }

    Node(const Node<DataType>& otherNode) {
        data = otherNode.data;
        link = otherNode.link;
    }

    Node<DataType>& operator=(Node<DataType>&& otherNode) {
        this->link = otherNode.link;
        this->data = otherNode.data;
        return  *this;
    }
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
class Iterator : public std::iterator<std::random_access_iterator_tag, Node<T>, long int> {
        friend class XLList;

    private:
        Node<T> *nodePtrBefore;
        Node<T> *nodePtrCurrent;
        int index;

        Iterator(Node<T> *newNodePtrBefore, Node<T> *newNodePtrCurrent) : nodePtrBefore(newNodePtrBefore),
                                                                          nodePtrCurrent(newNodePtrCurrent) {
            index = 0;
        };
        Node<T> *getNextPointer() const;

        Node<T> *getPreviousPointer() const;

    public:
        void setIndex(int newIndex);

        Iterator() : nodePtrBefore(nullptr), nodePtrCurrent(nullptr) {};

        bool operator!=(const Iterator &comparingIterator) const;

        bool operator==(const Iterator &comparingIterator) const;

        bool operator<(const Iterator &comparingIterator) const;

        bool operator<=(const Iterator &comparingIterator) const;

        bool operator>(const Iterator &comparingIterator) const;

        bool operator>=(const Iterator &comparingIterator) const;

        long int operator+(const Iterator otherIterator);

        long int operator-(const Iterator otherIterator);

        Iterator operator+(const long int difference);

        Iterator & operator+=(const long int &difference);

        Iterator operator-(const long int difference);

        Iterator & operator-=(const long int &difference);

        Node<T> & operator[](const long int &index);

        Node<T> operator*();

        const Iterator &operator++();

        Iterator operator++(int);

        const Iterator &operator--();

        Iterator operator--(int);

        Iterator & operator=(Iterator other);

        static Node<T>* xorNodes(Node<T> *first, Node<T> *second);
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

// Definition

// Private methods

// Constructors and destructors
template<typename T>
XLList<T>::XLList() {
    head = tail = new Node<T>();
    size = 0;
}

template<typename T>
XLList<T>::~XLList<T>() {
    for (int iter = size-1; iter>=0; iter--){
        removeElement(iter);
    }
    delete head;
}

// Iterator methods
template<typename T>
void XLList<T>::Iterator::setIndex(int newIndex){
    index = newIndex;
}

template<typename T>
bool XLList<T>::Iterator::operator!=(const Iterator &comparingIterator) const {
    return (index!=comparingIterator.index) || (nodePtrCurrent!=comparingIterator.nodePtrCurrent) || (nodePtrBefore!=comparingIterator.nodePtrBefore);
}

template<typename T>
bool XLList<T>::Iterator::operator==(const Iterator &comparingIterator) const {
    return (index==comparingIterator.index) & (nodePtrCurrent==comparingIterator.nodePtrCurrent) & (nodePtrBefore==comparingIterator.nodePtrBefore);
}

template<typename T>
bool XLList<T>::Iterator::operator<(const Iterator &comparingIterator) const {
    return index<comparingIterator.index;
}

template<typename T>
bool XLList<T>::Iterator::operator<=(const Iterator &comparingIterator) const {
    return index<=comparingIterator.index;
}

template<typename T>
bool XLList<T>::Iterator::operator>(const Iterator &comparingIterator) const {
    return index>comparingIterator.index;
}

template<typename T>
bool XLList<T>::Iterator::operator>=(const Iterator &comparingIterator) const {
    return index>=comparingIterator.index;
}

template<typename T>
long int XLList<T>::Iterator::operator+(const Iterator otherIterator){
    return index + otherIterator.index;
}

template<typename T>
long int XLList<T>::Iterator::operator-(const Iterator otherIterator){
    return index - otherIterator.index;
}

template<typename T>
typename XLList<T>::Iterator XLList<T>::Iterator::operator+(const long int difference){
    XLList<T>::Iterator copyIterator(*this);
    for (int iter=0;iter<difference;iter++) {
        Node<T> *helperPtr = copyIterator.getNextPointer();
        copyIterator.nodePtrBefore = copyIterator.nodePtrCurrent;
        copyIterator.nodePtrCurrent = helperPtr;
        copyIterator.index++;
    }
    return copyIterator;

}

template<typename T>
typename XLList<T>::Iterator XLList<T>::Iterator::operator-(const long int difference){
    XLList<T>::Iterator copyIterator = *this;
    for (int iter=0;iter<difference;iter++) {
        Node<T> *helperPtr = copyIterator.getPreviousPointer();
        copyIterator.nodePtrCurrent = copyIterator.nodePtrBefore;
        copyIterator.nodePtrCurrent = helperPtr;
        copyIterator.index--;
    }
    return copyIterator;
}

template<typename T>
typename XLList<T>::Iterator & XLList<T>::Iterator::operator+=(const long int &difference) {
    return *this + difference;
}

template<typename T>
typename XLList<T>::Iterator & XLList<T>::Iterator::operator-=(const long int &difference){
    return *this - difference;
}

template<typename T>
Node<T> & XLList<T>::Iterator::operator[](const long int &index){
    long int difference = index - this->index;
    return *(*this+difference);
}

template<typename T>
Node<T> XLList<T>::Iterator::operator*(){
    return *nodePtrCurrent;
}

template<typename T>
const typename XLList<T>::Iterator &XLList<T>::Iterator::operator++() {
    Node<T> *tempNode = getNextPointer();
    nodePtrBefore = nodePtrCurrent;
    nodePtrCurrent = tempNode;
    index++;
    return *this;
}

template<typename T>
typename XLList<T>::Iterator XLList<T>::Iterator::operator++(int) {
    XLList<T>::Iterator temp = *this;
    Node<T> *tempNode = getNextPointer();
    nodePtrBefore = nodePtrCurrent;
    nodePtrCurrent = tempNode;
    index++;
    return temp;
}

template<typename T>
const typename XLList<T>::Iterator &XLList<T>::Iterator::operator--() {
    Node<T> *tempNode = getPreviousPointer();
    nodePtrCurrent = nodePtrBefore;
    nodePtrBefore = tempNode;
    index--;
    return *this;
}

template<typename T>
typename XLList<T>::Iterator XLList<T>::Iterator::operator--(int) {
    XLList<T>::Iterator temp = *this;
    Node<T> *tempNode = getPreviousPointer();
    nodePtrCurrent = nodePtrBefore;
    nodePtrBefore = tempNode;
    index--;
    return temp;
}

template<typename T>
typename XLList<T>::Iterator & XLList<T>::Iterator::operator=(XLList<T>::Iterator other){
    this->index = other.index;
    this->nodePtrCurrent = other.nodePtrCurrent;
    this->nodePtrBefore = other.nodePtrBefore;
    return *this;
}

template<typename T>
Node<T> *XLList<T>::Iterator::getNextPointer() const {
    return xorNodes(nodePtrBefore, nodePtrCurrent->link);
}

template<typename T>
Node<T> *XLList<T>::Iterator::getPreviousPointer() const {
    return xorNodes(nodePtrBefore->link, nodePtrCurrent);
}

template<typename T>
Node<T> *XLList<T>::Iterator::xorNodes(Node<T> *first, Node<T> *second) {
    return reinterpret_cast<Node<T> *>(reinterpret_cast<uintptr_t>(first) ^ reinterpret_cast<uintptr_t>(second));
}

// Public methods
template<typename T>
typename XLList<T>::Iterator XLList<T>::begin() const {
    XLList<T>::Iterator beginIterator = Iterator(head, head->link);
    beginIterator.setIndex(-1);
    return beginIterator;
}

template<typename T>
typename XLList<T>::Iterator XLList<T>::end() const {
    XLList<T>::Iterator endIterator = Iterator(tail, head);
    endIterator.setIndex(size-1);
    return endIterator;
}

template<typename T>
bool XLList<T>::addElement(T newElement, int index) {
    if (index < 0 || index > size) return false;
    Node<T> *newNode = new Node<T>();
    newNode->data = newElement;
    if (size == 0) {
        newNode->link = Iterator::xorNodes(head, tail);
        head->link = newNode;
        tail = newNode;
    } else {
        if (index == size) {
            newNode->link = Iterator::xorNodes(tail, head);
            tail->link = Iterator::xorNodes(tail->link, head);
            tail->link = Iterator::xorNodes(tail->link, newNode);
            tail = newNode;
        } else {
            Iterator listIterator = begin();
            int currentIndex = 0;
            while (currentIndex != index) {
                ++listIterator;
                ++currentIndex;
            }
            // Define link in new node.
            newNode->link = Iterator::xorNodes(listIterator.nodePtrBefore, listIterator.nodePtrCurrent);
            // Update link in prevoius node.
            listIterator.nodePtrBefore->link = Iterator::xorNodes(listIterator.nodePtrBefore->link,
                                                                  listIterator.nodePtrCurrent);
            listIterator.nodePtrBefore->link = Iterator::xorNodes(listIterator.nodePtrBefore->link, newNode);
            // Update link in current (next) node.
            listIterator.nodePtrCurrent->link = Iterator::xorNodes(listIterator.nodePtrBefore,
                                                                   listIterator.nodePtrCurrent->link);
            listIterator.nodePtrCurrent->link = Iterator::xorNodes(newNode, listIterator.nodePtrCurrent->link);
        }
    }
    ++size;
    return true;
}

template<typename T>
bool XLList<T>::removeElement(int index) {
    if (index < 0 || index >= size) return false;
    if (size == 1) {
        tail = head;
        delete head->link;
    } else {
        if (index == size - 1) {
            Node<T> *previousNode = Iterator::xorNodes(tail->link, head);
            previousNode->link = Iterator::xorNodes(previousNode->link, tail);
            previousNode->link = Iterator::xorNodes(previousNode->link, head);
            delete tail;
            tail = previousNode;
        } else {
            Iterator listIterator = begin();
            int currentIndex = 0;
            while (currentIndex != index) {
                ++listIterator;
                ++currentIndex;
            }
            Node<T> *previousToDelete = listIterator.nodePtrBefore;
            ++listIterator;
            // Update link in prevoius node.
            previousToDelete->link = Iterator::xorNodes(previousToDelete->link, listIterator.nodePtrBefore);
            previousToDelete->link = Iterator::xorNodes(previousToDelete->link, listIterator.nodePtrCurrent);
            // Update link in next node.
            listIterator.nodePtrCurrent->link = Iterator::xorNodes(listIterator.nodePtrBefore,
                                                                   listIterator.nodePtrCurrent->link);
            listIterator.nodePtrCurrent->link = Iterator::xorNodes(previousToDelete, listIterator.nodePtrCurrent->link);

            delete listIterator.nodePtrBefore;
        }
    }
    --size;
    return true;
}

template<typename T>
T XLList<T>::getElement(int index) {
    if (index < 0 || index >= size) return false;
    Iterator listIterator = begin();
    int currentIndex = 0;
    while (currentIndex != index) {
        ++listIterator;
        ++currentIndex;
    }
    return  (*listIterator).data;
}

template<typename T>
bool XLList<T>::pushFront(T newElement){
    return addElement(newElement, 0);
}

template<typename T>
bool XLList<T>::pushBack(T newElement){
    return addElement(newElement, size);
}

template<typename T>
T XLList<T>::popFront(){
    T element = getElement(0);
    removeElement(0);
    return element;
}

template<typename T>
T XLList<T>::popBack(){
    T element = getElement(size-1);
    removeElement(size-1);
    return element;
}

template<typename T>
int XLList<T>::getSize() {
    return size;
}

#endif //XLLIST_XLLIST_H
