#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_


#include <string>
#include <iostream>
#include <ctime>
#include <cassert>
<<<<<<< HEAD
=======
#include <bits/stdc++.h>

>>>>>>> 9a017375f24f92b3c1983d0f031056853604d266
using namespace std;

class BankAccount
{
    private:
        std::string id;
        tm fecha = {0};
        void validaciones();
<<<<<<< HEAD
        //Añadir fecha no se si como string o como time_t
=======
>>>>>>> 9a017375f24f92b3c1983d0f031056853604d266
    public:
        //Clase Invalida para lanzar un mensaje de error
        class Invalida
		{
			public:
				explicit Invalida (const char* s) : cadena(s){};
				const char* por_que() const{return cadena;};

			private:
				const char* cadena;
		};

        //Constructor del banco
        BankAccount(std::string number,tm fecha_);

        //Get y set del id del banco
        const std::string& getId() const {return id;};
        std::string& setId(){return id;};

        //Get y set de la fecha
        int dia()const{return fecha.tm_mday;};
        int mes()const{return fecha.tm_mon;};
        int ano()const{return fecha.tm_year;};
        int dia(){return fecha.tm_mday;};
        int mes(){return fecha.tm_mon;};
        int ano(){return fecha.tm_year;};
<<<<<<< HEAD
        ~BankAccount();
};


class BankAcccountComparatorById: public BankAccount{
    public:
        BankAcccountComparatorById(std::string number,tm fecha_):BankAccount(number,fecha_){};
};

bool operator == (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2);
bool operator != (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2);
bool operator < (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2);
bool operator > (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2);
bool operator <= (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2);
bool operator >= (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2);

class BankAccountComparatorByCreationDate: public BankAccount{
    public:
        BankAccountComparatorByCreationDate(std::string number,tm fecha_):BankAccount(number,fecha_){};
};

bool operator == (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2);
bool operator != (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2);
bool operator < (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2);
bool operator > (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2);
bool operator <= (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2);
bool operator >= (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2);
=======

        //Operadores de fecha
        bool operator == (const tm& fecha){return (dia()==fecha.tm_mday && mes()==fecha.tm_mon && ano()==fecha.tm_year);};
        bool operator !=(const tm& fecha){return (!(*this==fecha));};
        bool operator < (const tm& fecha);
        bool operator <= (const tm& fecha){return (*this==fecha || *this < fecha);};
        bool operator >(const tm& fecha){return (!(*this < fecha || *this==fecha));};
        bool operator >=(const tm& fecha){return (*this > fecha || *this==fecha);};

        //Operadores de id
        bool operator == (const string& id){return (getId().compare(id)==0);};
        bool operator != (const string& id){return (!(*this==id));};
        bool operator < (const string& id){return (getId().compare(id)<0);};
        bool operator <=(const string& id){return (*this < id || *this==id);};
        bool operator >(const string& id){return (getId().compare(id)>0);};
        bool operator >=(const string& id){return (*this>id || *this==id);};

        ~BankAccount();
};



>>>>>>> 9a017375f24f92b3c1983d0f031056853604d266

#endif