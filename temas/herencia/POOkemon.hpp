#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

using namespace std;

//Clase abstracta
class Pokemon
{
    //Parte publica
    public:
        //Constructor
        Pokemon(int HP = 10): HP_{HP}{}

        //Para imprimir el tipo del pokemon, método virtual puro
        virtual string tipo() const = 0;

        //Método de ataque virtual puro
        virtual void Atacar(Pokemon&) = 0;

        //Consultor de la vida
        const int& Vida() const {return (HP_);}
        //Modificador de la vida
        int& Vida() {return(HP_);}

        //Destructor
        virtual ~Pokemon() {};

    //Parte privada
    private:
        int HP_; //Atributo con la vida
};

//Interfaces
class SabeAtaquePlanta
{
    public:
        virtual void AtaquePlanta(Pokemon& target) = 0;
};

class SabeAtaqueFuego
{
    public:
        virtual void AtaqueFuego(Pokemon& target) = 0;
};

class SabeAtaqueAgua
{
    public:
        virtual void AtaqueAgua(Pokemon& target) = 0;
};

//Clase para los ataques
class Ataques
{
    public:
        int PocoEficaz();
        int Neutro();
        int MuyEficaz();
};


//Clase de pokemon tipo planta
class PokemonTipoPlanta: public Pokemon, Ataques, SabeAtaquePlanta
{
    public:
        //Constructor, usa el de pokemon genérico
        PokemonTipoPlanta(int HP = 10): Pokemon(HP){}

        //Le otorgo de comportamiento a los métodos y no quiero que nadie los sobreescriba
        void AtaquePlanta(Pokemon& target) override final;

        void Atacar(Pokemon& target) override final {AtaquePlanta(target);}

        //Método para devolver el tipo como string
        string tipo () const override;
};

class PokemonTipoFuego: public Pokemon, Ataques, SabeAtaqueFuego
{
    public:
        //Constructor, usa el de pokemon genérico
        PokemonTipoFuego(int HP = 10): Pokemon(HP){}

        //Le otorgo de comportamiento al método y no quiero que nadie lo sobreescriba
        void AtaqueFuego(Pokemon& target) override final;

        void Atacar(Pokemon& target) override final {AtaqueFuego(target);}

        //Método para devolver el tipo como string
        string tipo () const override;
};

class PokemonTipoAgua : public Pokemon, Ataques, SabeAtaqueAgua
{
    public:
        //Constructor, usa el de pokemon genérico
        PokemonTipoAgua(int HP = 10): Pokemon(HP){}

        //Le otorgo de comportamiento al método y no quiero que nadie lo sobreescriba
        void AtaqueAgua(Pokemon& target) override final;

        void Atacar(Pokemon& target) override final {AtaqueAgua(target);}

        //Método para devolver el tipo como string
        string tipo () const override;
};

#endif