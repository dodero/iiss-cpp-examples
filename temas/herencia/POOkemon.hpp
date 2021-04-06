#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

using namespace std;

//Declaración adelantada
class Pokemon;

//Enumerado de tipos
enum Tipo
{
    Planta, Agua, Fuego
};

//Interfaz Mediator
class AtaquesMediator
{
    public:
        virtual void resolverAtaque(Pokemon& shooter, Pokemon& target) = 0;
        virtual string getTipoString(Tipo t) = 0;
};

//Implementación del mediator
class AtaquesImp: public AtaquesMediator
{
    public:
        void resolverAtaque(Pokemon& shooter, Pokemon& target) override final;
        string getTipoString(Tipo t) override final;
    private:    
        bool esPocoEficaz(Pokemon& shooter, Pokemon& target);
        bool esNeutro(Pokemon& shooter, Pokemon& target);
        bool esMuyEficaz(Pokemon& shooter, Pokemon& target);
        int AtaquePocoEficaz();
        int AtaqueNeutro();
        int AtaqueMuyEficaz();
};

//Clase
class Pokemon
{
    //Parte publica
    public:
        //Constructor
        Pokemon(int HP, Tipo T, AtaquesMediator& A): hp{HP}, t{T}, a{A} {}

        //Devuelve el enumerado del tipo del pokemon
        const Tipo& getTipo() const {return t;}
        //Devuelve un string segun el tipo del pokemon
        string getTipoString() const;

        //Método de ataque
        void Atacar(Pokemon&);
        //Celebración de la victoria (virtual puro)
        virtual string Celebra() = 0;

        //Consultor de la vida
        const int& Vida() const {return (hp);}
        //Modificador de la vida
        int& Vida() {return(hp);}

        //Destructor
        virtual ~Pokemon() {};

    //Parte privada
    private:
        int hp; //Atributo con la vida
        Tipo t; //Atributo con el tipo del pokemon

    //Protegido
    protected:
        AtaquesMediator& a; //Mediador para los ataques
};


//Clase de pokemon tipo planta
class PokemonTipoPlanta: public Pokemon
{
    public:
        //Constructor, usa el de pokemon genérico
        PokemonTipoPlanta(AtaquesMediator& A, int HP = 10): Pokemon(HP, Planta, A){}

        //Celebración de la victoria del pokemon tipo planta
        string Celebra() override final; 
};

class PokemonTipoFuego: public Pokemon
{
    public:
        //Constructor, usa el de pokemon genérico
        PokemonTipoFuego(AtaquesMediator& A, int HP = 10): Pokemon(HP, Fuego, A){}

        //Celebración de la victoria del pokemon tipo fuego
        string Celebra() override final; 
};

class PokemonTipoAgua : public Pokemon
{
    public:
        //Constructor, usa el de pokemon genérico
        PokemonTipoAgua(AtaquesMediator& A, int HP = 10): Pokemon(HP, Agua, A){}

        //Celebración de la victoria del pokemon tipo agua
        string Celebra() override final; 
};

#endif