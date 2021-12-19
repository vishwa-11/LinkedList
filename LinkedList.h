//
// Created by Vishweshwar Ramanakumar on 2/26/21.
//

#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H
#include <iostream>
#include <vector>
#include <string>
#include <array>
//#include "leaker.h"
using namespace std;
template <typename T>



class LinkedList {
public:

    struct Node {
        Node *next = nullptr;
        Node *prev = nullptr;
        T data;
    };

    LinkedList();
    ~LinkedList();
    void InsertAfter(Node* node, const T& data);
    void InsertBefore(Node* node, const T& data);
    void InsertAt(const T& data, unsigned int index);
    bool operator==(const LinkedList<T>& rhs) const;
    void AddHead(const T& data);
    void AddTail(const T& data);
    void AddNodesHead(const T* data, unsigned int count);
    void AddNodesTail(const T* data, unsigned int count);
    unsigned int NodeCount() const;
    void PrintForward() const;
    void PrintReverse() const;
    Node* Head();
    const Node* Head() const;
    Node* Tail();
    const Node* Tail() const;
    Node* GetNode(unsigned int index);
    const Node* GetNode(unsigned int index) const;
    T& operator[](unsigned index);
    Node* Find(const T& data);
    const Node* Find(const T& data) const;
    void FindAll(vector<Node*>& outData, const T& value) const;
    LinkedList(const LinkedList<T>& list);
    LinkedList<T>& operator=(const LinkedList<T>& rhs);
    bool RemoveHead();
    bool RemoveTail();
    bool RemoveAt(unsigned int index);
    unsigned int Remove(const T&data);
    void Clear();
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive(const Node* node) const;

private:
    Node *head;
    Node *tail;
    unsigned int nodeCount = 0;
};


template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
    return head;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
    return head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
    return tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
    return tail;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
    if (index >= nodeCount) {
        throw out_of_range("Out of range.");
    }
    else {
        Node* node = head;
        for (int i = 0; i < (int)index; i++) {
            node = node->next;
        }
        return node;
    }
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
    if (index >= nodeCount) {
        throw out_of_range("Out of range.");
    }
    else {
        Node* node = head;
        for (int i = 0; i < (int)index; i++) {
            node = node->next;
        }
        return node;
    }
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
    if (index >= nodeCount) {
        throw out_of_range("");
    }
    else {
        Node* node = head;
        for (int i = 0; i < (int)index; i++) {
            node = node->next;
        }
        return node->data;
        delete node;
    }

}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T &data) const {
    Node* node = head;
    int match = 0;
    for (int i = 0; i < (int)nodeCount; i++) {
        if (node->data == data) {
            match++;
            break;
        }
        else {
            node = node->next;
            continue;
        }
    }
    if (match > 0) {
        return node;
    }
    else {
        return nullptr;
    }
    //delete node;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
    Node* node = head;
    int match = 0;
    for (int i = 0; i < (int)nodeCount; i++) {
        if (node->data == data) {
            match++;
            break;
        }
        else {
            node = node->next;
            continue;
        }
    }
    if (match > 0) {
        return node;
    }
    else {
        return nullptr;
    }
    //delete node;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node *> &outData, const T &value) const {
    Node* node = head;
    for (int i = 0; i < (int)nodeCount; i++) {
        if (node->data == value) {
            outData.push_back(node);
            node = node->next;
            continue;
        }
        else {
            node = node->next;
            continue;
        }
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
    Node* node = rhs.head;

    while (node != nullptr) {
        AddTail(node->data);
        node = node->next;
        nodeCount++;
    }

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
    Node * deleteNode = head;
    while (deleteNode != nullptr) {
        head = head->next;
        delete deleteNode;
        deleteNode = head;
    }
    nodeCount = 0;
    Node* node = rhs.head;

    while (node != nullptr) {
        AddTail(node->data);
        node = node->next;
        nodeCount++;
    }
    return *this;
}

template <typename T>
LinkedList<T>::LinkedList() {
    nodeCount = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node * deleteNode = head;
    while (deleteNode != nullptr) {
        head = head->next;
        delete deleteNode;
        deleteNode = head;
    }
    nodeCount = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void LinkedList<T>::AddHead(const T &data) {
    if (nodeCount == 0) {
        Node* currentNode = new Node;
        currentNode->data = data;
        currentNode->prev = nullptr;
        currentNode->next = nullptr;
        head = currentNode;

    }
    else if (nodeCount == 1) {
        Node* currentNode = new Node;
        currentNode->data = data;
        currentNode->next = head;
        currentNode->prev = nullptr;
        head->prev = currentNode;
        tail = head;
        head = currentNode;

    }
    else if (nodeCount > 1) {
        Node* currentNode = new Node;
        currentNode->data = data;
        currentNode->next = head;
        currentNode->prev = nullptr;
        head->prev = currentNode;
        head = currentNode;

    }
    nodeCount++;
}

template <typename T>
void LinkedList<T>::AddTail(const T &data) {
    Node* currentNode = new Node;
    if (nodeCount == 0) {

        currentNode->data = data;
        currentNode->prev = nullptr;
        currentNode->next = nullptr;
        head = currentNode;
        tail = currentNode;

    }
    else if (nodeCount == 1) {

        currentNode->data = data;
        currentNode->next = nullptr;
        currentNode->prev = head;
        head->next = currentNode;
        tail = currentNode;
    }
    else if (nodeCount > 1) {

        currentNode->data = data;
        currentNode->next = nullptr;
        currentNode->prev = tail;
        tail->next = currentNode;
        tail = currentNode;
    }
    nodeCount++;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T *data, unsigned int count) {

    for (int i = (int)count - 1; i >= 0; i--) {
        AddHead(data[i]);
    }
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {

        AddTail(data[i]);
    }

}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
    return nodeCount;
}

template <typename T>
void LinkedList<T>::PrintForward() const {
    cout << head->data << endl;
    Node * pointer = head->next;
    /*for (unsigned int i = 0; i < nodeCount - 2; i++) {
        cout << pointer->data << endl;
        pointer = pointer->next;
    }*/
    while (pointer != nullptr) {
        cout << pointer->data << endl;
        pointer = pointer->next;
    }
    //cout << tail->data << endl;
}

template <typename T>
void LinkedList<T>::PrintReverse() const {
    cout << tail->data << endl;
    Node * pointer = tail->prev;
    /*for (unsigned int i = 0; i < nodeCount - 2; i++) {
        cout << pointer->data << endl;
        pointer = pointer->prev;
    }*/
    while (pointer != nullptr) {
        cout << pointer->data << endl;
        pointer = pointer->prev;
    }
    //cout << head->data << endl;
}

template<typename T>
void LinkedList<T>::InsertAfter(LinkedList::Node *node, const T &data) {
    Node* node1 = new Node;
    if (node == tail) {
        node->next = node1;
        tail = node1;
        node1->next = nullptr;

    }
    else if (nodeCount == 2 && node != tail) {
        head-> next = node1;
        node1->prev = node;
        node1->next = tail;
        tail->prev = node1;
    }
    else {
        node->next->prev = node1;
        node1->next = node->next;
        node->next = node1;
        node1->prev = node;
        if (node == tail) {
            node1 = tail;
        }
    }
    node1->data = data;
    nodeCount++;
}

template<typename T>
void LinkedList<T>::InsertBefore(LinkedList::Node *node, const T &data) {
    Node* node1 = new Node;
    if (node == head) {
        node->prev = node1;
        head = node1;
        node1->prev = nullptr;

    }
    else if (nodeCount == 2 && node != head) {
        head-> next = node1;
        node1->prev = node;
        node1->next = tail;
        tail->prev = node1;
    }
    else {
        node->prev->next = node1;
        node1->prev = node->prev;
        node->prev = node1;
        node1->next = node;
        if (node == head) {
            node1 = head;
        }
    }
    node1->data = data;
    nodeCount++;
}

template<typename T>
void LinkedList<T>::InsertAt(const T &data, unsigned int index) {
    if (index > nodeCount) {
        throw out_of_range("Out of range.");
    }
    if (index == 0) {
        AddHead(data);
    }
    else if (index == nodeCount) {
        AddTail(data);
    }
    else {
        InsertBefore(GetNode(index), data);
    }

    nodeCount++;


}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const {


    bool match = true;
    for (int i = 0; i < (int)nodeCount; i++) {
        if (GetNode(i)->data != rhs.GetNode(i)->data) {
            match = false;
            break;
        }
    }
    return match;
}

template<typename T>
bool LinkedList<T>::RemoveHead() {
    if (nodeCount == 0) {
        return false;
    }
    else {
        if (nodeCount == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* node = head->next;
            node->prev = nullptr;
            delete head;
            head = node;
        }
        nodeCount--;
        return true;
    }

}

template<typename T>
bool LinkedList<T>::RemoveTail() {
    if (nodeCount == 0) {
        return false;
    }
    else {
        if (nodeCount == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            nodeCount--;
            return true;
        }
        else {
            Node* node = tail->prev;
            node->next = nullptr;
            delete tail;
            tail = node;
            nodeCount--;
            return true;
        }
    }
}

template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
    if (nodeCount == 0 || index >= nodeCount) {
        return false;
    }
    if (index == 0) {
        RemoveHead();
        return true;
    }
    if (index == nodeCount - 1) {
        RemoveTail();
        return true;
    }

        Node* node = GetNode(index);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        nodeCount--;
        return true;
}

template<typename T>
unsigned int LinkedList<T>::Remove(const T &data) {
    unsigned int removals = 0;
    for (unsigned int i = 0; i < nodeCount; i++) {
        if (GetNode(i)->data == data) {
            RemoveAt(i);
            removals++;
        }
    }
    nodeCount = nodeCount - removals;
    return removals;
}

template<typename T>
void LinkedList<T>::Clear() {
    Node * deleteNode = head;
    while (deleteNode != nullptr) {
        head = head->next;
        delete deleteNode;
        deleteNode = head;
    }
    nodeCount = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void LinkedList<T>::PrintForwardRecursive(const LinkedList::Node *node) const {
    cout << node->data << endl;
    if (node->next != nullptr) {
        PrintForwardRecursive(node->next);
    }
}

template<typename T>
void LinkedList<T>::PrintReverseRecursive(const LinkedList::Node *node) const {
    cout << node->data << endl;
    if (node->prev != nullptr) {
        PrintReverseRecursive(node->prev);
    }
}


#endif //PROJECT1_LINKEDLIST_H
