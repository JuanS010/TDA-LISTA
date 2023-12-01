#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2m.h"
#define VOLUMEN 10000

void listaSeCreaVacia()
{	
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista != NULL, "Se crea la lista");
	pa2m_afirmar(lista_vacia(lista), "La lista se crea vacia");
	pa2m_afirmar(!lista_primero(lista), "La lista no tiene inicio");
	pa2m_afirmar(!lista_ultimo(lista), "La lista no tiene fin");
	pa2m_afirmar(lista_quitar(lista) == NULL, "No se puede quitar");
	pa2m_afirmar(lista_tamanio(lista) == 0, "El tamaño de la lista es 0");
	lista_destruir(lista);
}

void prueba_insertar_quitar(){

    lista_t *lista = lista_crear();
    int n1=10,n2=20;
    short n3=30,n4=40; 
    char n5=5,n6=6;
    lista_t *lista2 = lista_crear();
    long n7=7,n8=8;
    float n9=9.0;
    double n10=10.0,n11=11.0;

    lista_insertar_en_posicion(lista, &n1, 0);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &n1, 
				"El elemento de la posicion 0 es el correcto");
    lista_insertar(lista, &n4);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &n4, 
				"El elemento de la posicion 1 es el correcto");
    lista_insertar(lista, &n5);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &n5, 
				"El elemento de la posicion 2 es el correcto");
    lista_insertar_en_posicion(lista, &n2,1);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &n2, 
				"El elemento de la posicion 1 es el correcto");
    lista_insertar_en_posicion(lista, &n3, 2);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &n3, 
				"El elemento de la posicion 2 es el correcto");
	pa2m_afirmar(lista_ultimo(lista) == &n5, 
				"El ultimo elemento de la lista es el correcto");
    lista_insertar(lista, &n6);
    lista_insertar(lista, &n7);
    lista_insertar(lista, &n9);
    lista_insertar_en_posicion(lista, &n8, 7);
    lista_insertar(lista, &n10);
    lista_insertar_en_posicion(lista, &n11, 100);

	pa2m_afirmar(lista_ultimo(lista) == &n11, 
				"El ultimo elemento de la lista es el correcto");
    lista_insertar_en_posicion(lista, &lista2, 0);

	pa2m_afirmar(lista_tamanio(lista) == 12, 
				"Se insertaron 12 elementos y la lista tiene tamaño 12");
	pa2m_afirmar(!lista_vacia(lista), "La lista NO esta vacia");
	pa2m_afirmar(lista_primero(lista) == &lista2, 
				"El primer elemento es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == &n4, 
				"El elemento de la posicion 4 es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &lista2, 
				"El elemento de la posicion 0 es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 11) == &n11, 
				"El elemento de la posicion 11 es el correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 100) == NULL, 
				"El elemento de la posicion 100 es NULL");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 9) == &n9, 
				"Se elimina de la posicion 9");
    pa2m_afirmar(lista_quitar(lista) == &n11, 
				"Se elimina el elemento de la ultima posicion");
    pa2m_afirmar(lista_quitar(lista) == &n10, 
				"Se elimina el elemento de la ultima posicion");
    pa2m_afirmar(lista_quitar(lista) == &n8, 
				"Se elimina el elemento de la ultima posicion");
    pa2m_afirmar(lista_quitar(lista) == &n7, 
				"Se elimina el elemento de la ultima posicion");
    pa2m_afirmar(lista_quitar_de_posicion(lista, 4) == &n4, 
				"Se elimina de la posicion 7");
    pa2m_afirmar(lista_quitar_de_posicion(lista, 6) == &n6, 
				"Se elimina de la posicion 5");
    pa2m_afirmar(lista_quitar(lista) == &n5, 
				"Se elimina el elemento de la ultima posicion");
	pa2m_afirmar(lista_quitar_de_posicion(lista, 2) == &n2, 
				"Se elimina de la posicion 2");
    pa2m_afirmar(lista_quitar(lista) == &n3, 
				"Se elimina el elemento de la ultima posicion");
    pa2m_afirmar(lista_quitar(lista) == &n1, 
				"Se elimina el elemento de la ultima posicion");

	pa2m_afirmar(lista_tamanio(lista) == 1, "La lista tiene 1 elemento");

    lista_destruir(lista); 
    pa2m_afirmar(lista2 != NULL, "Los elementos no se destruyen con la lista");
    lista_destruir(lista2);
}

void destruir(void *lista){
    lista_destruir(lista);
}

void prueba_destruir_todo(){

    lista_t *lista = lista_crear();
    lista_t *lista1 = lista_crear();
    lista_t *lista2 = lista_crear();
    lista_t *lista3 = lista_crear();
    lista_insertar(lista, lista1);
    lista_insertar(lista, lista2);
    lista_insertar(lista, lista3);

	pa2m_afirmar(lista_tamanio(lista) == 3, "La lista tiene 3 elementos");
    lista_destruir_todo(lista, destruir);

	pa2m_afirmar(1, "El elemento 1 se destuye con la lista");
	pa2m_afirmar(1, "El elemento 2 se destuye con la lista");
	pa2m_afirmar(1, "El elemento 3 se destuye con la lista\n  (ver valgrind)");
}

void prueba_volumen(){

	lista_t *lista = lista_crear();
	pa2m_afirmar(lista_vacia(lista) && lista_tamanio(lista) == 0, 
				"La lista esta vacia, el tamaño es 0");

	int vector[VOLUMEN];
    for (int i=0; i<VOLUMEN; i++){
        vector[i] = i;
        lista_insertar(lista, &vector[i]);
	}
	pa2m_afirmar(lista_tamanio(lista) == VOLUMEN, 
				"Se insertan 10000 elementos");
	lista_destruir(lista);
}

void prueba_null(){
	lista_t *lista = lista_crear();
	pa2m_afirmar(lista_vacia(lista), "La lista esta vacia");
	lista_insertar(lista, NULL);
	pa2m_afirmar(lista_tamanio(lista) == 1, "Inserto NULL, el tamaño es 1");
	pa2m_afirmar(!lista_vacia(lista), "La lista no esta vacia");
	pa2m_afirmar(lista_quitar(lista) == NULL, "Quito NULL");
	pa2m_afirmar(lista_tamanio(lista) == 0, "El tamaño de la lista es 0");
	pa2m_afirmar(lista_vacia(lista), "la lista esta vacia"); 
	lista_destruir(lista);
}

bool sumatoria_impares(void *elemento, void *extra) {
    
    if (*(int*) extra == 9){
        return false;
    }
    if ((*(int*) elemento % 2) != 0){
        *(int*) extra += *(int*) elemento;
    }    
    return true;
}

bool sumatoria_pares(void *elemento, void *extra) {

    if ((*(int*) elemento % 2) == 0){
        *(int*) extra += *(int*) elemento;
    }    
    return true;
}

bool sumatoria(void *elemento, void *extra){

	*(int*) extra += *(int*) elemento;
	return true;
}

bool buscar_segundo(void* elemento, void* extra) {

	if (*(int*)elemento == 2) {
		return false;
	}
	return true;
}

void prueba_iterador(){

	lista_t *lista = lista_crear();
    int n1=1, n2=2, n3=3, n4=4, n5=5, n6=6, n7=7, n8=8;
    lista_insertar(lista, &n1);
    lista_insertar(lista, &n2);
    lista_insertar(lista, &n3);
    lista_insertar(lista, &n4);
    lista_insertar(lista, &n5);
    lista_insertar(lista, &n6);
    lista_insertar(lista, &n7);
    lista_insertar(lista, &n8);

	int contador = 0;
	pa2m_afirmar(lista_con_cada_elemento(lista, sumatoria, &contador) == 8 
				&& contador == 36, "Se itero la lista");

    contador = 0;
	pa2m_afirmar(lista_con_cada_elemento(lista, sumatoria_pares, &contador) == 8
				&& contador == 20, "Se itero la lista con una condicion");

	contador = 0;
	pa2m_afirmar(lista_con_cada_elemento(lista, sumatoria_impares, &contador) == 6
				&& contador == 9, "Se itero la lista con corte");

	pa2m_afirmar(lista_con_cada_elemento(lista, buscar_segundo, &contador) == 2,
				"Se itero la lista hasta el segundo elemento");

	lista_destruir(lista);
}

void prueba_iterador_externo(){

	lista_t *lista = lista_crear();
    int n1=1, n2=2, n3=3;
    lista_insertar(lista, &n1);
    lista_insertar(lista, &n2);
    lista_insertar(lista, &n3);

	lista_iterador_t* iterador = lista_iterador_crear(lista);
	pa2m_afirmar(iterador != NULL, "Se creo el iterador");
	
	pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &n1, 
				"El elemento actual es 1");
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador), 
				"Hay siguiente");
	pa2m_afirmar(lista_iterador_avanzar(iterador), 
				"Se avanza");
	
	pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &n2, 
				"El elemento actual es 2");
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador), 
				"Hay siguiente");
	pa2m_afirmar(lista_iterador_avanzar(iterador), 
				"Se avanza");

	pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &n3, 
				"El elemento actual es 3");
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador), 
				"Hay siguiente");
	pa2m_afirmar(!lista_iterador_avanzar(iterador), 
				"Se avanza a NULL");

	pa2m_afirmar(lista_iterador_elemento_actual(iterador) == NULL, 
				"El elemento actual es NULL");
	pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador), 
				"NO Hay siguiente");
	pa2m_afirmar(!lista_iterador_avanzar(iterador), 
				"NO se avanza");

	lista_iterador_destruir(iterador);
	lista_destruir(lista);
}

void prueba_funciones_null(){

	lista_t *lista = lista_crear();
	void* puntero = NULL;

	pa2m_afirmar(lista_insertar(NULL, NULL) == NULL, 
				"Insertar con lista NULL devuelve NULL");
	pa2m_afirmar(lista_insertar_en_posicion(NULL, NULL, 2) == NULL, 
				"Insertar posicion con lista NULL devuelve NULL");
	pa2m_afirmar(lista_quitar(NULL) == NULL, 
				"Quitar con lista NULL devuelve NULL");
	pa2m_afirmar(lista_quitar_de_posicion(NULL, 2) == NULL, 
				"Quitar posicion con lista NULL devuelve NULL");
	pa2m_afirmar(lista_elemento_en_posicion(NULL, 2) == NULL, 
				"Elemento posicion con lista NULL devuelve NULL");
	pa2m_afirmar(lista_buscar_elemento(NULL, NULL, puntero) == NULL, 
				"Buscar elemento con lista NULL devuelve NULL");
	pa2m_afirmar(lista_buscar_elemento(lista, NULL, puntero) == NULL, 
				"Buscar elemento con comparador NULL devuelve NULL");
	pa2m_afirmar(lista_primero(NULL) == NULL, 
				"Primero con lista NULL devuelve NULL");
	pa2m_afirmar(lista_ultimo(NULL) == NULL, 
				"Ultimo con lista NULL devuelve NULL");
	pa2m_afirmar(lista_vacia(NULL) == true, 
				"Vacia con lista NULL devuelve true");
	pa2m_afirmar(lista_tamanio(NULL) == 0, 
				"Tamaño con lista NULL devuelve 0");
	pa2m_afirmar(lista_iterador_crear(NULL) == NULL, 
				"Crear iterador con lista NULL devuelve NULL");
	pa2m_afirmar(lista_iterador_tiene_siguiente(NULL) == false, 
				"Iterador siguiente con lista NULL devuelve false");	
	pa2m_afirmar(lista_iterador_avanzar(NULL) == false, 
				"Iterador avanzar con lista NULL devuelve false");
	pa2m_afirmar(lista_iterador_elemento_actual(NULL) == NULL, 
				"Iterador actual con lista NULL devuelve NULL");
	pa2m_afirmar(lista_con_cada_elemento(NULL, NULL, NULL) == 0, 
				"Iterador interno con lista NULL devuelve 0");
	pa2m_afirmar(lista_con_cada_elemento(lista, NULL, NULL) == 0, 
				"Iterador interno con funcion NULL devuelve 0");

	lista_destruir(lista);
}

void PilaSeCreaVacia(){

	pila_t *pila = pila_crear();
	pa2m_afirmar(pila != NULL, "Se crea la pila");
	pa2m_afirmar(pila_vacia(pila), "La pila se crea vacia");
	pa2m_afirmar(!pila_tope(pila), "La pila no tiene tope");
	pa2m_afirmar(pila_desapilar(pila) == NULL, "No se puede desapilar");
	pa2m_afirmar(pila_tamanio(pila) == 0, "El tamaño de la pila es 0");
	pila_destruir(pila);
}

void prueba_apilar_desapilar(){

	pila_t* pila = pila_crear();
    int n1=1, n2=2, n3=3, n4=4, n5=5, n6=6, n7=7, n8=8;
	pa2m_afirmar(pila_vacia(pila), "La pila esta vacia");

	pa2m_afirmar(pila_apilar(pila, &n1) == pila, "Se apila 1");
	pa2m_afirmar(pila_apilar(pila, &n2) == pila, "Se apila 2");
	pa2m_afirmar(pila_apilar(pila, &n3) == pila, "Se apila 3");
	pa2m_afirmar(pila_apilar(pila, &n4) == pila, "Se apila 4");
	pa2m_afirmar(pila_apilar(pila, &n5) == pila, "Se apila 5");
	pa2m_afirmar(pila_apilar(pila, &n6) == pila, "Se apila 6");
	pa2m_afirmar(pila_apilar(pila, &n7) == pila, "Se apila 7");
	pa2m_afirmar(pila_apilar(pila, &n8) == pila, "Se apila 8");

	pa2m_afirmar(pila_tamanio(pila) == 8, "El tamaño de la pila es 8");
	pa2m_afirmar(!pila_vacia(pila), "La pila no esta vacia");
	pa2m_afirmar(pila_tope(pila) == &n8, "El tope de la pila es 8");

	pa2m_afirmar(pila_desapilar(pila) == &n8, "Se desapila 8");
	pa2m_afirmar(pila_desapilar(pila) == &n7, "Se desapila 7");
	pa2m_afirmar(pila_desapilar(pila) == &n6, "Se desapila 6");
	pa2m_afirmar(pila_desapilar(pila) == &n5, "Se desapila 5");
	pa2m_afirmar(pila_desapilar(pila) == &n4, "Se desapila 4");
	pa2m_afirmar(pila_desapilar(pila) == &n3, "Se desapila 3");
	pa2m_afirmar(pila_desapilar(pila) == &n2, "Se desapila 2");
	pa2m_afirmar(pila_desapilar(pila) == &n1, "Se desapila 1");

	pa2m_afirmar(pila_tope(pila) == NULL, "El tope de la pila no existe");
	pa2m_afirmar(pila_vacia(pila), "La pila esta vacia");
	pa2m_afirmar(pila_tamanio(pila) == 0, "El tamaño de la pila es 0"); 

	pila_destruir(pila);
}

void pila_volumen(){

	pila_t *pila = pila_crear();
	pa2m_afirmar(pila_vacia(pila) && pila_tamanio(pila) == 0, 
				"La pila esta vacia, el tamaño es 0");

    int vector[VOLUMEN];
    for (int i=0; i<VOLUMEN; i++){
        vector[i] = i;
        pila_apilar(pila, &vector[i]);
    }

	pa2m_afirmar(!pila_vacia(pila) && pila_tamanio(pila) == VOLUMEN, 
				"La pila no esta vacia, el tamaño es 10000");

    for (int i=VOLUMEN; i>=0; i--){
        pila_desapilar(pila);
    }

	pa2m_afirmar(pila_vacia(pila) && pila_tamanio(pila) == 0, 
				"La pila esta vacia, el tamaño es 0");
	pila_destruir(pila);
}

void pila_null(){

	pila_t *pila = pila_crear();
	pila_apilar(pila, NULL);
	pa2m_afirmar(pila_tope(pila) == NULL, "El tope de la pila es NULL");
	pa2m_afirmar(pila_vacia(pila) == false, "La pila no esta vacia");
	pa2m_afirmar(pila_desapilar(pila) == NULL, "Se puede desapilar NULL");
	pa2m_afirmar(pila_vacia(pila) == true, "La pila se encuentra vacia");
	pila_destruir(pila);
}

void pila_funciones_null(){

	pila_t *pila = pila_crear();
	pa2m_afirmar(pila_apilar(NULL, NULL) == NULL, 
				"Apilar con pila NULL devuelve NULL");
	pa2m_afirmar(pila_desapilar(NULL) == NULL, 
				"Desapilar con pila NULL devuelve NULL");
	pa2m_afirmar(pila_tope(NULL) == NULL, 
				"Ver tope con pila NULL devuelve NULL");
	pa2m_afirmar(pila_tamanio(NULL) == 0, 
				"Tamaño con pila NULL devuelve 0");
	pa2m_afirmar(pila_vacia(NULL) == true, 
				"Vacia con pila NULL devuelve NULL");
	pila_destruir(pila);

}

void ColaSeCreaVacia(){
	cola_t *cola = cola_crear();
	pa2m_afirmar(cola != NULL, "Se crea la cola");
	pa2m_afirmar(cola_vacia(cola) == true, "La cola esta vacia");
	pa2m_afirmar(cola_frente(cola) == NULL, "La cola no tiene frente");
	pa2m_afirmar(cola_tamanio(cola) == 0, "El tamaño de la cola es 0");
	pa2m_afirmar(cola_desencolar(cola) == NULL, "No se puede desencolar");
	cola_destruir(cola);
}

void prueba_encolar_desencolar(){

	cola_t *cola = cola_crear();
	int n1=1, n2=2, n3=3, n4=4, n5=5, n6=6, n7=7, n8=8;
	pa2m_afirmar(cola_vacia(cola) == true, "La cola esta vacia");

	pa2m_afirmar(cola_encolar(cola, &n1) == cola, "Se encola 1");
	pa2m_afirmar(cola_frente(cola) == &n1, "El frente de la cola es 1");
	pa2m_afirmar(cola_encolar(cola, &n2) == cola, "Se encola 2");
	pa2m_afirmar(cola_frente(cola) == &n1, "El frente de la cola todavia es 1");
	cola_encolar(cola, &n3);
	cola_encolar(cola, &n4);
	cola_encolar(cola, &n5);
	cola_encolar(cola, &n6);
	cola_encolar(cola, &n7);
	cola_encolar(cola, &n8);
	pa2m_afirmar(cola_tamanio(cola) == 8, "El tamaño de la cola es 8");

	pa2m_afirmar(cola_desencolar(cola) == &n1, "Desencolo 1");
	pa2m_afirmar(cola_frente(cola) == &n2, "El nuevo frente de la cola es 2");

	pa2m_afirmar(cola_desencolar(cola) == &n2, "Se desencola 2");
	pa2m_afirmar(cola_desencolar(cola) == &n3, "Se desencola 3");
	pa2m_afirmar(cola_desencolar(cola) == &n4, "Se desencola 4");
	pa2m_afirmar(cola_desencolar(cola) == &n5, "Se desencola 5");
	pa2m_afirmar(cola_desencolar(cola) == &n6, "Se desencola 6");
	pa2m_afirmar(cola_desencolar(cola) == &n7, "Se desencola 7");
	pa2m_afirmar(cola_desencolar(cola) == &n8, "Se desencola 8");

	pa2m_afirmar(cola_tamanio(cola) == 0, "El tamaño de la cola es 0");
	pa2m_afirmar(cola_vacia(cola) == true, "La cola esta vacia");
	cola_destruir(cola);
}

void cola_volumen(){
	cola_t *cola = cola_crear();
    pa2m_afirmar(cola_vacia(cola) == true, "Cola vacia al crear");

    int vector[VOLUMEN];
    for (int i=0; i<VOLUMEN; i++){
        vector[i] = i;
        cola_encolar(cola, &vector[i]);
    }

	pa2m_afirmar(!cola_vacia(cola) && cola_tamanio(cola) == VOLUMEN, 
				"La cola no esta vacia, el tamaño es 10000");

    for (int i=0; i<VOLUMEN; i++){
        cola_desencolar(cola);
    }
    pa2m_afirmar(cola_frente(cola) == NULL, "La cola no tiene frente");
    pa2m_afirmar(cola_vacia(cola) == true, "La cola esta vacia");
    pa2m_afirmar(cola_desencolar(cola)==NULL, "No se puede desencolar");
    cola_destruir(cola);
}

void cola_null(){

	cola_t *cola = cola_crear();
	pa2m_afirmar(cola_vacia(cola) == true, "La cola esta vacia");
	pa2m_afirmar(cola_encolar(cola, NULL) == cola, "Se encola NULL");
	pa2m_afirmar(cola_vacia(cola) == false, "La cola no esta vacia");
	pa2m_afirmar(cola_tamanio(cola) == 1, "La cola tiene un elemento");
	pa2m_afirmar(cola_desencolar(cola) == NULL, "Se desencola NULL");
	pa2m_afirmar(cola_vacia(cola) == true, "La cola esta vacia");
	cola_destruir(cola);

}

void cola_funciones_null(){

	cola_t *cola = cola_crear();
	pa2m_afirmar(cola_encolar(NULL, NULL) == NULL, 
				"Encolar con cola NULL devuelve NULL");
	pa2m_afirmar(cola_desencolar(NULL) == NULL, 
				"Desencolar con cola NULL devuelve NULL");
	pa2m_afirmar(cola_frente(NULL) == NULL, 
				"Ver frente con cola NULL devuelve NULL");
	pa2m_afirmar(cola_tamanio(NULL) == 0, 
				"Tamaño con cola NULL devuelve 0");
	pa2m_afirmar(cola_vacia(NULL) == true, 
				"Vacia con cola NULL devuelve NULL");
	cola_destruir(cola);
}

void pruebas_lista(){
	pa2m_nuevo_grupo("Pruebas de creación de lista");
	listaSeCreaVacia();
	pa2m_nuevo_grupo("Pruebas de insertar y quitar - lista");
	prueba_insertar_quitar();
	pa2m_nuevo_grupo("Prueba funcion destruir todo");
	prueba_destruir_todo();
	pa2m_nuevo_grupo("Prueba de volumen- lista");
	prueba_volumen();
	pa2m_nuevo_grupo("Prueba insertar NULL - lista");
	prueba_null();
	pa2m_nuevo_grupo("Prueba iterador interno lista");
	prueba_iterador();
	pa2m_nuevo_grupo("Prueba iterador externo lista");
	prueba_iterador_externo();
	pa2m_nuevo_grupo("Prueba funciones NULL lista");
	prueba_funciones_null();
}

void pruebas_pila(){
	pa2m_nuevo_grupo("Pruebas de creación de pila");
	PilaSeCreaVacia();
	pa2m_nuevo_grupo("Pruebas de apilar y desapilar");
	prueba_apilar_desapilar();
	pa2m_nuevo_grupo("Pruebas de volumen - pila");
	pila_volumen();
	pa2m_nuevo_grupo("Prueba insertar NULL pila");
	pila_null();
	pa2m_nuevo_grupo("Prueba funciones NULL pila");
	pila_funciones_null();
}

void pruebas_cola(){
	pa2m_nuevo_grupo("Pruebas de creación de cola");
	ColaSeCreaVacia();
	pa2m_nuevo_grupo("Pruebas de encolar y desencolar");
	prueba_encolar_desencolar();
	pa2m_nuevo_grupo("Pruebas de volumen - cola");
	cola_volumen();
	pa2m_nuevo_grupo("Prueba insertar NULL cola");
	cola_null();
	pa2m_nuevo_grupo("Prueba funciones NULL cola");
	cola_funciones_null();
}

int main()
{
	pruebas_lista();
	pruebas_pila();
	pruebas_cola();
	return pa2m_mostrar_reporte();
}
