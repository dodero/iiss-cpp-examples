#include <iostream>
#include <string>
using namespace std;

class Animal{
	public:
		Animal(): m_id (0),m_precio(1),m_sexo(true),m_peso(0){};

		void setPeso(float peso){m_peso = peso;}
		void setPrecio(float precio){m_precio += precio;}
		
		//virtual float getPrecio() = 0;
		float getPeso(){return m_peso;};
	
		int m_id;
		float m_precio;
		float m_peso;
		bool m_sexo;
};

template <typename T>
class AnimaldeCarreras: public T{
	public:
		AnimaldeCarreras():T(), m_carreras_ganadas(0){};
		void setCarreras_ganadas(int num){m_carreras_ganadas += num;}

		float getPrecio(){return T::getPrecio(T::setPrecio(m_carreras_ganadas * 10));}

		int m_carreras_ganadas;
};

template <typename T>
class AnimaldeCampo:public T{
	public:
		AnimaldeCampo():T(), m_pastoreo(0){};
		void setPastoreo(int flag){m_pastoreo = flag;}

		float getPrecio(){return T::getPrecio(T::setPrecio((m_pastoreo + 1)* 10));}
		int m_pastoreo;
};

template <typename T>
class Comer : public T{
	public:
		void setComer(int num){T::setPeso(num);}
};

template <typename T>
class Ganar : public T{
	public:
		void setGanar(int num){T::setCarreras_ganadas(num),T::setPrecio(T::getPrecio +=25);}
};

int main(){

	AnimaldeCarreras<Ganar<Animal>> Speedy_Gonzales;
	AnimaldeCarreras<Comer<Animal>> Galgoloco;

	AnimaldeCampo<Comer<Animal>> Boyero;


	Speedy_Gonzales.setCarreras_ganadas(7);
	Galgoloco.setComer(50);
	Boyero.setComer(20);

	cout<< "El animal de carreras Speedy Gonzales ha ganado: "<< Speedy_Gonzales.m_carreras_ganadas<< " carreras" <<endl;
	cout<< "El animal de carreras Galgoloco pesa:"<< Galgoloco.m_peso<< " kg" <<endl;
	cout<< "El animal de campo Boyero pesa:"<< Boyero.m_peso<< " kg"<<endl;
}
