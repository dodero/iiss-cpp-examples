Para realizar el ejercicio de los bancos he seguido lo siguientes aspectos vistos en la asignatura:
	-He creado la clase BankAccount donde aparte de crear el objeto compararemos con las fechas y los id
	
	-He usado también polimorfismo paramétrico que consiste en definir la misma función pero con parámetros distintos. Para ello en las functors recibiremos un tipo tm y un tripo string dentro de nuestra clase BankAccount

	-Se hace uso del tm (librería ctime) para almacenar la fecha recibida.

Detalles de implementación vistos en la asignatura

	-Uso de las excepciones mediante una clase Invalida que almacenará nuestro mensaje de error y lanzaremos excepciones con el throw y utilizaremos el try y el catch para recibirlas.
	-También se hará uso del assert en el constructor de BankAccount para aplicar otra técnica distinta de lanzamientos de excepciones vista en clase.
	
	
Para compilar este programa tendrás que hacer el comando:
	g++ -o main .\BankAccount.hpp .\BankAccount.cpp .\main.cpp

Para ejecutarlo:
	.\main