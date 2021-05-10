<h1> MIXINS </h2>

<h2> Introducción </h2>

En este ejercicio implementamos un mixin en C++ haciendo uso de mecanismos del lenguaje como el polimorfismo estático y el dinámico

<h2> Compilación y ejecución </h2>

En mi caso, uso Visual Studio Code, por lo que, para compilarlo tendremos que tener configurado la extensión de c++ y tener instalado un compilador 
como bien explica en la pagina del soporte de VSC https://code.visualstudio.com/docs/languages/cpp, aunque puede usar cualquier entorno a su alcance
(que tenga configurado un compilador de C++).

<h2> Mecanismos utilizados </h2>

<p>El codigo implementado usa dos recursos del lenguaje muy potentes como son el polimorfismo estático, y el dinámico:
	Primero implementamos el polimorfismo estático mediante las templates
	Y tras esto implementamos el polimorfismo dinámico mediante la definición de metodos virtuales

<h2> Explicación del ejercicio  </h2>
<p> Antes de empezar a comprender el ejercicio vamos estaría bien explicar de manera sencilla lo que es un Mixin
	Un Mixin es un patrón de diseño que funciona de la siguiente manera:
		Añade una funcionalidad a una clase mediante otra que es denominada mixin o mixin class, la diferencia entre esta clase y una normal
		e independienter es que un mixin no esta pensado para un uso independiente.

Sabiendo esto, vamos a comenzar a explicar el ejercicio en cuestion:

En primer lugar vamos a intentar comprender la estructura del ejercicio. En primer lugar tenemos una clase padre como es Animal,
el cual tiene una serie de atributos como son m_id, m_precio, m_peso, m_sexo y y los getter's, setter's de los atributos m_peso y m_precio,
con una distinción entre ellos, que getPrecio() es un metodo virutal puro.

Para ver con mas claridad el polimorfismo hemos creado otras 2 subclases que heredan de la clase Animal y que constan en caso de Animal de Carrera un atributo 
m_carreras_ganadas que hará que aumente el precio del animal, en el caso de AnimaldeCampo tiene este mismo método que modifica su precio si este puede hacer pastoreo
o no.

A continuación tenemos las Mixin class que son tanto Comer como Ganar, comer añade una funcionalidad a la clase Animal, su funcionalidad es simple y sencilla, cuando el animal 
come (ya sea AnimalDeCarrera o AnimalDeCampo) el Animal aumenta de peso, Ganar por otra parte añade funcionalidad a la clase AnimalDeCarreras de la siguiente manera, mediante
el método setGanar podremos modificar el atributo de la clase AnimalDeCarrera de manera que también modificará el atributo heredado de la clase Animal m_precio.