#pragma once

#include <iostream>
#include "Node.h"
#include "Payment.h"
#include "spisok_Node.h"

template <class T>
class Dec {
public:
    spisok_Node<T>* spisok;
    Dec();
    ~Dec();
    void pop_front(); //удаление первого
    void push_back(T* data); //добавление в конец
    void pop_back(); //удаление с конца
};

extern template class Dec<int>;
extern template class Dec<float>;
extern template class Dec<Payment>;