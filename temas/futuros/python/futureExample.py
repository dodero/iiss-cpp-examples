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