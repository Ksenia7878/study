#pragma once
#include <iostream>
#include "Node.h"
#include "Payment.h"

//у стека все операции ќ(1)
//одн список добавление/удаление в начало ќ(1), добавление/удаление по индексу/в конец ќ(n),  поиск ќ(n)

template <class T>
class spisok_Node {
public:
    Node<T>* head, * tail;
    spisok_Node();
    ~spisok_Node();
    int cnt();
    Node<T>* getAt(int index); // возращение по индексу
    void insert(int index, T* data); //добавление по индексу
    void earsy(int index); //удаление по индексу
    Node<Payment>* poick();
};
extern template class spisok_Node<int>;
extern template class spisok_Node<float>;
extern template class spisok_Node<Payment>;
