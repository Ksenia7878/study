#include <iostream>
#include "Node.h"
#include "Payment.h"
#include "spisok_Node.h"
#include <string>

template <class T>
spisok_Node<T>::spisok_Node() {
    this->head = this->tail = NULL;
}

template <class T>
spisok_Node<T>:: ~spisok_Node() {
    while (head != NULL) { 
        Node<T>* node = head;
        head = head->next;
        delete node;
    }
    tail = NULL;

}
template <class T>
Node<T>* spisok_Node<T>::getAt(int index) { // возращение по индексу
    if (index < 0) return NULL;
    Node<T>* node = head;
    int i = 0;
    while (node != NULL && i < index) {
        node = node->next;
        i++;
    }
    return node;
}

template <class T>
int spisok_Node<T>::cnt() {
    Node<T>* node = head;
    int cnt = 0;
    for (; node != NULL; node = node->next) {
        cnt++;
    }
    return cnt;
}

template <class T>
void spisok_Node<T>::insert(int index, T* data) { //добавление по индексу
    index--;
    Node<T>* left = getAt(index);
    if (left == NULL) {
        Node<T>* node = new Node<T>(data);
        if (head == NULL) head = node;
        if (tail != NULL) tail->next = node;
        tail = node;
        return;
    }
    Node<T>* right = left->next;
    Node<T>* node = new Node<T>(data);
    left->next = node;
    node->next = right;
    if (right == NULL) tail = node;

}

template <class T>
void spisok_Node<T>::earsy(int index) { //удаление по индексу
    if (index < 0) return;
    if (index == 0) {
        if (head == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node<T>* node = head;
        head = head->next;
        delete node;
        return;
    }
    Node<T>* left = getAt(index - 1);
    Node<T>* node = left->next;
    if (node == NULL)           return;
    Node<T>* right = node->next;
    left->next = right;
    if (node == tail) tail = left;
    delete node;
}

template <>
Node<Payment>* spisok_Node<Payment>::poick() {
    cout << "Введите ФИО сотрудника: " << endl;
    std::string fio;
    std::getline(std::cin, fio);
    Node<Payment>* node = head;
    while (node != NULL) {
        if (node->data->get_fio() == fio) {
            return node;
        }
        node = node->next;
    }
    return 0;
}

template class spisok_Node<int>;
template class spisok_Node<float>;
template class spisok_Node<Payment>;
