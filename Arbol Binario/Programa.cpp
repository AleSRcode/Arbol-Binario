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

Nodo* EliminarNodoConUnHijosinHijos(Nodo* nodoAEliminar, Nodo* nodoPadre) //|||Elimina nodos con un hijo o sin hijos|||
{
	Nodo* nodoReemplazo = EncontrarNodoParaReemplazar(nodoAEliminar);	//Usamos la funcion para encontrar el nodo que reemplazara al nodo a eliminar

	if (nodoPadre->izquierda == nodoAEliminar) {		//Si el nodo a eliminar es hijo izquierdo del padre, reemplazamos el hijo izquierdo del padre con el nodo de reemplazo
		nodoPadre->izquierda = nodoReemplazo;
	}
	else if (nodoPadre->derecha == nodoAEliminar) {		//Si el nodo a eliminar es hijo derecho del padre, reemplazamos el hijo derecho del padre con el nodo de reemplazo
		nodoPadre->derecha = nodoReemplazo;
	}

	if (nodoReemplazo->izquierda != NULL) {				//Si el nodo de reemplazo tiene un hijo izquierdo, lo asignamos al hijo izquierdo del nodo a eliminar
		nodoReemplazo->izquierda = nodoAEliminar->izquierda;
	}
	if (nodoReemplazo->derecha != NULL) {				//Si el nodo de reemplazo tiene un hijo derecho, lo asignamos al hijo derecho del nodo a eliminar
		nodoReemplazo->derecha = nodoAEliminar->derecha;
	}

	delete nodoAEliminar;

	return nodoReemplazo;
}

int main()
{
  return 0;
}
