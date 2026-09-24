#include <iostream>
#include <string>

using namespace std;

struct Nodo {
	int dato;
	Nodo* izquierda;
	Nodo* derecha;
};

Nodo* EncontrarNodoParaReemplazar(Nodo* nodoAEliminar) //|||SOLO USAR SI EL NodoAEliminar TIENE HIJOS|||
{
	Nodo* nodoBusqueda = NULL;
	if (nodoAEliminar -> derecha != NULL) {

		nodoBusqueda = nodoAEliminar -> derecha;

		while (nodoBusqueda->izquierda != NULL)
		{
			nodoBusqueda = nodoBusqueda -> izquierda;
		}
	}
	else if (nodoAEliminar -> izquierda != NULL) {

		nodoBusqueda = nodoAEliminar -> izquierda;

		while (nodoBusqueda->derecha != NULL)
		{
			nodoBusqueda = nodoBusqueda -> derecha;
		}
	}
		return nodoBusqueda;
}

int main()
{
  return 0;
}
