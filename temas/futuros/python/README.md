## Instrucciones para compilar y ejecutar el código
Deberemos tener instalado python, luego instalar el módulo request ejecutando en una terminal:

pip3 install requests

Para finalizar abriremos la carpeta correspondiente y escribiremos en la terminal:  
`python futureExample.py`

## Codigo
import logging
import requests
import threading
from concurrent.futures import Future

logging.basicConfig(level=logging.DEBUG, format='%(message)s')
#definimos la petición a la api
def show_pokemon_name(response):
    if response.status_code == 200:
        response_json = response.json()
        name = response_json.get('forms')[0].get('name')

        logging.info(f'El nombre del pokemon es {name}')

def generate_request(url):
    #generemos el atributo future
    future = Future()
 
    #lanzamos un hilo a la espera de que future obtenga un valor
    thread = threading.Thread(target=(
        lambda: future.set_result(requests.get(url))
    ))
    thread.start()

    return future

if __name__ == '__main__':
    future = generate_request('https://pokeapi.co/api/v2/pokemon/1/')
    #funcion que se ejecutará una vez el future cambie de valor
    future.add_done_callback(
        lambda future: show_pokemon_name(future.result())
    )
    #mensaje que se irá mostrando mientra future no tenga valor
    while not future.done():
        logging.info('A la espera de un resultado')## Instrucciones para compilar y ejecutar el código')


## Explicación
Un future, es un valor abstracto que en el momento de declararlo no tiene ningún valor asociado, pero que en algún momento del programa, puede coger valor, de ahí su nombre.

Lo interesante es que podremos lanzar funciones, llamadas callbacks, una vez el atributo future modifique su valor y hacer uso del parámetro.

Para verlo más claro, voy a explicar un poco el código de ejemplo. El programa consiste en lanzar una petición a una api de pokemon, que nos devolverá el nombre de un pokemon. Este caso nos viene perfecto, porque la petición a la api tardará unos segundos en responder, siendo ideal para comprobar el funcionamiento de los futuros.
Primero formalizamos la petición a la api y definimos que queremos que nos devuelva. Luego declararemos un future, que no tendrá valor y lanzaremos un hilo que se quedará a la respuesta de la petición de la api. 
Mientras el valor future no obtenga ningún resultado, iremos imprimiendo en pantalla "a la espera de resultado".
Una vez future tenga valor, se lanzará el método callback con el parámetro y se imprimirá por pantalla el nombre de pokemon.