#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Payment.h"
#include "ind_payment.h"

using namespace std;

void ind_payment::vivod(ostream& os) const { //для вывода
    Payment::vivod(os);
    os << "Должность сотрудника: " << doljnocti << endl << "Надбавка за должность в %: " << nadbavka << endl <<
        "Итоговая зарплат: " << this->operator()() << endl;
}

void ind_payment::vvod(istream& is) { // для ввода
    Payment::vvod(is);
    cout << "Введите должность сотрудника: " << endl;
    char d[201];
    is.ignore(1000, '\n');  
    is.getline(d, 200);

    set_doljnocti(d);
    cout << "Введите надбавку за должность в %: " << endl;
    is >> nadbavka;
    if (nadbavka < 0) {
        this->nadbavka = 0;
    }
    if (nadbavka > 1) { 
        this->nadbavka = 1;
    }
}


ind_payment :: ind_payment() : nadbavka(0){ // конструктор по умолчанию
	doljnocti = new char[strlen("Должность неизвестна") + 1];
	strcpy(doljnocti, "Должность неизвестна");
    tip = new char[strlen("Сотрудник с должностью") + 1];
    strcpy(tip, "Сотрудник с должностью");
}

ind_payment ::~ ind_payment() { // деструктор
	delete[] doljnocti;

}

ind_payment::ind_payment(const ind_payment& other) { // конструктор копирования
    if (other.doljnocti) {
        doljnocti = new char[strlen(other.doljnocti) + 1];
        strcpy(doljnocti, other.doljnocti);
    }
    else {
        doljnocti = nullptr;
    }
    nadbavka = other.nadbavka;
}

    // должна быть проверка в маин на успешность операции
int ind_payment:: set_doljnocti(const char* d) { // смена должности с проверкой
    if (strlen(d) > 100 || strlen(d) == 0) {
        return 0;
    }

    delete[] doljnocti;
    doljnocti = new char[strlen(d) + 1];
    strcpy(doljnocti, d);
    return 1;
}

    // должна быть проверка в маин на успешность операции
int ind_payment::set_nadbavka(double n) { // смена надбавки с проверкой
    if (n < 0) {
        this->nadbavka = 0;
        return 1; // успех
    }
    if (n > 1) { //выводить типа число было больше/меньше ожидаемого вы наверное ошиблись число было округлено до оклад
        this->nadbavka = 1;
        return 1;
    }
    this->nadbavka = n;
    return 0;
}

const char* ind_payment::get_doljnocti() const { // получение должности
    return doljnocti;
}

double ind_payment::get_nadbavka() const { // получение надбавки
    return nadbavka;
}

double ind_payment::operator()(void) const{
    return (zarplata() + zarplata()*nadbavka);
}