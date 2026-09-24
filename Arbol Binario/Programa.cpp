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


void ElimNodoCon1o0Hijos(Nodo* nodoAEliminar, Nodo* nodoPadre, Nodo*& raiz) 
//|||Elimina nodos con UN HIJO o SIN HIJOS|||
{
	// Verificar que el nodo tiene UN SOLO hijo o NINGUNO
	bool tieneHijoIzquierdo = (nodoAEliminar->izquierda != NULL);
	bool tieneHijoDerecho = (nodoAEliminar->derecha != NULL);
	
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
}

void ElimNodoCon2Hijos(Nodo* nodoAEliminar, Nodo*& raiz) //|||SOLO USAR SI EL NodoAEliminar TIENE HIJOS|||
{
	Nodo* nodoPadreReemplazo = nodoAEliminar;
	Nodo* nodoReemplazo = nodoAEliminar->derecha;
	if (nodoReemplazo->izquierda != NULL) {
		while (nodoReemplazo->izquierda != NULL)
		{
			nodoPadreReemplazo = nodoReemplazo;
			nodoReemplazo = nodoReemplazo->izquierda;
		}
	}
	else {
		nodoReemplazo = nodoAEliminar->izquierda;
		while (nodoReemplazo->derecha != NULL)
		{
			nodoPadreReemplazo = nodoReemplazo;
			nodoReemplazo = nodoReemplazo->derecha;
		}
	}
	nodoAEliminar->dato = nodoReemplazo->dato;

	ElimNodoCon1o0Hijos(nodoReemplazo, nodoPadreReemplazo, raiz);
}

void Eliminar(Nodo*& nodoRaiz, int datoNodoEliminar)
{
	Nodo* nodoActual = nodoRaiz;
	Nodo* nodoPadre = NULL;

	while (nodoActual != NULL && nodoActual->dato != datoNodoEliminar)
	{
		nodoPadre = nodoActual;
		if (nodoActual->dato > datoNodoEliminar) {
			nodoActual = nodoActual->izquierda;
		}
		else {
			nodoActual = nodoActual->derecha;
		}
	}

	if (nodoActual == NULL) {
		cout << "El nodo de valor " << datoNodoEliminar << " no existe\n"; 
		return;
	}
	if (nodoActual->izquierda != NULL && nodoActual->derecha != NULL)
	{
		ElimNodoCon2Hijos(nodoActual, nodoRaiz);
	}
	else
	{
		ElimNodoCon1o0Hijos(nodoActual, nodoPadre, nodoRaiz);
	}
}

int main()
{
  return 0;
}