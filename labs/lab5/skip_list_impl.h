#ifndef SKIP_LIST_IMPL_H
#define SKIP_LIST_IMPL_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>

const double P = 0.5;
// the fraction of the nodes with level i pointers also having level i+1 pointers

const int MAX_LEVEL = 25;
// maximum level of a skip list

static int randomLevel();
// EFFECTS: generate a random level for node

template<class T>
SkipList<T>::Node::Node(T value, int level) : value(value), forward(new Node *[level]()) {};

template<class T>
SkipList<T>::Node::~Node() {
    delete[] forward;
}

template<class T>
SkipList<T>::SkipList() {
    // TODO: Your implementation here
};

template<class T>
SkipList<T>::SkipList(const SkipList &l) {
    // TODO: Your implementation here
}

template<class T>
SkipList<T> &SkipList<T>::operator=(const SkipList &l) {
    // TODO: Your implementation here
    return *this;
}

template<class T>
SkipList<T>::~SkipList() {
    // TODO: Your implementation here
}

template<class T>
void SkipList<T>::insert(T value) {
    // TODO: Your implementation here
};

template<class T>
bool SkipList<T>::search(T value) const {
    // TODO: Your implementation here
    return false;
};

template<class T>
void SkipList<T>::remove(T value) {
    // TODO: Your implementation here
};

template<class T>
void SkipList<T>::display() const {
    for (int i = level - 1; i >= 0; i--) {
        Node *node = header->forward[i];
        Node *base = header->forward[0];
        std::cout << "[" << i << "] ";
        while (node != nullptr) {
            while (base->value != node->value) {
                std::ostringstream oss;
                oss << base->value;
                std::cout << std::string(oss.str().length(), '-') << " ";
                base = base->forward[0];
            }
            std::cout << node->value << " ";
            node = node->forward[i];
            base = base->forward[0];
        }
        while (base != nullptr) {
            std::ostringstream oss;
            oss << base->value;
            std::cout << std::string(oss.str().length(), '-') << " ";
            base = base->forward[0];
        }
        std::cout << std::endl;
    }
};

static int randomLevel() {
    int level = 1;
    while ((double) rand() / RAND_MAX < P && level < MAX_LEVEL) {
        level++;
    }
    return level;
};

#endif
