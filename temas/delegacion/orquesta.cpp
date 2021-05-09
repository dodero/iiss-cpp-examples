#include "iostream"
#include <vector>
#include "instrumento.cpp"
using namespace std;

class Orquesta{
    public:
        void addInstrumento(Instrumento *i) { Instrumentos.push_back(i); }
        void tocarInstrumentos(){
            for(auto it : Instrumentos){
                it->tocar();
            }
        }
        void afinarInstrumentos(){
            for(auto it : Instrumentos){
                it->afinar();
            }
        }
    private:
        vector<Instrumento*> Instrumentos;
};
