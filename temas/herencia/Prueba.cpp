#include <iostream>
#include "Aventura.hpp"

int main()
{
    Heroe * i = new Heroe();

    Aventura::t(*i);    //Heroe::luchar()
    Aventura::u(*i);    //Heroe::nadar()
    Aventura::v(*i);    //Heroe::volar()
    Aventura::w(*i);    //PersonajeDeAccion::luchar()

    return(0);
}