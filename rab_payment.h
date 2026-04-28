#pragma once
#include <iostream>
#include "Payment.h"
using namespace std;

class rab_payment : public Payment {
private:
    char* profeci; //професси€
    int pay; //руб в 1 час
    int hac; // кол-во часов в мес€ц
    void vivod(ostream& os) const override;
    void vvod(istream& is) override;
public:
    rab_payment(); // конструктор по умолчанию
    ~rab_payment() override; // деструктор
    rab_payment(const rab_payment& other); // конструктор копировани€
    int set_profeci(const char* d); // смена профессии с проверкой
    int set_pay(double n); // смена надбавки с проверкой
    int set_hac(double n); //cмена часов
    const char* get_profeci() const; // получение профессии
    int get_pay() const; // получение руб в 1 час
    int get_hac() const; // получение кол-во часов
    double operator()(void) const;
};
