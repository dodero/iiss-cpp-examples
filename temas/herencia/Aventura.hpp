#ifndef AVENTURA_HPP
#define AVENTURA_HPP

#include <string>

//Interfaces
class SabeLuchar
{
    public:
        virtual void luchar() = 0;
};

class SabeNadar
{
    public:
        virtual void nadar() = 0;
};

class SabeVolar
{
    public:
        virtual void volar() = 0;
};

//Clases
class PersonajeDeAccion
{
    public:
        void luchar();
};

class Heroe: public PersonajeDeAccion, public SabeLuchar, public SabeNadar, public SabeVolar
{
    public:
        void volar() override final;
        void nadar() override final;
        void luchar() override final;
};

class Aventura
{
    public:
        static void t(SabeLuchar& x){x.luchar();}
        static void u(SabeNadar& u){u.nadar();}
        static void v(SabeVolar& v){v.volar();}
        static void w(PersonajeDeAccion& x){x.luchar();}
};
#endif