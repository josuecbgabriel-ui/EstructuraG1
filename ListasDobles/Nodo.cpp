#include <iostream>
using namespace std;

// ============================================================
//  LISTA DOBLEMENTE ENLAZADA (sin struct, usando class)
//  Operaciones: 1 Insertar, 2 Eliminar, 3 Buscar, 4 Imprimir
// ============================================================

class Nodo {
public:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int d) {
        dato = d;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

class ListaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDoble() {
        cabeza = nullptr;
        cola = nullptr;
    }

    // Libera toda la memoria al terminar el programa
    ~ListaDoble() {
        Nodo* aux = cabeza;
        while (aux != nullptr) {
            Nodo* temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    // ---------------- 1. INSERTAR ----------------
    void insertarInicio(int d) {
        Nodo* nuevo = new Nodo(d);
        if (estaVacia()) {
            cabeza = cola = nuevo;
        } else {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;
        }
        cout << "Dato " << d << " insertado al inicio." << endl;
    }

    void insertarFinal(int d) {
        Nodo* nuevo = new Nodo(d);
        if (estaVacia()) {
            cabeza = cola = nuevo;
        } else {
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cola = nuevo;
        }
        cout << "Dato " << d << " insertado al final." << endl;
    }

    // ---------------- 2. ELIMINAR ----------------
    bool eliminar(int d) {
        if (estaVacia()) {
            cout << "La lista esta vacia." << endl;
            return false;
        }

        // Buscar el nodo a eliminar
        Nodo* aux = cabeza;
        while (aux != nullptr && aux->dato != d) {
            aux = aux->siguiente;
        }

        if (aux == nullptr) {
            cout << "El dato " << d << " no existe en la lista." << endl;
            return false;
        }

        if (aux == cabeza) {                 // es el primero
            cabeza = cabeza->siguiente;
            if (cabeza != nullptr)
                cabeza->anterior = nullptr;
            else
                cola = nullptr;              // la lista quedo vacia
        }
        else if (aux == cola) {              // es el ultimo
            cola = cola->anterior;
            cola->siguiente = nullptr;
        }
        else {                               // esta en medio
            aux->anterior->siguiente = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;
        }

        delete aux;
        cout << "Dato " << d << " eliminado." << endl;
        return true;
    }

    // ---------------- 3. BUSCAR ----------------
    // Devuelve la posicion (empezando en 1) o -1 si no existe
    int buscar(int d) {
        Nodo* aux = cabeza;
        int pos = 1;
        while (aux != nullptr) {
            if (aux->dato == d) {
                return pos;
            }
            aux = aux->siguiente;
            pos++;
        }
        return -1;
    }

    // ---------------- 4. IMPRIMIR ----------------
    void imprimirAdelante() {
        if (estaVacia()) {
            cout << "Lista vacia." << endl;
            return;
        }
        cout << "Adelante: NULL <-> ";
        Nodo* aux = cabeza;
        while (aux != nullptr) {
            cout << aux->dato << " <-> ";
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }

    void imprimirAtras() {
        if (estaVacia()) {
            cout << "Lista vacia." << endl;
            return;
        }
        cout << "Atras:    NULL <-> ";
        Nodo* aux = cola;
        while (aux != nullptr) {
            cout << aux->dato << " <-> ";
            aux = aux->anterior;
        }
        cout << "NULL" << endl;
    }
};
