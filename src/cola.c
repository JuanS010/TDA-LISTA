#include "cola.h"
#include "lista.h"
#define LISTA_P (lista_t*)cola

cola_t *cola_crear()
{
	lista_t *lista = lista_crear();
	if (!lista) {
		return NULL;
	}
	return (cola_t*)lista;
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{	
	if (!lista_insertar(LISTA_P, elemento)) {
		return NULL;
	}
	return cola;
}

void *cola_desencolar(cola_t *cola)
{
	if (lista_vacia(LISTA_P)) {
		return NULL;
	}
	return lista_quitar_de_posicion(LISTA_P, 0);
}

void *cola_frente(cola_t *cola)
{
	if (lista_vacia(LISTA_P)) {
		return NULL;
	}
	return lista_primero(LISTA_P);
}

size_t cola_tamanio(cola_t *cola)
{
	return lista_tamanio(LISTA_P);
}

bool cola_vacia(cola_t *cola)
{
	if (lista_vacia(LISTA_P)) {
		return true;
	}
	return false;
}

void cola_destruir(cola_t *cola)
{
	lista_destruir(LISTA_P);
}
