#include <iostream>
#include <typeinfo> 
#include "POOkemon.hpp"

using namespace std;

//SabeAtacar
int Ataques::PocoEficaz()
{
    cout << "No es muy eficaz..." << endl;
    return(-1);
}

int Ataques::Neutro()
{
    cout << "Se ha realizado el ataque" << endl;
    return(-2);
}

int Ataques::MuyEficaz()
{
    cout << "¡Es supereficaz!" << endl;
    return(-4);
}

//Pokemon tipo Planta
string PokemonTipoPlanta::Tipo() const
{
    return("tipo Planta");
}

void PokemonTipoPlanta::AtaquePlanta(Pokemon& target)
{
    if(typeid(target) == typeid(PokemonTipoPlanta))
        target.Vida() += Neutro();
    else
    {
        if(typeid(target) == typeid(PokemonTipoFuego))
            target.Vida() += PocoEficaz();
        else
        {
            if(typeid(target) == typeid(PokemonTipoAgua))
                target.Vida() += MuyEficaz();
            else
                cerr << "Tipo no detectado";
        }
    }
}

//Pokemon tipo Fuego
string PokemonTipoFuego::Tipo() const
{
    return("tipo Fuego");
}

void PokemonTipoFuego::AtaqueFuego(Pokemon& target)
{
    if(typeid(target) == typeid(PokemonTipoPlanta))
        target.Vida() += MuyEficaz();
    else
    {
        if(typeid(target) == typeid(PokemonTipoFuego))
            target.Vida() += Neutro();
        else
        {
            if(typeid(target) == typeid(PokemonTipoAgua))
                target.Vida() += PocoEficaz();
            else
                cerr << "Tipo no detectado";
        }
    }
}

//Pokemon tipo Agua
string PokemonTipoAgua::Tipo() const
{
    return("tipo Agua");
}

void PokemonTipoAgua::AtaqueAgua(Pokemon& target)
{
    if(typeid(target) == typeid(PokemonTipoPlanta))
        target.Vida() += PocoEficaz();
    else
    {
        if(typeid(target) == typeid(PokemonTipoFuego))
            target.Vida() += MuyEficaz();
        else
        {
            if(typeid(target) == typeid(PokemonTipoAgua))
                target.Vida() += Neutro();
            else
                cerr << "Tipo no detectado";
        }
    }
}

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
        cout << endl<< "¡P2 ha ganado el combate!" << endl;
    else
        cout << endl <<"¡P1 ha ganado el combate!" << endl;
}

//Esta devuelve una referencia
Pokemon& Pokemon_Aleatorio_Referencia(int HP = 10)
{
    switch (rand()%3)
    {
        case 0:
            return (*new PokemonTipoPlanta(HP)); //UpCasting
            break;
        case 1:
            return *new PokemonTipoFuego(HP);
            break;
        case 2:
            return *new PokemonTipoAgua(HP);
            break;
        default:
            return *new PokemonTipoPlanta(HP);
            break;
    }
}

//Esta devuelve un puntero
Pokemon * Pokemon_Aleatorio_Puntero(int HP = 10)
{
    switch (rand()%3)
    {
        case 0:
            return new PokemonTipoPlanta(HP); //UpCasting
            break;
        case 1:
            return new PokemonTipoFuego(HP);
            break;
        case 2:
            return new PokemonTipoAgua(HP);
            break;
        default:
            return new PokemonTipoPlanta(HP);
            break;
    }
}
