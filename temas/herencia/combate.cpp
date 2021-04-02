#include <ctime>
#include <iostream>
#include "POOkemon.hpp"

void Combate(Pokemon& P1, Pokemon& P2);
Pokemon* Pokemon_Aleatorio_Puntero(int HP = 10);
Pokemon& Pokemon_Aleatorio_Referencia(int HP = 10);

int main()
{
    srand(time(0));
    Pokemon * P1 = Pokemon_Aleatorio_Puntero();
    Pokemon& P2 = Pokemon_Aleatorio_Referencia();

    cout << "P1 es de " << P1->tipo() <<endl;
    cout << "P2 es de " << P2.tipo() << endl;

    Combate(*P1, P2);

    return(0);
}