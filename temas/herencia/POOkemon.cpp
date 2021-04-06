#include <iostream>
#include <typeinfo> 
#include "POOkemon.hpp"

using namespace std;

//Mediator
void AtaquesImp::resolverAtaque(Pokemon& shooter, Pokemon& target)
{
    if(esNeutro(shooter, target))
    {
        target.Vida() += AtaqueNeutro();
    }
    else
    {
        if(esMuyEficaz(shooter, target))
        {
            target.Vida() += AtaqueMuyEficaz();
        }
        else
        {
            if(esPocoEficaz(shooter, target))
            {
                target.Vida() += AtaquePocoEficaz();
            }
            else
            {
                cout << "No se puede reconocer la situación" << endl;
            }
        }
    }
}

bool AtaquesImp::esNeutro(Pokemon& shooter, Pokemon& target)
{
    return(shooter.getTipo() == target.getTipo());
}

bool AtaquesImp::esPocoEficaz(Pokemon& shooter, Pokemon& target)
{
    bool r;

    r = ((shooter.getTipo() == Planta)&&(target.getTipo() == Fuego)) ||
        ((shooter.getTipo() == Fuego)&&(target.getTipo() == Agua)) ||
        ((shooter.getTipo() == Agua)&&(target.getTipo() == Planta));

    return r;
}

bool AtaquesImp::esMuyEficaz(Pokemon& shooter, Pokemon& target)
{
    bool r;

    r = ((shooter.getTipo() == Planta)&&(target.getTipo() == Agua)) ||
        ((shooter.getTipo() == Fuego)&&(target.getTipo() == Planta)) ||
        ((shooter.getTipo() == Agua)&&(target.getTipo() == Fuego));

    return r;
}

int AtaquesImp::AtaquePocoEficaz()
{
    cout << "No es muy eficaz..." << endl;
    return(-1);
}

int AtaquesImp::AtaqueNeutro()
{
    cout << "Se ha realizado el ataque" << endl;
    return(-2);
}

int AtaquesImp::AtaqueMuyEficaz()
{
    cout << "¡Es supereficaz!" << endl;
    return(-4);
}

string AtaquesImp::getTipoString(Tipo t)
{
    string s;
    switch (t)
    {
    case Planta:
        s = "tipo planta";
        break;
    case Fuego:
        s = "tipo fuego";
        break;
    case Agua:
        s = "tipo agua";
        break;
    default:
        s = "tipo no reconocido";
        break;
    }
    return s;
}

//Pokemon
void Pokemon::Atacar(Pokemon& target)
{
    a.resolverAtaque(*this, target);
}

string Pokemon::getTipoString() const 
{
    return(a.getTipoString(getTipo()));
}

//Celebraciones
string PokemonTipoPlanta::Celebra()
{
    return(" luce sus hojas al sol!");
} 

string PokemonTipoFuego::Celebra()
{
    return(" lanza gigantescas llamas de alegria!");
} 

string PokemonTipoAgua::Celebra()
{
    return(" forma un remolino gigantesco!");
} 

//Resto de funciones
void Combate(Pokemon& P1, Pokemon& P2)
{
    while (P1.Vida()>0 && P2.Vida()>0)
    {
        cout << endl << "¡P1 ha atacado!"<< endl; 
        P1.Atacar(P2);
        if (P2.Vida()<=0)
            break;
        cout << endl << "¡P2 ha atacado!"<< endl;
        P2.Atacar(P1);
    }
    if (P1.Vida()<0)
    {
        cout << endl<< "¡P2 ha ganado el combate!" << endl;
        cout << "¡P2" << P2.Celebra() << endl;
    }
    else
    {
        cout << endl<< "¡P1 ha ganado el combate!" << endl;
        cout << "¡P1" << P1.Celebra() << endl;
    }
}

//Esta devuelve una referencia
Pokemon& Pokemon_Aleatorio_Referencia(AtaquesMediator& A, int HP = 10)
{
    switch (rand()%3)
    {
        case 0:
            return *new PokemonTipoPlanta(A, HP); //UpCasting
            break;
        case 1:
            return *new PokemonTipoFuego(A, HP);
            break;
        case 2:
            return *new PokemonTipoAgua(A, HP);
            break;
        default:
            return *new PokemonTipoPlanta(A, HP);
            break;
    }
}

//Esta devuelve un puntero
Pokemon * Pokemon_Aleatorio_Puntero(AtaquesMediator& A, int HP = 10)
{
    switch (rand()%3)
    {
        case 0:
            return new PokemonTipoPlanta(A, HP); //UpCasting
            break;
        case 1:
            return new PokemonTipoFuego(A, HP);
            break;
        case 2:
            return new PokemonTipoAgua(A, HP);
            break;
        default:
            return new PokemonTipoPlanta(A, HP);
            break;
    }
}
