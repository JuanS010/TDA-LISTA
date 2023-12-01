#include "pila.h"
#include "lista.h"
#define LISTA_P (lista_t*)pila

pila_t *pila_crear()
{
	lista_t *lista = lista_crear();
	if (!lista) {
		return NULL;
	}
	return (pila_t*)lista;
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{	
	if (!lista_insertar_en_posicion(LISTA_P, elemento, 0)) {
		return NULL;
	}
	return pila;
}

void *pila_desapilar(pila_t *pila)
{
	if (lista_vacia(LISTA_P)) {
		return NULL;
	}
	return lista_quitar_de_posicion(LISTA_P, 0);
}

void *pila_tope(pila_t *pila)
{
	if (lista_vacia(LISTA_P)) {
		return NULL;
	}
	return lista_primero(LISTA_P);
}

size_t pila_tamanio(pila_t *pila)
{
	return lista_tamanio(LISTA_P);
}

bool pila_vacia(pila_t *pila)
{
	if (lista_vacia(LISTA_P)) {
		return true;
	}
	return false;
}

void pila_destruir(pila_t *pila)
{
	lista_destruir(LISTA_P);
}
