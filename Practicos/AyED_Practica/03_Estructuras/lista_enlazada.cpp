//
// Created by facuh on 9/27/25.
//
#include <iostream>
using namespace std;

// ===== UNIDAD 3.2: LISTAS SIMPLEMENTE ENLAZADAS =====

// Estructura del nodo - ESTO SIEMPRE APARECE EN EXÁMENES
struct Nodo {
    int dato;           // El valor que almacena
    Nodo* siguiente;    // Puntero al siguiente nodo

    // Constructor para crear nodos fácilmente
    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

class ListaEnlazada {
private:
    Nodo* cabeza;  // Puntero al primer nodo
    int tamaño;    // Cantidad de elementos

public:
    // Constructor
    ListaEnlazada() {
        cabeza = nullptr;
        tamaño = 0;
    }

    // Destructor - IMPORTANTE para liberar memoria
    ~ListaEnlazada() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    // INSERTAR AL INICIO - O(1)
    void insertarAlInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        tamaño++;
        cout << "Insertado " << valor << " al inicio" << endl;
    }

    // INSERTAR AL FINAL - O(n)
    void insertarAlFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);

        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            Nodo* actual = cabeza;
            // Ir hasta el último nodo
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        tamaño++;
        cout << "Insertado " << valor << " al final" << endl;
    }

    // INSERTAR EN POSICIÓN ESPECÍFICA
    void insertarEnPosicion(int valor, int posicion) {
        if (posicion < 0 || posicion > tamaño) {
            cout << "❌ Posición inválida" << endl;
            return;
        }

        if (posicion == 0) {
            insertarAlInicio(valor);
            return;
        }

        Nodo* nuevo = new Nodo(valor);
        Nodo* actual = cabeza;

        // Ir hasta la posición anterior a donde insertamos
        for (int i = 0; i < posicion - 1; i++) {
            actual = actual->siguiente;
        }

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        tamaño++;
        cout << "Insertado " << valor << " en posición " << posicion << endl;
    }

    // ELIMINAR POR VALOR - EJERCICIO TÍPICO DE EXAMEN
    bool eliminar(int valor) {
        if (cabeza == nullptr) {
            cout << "❌ Lista vacía" << endl;
            return false;
        }

        // Si es el primer elemento
        if (cabeza->dato == valor) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            tamaño--;
            cout << "Eliminado " << valor << " de la lista" << endl;
            return true;
        }

        // Buscar en el resto de la lista
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            if (actual->siguiente->dato == valor) {
                Nodo* temp = actual->siguiente;
                actual->siguiente = temp->siguiente;
                delete temp;
                tamaño--;
                cout << "Eliminado " << valor << " de la lista" << endl;
                return true;
            }
            actual = actual->siguiente;
        }

        cout << "❌ Valor " << valor << " no encontrado" << endl;
        return false;
    }

    // BUSCAR ELEMENTO - O(n)
    bool buscar(int valor) {
        Nodo* actual = cabeza;
        int posicion = 0;

        while (actual != nullptr) {
            if (actual->dato == valor) {
                cout << "✅ Encontrado " << valor << " en posición " << posicion << endl;
                return true;
            }
            actual = actual->siguiente;
            posicion++;
        }

        cout << "❌ Valor " << valor << " no encontrado" << endl;
        return false;
    }

    // MOSTRAR LISTA COMPLETA
    void mostrar() {
        if (cabeza == nullptr) {
            cout << "Lista vacía: []" << endl;
            return;
        }

        cout << "Lista: [";
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->dato;
            if (actual->siguiente != nullptr) {
                cout << " -> ";
            }
            actual = actual->siguiente;
        }
        cout << "] (tamaño: " << tamaño << ")" << endl;
    }

    // OBTENER TAMAÑO
    int obtenerTamaño() {
        return tamaño;
    }

    // VERIFICAR SI ESTÁ VACÍA
    bool estaVacia() {
        return cabeza == nullptr;
    }

    // OBTENER PRIMER ELEMENTO
    int obtenerPrimero() {
        if (cabeza == nullptr) {
            cout << "❌ Lista vacía" << endl;
            return -1;  // Valor de error
        }
        return cabeza->dato;
    }

    // LIMPIAR TODA LA LISTA
    void limpiar() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
        tamaño = 0;
        cout << "Lista limpiada" << endl;
    }
};

// EJERCICIOS TÍPICOS DE EXAMEN
void ejerciciosBasicos() {
    cout << "\n=== EJERCICIOS BÁSICOS DE LISTA ENLAZADA ===" << endl;

    ListaEnlazada lista;

    cout << "\n1. Insertar elementos:" << endl;
    lista.insertarAlInicio(10);
    lista.insertarAlInicio(20);
    lista.insertarAlFinal(30);
    lista.insertarAlFinal(40);
    lista.mostrar();

    cout << "\n2. Insertar en posición específica:" << endl;
    lista.insertarEnPosicion(25, 2);
    lista.mostrar();

    cout << "\n3. Buscar elementos:" << endl;
    lista.buscar(25);
    lista.buscar(100);

    cout << "\n4. Eliminar elementos:" << endl;
    lista.eliminar(20);
    lista.mostrar();
    lista.eliminar(40);
    lista.mostrar();

    cout << "\n5. Estado de la lista:" << endl;
    cout << "Tamaño: " << lista.obtenerTamaño() << endl;
    cout << "¿Está vacía? " << (lista.estaVacia() ? "Sí" : "No") << endl;
    cout << "Primer elemento: " << lista.obtenerPrimero() << endl;
}

// EJERCICIO TÍPICO: Contar elementos
int contarElementos(Nodo* cabeza) {
    int contador = 0;
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

// EJERCICIO TÍPICO: Encontrar máximo
int encontrarMaximo(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "❌ Lista vacía" << endl;
        return -1;
    }

    int maximo = cabeza->dato;
    Nodo* actual = cabeza->siguiente;

    while (actual != nullptr) {
        if (actual->dato > maximo) {
            maximo = actual->dato;
        }
        actual = actual->siguiente;
    }

    return maximo;
}

// EJERCICIO TÍPICO: Invertir lista
Nodo* invertirLista(Nodo* cabeza) {
    Nodo* anterior = nullptr;
    Nodo* actual = cabeza;
    Nodo* siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->siguiente;  // Guardar referencia
        actual->siguiente = anterior;   // Invertir el enlace
        anterior = actual;              // Mover anterior
        actual = siguiente;             // Mover actual
    }

    return anterior;  // Nueva cabeza
}

void ejerciciosAvanzados() {
    cout << "\n=== EJERCICIOS AVANZADOS ===" << endl;

    // Crear lista manualmente para ejercicios
    Nodo* cabeza = new Nodo(5);
    cabeza->siguiente = new Nodo(15);
    cabeza->siguiente->siguiente = new Nodo(8);
    cabeza->siguiente->siguiente->siguiente = new Nodo(22);

    // Mostrar lista original
    cout << "\nLista original: ";
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "nullptr" << endl;

    cout << "Elementos: " << contarElementos(cabeza) << endl;
    cout << "Máximo: " << encontrarMaximo(cabeza) << endl;

    cout << "\nInvirtiendo lista..." << endl;
    cabeza = invertirLista(cabeza);

    cout << "Lista invertida: ";
    temp = cabeza;
    while (temp != nullptr) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "nullptr" << endl;

    // Liberar memoria
    while (cabeza != nullptr) {
        Nodo* aEliminar = cabeza;
        cabeza = cabeza->siguiente;
        delete aEliminar;
    }
}

int main() {
    cout << "🎯 LISTAS SIMPLEMENTE ENLAZADAS - EXAMEN" << endl;
    cout << "========================================" << endl;

    ejerciciosBasicos();
    ejerciciosAvanzados();

    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • struct Nodo { int dato; Nodo* siguiente; }" << endl;
    cout << "   • Insertar: al inicio O(1), al final O(n)" << endl;
    cout << "   • Eliminar: buscar + reorganizar enlaces" << endl;
    cout << "   • Recorrer: while (actual != nullptr)" << endl;
    cout << "   • SIEMPRE liberar memoria con delete" << endl;
    cout << "   • Manejar casos: lista vacía, un elemento" << endl;
    cout << "   • Operaciones típicas: buscar, contar, máximo" << endl;

    return 0;
}