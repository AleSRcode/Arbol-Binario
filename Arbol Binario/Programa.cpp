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

Nodo* EliminarNodoConUnHijosinHijos(Nodo* nodoAEliminar, Nodo* nodoPadre, Nodo*& raiz) 
//|||Elimina nodos con UN HIJO o SIN HIJOS|||
{
	// Verificar que el nodo tiene UN SOLO hijo o NINGUNO
	bool tieneHijoIzquierdo = (nodoAEliminar->izquierda != NULL);
	bool tieneHijoDerecho = (nodoAEliminar->derecha != NULL);
	
	// Si tiene DOS hijos, NO usamos este método
	if (tieneHijoIzquierdo && tieneHijoDerecho) {
		cout << "Error: Este nodo tiene dos hijos" << endl;
		return raiz;
	}
	
	// El nodo reemplazo es el hijo que tenga (o NULL si no tiene)
	Nodo* nodoReemplazo = NULL;
	
	if (tieneHijoIzquierdo) {
		nodoReemplazo = nodoAEliminar->izquierda;
	}
	else if (tieneHijoDerecho) {
		nodoReemplazo = nodoAEliminar->derecha;
	}
	
	// CASO 1: Si el nodo a eliminar es la raiz
	if (nodoAEliminar == raiz) {
		raiz = nodoReemplazo; // El reemplazo (o NULL) es la nueva raiz
	}
	// CASO 2: Si el nodo a eliminar NO es la raiz
	else {
		if (nodoPadre->izquierda == nodoAEliminar) {
			nodoPadre->izquierda = nodoReemplazo;
		}
		else if (nodoPadre->derecha == nodoAEliminar) {
			nodoPadre->derecha = nodoReemplazo;
		}
	}
	
	delete nodoAEliminar;
	return raiz;
}

int main()
{
  return 0;
}