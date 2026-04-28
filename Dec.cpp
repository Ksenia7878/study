#include <iostream>
#include "Node.h"
#include "Payment.h"
#include "spisok_Node.h"
#include <string>
#include "Dec.h"


template <class T>
Dec<T>::Dec() {
    spisok = new spisok_Node<T>();
}

template <class T>
Dec<T>::~Dec() {
    delete spisok;  
}

template <class T>
void Dec<T>::pop_front() { //удаление первого
    spisok->earsy(0);
}

template <class T>
void Dec<T>::push_back(T* data) { //добавление в конец
    spisok->insert(spisok->cnt(), data);
}

template <class T>
void Dec<T>::pop_back() { //удаление с конца
    spisok->earsy((spisok->cnt())-1);
}

template class Dec<int>;
template class Dec<float>;
template class Dec<Payment>;