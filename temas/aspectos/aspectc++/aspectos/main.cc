#include <iostream>
#include "Clases.h"

using namespace std;

int main(){
	Point p1 ,p2;
	Line l1,l2;
	
	p1.setX(2);
	p2.setY(3);

	cout << "Valor: " << p1.getX() << ", Obtenido desde Point" << endl;
	cout << "Valor: " << p2.getY() << ", Obtenido desde Point" << endl;
	
	l1.setP1(p1);
	l2.setP2(p2);
	
	cout << "Valor: " << l1.getP1().getX() << ", Obtenido de Point a través de Line" << endl;
	cout << "Valor: " << l2.getP2().getY() << ", Obtenido de Point a través de Line"<< endl;
	
	return 0;
	
}