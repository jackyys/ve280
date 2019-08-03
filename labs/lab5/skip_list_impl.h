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
SkipList<T>::SkipList(const SkipList &l) : level(), header() {
    *this = l;
}

template<class T>
SkipList<T> &SkipList<T>::operator=(const SkipList &l) {
    if (this != &l) {
        this->~SkipList();

        level = l.level;
        header = new Node(T(), MAX_LEVEL);

        Node *source[MAX_LEVEL];
        std::fill_n(source, MAX_LEVEL, l.header);

        Node *target[MAX_LEVEL];
        std::fill_n(target, MAX_LEVEL, header);

        Node *node = source[0]->forward[0];
        while (node) {
            int nlevel = 0;
            while (nlevel < MAX_LEVEL && source[nlevel]->forward[nlevel] == node) {
                source[nlevel] = source[nlevel]->forward[nlevel];
                nlevel++;
            }
            Node *copy = new Node(node->value, nlevel);
            for (int i = 0; i < nlevel; i++) {
                target[i]->forward[i] = copy;
                target[i] = target[i]->forward[i];
            }
            node = node->forward[0];
        }
    }
    return *this;
}

template<class T>
SkipList<T>::~SkipList() {
    Node *node = header;
    while (node) {
        Node *next = node->forward[0];
        delete node;
        node = next;
    }
}

template<class T>
void SkipList<T>::insert(T value) {
    Node *update[MAX_LEVEL];
    std::fill_n(update, MAX_LEVEL, nullptr);

    Node *x = header;
    for (int i = level - 1; i >= 0; --i) {
        while (x->forward[i] && x->forward[i]->value < value) {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    if (!x || x->value != value) {
        int rlevel = randomLevel();
        if (rlevel > level) {
            for (int i = level; i < rlevel; ++i) {
                update[i] = header;
            }
            level = rlevel;
        }
        Node *n = new Node(value, rlevel);
        for (int i = 0; i < rlevel; ++i) {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
    }
}

template<class T>
bool SkipList<T>::search(T value) const {
    Node *x = header;
    for (int i = level - 1; i >= 0; --i) {
        while (x->forward[i] && x->forward[i]->value < value) {
            x = x->forward[i];
        }
    }
    x = x->forward[0];
    return x && x->value == value;
};

template<class T>
void SkipList<T>::remove(T value) {
    Node *update[MAX_LEVEL];
    std::fill_n(update, MAX_LEVEL, nullptr);

    Node *x = header;
    for (int i = level - 1; i >= 0; --i) {
        while (x->forward[i] && x->forward[i]->value < value) {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    if (x && x->value == value) {
        for (int i = 0; i < level; ++i) {
            if (update[i]->forward[i] != x) {
                break;
            }
            update[i]->forward[i] = x->forward[i];
        }
        delete x;
        while (level > 1 && !header->forward[level - 1]) {
            level -= 1;
        }
    }
}

template<class T>
void SkipList<T>::display() const {
    for (int i = level - 1; i >= 0; i--) {
        Node *node = header->forward[i];
        Node *base = header->forward[0];
        std::cout << "[" << i << "] ";
        while (node) {
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
        while (base) {
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
