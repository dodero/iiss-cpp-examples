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
	struct EstadoEspera{
		EstadoEspera(){
			std::cout << "===================\nMÁQUINA EN ESPERA." << std::endl;
			std::cout << "Introduce cualquier string para comenzar a trabajar." << std::endl;
		}
	};
	struct EstadoPausa{
		int contador_;
		EstadoPausa(int i){
			contador_=i;
			std::cout << "===================\nMÁQUINA EN PAUSA (" << contador_ << "%)." << std::endl;
			std::cout << "Introduce cualquier string para continuar con el trabajo." << std::endl;
		}
	};
	struct EstadoActivo{
		int contador_;
		EstadoActivo(){
			std::cout << "===================\nMÁQUINA ACTIVA." << std::endl;
			std::cout << "Introduce cualquier string para pausar el trabajo." << std::endl;
			contador_=0;
		}
		
		EstadoActivo(int i){
			std::cout << "===================\nMÁQUINA ACTIVA." << std::endl;
			std::cout << "Introduce cualquier string para pausar el trabajo." << std::endl;
			contador_=i;
		}
		void trabajar(){
			std::cout << "Progreso: " << contador_ << "%" << std::endl;
			contador_+=5;
		}
	};
	struct EstadoTerminado{
		EstadoTerminado(){
			std::cout << "===================\nTrabajo finalizado." << std::endl;
			std::cout <<"Introduce cualquier string para reiniciar la máquina en estado de espera." << std::endl;
		}
	};
	
	using Estado = std::variant<EstadoEspera,EstadoPausa,EstadoActivo,EstadoTerminado>; //Definición de variant de estados
	Estado estado_; 
	
	struct CambioEstado{
		Estado operator()(const EstadoActivo& e){
			if(e.contador_<100) {return EstadoPausa(e.contador_);}
			else{return EstadoTerminado();}
		}
		Estado operator()(const EstadoPausa& e){return EstadoActivo(e.contador_);}
		Estado operator()(const EstadoEspera& e){return EstadoActivo();}
		Estado operator()(const EstadoTerminado& e){return EstadoEspera();}
	};
};

int main(){
	Maquina m; //Estado por defecto 'EstadoEspera'
	std::string s;
	
	using namespace std::literals;
    while(true){
    	if(std::cin >> s) m.estado_ = std::visit(Maquina::CambioEstado{},m.estado_);	//Activación de máquina
    	
    	//Bucle de trabajo: Mientras estado sea 'EstadoActivo' o 'EstadoPausa'. 
    	//En 'EstadoTerminado', salimos; 'EstadoEspera' no se da.
    	while(std::holds_alternative<Maquina::EstadoActivo>(m.estado_) || std::holds_alternative<Maquina::EstadoPausa>(m.estado_)){
    		auto f = std::async(std::launch::async, [] {	//Capturamos el input del usuario para pausar la máquina
        		auto s = ""s;
        		std::cin >> s;
        		return s;
    		});
    		
    		//Mientras el estado sea 'EstadoActivo'
    		while(std::holds_alternative<Maquina::EstadoActivo>(m.estado_)){	
    			Maquina::EstadoActivo* e = &std::get<Maquina::EstadoActivo>(m.estado_);
    			e->trabajar();
    			if (e->contador_>100) break;
    			if(f.wait_for(1s) == std::future_status::ready) 
    				m.estado_ = std::visit(Maquina::CambioEstado{},m.estado_);	//Si hay input, pausa de máquina
    		}
    		
    		//Dejamos de estar en 'EstadoActivo'
    		if(std::holds_alternative<Maquina::EstadoPausa>(m.estado_)){				
    			if(std::cin >> s){											//Si el estado es de pausa, esperamos al input
    			 m.estado_ = std::visit(Maquina::CambioEstado{},m.estado_);	//Reactivación de máquina
    			}
    		}
    		else {
    			m.estado_ = std::visit(Maquina::CambioEstado{},m.estado_);	//Si el estado de la máquina no está en pausa, ya hemos 																																						llegado al 100% de progreso: el estado pasa a 'EstadoTerminado'.
    		}
    	}
    	m.estado_ = std::visit(Maquina::CambioEstado{},m.estado_);			//'EstadoTerminado' -> 'EstadoEspera'
    }
    
    return 0;
}
