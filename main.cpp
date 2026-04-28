#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>
#include <limits>
#include <vector>
#include "Payment.h"
#include <fstream>
#include <iostream>
#include "function_main.h"
#include "ind_payment.h"
#include "Node.h"
#include "spisok_Node.h"
#include "Dec.h"

using std::cin;
using std::cout;
using std::endl;


int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_NUMERIC, "C");
    using std::ios;

    int index = 100;
    int pol012 = 0;

    std::vector<Payment*> macciv, macciv1; //для тех, ктр с клавиатуры | для тех, что из файла
    Dec<float> macc1;
    Dec<Payment> macc;
    Dec<int> macc0;
   
    while (pol012 != 4) {
        int polizovatel = 0, pol01 = 0, pol02=0;
        pol012 = proverka_meni0();
        if (pol012 == 1) {
            while (pol02 != 7) {
                pol02 = proverka_meni1();
                int* chiclo = new int;
                if (pol02 == 1) {
                    cout << "Введите целое число" << endl;
                    cin >> *chiclo;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    macc0.push_back(chiclo);
                    cout << "Число добавлено" << endl;
                }
                if (pol02 == 2) {
                    int i = 0;
                    for (Node<int>* node = macc0.spisok->head; node != NULL; node = node->next) {
                        std::cout << i << ". " << *(node->data) << endl;
                        i++;
                    }
                }
                if (pol02 == 3) {
                    cout << "Введите индекс: " << endl;
                    index = proverka_index3();
                    int cnt = macc0.spisok->cnt();
                    if (index >= cnt) {
                        cout << "Введите целое число" << endl;
                        cin >> *chiclo;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        macc0.push_back(chiclo);
                        cout << "Число добавлено в конец!" << endl;
                    }
                    else {
                        macc0.spisok->insert(index, chiclo);
                        cout << "Число с индексом " << index << " добавлено" << endl;
                    }
                }
                if (pol02 == 4) {
                    int cnt = macc0.spisok->cnt();
                    if (cnt == 0) cout << "Чисел 0, удалять некого." << endl;
                    else {
                        cout << "Введите индекс числа, которого нужно удалить: " << endl;
                        index = proverka_index4(index, cnt);
                        macc0.spisok->earsy(index);
                        cout << "Число с индексом " << index << " удален " << endl;
                    }
                }
                if (pol02 == 5) { //удаление первого
                    macc0.pop_front();
                    cout << "Первое число удален" << endl;
                }

                if (pol02 == 6) { // удаление последнего
                    macc0.pop_back();
                    cout << "Последнее число удалено" << endl;
                }
            }
        }
        if (pol012 == 2) {
            while (pol01 != 7) {
                pol01 = proverka_meni1();
                if (pol01 == 1) {
                    string input;
                    cout << "Введите вещественное число" << endl;
                    while (1) {
                        cin >> input;
                        if (input.find('.') == string::npos) cout << "Введите вещественное, а не целочисленное число" << endl;
                        else break;
                    }
                    float* chiclo = new float(stof(input));
                    macc1.push_back(chiclo);
                    cout << "Число добавлено" << endl;
                }
                if (pol01 == 2) {
                    int i = 0;
                    for (Node<float>* node = macc1.spisok->head; node != NULL; node = node->next) {
                        std::cout << i << ". " << *(node->data) << endl;
                        i++;
                    }
                }
                if (pol01 == 3) {
                    cout << "Введите индекс: " << endl;
                    index = proverka_index3();
                    int cnt = macc1.spisok->cnt();
                    string input;
                    cout << "Введите вещественное число" << endl;
                    while (1) {
                        cin >> input;
                        if (input.find('.') == string::npos) cout << "Введите вещественное, а не целочисленное число" << endl;
                        else break;
                    }
                    float* chiclo = new float(stof(input));
                    if (index >= cnt) {
                        macc1.push_back(chiclo);
                        cout << "Число добавлено в конец!" << endl;
                    }
                    else {
                        macc1.spisok->insert(index, chiclo);
                        cout << "Число с индексом " << index << " добавлено" << endl;
                    }
                }
                if (pol01 == 4) {
                    int cnt = macc1.spisok->cnt();
                    if (cnt == 0) cout << "Чисел 0, удалять некого." << endl;
                    else {
                        cout << "Введите индекс числа, которого нужно удалить: " << endl;
                        index = proverka_index4(index, cnt);
                        macc1.spisok->earsy(index);
                        cout << "Число с индексом " << index << " удален " << endl;
                    }
                }
                if (pol01 == 5) { //удаление первого
                    macc1.pop_front();
                    cout << "Первое число удален" << endl;
                }

                if (pol01 == 6) { // удаление последнего
                    macc1.pop_back();
                    cout << "Последнее число удалено" << endl;
                }
            }
        }
    
        if (pol012 == 3) {
            while (polizovatel != 8) {
                polizovatel = proverka_meni();

                if (polizovatel == 1) {
                    vvod(macc, 1000);
                }

                if (polizovatel == 2) {
                    vvivod(macc);
                }

                if (polizovatel == 3) {
                    cout << "Введите индекс сотрудника: " << endl;
                    index = proverka_index3();
                    vvod(macc, index);
                }

                if (polizovatel == 4) {
                    int cnt = macc.spisok->cnt();
                    if (cnt == 0) cout << "Сотрудников 0, удалять некого." << endl;
                    else {
                        cout << "Введите индекс сотрудника, которого нужно удалить: " << endl;
                        index = proverka_index4(index, cnt);
                        macc.spisok->earsy(index);
                        cout << "Сотрудник с индексом " << index << " удален " << endl;
                    }
                }
                if (polizovatel == 5) { //удаление первого
                    macc.pop_front();
                    cout << "Первый сотрудник удален" << endl;
                }

                if (polizovatel == 6) { // удаление последнего
                    macc.pop_back();
                    cout << "Последний сотрудник удален" << endl;
                }

                if (polizovatel == 7) {
                    Node<Payment>* found = macc.spisok->poick();
                    if (found == 0) {
                        cout << "Сотрудник не найден" << endl;
                        continue;
                    }
                    cout << *(found->data) << endl;
                }
            }
        }
        /*
    //    if (polizovatel == 5) {
    //        Payment New = macciv[0].operator+(100);
    //        Payment New1 = macciv[0].operator+(macciv[1].get_oklad());
    //        Payment New3 = macciv[1] + 500;
    //        macciv.push_back(New);
    //        macciv.push_back(New1);
    //        macciv.push_back(New3);
    //    }

    //    if (polizovatel == 6) {
    //        if (macciv.size() == 0) cout << "Сотрудников 0, премию назначать некому." << endl;
    //        else {
    //            int summa = 0, index2 = 0;
    //            cout << "Введите сумму, на которую уменьшится оклад" << endl;
    //            summa = proverka_index3(summa);
    //            cout << "Введите индекс сотрудника, у которого нужно уменьшить оклад: " << endl;
    //            index = proverka_index4(index, macciv.size());
    //            Payment New = summa - macciv[index];
    //            macciv[index] = New;
    //            cout << "Оклад сотрудника измненен" << endl;

    //            cout << "Введите индекс сотрудника 1" << endl;
    //            index = proverka_index4(index, macciv.size());
    //            cout << "Введите индекс сотрудника 2" << endl;
    //            index2 = proverka_index4(index2, macciv.size());
    //            Payment New1 = macciv[index2].get_oklad() - macciv[index];
    //            macciv.push_back(New1);
    //            cout << "Сотрудник с разницей окладов добавлен в конец" << endl;

    //        }
    //    }

    //    if (polizovatel == 7) {
    //        if (macciv.size() == 0) cout << "Сотрудников 0, менять год некому." << endl;
    //        else {
    //            cout << "Введите индекс сотрудника, у которого нужно увеличить год: " << endl;
    //            index = proverka_index4(index, macciv.size());
    //            macciv[index] = macciv[index].operator++();
    //            cout << "Год сотрудника измненен" << endl;
    //        }
    //    }

    //    if (polizovatel == 8) {
    //        if (macciv.size() == 0) cout << "Сотрудников 0, менять год некому." << endl;
    //        else {
    //            cout << "Введите индекс сотрудника, у которого нужно уменьшить год: " << endl;
    //            index = proverka_index4(index, macciv.size());
    //            macciv[index] = macciv[index].operator--();
    //            cout << "Год сотрудника измненен" << endl;

    //        }
    //    }

    //    if (polizovatel == 9) {
    //        if (macciv.size() == 0) cout << "Сотрудников 0, менять год некому." << endl;
    //        else {
    //            cout << "Введите индекс сотрудника, которому нужно вывести зарплату: " << endl;
    //            index = proverka_index4(index, macciv.size());
    //            double g = macciv[index]();
    //            cout << "Зарплата сотрудника " << macciv[index].get_fio() << ": " << g << endl;

    //        }
    //    }

        if (polizovatel == 10) { //  запись из файла
            macciv1.clear();
            zapici_10(macciv1);
        }

        if (polizovatel == 11) { //вывод файловых записей
            vvivod(macciv1);
      }

        if (polizovatel == 12) { //запись в файл
            if (zapici_12(macciv)) cout << "Данные записаны" << endl;
            else cout << "Файл не был открыт" << endl;
        }

        if (polizovatel == 13) { //запись в бинарный файл
            zapic_binary(macciv);
        }

        if (polizovatel == 14) {
            if (izfaila_bin(macciv1)) {
                vvivod(macciv1);
            }
            else {
                cout << "Файл не открылся" << endl;
            }
        }

        if (polizovatel == 15) {
            perezapic(macciv1);
        }
        */
    }

}







