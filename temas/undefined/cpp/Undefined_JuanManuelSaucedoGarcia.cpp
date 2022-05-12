#include <optional>
#include <iostream>

class Jugador
{
public:
    Jugador (const std::string& nombre_, std::optional<std::string> apodo_, std::optional<int> dorsal_)
    : nombre{nombre_}, apodo{apodo_}, dorsal{dorsal_} {}

    friend std::ostream& operator << (std::ostream& os, const Jugador& player);

private:
    std::string nombre;
    std::optional<std::string> apodo;
    std::optional<int> dorsal;

};

std::ostream& operator << (std::ostream& os, const Jugador& player) 
{
    os << player.nombre << " ";
    if (player.apodo)
    {
        os << ", " << *player.apodo << ", ";
    }
    if (player.dorsal)
    {
        os << "tiene el dorsal " << *player.dorsal;
    }

    return os;
}

int main()
{
    Jugador Messi { "Messi", "la pulga", 10 };
    Jugador serresiete { "Cristiano Ronaldo", "el bicho", 7};
    Jugador Iniesta { "Iniesta", std::nullopt, 8 };
    Jugador Pepito { "Pepito", std::nullopt, std::nullopt };

    std::cout << Messi << "\n";
    std::cout << serresiete << "\n";
    std::cout << Iniesta << "\n";
    std::cout << Pepito << "\n";

    return 0;
}