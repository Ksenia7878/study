#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Payment.h"
#include "rab_payment.h"


using namespace std;

void rab_payment::vivod(ostream& os) const { //для вывода
    os << "Тип сотрудника: " << tip << endl << "ФИО сотрудника: " << fio << endl << "Оклад: " << oklad << endl << "Кол-во дней в месяц: " << days 
        << endl << "Год поступления на работу: " << year << endl << "Профессия сотрудника: " << profeci << endl << "Оплата в час: " << pay << endl << "Кол-во часов в месяц: " <<
         hac << endl << "Итоговая зарплат: " << this->operator()() << endl;
}

void rab_payment::vvod(istream& is) { // для вода
    Payment::vvod(is);
    cout << "Введите профессию сотрудника: " << endl;
    char d[201];
    is.ignore(1000, '\n');  
    is.getline(d, 200);

    set_profeci(d);
    cout << "Введите оплату в час сотрудника: " << endl;
    is >> pay;
    if (pay < 0) {
        this->pay = 0;
    }
    cout << "Введите сколько часов в месяц отработал сотрудник: " << endl;
    is >> hac;
    if (hac < 0) {
        this->hac = 0;
    }
}

rab_payment::rab_payment() : pay(0), hac(0) { // конструктор по умолчанию
    profeci = new char[strlen("Профессия неизвестна") + 1];
    strcpy(profeci, "Профессия неизвестна");
    tip = new char[strlen("Сотрудник с профессией") + 1];
    strcpy(tip, "Сотрудник с профессией");
}

rab_payment ::~rab_payment() { // деструктор
    delete[] profeci;

}

class error_pamit {
public: 
    error_pamit() {
        cerr << "Ошибка выделения памяти в rab_payment" << endl;

    };
};

rab_payment::rab_payment(const rab_payment& other) { // конструктор копирования
    try {

        if (other.profeci) {
            profeci = new char[strlen(other.profeci) + 1];
            strcpy(profeci, other.profeci);
        }
        else {
            profeci = nullptr;;
        }
        pay = other.pay;
        hac = other.hac;
    }
    catch(const std::bad_alloc&) {
            throw error_pamit();
        }
    } 



int rab_payment::set_profeci(const char* d) { // смена должности с проверкой
    if (strlen(d) > 100 || strlen(d) == 0) {
        cerr << "Неккоректная должность" << endl;
        return 0;
    }

    delete[] profeci;
    profeci = new char[strlen(d) + 1];
    strcpy(profeci, d);
    return 1;
}


int rab_payment::set_pay(double n) { // смена руб в 1 час с проверкой
    if (n < 0) {
        this->pay = 0;
        return 1; // успех
    }
    this->pay = n;
    return 0;
}

int rab_payment::set_hac(double n) { // смена руб в 1 час с проверкой
    if (n < 0) {
        this->hac = 0;
        return 1; // успех
    }
    if (n > 240) {
        this->hac = 240;
        return 1;
    }
    this->hac = n;
    return 0;
}

const char* rab_payment::get_profeci() const { // получение должности
    return profeci;
}

int rab_payment::get_pay() const { // получение руб в 1 час
    return pay;
}

int rab_payment::get_hac() const { // получение кол-во часов
    return hac;
}

double rab_payment::operator()(void) const {
    return (pay*hac) + oklad;
}