## Aspectos
### Descripción

Se ha realizado la transformación del código ejemplo Editor de Figuras en Java a C++, con la adición de aspectos a este último.

Para ello, he hecho uso de la documentación de [AspectC++](https://www.aspectc.org/Home.php "AspectC++"). Se ha usado un aspecto que he llamado LineBeforePoint en el cual mediante un pointcut le indicamos cuando queremos que se ejecute dicho aspecto. En este caso, el pointcut le indica al aspecto que debe lanzarse antes de que nuestro método set de la clase Point asigne nuevos valores a la variables x e y.


### Instalación y compilación del código

Para la realización de nuestro código en windows se necesita los siguientes requisitos:

- [Cmake](https://cmake.org/ "Cmake")
- [AspectC++](https://www.aspectc.org/Download.php "AspectC++")

Para la realización de nuestro código en Linux se necesita los siguientes requisitos:

- sudo apt-get install build-essential
- sudo apt install aspectc++

Una vez cumplamos los requisitos anteriores, debemos hacer lo siguiente:

> Para nuestro ejemplo, hemos realizado el proceso en linux, ya que windows es mas propenso a dar errores por incompatibilidades.

1. Tenemos nuestra carpeta aspectc++ en la cual se incluyen los dos binarios que deben residir en el mismo directorio. ag++ es solo un contenedor que llama a ac++, que realiza la transformación de código real, y g++ para la compilación en un archivo de objeto. En esta carpeta tenemos los siguientes elementos (aspectos, ac++, ag++, makefile, makefile.generic)
2. Entramos dentro de nuestra carpeta **aspectos** en la cual tenemos nuestro código.
3. Una vez dentro de dicha carpeta simplemente tendremos que abrir un terminal y escribir:
> Make run

de esta manera ejecutaremos nuestro código, igualmente para limpiar el directorio deberemos hacer un:
> Make clean

Otra opción es abrir un terminal en la carpeta aspectos y ejecutar nuestro archivo aspectos.o con el siguiente comando:

> ./aspectos

con estos comandos se ejecutaría nuestro código con éxito.

### Código
######Main.cc

    #include <iostream>
    #include "Clases.h"
    
    using namespace std;
    
    int main(){
    	Point p1 ,p2; //Declaración de dos objetos locales de la clase Point.
    	Line l1,l2; //Declaración de dos objetos locales de la clase Point.
    	
    	p1.setX(2); // Pasamos el valor de x.
    	p2.setY(3); // Pasamos el valor de y.
    
    	cout << "Valor: " << p1.getX() << ", Obtenido desde Point" << endl;
    	cout << "Valor: " << p2.getY() << ", Obtenido desde Point" << endl;
    	
    	l1.setP1(p1); // Pasamos un objeto p1 con un valor de x asignado previamente.
    	l2.setP2(p2); // Pasamos un objeto p2 con un valor de y asignado previamente.
    	
    	cout << "Valor: " << l1.getP1().getX() << ", Obtenido de Point a través de Line" << endl;
    	cout << "Valor: " << l2.getP2().getY() << ", Obtenido de Point a través de Line"<< endl;
    	
    	return 0;	
    }