#include <iostream>       
#include <future>         
#include <chrono>         

using namespace std;

bool primo (int x) {
  for (int i=2; i<x/2; ++i) if (x%i==0) return false;
  return true;
}

int main ()
{
	int num;
	cout <<"Introduce un numero"<<endl;
	cin >> num;
	std::future<bool> fut = std::async (primo,num); 

	cout << "comprobando, espere..."<<endl;
	std::chrono::milliseconds span (100);
	while (fut.wait_for(span)==std::future_status::timeout)
    std::cout << '.' << std::flush;

	bool x = fut.get();     

	cout << num << (x?" es":" no es") << " primo.\n";

	return 0;
}
