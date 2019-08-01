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
SkipList<T>::SkipList() : level(1), header(new Node(T(), MAX_LEVEL)) {}

template<class T>
SkipList<T>::SkipList(const SkipList &l) {
    copyAll(l);
}

template<class T>
SkipList<T> &SkipList<T>::operator=(const SkipList &l) {
    if (this != &l) {
        removeAll();
        copyAll(l);
    }
    return *this;
}

template<class T>
SkipList<T>::~SkipList() {
    removeAll();
}

template<class T>
void SkipList<T>::insert(T value) {
    Node* update[MAX_LEVEL];
    Node* x = header;
    for (int i = level - 1; i >= 0; --i) {
        while (x->forward[i] && x->forward[i]->value < value) x = x->forward[i];
        update[i] = x;
    }   
    x = x->forward[0];
    if (!x || x->value != value) {
        int rlevel = randomLevel();
        if (rlevel > level) {
            for (int i = level; i < rlevel; ++i) update[i] = header;
            level = rlevel;
        }
        x = new Node(value, rlevel);
        for (int i = 0; i < rlevel; ++i) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
}

template<class T>
bool SkipList<T>::search(T value) const {
    Node* x = header;
    for (int i = level - 1; i >= 0; --i) {
        while (x->forward[i] && x->forward[i]->value < value) x = x->forward[i];
    }
    x = x->forward[0];
    if (x && x->value == value) return true;
    else return false;
};

template<class T>
void SkipList<T>::remove(T value) {
    Node* update[MAX_LEVEL];
    Node* x = header;
    for (int i = level - 1; i >= 0; --i) {
        while (x->forward[i] && x->forward[i]->value < value) x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[0];
    if (x && x->value == value) {
        for (int i = 0; i < level; ++i) {
            if (update[i]->forward[i] != x) break;
            update[i]->forward[i] = x->forward[i];
        }
        delete x;
        while (level > 1 && header->forward[level] == nullptr) level -= 1; 
    }
}

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

template<class T>
void SkipList<T>::removeAll() {
    Node* node = header;
    while (header) {
        node = header;
        header = node->forward[0];
        delete node;
    }
}

template<class T>
void SkipList<T>::copyAll(const SkipList &l) {
    level = l.level;
    header = new Node(T(), MAX_LEVEL);
    Node* source[MAX_LEVEL];
    Node* target[MAX_LEVEL];
    Node* node = l.header->forward[0];
    int nodeLevel = 0;
    if (!node) return;
    for (int i = 0; i < l.level; ++i) {
        source[i] = l.header->forward[i];
        target[i] = header;
    }
    while (node) {
        nodeLevel = 0;
        for (int i = 0; i < l.level; ++i) {
            if (!source[i]) break;
            if (node->value == source[i]->value) nodeLevel++;
        }
        Node* x = new Node(node->value, nodeLevel);
        for (int i = 0; i < nodeLevel; ++i) {
            target[i]->forward[i] = x;
            target[i] = x;
        }
        for (int i = 0; i < l.level; ++i) {
            if (!source[i]) break;
            if (node->value == source[i]->value) source[i] = source[i]->forward[i];
        }
        node = node->forward[0];
    }
}

#endif
