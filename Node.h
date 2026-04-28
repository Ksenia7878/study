#pragma once
#include "Payment.h"

template <class T>
class Node {
public:
    T* data; //указатель на объект
    Node* next;
    Node(T* data);
    ~Node();  
};

extern template class Node<int>;
extern template class Node<float>;
extern template class Node<Payment>;