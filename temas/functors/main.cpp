#include "BankAccount.hpp"
using namespace std;

int main(){
    //Prueba del constructor de BankAccount
    
    tm fecha={0};
    tm fechaerror={0};
    fecha.tm_mday=28;
    fecha.tm_mon=11;
    fecha.tm_year=2019;

    //Prueba de error
    fechaerror.tm_mday=40;
    fechaerror.tm_mon=11;
    fechaerror.tm_year=2019;

    tm fecha_comparable{0};
    fecha_comparable.tm_mday=28;
    fecha_comparable.tm_mon=11;
    fecha_comparable.tm_year=2019;

    try
	{
        BankAccount b_ac("398765ES",fechaerror);
    }catch(BankAccount::Invalida(pq))
	{
		cout << pq.por_que() << endl;
	}

    //Prueba del constructor
    BankAccount b_a("398765ES",fecha);

    //Prueba del set de BankAccount
    b_a.setId()="326548ES";
    cout << "Se ha cambiado el id de la cuenta 'b_a' a: " << b_a.getId() << endl;

    //Operador == Fecha
    bool result=(b_a==fecha_comparable);

    if(result==1){
        cout << "Las fechas son iguales" << endl;
    }else{
        cout << "Los fechas no son iguales" << endl;
    }

    //Operador != Fecha
    
    fecha_comparable.tm_mday=29;
    result=(b_a!=fecha_comparable);

    if(result==1){
        cout << "Las fechas son distintas" << endl;
    }else{
        cout << "Los fechas son iguales" << endl;
    }

    //Operador < fecha
    result=(b_a<fecha_comparable);

    if(result==1){
        cout << "La fecha es menor" << endl;
    }else{
        cout << "La fecha es mayor o igual" << endl;
    }

    //Operador <= fecha
    result=(b_a<=fecha_comparable);

    if(result==1){
        cout << "La fecha es menor o igual" << endl;
    }else{
        cout << "La fecha es mayor" << endl;
    }

    //Operador > fecha
    fecha_comparable.tm_mday=27;
    result=(b_a>fecha_comparable);

    if(result==1){
        cout << "La fecha es mayor" << endl;
    }else{
        cout << "La fecha es menor o igual" << endl;
    }

    //Operador > fecha
    fecha_comparable.tm_mday=27;
    result=(b_a>=fecha_comparable);

    if(result==1){
        cout << "La fecha es mayor o igual" << endl;
    }else{
        cout << "La fecha es menor " << endl;
    }

    //Operador == id
    BankAccount b2("3542E",fecha);
    string s("3542E");
    result =(b2==s);

    if(result==1){
        cout << "El id es igual" << endl;
    }else{
        cout << "El id es distinto" << endl;
    }

    //Operador != id
    string s1("3543E");
    result =(b2!=s1);

    if(result==1){
        cout << "El id es distinto" << endl;
    }else{
        cout << "El id es igual" << endl;
    }

    //Operador < id
    result =(b2<s1);

    if(result==1){
        cout << "El id es menor" << endl;
    }else{
        cout << "El id es mayor igual" << endl;
    }

    //Operador <= id
    result =(b2<=s1);

    if(result==1){
        cout << "El id es menor o igual" << endl;
    }else{
        cout << "El id es mayor" << endl;
    }

    //Operador > id
    s1="3541E";
    result =(b2>s1);

    if(result==1){
        cout << "El id es mayor" << endl;
    }else{
        cout << "El id es menor o igual" << endl;
    }

    //Operador > id
    result =(b2>=s1);

    if(result==1){
        cout << "El id es mayor o igual" << endl;
    }else{
        cout << "El id es menor" << endl;
    }

    return 0;
}
