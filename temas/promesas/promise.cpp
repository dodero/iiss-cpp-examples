#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
#include <thread>
#include <string> 
#include <thread>
using namespace std;



int factorial ( std::future<int>& f ){
	
	int k =1;
	int N = f.get();
	
	for(int i= N ; i>1 ; i--)
		k *=i;
	cout << "el factorial es "<< k << endl;
	return k;
}

int main(){
	int y = 5;
	int x;
	std::promise<int> prom;
	std::future<int> f = prom.get_future();
    std::future<int> futur = std::async(std::launch::async , factorial, std::ref(f));
    
    std::this_thread::sleep_for(chrono::milliseconds(10));
	

    
    prom.set_value(y);
    
    x = futur.get();
    cout << y << "! = "<<x ;
    return 0;
}
