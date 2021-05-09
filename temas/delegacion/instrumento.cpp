#include "iostream"
using namespace std;

class Instrumento{
    public:
        virtual void afinar() = 0;
        virtual void tocar() = 0;
        const string getNombreInstrumento() { return nombreInstrumento; }
    protected:
        string nombreInstrumento;
};

class Viento: public Instrumento{
    public:
        Viento(string name){nombreInstrumento = name;}
        void afinar(){ cout << "Afinando instrumento de Viento: " << getNombreInstrumento() << endl;}
        void tocar() { cout << "Tocando instrumento de Viento: " << getNombreInstrumento() << endl;}

};

class Cuerda: public Instrumento{
    public:
        Cuerda(string name){nombreInstrumento = name;}
        void afinar(){ cout << "Afinando instrumento de Cuerda: " << getNombreInstrumento() << endl;}
        void tocar(){ cout << "Tocando instrumento de Cuerda: " << getNombreInstrumento() << endl;}
};

class Percusion: public Instrumento{
    public:
        Percusion(string name){nombreInstrumento = name;}
        void afinar(){ cout << "Afinando instrumento de Percusión: " << getNombreInstrumento() << endl;}
        void tocar(){ cout << "Tocando instrumento de Percusión: " << getNombreInstrumento() << endl;}
};