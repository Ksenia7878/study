#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>
#include "Payment.h"
#include <limits>  

using std::cin;
using std::cout;
using std::endl;

int Payment::cnt = 0;

ostream& operator<<(ostream& os, const Payment& p) {
    p.vivod(os);
    return os;
}

istream& operator>> (istream& is, Payment& p) {
    p.vvod(is);
    return is;
}

class FioError0 {};
class ErrorOklad{};
class ErrorYear{
public:
    ErrorYear() {
        cerr << "Год должен находиться в диапозоне с 1950 по 2025" << endl;
    }
};
class ErrorDays {
public:
    ErrorDays() {
        cerr << "Человек мог отработать от 0 до 31 дня" << endl;
    }
};

void Payment:: vivod(ostream& os) const { //для вывода
    os << "Тип сотрудника: " << tip <<  endl << "ФИО сотрудника: " << fio << endl << "Оклад: " << oklad << endl << "Кол-во дней: " << days << endl << "Год поступления на работу: " << year <<
            endl << "Зарплата: " << oklad * days << endl << "Пенсионный налог: " << (oklad * days) * 0.01 << endl
            << "Обычный налог: " << (oklad * days) * 0.13 << endl;  

}

void Payment:: vvod (istream& is) { // для ввода
    while (1) {
        cout << "Введите ФИО сотрудника: " << endl;
        if (is.peek() == '\n') is.get();
        char buffer[201];
        is.getline(buffer, 200);
        if (is.fail()) {
            cout << "ФИО слишком длинное" << endl;
            is.clear();
            is.ignore(10000, '\n');  
            continue;
        }
        try {
            if (set_fio(buffer)) {
                cout << "ФИО установлено" << endl;
                break;
            }
            else {
                cout << "Не удалось установить ФИО из-за нехватки памяти. Сохраняется предыдущее значение" << endl;
                break;  
            }
        }
        catch (const FioError0&) {
            cout << "ФИО не может быть пустым" << endl;
        }
    }
    while (1) {
        cout << "Введите оклад сотрудника: " << endl;
        is >> oklad;
        try {
            set_oklad(oklad);
            cout << "Оклад установлен" << endl;
            break;
        }
        catch (const ErrorOklad&) {
            cerr << "Оклад не может быть меньше 0" << endl;
        }
    }
    while (1) {
        cout << "Введите год, с которого работает сотрудник: " << endl;
        is >> year;
        try {
            set_year(year);
            cout << "Год успешно установлен" << endl;
            break;
        }
        catch (const ErrorYear&) {};
    }
    while (1) {
        cout << "Введите сколько дней отработал сотрудник в этом месяце: " << endl;
        is >> days;
        try {
            set_days(days);
            cout << "Дни успешно установлены" << endl;
            break;
        }
        catch (const ErrorDays&) {};

    }
}

Payment::Payment() : oklad(0), year(0), days(0) {
    cnt++;
    fio = new char[strlen("Неизвестный") + 1];
    strcpy(fio, "Неизвестный");
    tip = new char[strlen("Сотрудник без должности и профессии") + 1];
    strcpy(tip, "Сотрудник без должности и профессии");
}

Payment::Payment(const char* new_fio, int oklad, int year, int days) {
    set_fio(new_fio);
    set_oklad(oklad);
    set_year(year);
    set_days(days);
    cnt++;
}


Payment::Payment(const Payment& other) {
    if (other.fio) {
        fio = new char[strlen(other.fio) + 1];
        strcpy(fio, other.fio);
    }else {
        fio = nullptr; 
    }
    if (other.tip) {
        tip = new char[strlen(other.tip) + 1];
        strcpy(tip, other.tip);
    }else {
        tip = nullptr;
    }
    oklad = other.oklad;
    year = other.year;
    days = other.days;
    cnt++;
}

Payment& Payment::operator=(const Payment& other) {
    if (this != &other) {
        delete[] fio;
        fio = nullptr;  // обнуляем указатель

        if (other.fio && strlen(other.fio) > 0) {
            fio = new char[strlen(other.fio) + 1];
            strcpy(fio, other.fio);
        }
        else {
            fio = new char[strlen("Неизвестный") + 1];
            strcpy(fio, "Неизвестный");
        }
        if (other.tip) {
            tip = new char[strlen(other.tip) + 1];
            strcpy(tip, other.tip);
        }
        else {
            tip = new char[strlen("Сотрудник без должности и профессии") + 1];
            strcpy(tip, "Сотрудник без должности и профессии");
        }

        oklad = other.oklad;
        year = other.year;
        days = other.days;
    }
    return *this;
}

Payment Payment::operator+(int okl) {
    return Payment(fio, oklad + okl, year, days);
}

Payment& Payment::operator++(){
    year++;
    return *this;

}

Payment& Payment::operator--() {
    year--;
    return *this;

}

Payment::~Payment() {
    delete[] fio;
    delete[] tip;
}




int Payment::set_fio(const char* new_fio) {
    if (new_fio==nullptr || strlen(new_fio) == 0) {
        throw FioError0();
    }
    char* old_fio = fio;
    fio = nullptr;
    try {
        fio = new char[strlen(new_fio) + 1]; //0000000000000000000ULL
    }
    catch (const std::bad_alloc& e) {
        cerr << "Ошибка выделения памяти для ФИО "  << endl;
        fio = old_fio;
        return 0;
    }
    strcpy(fio, new_fio);
    delete[] old_fio;
    return 1;
}

void Payment::set_oklad(int oklad) {
    if (oklad < 0) throw ErrorOklad();
    this->oklad = oklad;
}

void Payment::set_year(int year) {
    if (year > 2025 || year < 1950) throw ErrorYear();
    this->year = year;
}

void Payment::set_days(int days) {
    if (days < 0 || days > 31) throw ErrorDays();
    this->days = days;
}

const char* Payment::get_fio() const {
    return fio;
}

int Payment::get_oklad() const {
    return oklad;
}

int Payment::get_year() const {
    return year;
}

int Payment::get_days() const {
    return days;
}

int Payment::zarplata() const{
    return oklad * days;
}

double Payment::pencia() {
    return (oklad * days) * 0.01;
}

double Payment::nalog() {
    return (oklad * days) * 0.13;
}


double Payment::operator()(void) {
    return (oklad * days - nalog() - pencia());
}



