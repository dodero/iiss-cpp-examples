#include <ctime>
#include <iostream>
#include "POOkemon.hpp"

void Combate(Pokemon& P1, Pokemon& P2);
Pokemon& Pokemon_Aleatorio_Referencia(AtaquesMediator& A, int HP = 10);
Pokemon * Pokemon_Aleatorio_Puntero(AtaquesMediator& A, int HP = 10);

int main()
{
    AtaquesMediator * mediator = new AtaquesImp();

    srand(time(0));
    Pokemon * P1 = Pokemon_Aleatorio_Puntero(*mediator, 10);
    Pokemon& P2 = Pokemon_Aleatorio_Referencia(*mediator, 10);

    cout << "P1 es de " << P1->getTipoString() <<endl;
    cout << "P2 es de " << P2.getTipoString() << endl;

    Combate(*P1, P2);

    return(0);
}