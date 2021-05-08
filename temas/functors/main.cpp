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

    //Prueba del constructor del BankAcccountComparatorById
    BankAcccountComparatorById b_a_id1("325675ES",fecha);
    BankAcccountComparatorById b_a_id2("325675ES",fecha);

    cout << "El id de b_a_id1 es: " << b_a_id1.getId() <<endl;
    cout << "El id de b_a_id2 es: " << b_a_id2.getId() <<endl;

    //Comparacion del metodo ==
    bool result= (b_a_id1==b_a_id2);
    if(result==1){
        cout << "Los id son iguales" << endl;
    }else{
        cout << "Los id no son iguales" << endl;
    }

    //Comparacion del metodo !=
    BankAcccountComparatorById b_a_id3("325685ES",fecha);

    result = (b_a_id1!=b_a_id3);
    if(result==1){
        cout << "Los id no son iguales" << endl;
    }else{
        cout << "Los id son iguales" << endl;
    }

    //Comparacion del metodo <
    result = (b_a_id1<b_a_id3);
    if(result==1){
        cout << "Es menor el id" << endl;
    }else{
        cout << "Es mayor el id" << endl;
    }

    //Comparacion del metodo >
    result = (b_a_id3>b_a_id1);
    if(result==1){
        cout << "Es mayor el id" << endl;
    }else{
        cout << "Es menor el id" << endl;
    }

    //Comparacion del metodo <=
    result = (b_a_id1<=b_a_id3);
    if(result==1){
        cout << "Es menor o igual el id" << endl;
    }else{
        cout << "Es mayor el id" << endl;
    }

    //Comparacion del metodo >=
    result = (b_a_id3>=b_a_id1);
    if(result==1){
        cout << "Es mayor o igual el id" << endl;
    }else{
        cout << "Es menor el id" << endl;
    }

    //BankAccountComparatorByCreationDate
    tm fecha1={0};
    tm fecha2={0};
    tm fecha3={0};
    fecha1.tm_mday=28;
    fecha1.tm_mon=11;
    fecha1.tm_year=2019;

    fecha2.tm_mday=28;
    fecha2.tm_mon=11;
    fecha2.tm_year=2019;

    fecha3.tm_mday=29;
    fecha3.tm_mon=11;
    fecha3.tm_year=2019;


    BankAccountComparatorByCreationDate b_a_f1("325675ES",fecha1);
    BankAccountComparatorByCreationDate b_a_f2("325675ES",fecha2);
    BankAccountComparatorByCreationDate b_a_f3("325675ES",fecha3);

    //Comparacion del metodo ==
    result = (b_a_f1==b_a_f2);
    if(result==1){
        cout << "Las fechas son iguales" << endl;
    }else{
        cout << "Las fechas no son iguales" << endl;
    }

    //Comparacion del metodo !=
    result = (b_a_f1!=b_a_f3);
    if(result==1){
        cout << "Las fechas no son iguales" << endl;
    }else{
        cout << "Las fechas son iguales" << endl;
    }

    //Comparacion del metodo <
    result = (b_a_f1<b_a_f3);
    if(result==1){
        cout << "Es menor la fecha" << endl;
    }else{
        cout << "Es mayor la fecha" << endl;
    }

        //Comparacion del metodo >

    result = (b_a_f3>b_a_f1);
    if(result==1){
        cout << "Es mayor la fecha" << endl;
    }else{
        cout << "Es menor la fecha" << endl;
    }

    //Comparacion del metodo <=
    result = (b_a_f1<=b_a_f3);
    if(result==1){
        cout << "Es menor o igual la fecha" << endl;
    }else{
        cout << "Es mayor la fecha" << endl;
    }

    //Comparacion del metodo >=
    result = (b_a_f3>=b_a_f1);
    if(result==1){
        cout << "Es mayor o igual la fecha" << endl;
    }else{
        cout << "Es menor la fecha" << endl;
    }

    return 0;
}