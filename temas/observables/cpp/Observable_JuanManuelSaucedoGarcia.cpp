#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Goleador {
	private:
		
		vector <class Observer *> goleadores;
	
	
	public:
		void incluir_goleadores(Observer *o)
		{
			goleadores.push_back(o);
		}
		
		void update();
	
	
};




class Observer {
	private:
		
		Goleador *g;
		string s;
		
		
	public:
		Observer(Goleador *g_, string s_)
		{
			g = g_;
			s = s_;
			g->incluir_goleadores(this);
		}
		
		virtual void update() = 0;

		
		Goleador *getGoleador()
		{
			return g;
		}
		
		string getcadena()
		{
			return s;
		}
	
	
};


void Goleador::update()
{
	for(int i = 0; i < goleadores.size(); i++)
	{
		goleadores[i]->update();
	}
}



class Defensa : public Observer{
	public:
		Defensa(Goleador *g, string s) : Observer(g,s){}
		void update()
		{
			cout << getcadena() << endl;
		}
};


class Medio : public Observer{
	public:
		Medio(Goleador *g, string s) : Observer(g,s){}
		void update()
		{
			cout << getcadena() << endl;
		}
};



class Delantero : public Observer{
	public:
		Delantero(Goleador *g, string s) : Observer(g,s){}
		void update()
		{
			cout << getcadena() << endl;
		}
};


int main()
{
	Goleador gol;
	
	Defensa dfc(&gol,"Que testarazo!!!");
	Medio mc(&gol, "Desde su casa!!!");
	Delantero dc(&gol, "Otro mas par su cuenta particular!!!");
	
	gol.update();
	
}


