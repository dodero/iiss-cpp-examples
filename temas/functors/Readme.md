Para realizar el ejercicio de los bancos he seguido lo siguientes aspectos vistos en la asignatura:
	-Primero he usado el principio de cohesión reduciendo la responsabilidad de la clase BankAccount. Para esto he creado tres clases: BankAccount,  BankAcccountComparatorById y BankAccountComparatorByCreationDate.
	
		1. BankAccount se encargara de la creación del objeto y la modificación y obtención de sus parámetros.

		2. BankAcccountComparatorById se encargará de la comparación a través del id. Para esto he usado las functors como ==, != etc y a su misma vez la sobrecarga de operadores
		usando en algunos operadores, otros operadores sobrecargados anteriormente.
		
		3. BankAccountComparatorByCreationDate se encargará de la comparación a través de la fecha. Para esto he usado las functors como ==, != etc y a su misma vez la sobrecarga de operadores
		usando en algunos operadores, otros operadores sobrecargados anteriormente.
	
	-He usado también polimorfismo paramétrico que consiste en definir la misma función pero con parámetros distintos. Para ello en las functors le pasaremos dos objetos de tipo BankAcccountComparatorById y
	le aplicaremos el polimorfismo parámetrico pasádole a otros functors dos objetos de BankAccountComparatorByCreationDate.
	
	-Para definir los operadores he utilizado métodos externos debido a que en c++ le da bastantes beneficios siendo el más importante realizar la conversión implícita.

	-Se hace uso del tm (librería ctime) para almacenar la fecha recibida.

Detalles de implementación vistos en la asignatura

	-Uso de las excepciones mediante una clase Invalida que almacenará nuestro mensaje de error y lanzaremos excepciones con el throw y utilizaremos el try y el catch para recibirlas.
	-También se hará uso del assert en el constructor de BankAccount para aplicar otra técnica distinta de lanzamientos de excepciones vista en clase.
	
	
Para compilar este programa tendrás que hacer el comando:
	g++ -o main .\BankAccount.hpp .\BankAccount.cpp .\main.cpp

Para ejecutarlo:
	.\main