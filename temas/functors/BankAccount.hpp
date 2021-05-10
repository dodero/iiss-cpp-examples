#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_


#include <string>
#include <iostream>
#include <ctime>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

class BankAccount
{
    private:
        std::string id;
        tm fecha = {0};
        void validaciones();
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




#endif