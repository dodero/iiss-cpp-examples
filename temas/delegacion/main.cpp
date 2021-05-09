#include "orquesta.cpp"

int main(int argc, char const *argv[])
{
    Orquesta orquesta;
    orquesta.addInstrumento(new Viento("trompeta"));
    orquesta.addInstrumento(new Cuerda("violin"));
    orquesta.addInstrumento(new Cuerda("viola"));
    orquesta.addInstrumento(new Percusion("tambor"));
    orquesta.afinarInstrumentos();
    orquesta.tocarInstrumentos();
}