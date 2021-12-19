//
// Created by Vishweshwar Ramanakumar on 2/28/21.
//

#ifndef PROJECT1_NODE_H
#define PROJECT1_NODE_H

template <typename T>
class Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    T data;
};


#endif //PROJECT1_NODE_H
