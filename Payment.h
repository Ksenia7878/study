#pragma once
#include <iostream>
using namespace std;

//юмл диаграма классов 
// 

class Payment
{
protected:
	char* fio; //фио
	int oklad, year, days; //оклад; с какого года работает; кол-во,отработанных дней
	static int cnt;
	virtual void vivod(ostream& os) const;
	virtual void vvod(istream& is);
public:
	char* tip;
	Payment();
	Payment(const char* new_fio, int oklad, int year, int days);
	Payment(const Payment& other);


	Payment& operator=(const Payment& other);
	Payment operator+(int okl);
	friend Payment operator-(int okl, const Payment& other);

	friend ostream& operator<<(ostream& os, const Payment& p);
	friend istream& operator>> (istream& is, Payment& p);

	Payment& operator++();
	Payment& operator--();
	double operator()(void);
	
	virtual ~Payment();

	int set_fio(const char* new_fio);
	void set_oklad(int oklad);
	void set_year(int year);
	void set_days(int days);
	const char* get_fio() const;

	int get_oklad() const;
	int get_year() const;
	int get_days() const;

	int zarplata() const;
	double pencia();
	double nalog();


};

