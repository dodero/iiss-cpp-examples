#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
#include <thread>
#include <string> 
#include <thread>

#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
#include <thread>
#include <string> 
#include <thread>


=======
using namespace std;

int functionFactorial ( std::future<int>& promiseOfFuture ){
	
	int finalFactorial =1;
	int numberFactorial = promiseOfFuture.get(); //Hasta que no se ejecute el 
						//set_value del hilo principal la promesa de un futuro no continuara
	
	for(int nextfactor= numberFactorial ; nextfactor>1 ; nextfactor--) //Calculo de factorial
		finalFactorial *=nextfactor;
		
	cout << "El factorial es "<< finalFactorial << endl;
	
	return finalFactorial; //Devoluci�n de un valor futuro (finalfactorial)
}

int main(){
	
	int factor = 5; //Factorial a realizar
	int factorial; //Factorial final
	
	std::promise<int> promise;	//Promesa de un valor
	std::future<int> promiseOfFuture = promise.get_future(); //La promesa nos proporcionar� un futuro
    std::future<int> future = std::async(std::launch::async , 
			functionFactorial, std::ref(promiseOfFuture));  //Ejecuci�n asincrona
    
    std::this_thread::sleep_for(chrono::milliseconds(10)); //dormimos el hilo principal por un tiempo
	

    try{

    promise.set_value(factor); //Damos el valor prometido anteriormente a promise.
	factorial = future.get(); //Obtenemos el valor prometido del futuro 
								//del hilo asincrono que ejecuta factorial
    cout << factor << "! = "<<factorial ; //Mostramos el factorial del factor 'factor'.
	
	}catch(std::exception &e){ //Si ocurre una excepcion, la lanzamos.
		promise.set_exception(std::current_exception());
	}
    
}
