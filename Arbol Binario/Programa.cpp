#include <iostream>
#include <string>

using namespace std;

struct Nodo {
	int dato;
	Nodo* izquierda;
	Nodo* derecha;
};

Nodo* Insertar(Nodo* raiz, int valor)
{
	if (raiz == NULL) { //Si el arbol (o subarbol) esta vacio, aqui va el nuevo nodo
		Nodo* nuevoNodo = new Nodo;
		nuevoNodo->dato = valor;
		nuevoNodo->izquierda = NULL;
		nuevoNodo->derecha = NULL;
		return nuevoNodo;
	}
	if (valor > raiz->dato) { //Si el valor es mayor que el nodo actual, va al subarbol derecho
		raiz->derecha = Insertar(raiz->derecha, valor);
	}
	else if (valor < raiz->dato) { //Si el valor es menor que el nodo actual, va al subarbol izquierdo
		raiz->izquierda = Insertar(raiz->izquierda, valor);
	}
	//Si el valor es igual, ya existe y no se inserta
	return raiz;
}

Nodo* EncontrarNodoParaReemplazar(Nodo* nodoAEliminar) //|||SOLO USAR SI EL NodoAEliminar TIENE HIJOS|||
{
	Nodo* nodoBusqueda = NULL;
	if (nodoAEliminar->derecha != NULL) {
		nodoBusqueda = nodoAEliminar->derecha;
		while (nodoBusqueda->izquierda != NULL)
		{
			nodoBusqueda = nodoBusqueda->izquierda;
		}
	}
	else if (nodoAEliminar->izquierda != NULL) {
		nodoBusqueda = nodoAEliminar->izquierda;
		while (nodoBusqueda->derecha != NULL)
		{
			nodoBusqueda = nodoBusqueda->derecha;
		}
	}
	return nodoBusqueda;
}
Nodo* EliminarNodoConUnHijosinHijos(Nodo* nodoAEliminar, Nodo* nodoPadre) //|||Elimina nodos con un hijo o sin hijos|||
{
	Nodo* nodoReemplazo = EncontrarNodoParaReemplazar(nodoAEliminar); //Usamos la funcion para encontrar el nodo que reemplazara al nodo a eliminar
	if (nodoPadre->izquierda == nodoAEliminar) { //Si el nodo a eliminar es hijo izquierdo del padre, reemplazamos el hijo izquierdo del padre con el nodo de reemplazo
		nodoPadre->izquierda = nodoReemplazo;
	}
	else if (nodoPadre->derecha == nodoAEliminar) { //Si el nodo a eliminar es hijo derecho del padre, reemplazamos el hijo derecho del padre con el nodo de reemplazo
		nodoPadre->derecha = nodoReemplazo;
	}
	if (nodoReemplazo->izquierda != NULL) { //Si el nodo de reemplazo tiene un hijo izquierdo, lo asignamos al hijo izquierdo del nodo a eliminar
		nodoReemplazo->izquierda = nodoAEliminar->izquierda;
	}
	if (nodoReemplazo->derecha != NULL) { //Si el nodo de reemplazo tiene un hijo derecho, lo asignamos al hijo derecho del nodo a eliminar
		nodoReemplazo->derecha = nodoAEliminar->derecha;
	}
	delete nodoAEliminar;
	return nodoReemplazo;
}

int main()
{
  return 0;
}
