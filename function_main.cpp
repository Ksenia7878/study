#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <Windows.h>
#include "Payment.h"
#include "function_main.h"
#include <fstream>
#include "ind_payment.h"
#include "rab_payment.h"
#include "Node.h"
#include "spisok_Node.h"
#include "Dec.h"

using namespace std;


Payment operator-(int okl, const Payment& other) {
    if ((other.oklad - okl) < 0) return Payment(other.fio, 0, other.year, other.days);
    return Payment(other.fio, other.oklad - okl, other.year, other.days);
}

class messdown {
public:
    messdown() {
        cerr << "Вы ввели символ, а нужно число" << endl;
    };
};

class indexsmaller0{
public:
    indexsmaller0() {
        cerr << "Индекс не может быть отрицательным" << endl;
    }
};



//------------------------------------------------------------------------ меню, проверка индексов

int proverka_meni0() { // проверка, что входит в диапозон меню и корректный ввод

    int polizovatel;
    while (true) {
        try {
            std::cout << endl << "1. Добавить целое число " << endl << "2. Добавить вещественное число " << endl
                << "3. Добавить сотрудника" << endl << "4. Выход " << endl;

            if (!(std::cin >> polizovatel)) {
                throw 1;
            }

            if (polizovatel < 1 || polizovatel>4) {
                throw 0.8;
            }
            return polizovatel;
        }
        catch (int)
        {
            cout << "Нужно ввести число целочисленное" << endl;
            std::cin >> polizovatel;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        catch (double) {
            cout << "Нужно ввести число в диапозоне от 1 до 3" << endl;
            std::cin.ignore(1000, '\n');
        }

    }
}

int proverka_meni1() { // проверка, что входит в диапозон меню и корректный ввод
    int polizovatel;
    while (true) {
        try {
            std::cout << endl << "1. Добавить число " << endl << "2. Вывести все числа " << endl <<
                "3. Вставить число по номеру" << endl << "4. Удалить число " << endl
                << "5. Удаление первого числа " << endl << "6. Удаление последнего числа" << endl << "7. Выход" << endl;

            if (!(std::cin >> polizovatel)) {
                throw 1;
            }

            if (polizovatel < 1 || polizovatel>7) {
                throw 0.8;
            }
            return polizovatel;
        }
        catch (int)
        {
            cout << "Нужно ввести число целочисленное" << endl;
            std::cin >> polizovatel;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        catch (double) {
            cout << "Нужно ввести число в диапозоне от 1 до 7" << endl;
            std::cin.ignore(1000, '\n');
        }

    }
}


int proverka_meni() { // проверка, что входит в диапозон меню и корректный ввод
    int polizovatel;
    while (true) {
        try {
            std::cout << endl << "1. Добавить сотрудника " << endl << "2. Вывести всех сотрудников " << endl <<
                "3. Вставить сотрудника по номеру" << endl << "4. Удалить сотрудника " << endl
                << "5. Удаление первого " << endl << "6. Удаление последнего " << endl << "7. Поиск по фамилии" << endl
                /* << "5. Увеличить оклад " << endl
                << "6. Уменьшить оклад " << endl << "7. Увеличить на 1 год " << endl << "8. Уменьшить на 1 год " << endl<<
                "9. Вывод зарплаты с вычетом всех налогов " << endl
                << "10. Записать данные из файла" << endl << "11. Вывести данные из файла"
                 << endl << "12. Записать в файл сотрудников" << endl << "13. Записать в бинарный файл" << endl <<
                "14. Вывести из бинарного файла" << endl << "15. Перезаписать данные из бинарного файла в текстовый" <<
                endl<< "16. Добавить сотрудника с должностью " << endl */ << "8. Выход " << endl;

            if (!(std::cin >> polizovatel)) {
                throw 1;
            }
            
            if (polizovatel < 1 || polizovatel>8) {
                throw 0.8;
            }
            return polizovatel;
        }
        catch (int)
        {
            cout << "Нужно ввести число целочисленное" << endl;
            std::cin >> polizovatel;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        catch (double) {
            cout << "Нужно ввести число в диапозоне от 1 до 8" << endl;
            std::cin.ignore(1000, '\n');
        }

    }
}

int proverka_index3() { //проверка на целое неотрицательное число
    int polizovatel;
    while (true) {
        try {
            if (!(cin >> polizovatel)) {
                throw messdown();
            }
            if (polizovatel < 0) {
                throw indexsmaller0();
            }
            cin.ignore(1000, '\n');
            return polizovatel;
        }
        catch (messdown) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        catch (indexsmaller0) {
            cerr << "Индекс не может быть отрицательным" << endl;
            std::cin.ignore(1000, '\n');
        }
    }
}

int proverka_index4(int polizovatel, size_t size) { //проверка на наличие сотрудника с данным индексом
    while (true) {
        try {
            if (!(std::cin >> polizovatel)) {
                throw messdown();
            }

            if (polizovatel < 0 || polizovatel>size) {
                throw 0.5;
            }

            std::cin.ignore(1000, '\n');
            return polizovatel;
        }
        catch (messdown){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        catch (double) {
            cout << "Сотрудник не найден с таким индексом" << endl;
            cin.ignore(1000, '\n');
        }
    }
}

int proverka_index012() { //проверка на целое неотрицательное число в диапозоне 0-1
    int polizovatel;
    while (true) {
        try {
            cout << "0 - сотрудник с неизвестной должностью и профессией" << endl <<
                "1 - сотрудник с известной должностью" << endl << "2 - сотрудник с известной профессией" << endl;

            if (!(std::cin >> polizovatel)) throw 2;
            if (polizovatel < 0 || polizovatel>2) throw 1;

            std::cin.ignore(1000, '\n');
            return polizovatel;
        }
        catch (...) {
            cout << "Ошибка " << endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
}

//-------------------------------------------------

//------------------------------------------------- основной класс


void vvod(Dec<Payment>& macc, int index) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);  
    Payment* Casha = nullptr;
    int vibor = proverka_index012();
    if (vibor == 0) {
        Casha = new Payment();
    }
    if (vibor == 1) {
        Casha = new ind_payment();
    }
    if (vibor == 2) {
        Casha = new rab_payment();
    }

    if (Casha) cin >> *Casha;
    
    int cnt = macc.spisok->cnt();
    if (index >= cnt) {
        macc.push_back(Casha);
        cout << "Сотрудник добавлен в конец!" << endl;
    }
    else {
        macc.spisok->insert(index, Casha);
        cout << "Сотрудник с индексом " << index << " добавлен!" << endl;
    }
}

void zapici_10(std::vector<Payment*>& macciv1) { // достаем из файла
    int oklad, year, days, hac, pay;
    double nadbavka;
    char fio_kl[201]; //фио
    char d[100]; //тип
    char dolj[200]; //должность
    char profeci[200]; //профессия
    std::ifstream ifs("date.txt");
    if (ifs.is_open()) {
        if (ifs.peek() == std::ifstream::traits_type::eof()) cout << "Файл пустой" << endl;
        else {
            while (true) {
                ifs.ignore(1000, ':'); // тип
                ifs.ignore(1000, ' ');
                ifs.getline(d, 100);
                if (ifs.fail()) break;
                ifs.ignore(1000, ':'); //ФИО
                ifs.ignore(1000, ' ');
                ifs.getline(fio_kl, 200);
                
                ifs.ignore(1000, ':'); //Оклад
                ifs.ignore(1000, ' ');
                ifs >> oklad;
               
                ifs.ignore(1000, ':'); // Дни
                ifs.ignore(1000, ' ');
                ifs >> days;
                
                ifs.ignore(1000, ':'); // Год
                ifs.ignore(1000, ' ');
                ifs >> year;

                
                Payment* Casha = nullptr;
                if (!strcmp(d, "Сотрудник без должности и профессии")) {
                    Casha = new Payment();
                    ifs.ignore(1000, ':'); //зарплата
                    ifs.ignore(1000, ':'); //налог
                    ifs.ignore(1000, ':'); // налог
                }
                else if (!strcmp(d, "Сотрудник с должностью")) {
                    Casha = new ind_payment();
                    ifs.ignore(1000, ':'); //зарплата
                    ifs.ignore(1000, ':'); //налог
                    ifs.ignore(1000, ':'); // налог

                    ifs.ignore(1000, ':'); // должность
                    ifs.ignore(1000, ' ');
                    ifs.getline(dolj, 100);
                    dynamic_cast<ind_payment*>(Casha)->set_doljnocti(dolj);  //приведение типа
                    ifs.ignore(1000, ':'); //надбавка
                    //ifs.ignore(1000, ' ');
                    ifs >> nadbavka;
                  
                    dynamic_cast<ind_payment*>(Casha)->set_nadbavka(nadbavka);
                    ifs.ignore(1000, ':'); // зарплата
                }
                else if (!strcmp(d, "Сотрудник с профессией")) {
                    Casha = new rab_payment();
                    ifs.ignore(1000, ':'); // профессия
                    ifs.ignore(1000, ' ');
                    ifs.getline(profeci, 100);
                    dynamic_cast<rab_payment*>(Casha)->set_profeci(profeci);
                    ifs.ignore(1000, ':'); //оплата в час
                    ifs >> pay;
                    ifs.ignore(1000, ':'); //кол-во часов
                    ifs >> hac;

                    dynamic_cast<rab_payment*>(Casha)->set_pay(pay);
                    dynamic_cast<rab_payment*>(Casha)->set_hac(hac);
                    ifs.ignore(1000, ':'); // зарплата
                }

                Casha->set_fio(fio_kl);
                Casha->set_days(days);
                Casha->set_oklad(oklad);
                Casha->set_year(year);
                strcpy(Casha->tip, d);

                macciv1.push_back(Casha);

            }
            cout << "Данные из файла записаны" << endl;
        }
    }
    else cout << "Файл не был открыт" << endl;
    ifs.close();
}

int zapici_12(std::vector<Payment*>& macciv) { // дозапись
    std::ofstream ofs("date.txt", ios::app);
    if (ofs.is_open()) {
        for (int i = 0; i < macciv.size(); i++) {
            ofs << *macciv[i] << endl;
        }
        ofs.close();
        return 1;
    }
    return 0;
}

void zapic_binary(std::vector<Payment*>& macciv) {
    std::ofstream bin("bin.dat", ios::app | ios::binary);
    if (bin.is_open()) {
        for (int i = 0; i < macciv.size(); i++) {
            Payment* Casha = macciv[i];

            size_t len = strlen(Casha->tip); //тип
            bin.write((char*)&len, sizeof(len));
            bin.write((char*)Casha->tip, len);

            len = strlen(Casha->get_fio()); //фио
            bin.write((char*)&len, sizeof(len));
            bin.write((char*)Casha->get_fio(), len);

            int time;
            time = Casha->get_oklad();
            bin.write((char*)&time, sizeof(int));
            time = Casha->get_days();
            bin.write((char*)&time, sizeof(int));
            time = Casha->get_year();
            bin.write((char*)&time, sizeof(int));
            if (!(strcmp(Casha->tip, "Сотрудник с должностью"))) {
                auto Casha1 = dynamic_cast<ind_payment*>(Casha); //приведение типа
                if (Casha1) {
                    double nadbavka;

                    len = strlen(Casha1->get_doljnocti()); //должность
                    bin.write((char*)&len, sizeof(len));
                    bin.write((char*)Casha1->get_doljnocti(), len);

                    nadbavka = Casha1->get_nadbavka();
                    bin.write((char*)&nadbavka, sizeof(nadbavka));
                }
            }

            if (!(strcmp(Casha->tip, "Сотрудник с профессией"))) {
                auto Casha1 = dynamic_cast<rab_payment*>(Casha); //приведение типа
                if (Casha1) {
                    int hac, pay;
                    len = strlen(Casha1->get_profeci()); //должность
                    bin.write((char*)&len, sizeof(len));
                    bin.write((char*)Casha1->get_profeci(), len);

                    pay = Casha1->get_pay();
                    bin.write((char*)&pay, sizeof(pay));
                    hac = Casha1->get_hac();
                    bin.write((char*)&hac, sizeof(hac));
                }
            }

        }
    }
    else cout << "Файл не был открыт" << endl;
}

int izfaila_bin(std::vector<Payment*>& macciv1) {
    macciv1.clear();
    std::ifstream bin1("bin.dat", ios::binary);
    if (bin1.is_open()) {
        
        while (bin1.peek() != EOF) {
            size_t len1; //длина типа
            bin1.read((char*)&len1, sizeof(len1));
            char* tip = new char[len1 + 1];
            bin1.read(tip, len1);
            tip[len1] = '\0';

            bin1.read((char*)&len1, sizeof(len1)); //длина фио
            char* fio_t = new char[len1 + 1];
            bin1.read(fio_t, len1);
            fio_t[len1] = '\0';

            int oklad, days, year, pay, hac;

            bin1.read((char*)&oklad, sizeof(int));
            
            bin1.read((char*)&days, sizeof(int));
            
            bin1.read((char*)&year, sizeof(int));
            
            Payment* Petr = nullptr;
            if (!strcmp(tip, "Сотрудник без должности и профессии")) {
                Petr = new Payment();
            }
            else if (!strcmp(tip, "Сотрудник с должностью")) {
                Petr = new ind_payment();

                bin1.read((char*)&len1, sizeof(len1));
                char* doljnoct = new char[len1 + 1];
                bin1.read(doljnoct, len1);
                doljnoct[len1] = '\0';
                dynamic_cast<ind_payment*>(Petr)->set_doljnocti(doljnoct);

                double nadbavka; 

                bin1.read((char*)&nadbavka, sizeof(nadbavka));

                dynamic_cast<ind_payment*>(Petr)->set_nadbavka(nadbavka);
            }
            else if (!strcmp(tip, "Сотрудник с профессией")) {
                Petr = new rab_payment();

                bin1.read((char*)&len1, sizeof(len1));
                char* profeci = new char[len1 + 1];
                bin1.read(profeci, len1);
                profeci[len1] = '\0';
                dynamic_cast<rab_payment*>(Petr)->set_profeci(profeci);

                int pay, hac;

                bin1.read((char*)&pay, sizeof(pay));
                dynamic_cast<rab_payment*>(Petr)->set_pay(pay);
                bin1.read((char*)&hac, sizeof(hac));
                dynamic_cast<rab_payment*>(Petr)->set_hac(hac);
            }
            Petr->set_fio(fio_t);
            Petr->set_days(days);
            Petr->set_oklad(oklad);
            Petr->set_year(year);
            strcpy(Petr->tip, tip);

            macciv1.push_back(Petr);
            delete[] fio_t;
            delete[] tip;
        }
        bin1.close();
        return 1;
    }
    else {
        return 0;
    } 
}

void perezapic(std::vector<Payment*>& macciv) { //из бинарного в текстовый
    macciv.clear();
    if (izfaila_bin(macciv)) {
        if (zapici_12(macciv)) cout << "Данные записаны из бинарного в текстовый файл" << endl;
        else cout << "Текстовый файл не открылся" << endl;
    }
    else cout << "Бинарный файл не открылся" << endl;
    macciv.clear();
}





void vvivod(Dec<Payment>& macc) {
    int i = 0;
    for (Node<Payment>* node = macc.spisok->head; node != NULL; node = node->next) {
        std::cout << i << ". " << *(node->data) << endl;
        i++;
    }
}

//-------------------------------------------------------

