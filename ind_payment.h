#pragma once
#include <iostream>
#include "Payment.h"
using namespace std;

class ind_payment : public Payment {
private:
    char* doljnocti; //должность
    double nadbavka; //надбавка за должность в %
    void vivod(ostream& os) const override;
    void vvod(istream& is) override;
public:
    ind_payment(); // конструктор по умолчанию
    ~ind_payment() override; // деструктор
    ind_payment(const ind_payment& other); // конструктор копирования

    int set_doljnocti(const char* d); // смена должности с проверкой
    int set_nadbavka(double n); // смена надбавки с проверкой


    const char* get_doljnocti() const; // получение должности
    double get_nadbavka() const; // получение надбавки

    double operator()(void) const;
};