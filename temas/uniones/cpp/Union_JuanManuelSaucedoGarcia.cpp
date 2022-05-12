#include <iostream>
#include <variant>
#include <vector>

using namespace std;

class Delantero
{
    public:
        void Chutar() {cout << "Es un golazo!!!" << endl;}
};

class Medio
{
    public:
        void Chutar() {cout << "Al palo!!!" << endl;}
};

class Defensa
{
    public:
        void Chutar() {cout << "Se va mas cerca del banderin de corner que de la porteria" << endl;}
};



int main()
{
  std::vector<std::variant<Delantero, Medio, Defensa>> jugadores
  {
      Delantero(),
      Medio(),
      Defensa(),
      Medio()
  }; 
    
    auto Instruccion_entrenador = [](auto& jugador) {jugador.Chutar();};

    for(auto& jugador : jugadores)
    {
        std::visit(Instruccion_entrenador, jugador);
    }

    return 0;
}






