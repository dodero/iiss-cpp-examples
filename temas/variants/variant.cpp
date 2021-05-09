#include <iostream>
#include <thread>
#include <future>
#include <variant>
#include <cstring>

/*
EJEMPLO DEL USO DE VARIANT PARA UNA MÁQUINA DE ESTADOS FINITOS.
REPRESENTAMOS LOS DISTINTOS ESTADOS POSIBLES EN UN VARIANT DE ESTRUCTURAS QUE REPRESENTAN
CADA UNO DE LOS ESTADOS, Y VAMOS VARIANDO EL ESTADO ACTUAL MEDIANTE FUNCIONES COMO 'ACTIVAR' O 'PAUSAR'
*/

class Maquina{
public:
	struct EstadoEspera{};
	struct EstadoPausa{};
	struct EstadoActivo{};
	struct EstadoTerminado{};
	int contador_;
	
	using Estado = std::variant<EstadoEspera,EstadoPausa,EstadoActivo,EstadoTerminado>; //Definición de variant de estados
	Estado estado_; 
	
	struct VisitorEstado{	//Visitor para mostrar el estado de la máquina por la consola
		void operator()(Maquina::EstadoEspera const&  e)const{
			std::cout << "===================\nMÁQUINA EN ESPERA.\nIntroduce cualquier string para activarla.\n===================" << std::endl;
		}
		
		void operator()(Maquina::EstadoPausa const&  e)const{
			std::cout << "===================\nMÁQUINA EN PAUSA.\nIntroduce cualquier string para continuar con el trabajo.\n===================" << std::endl;
		}
		
		void operator()(Maquina::EstadoActivo const&  e)const{
			std::cout << "===================\nMÁQUINA ACTIVA.\nIntroduce cualquier string para pausar el trabajo.\n===================" << std::endl;
		}
		
		void operator()(Maquina::EstadoTerminado const&  e)const{
			std::cout << "===================\nTrabajo finalizado. Introduce cualquier string para volver al estado de espera.\n===================" << std::endl;
		}
	};
	
	Maquina(){
		contador_=0;
		std::visit(VisitorEstado{},estado_);
	}
	
	//Funciones para cambiar el estado de la máquina
	void pausar(){
		estado_ = EstadoPausa();
		std::visit(VisitorEstado{},estado_);
	}
	
	void activar(){
		estado_ = EstadoActivo();
		std::visit(VisitorEstado{},estado_);
	}
	
	void reiniciar(){
		contador_=0;
		estado_ = EstadoEspera();
		std::visit(VisitorEstado{},estado_);
	}
	
	void terminar(){
		estado_ = EstadoTerminado();
		std::visit(VisitorEstado{},estado_);
	}
};

int main(){
	Maquina m; //Estado por defecto 'EstadoEspera'
	std::string s;
	
	using namespace std::literals;
    while(true){
    	if(std::cin >> s) m.activar();	//Activación de máquina
    	
    	while(m.contador_<100){
    		auto f = std::async(std::launch::async, [] {
        		auto s = ""s;
        		std::cin >> s;
        		return s;
    		});
    		
    		while(std::holds_alternative<Maquina::EstadoActivo>(m.estado_) && m.contador_<=100){	//Mientras el estado sea 'EstadoActivo' y no haya terminado el trabajo
    			std::cout << "Progreso: " << m.contador_ << "%" << std::endl;	//Mostramos el progreso
				m.contador_+=5;
    			if(f.wait_for(1s) == std::future_status::ready) m.pausar();	//Si hay input, pausa de máquina
    		}
    		if(std::holds_alternative<Maquina::EstadoPausa>(m.estado_)){	//Si el estado es de pausa, esperamos al input
    			if(std::cin >> s) m.activar();	//Reactivación de máquina
    		}
    		else m.terminar();	//Si el estado de la máquina no está en pausa, ya hemos llegado al 100% de progreso: el estado pasa a 'EstadoTerminado'.
    	}
    	m.reiniciar();
    }
    
    return 0;
}
