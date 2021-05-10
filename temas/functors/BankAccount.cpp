#include "BankAccount.hpp"

BankAccount::BankAccount(std::string number,tm fecha_){
    id=number;
    fecha.tm_mday=fecha_.tm_mday;
    fecha.tm_mon=fecha_.tm_mon;
    assert(fecha.tm_mon>=1 && fecha.tm_mon<=12);
    fecha.tm_year=fecha_.tm_year;
    validaciones();
}

BankAccount::~BankAccount(){
    id.~string();
    fecha={0};
}

bool BankAccount::operator < (const tm& fecha){
    if (ano()<fecha.tm_year){
        return true;
    }
    if (ano()==fecha.tm_year && mes()<fecha.tm_mon){
        return true;
    }
    if(ano()==fecha.tm_year && mes()==fecha.tm_mon && dia()<fecha.tm_mday){
        return true;
    }
    return false;
}

void BankAccount::validaciones()
{
		if ((fecha.tm_mon==1 || fecha.tm_mon==3 || fecha.tm_mon==5 || fecha.tm_mon==7 || fecha.tm_mon==8 || fecha.tm_mon==10 || fecha.tm_mon==12) && (fecha.tm_mday < 1 || fecha.tm_mday > 31)) throw BankAccount::Invalida("NO EXISTE EL DIA");
		if ((fecha.tm_mon==4 || fecha.tm_mon==6 || fecha.tm_mon==9 || fecha.tm_mon==11) && (fecha.tm_mday< 1 || fecha.tm_mday > 30)) throw BankAccount::Invalida("NO EXISTE EL DIA");
		if ((fecha.tm_mon==2 && (fecha.tm_year%4==0 && (fecha.tm_year % 400 == 0 || fecha.tm_year % 100 != 0))) && (fecha.tm_mday < 1 || fecha.tm_mday> 29)) throw BankAccount::Invalida("EXISTE EL DIA BISIESTO");
		if ((fecha.tm_mon==2 && !(fecha.tm_year%4==0 && (fecha.tm_year % 400 == 0 || fecha.tm_year % 100 != 0))) && (fecha.tm_mday < 1 || fecha.tm_mday > 28)) throw BankAccount::Invalida("NO EXISTE EL DIA BISIESTO");
}