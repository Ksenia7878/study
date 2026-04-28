#include "Node.h"

template <class T>
Node<T>::Node(T* data) {
    this->data = data;
    this->next = NULL;
}



//трудоемкость в дек стек и односв


template <class T>
Node<T>::~Node() {
    delete data;  
}

template class Node<int>;
template class Node<float>;
template class Node<Payment>;