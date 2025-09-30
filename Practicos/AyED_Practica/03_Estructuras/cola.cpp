//
// Created by facuh on 9/27/25.
//
#include <iostream>
using namespace std;

// ===== UNIDAD 3.4: COLAS (QUEUE) - FIFO =====
// First In, First Out - El primero que entra es el primero que sale

struct NodoCola {
    int dato;
    NodoCola* siguiente;

    NodoCola(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

class Cola {
private:
    NodoCola* frente;  // Puntero al primer elemento (para dequeue)
    NodoCola* final;   // Puntero al último elemento (para enqueue)
    int tamaño;

public:
    // Constructor
    Cola() {
        frente = nullptr;
        final = nullptr;
        tamaño = 0;
    }

    // Destructor
    ~Cola() {
        while (!estaVacia()) {
            dequeue();
        }
    }

    // ENQUEUE - Insertar elemento al final O(1)
    void enqueue(int valor) {
        NodoCola* nuevo = new NodoCola(valor);

        if (estaVacia()) {
            frente = final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        tamaño++;
        cout << "Enqueue: " << valor << " agregado al final" << endl;
    }

    // DEQUEUE - Quitar elemento del frente O(1)
    int dequeue() {
        if (estaVacia()) {
            cout << "❌ Error: Cola vacía (queue underflow)" << endl;
            return -1;
        }

        int valor = frente->dato;
        NodoCola* temp = frente;
        frente = frente->siguiente;

        // Si era el único elemento
        if (frente == nullptr) {
            final = nullptr;
        }

        delete temp;
        tamaño--;
        cout << "Dequeue: " << valor << " removido del frente" << endl;
        return valor;
    }

    // FRONT - Ver elemento del frente sin quitarlo O(1)
    int front() {
        if (estaVacia()) {
            cout << "❌ Error: Cola vacía" << endl;
            return -1;
        }
        return frente->dato;
    }

    // REAR - Ver elemento del final sin quitarlo O(1)
    int rear() {
        if (estaVacia()) {
            cout << "❌ Error: Cola vacía" << endl;
            return -1;
        }
        return final->dato;
    }

    // Verificar si está vacía
    bool estaVacia() {
        return frente == nullptr;
    }

    // Obtener tamaño
    int obtenerTamaño() {
        return tamaño;
    }

    // Mostrar cola completa (desde frente hacia final)
    void mostrar() {
        if (estaVacia()) {
            cout << "Cola vacía: []" << endl;
            return;
        }

        cout << "Cola (frente -> final): [";
        NodoCola* actual = frente;
        while (actual != nullptr) {
            cout << actual->dato;
            if (actual->siguiente != nullptr) {
                cout << " <- ";
            }
            actual = actual->siguiente;
        }
        cout << "] (tamaño: " << tamaño << ")" << endl;
    }
};

// EJERCICIO TÍPICO: Simulación de banco (atención al cliente)
void simulacionBanco() {
    cout << "\n=== SIMULACIÓN DE BANCO ===" << endl;

    Cola colaBanco;

    cout << "\nLlegada de clientes:" << endl;
    colaBanco.enqueue(101);  // Cliente 101
    colaBanco.enqueue(102);  // Cliente 102
    colaBanco.enqueue(103);  // Cliente 103
    colaBanco.mostrar();

    cout << "\nAtendiendo clientes (FIFO):" << endl;
    cout << "Atendiendo cliente: " << colaBanco.dequeue() << endl;
    colaBanco.mostrar();

    cout << "\nLlegan más clientes:" << endl;
    colaBanco.enqueue(104);
    colaBanco.enqueue(105);
    colaBanco.mostrar();

    cout << "\nSiguiendo la atención:" << endl;
    while (!colaBanco.estaVacia()) {
        cout << "Atendiendo cliente: " << colaBanco.dequeue() << endl;
        colaBanco.mostrar();
    }
}

// EJERCICIO TÍPICO: Procesamiento por lotes (batch processing)
void procesamientoPorLotes() {
    cout << "\n=== PROCESAMIENTO POR LOTES ===" << endl;

    Cola colaTrabajos;

    // Agregar trabajos a la cola
    cout << "\nAgregar trabajos:" << endl;
    string trabajos[] = {"Backup", "Reporte", "Cálculos", "Email", "Limpieza"};

    for (int i = 0; i < 5; i++) {
        colaTrabajos.enqueue(i + 1);
        cout << "Trabajo agregado: " << trabajos[i] << " (ID: " << (i + 1) << ")" << endl;
    }

    colaTrabajos.mostrar();

    // Procesar trabajos en orden
    cout << "\nProcesando trabajos en orden FIFO:" << endl;
    while (!colaTrabajos.estaVacia()) {
        int id = colaTrabajos.dequeue();
        cout << "Procesando: " << trabajos[id - 1] << " (ID: " << id << ")" << endl;
        colaTrabajos.mostrar();
    }
}

// Implementación con arreglo circular (alternativa común)
class ColaArreglo {
private:
    static const int MAXSIZE = 5;
    int elementos[MAXSIZE];
    int frente, final;
    int contador;  // Para distinguir vacía de llena

public:
    ColaArreglo() {
        frente = 0;
        final = -1;
        contador = 0;
    }

    bool enqueue(int valor) {
        if (contador >= MAXSIZE) {
            cout << "❌ Cola llena" << endl;
            return false;
        }

        final = (final + 1) % MAXSIZE;  // Circular
        elementos[final] = valor;
        contador++;
        cout << "Enqueue (arreglo): " << valor << endl;
        return true;
    }

    int dequeue() {
        if (contador == 0) {
            cout << "❌ Cola vacía" << endl;
            return -1;
        }

        int valor = elementos[frente];
        frente = (frente + 1) % MAXSIZE;  // Circular
        contador--;
        cout << "Dequeue (arreglo): " << valor << endl;
        return valor;
    }

    int front() {
        if (contador == 0) return -1;
        return elementos[frente];
    }

    bool estaVacia() {
        return contador == 0;
    }

    bool estaLlena() {
        return contador == MAXSIZE;
    }

    void mostrar() {
        if (contador == 0) {
            cout << "Cola vacía (arreglo): []" << endl;
            return;
        }

        cout << "Cola (arreglo): [";
        for (int i = 0; i < contador; i++) {
            int indice = (frente + i) % MAXSIZE;
            cout << elementos[indice];
            if (i < contador - 1) cout << " <- ";
        }
        cout << "] (" << contador << "/" << MAXSIZE << ")" << endl;
    }
};

// EJERCICIO TÍPICO: BFS (Breadth-First Search) básico
void ejemploBFS() {
    cout << "\n=== EJEMPLO DE BFS CON COLA ===" << endl;

    // Simular un grafo simple: A conectado con B,C y B conectado con D
    Cola colaBFS;

    cout << "\nRecorrido BFS comenzando desde nodo A:" << endl;
    colaBFS.enqueue(1);  // A = 1
    cout << "Visitando nodo A(1)" << endl;

    while (!colaBFS.estaVacia()) {
        int nodo = colaBFS.dequeue();

        // Simular vecinos
        if (nodo == 1) {  // Nodo A
            cout << "Agregando vecinos de A: B(2), C(3)" << endl;
            colaBFS.enqueue(2);  // B
            colaBFS.enqueue(3);  // C
        } else if (nodo == 2) {  // Nodo B
            cout << "Visitando nodo B(2)" << endl;
            cout << "Agregando vecino de B: D(4)" << endl;
            colaBFS.enqueue(4);  // D
        } else if (nodo == 3) {  // Nodo C
            cout << "Visitando nodo C(3)" << endl;
        } else if (nodo == 4) {  // Nodo D
            cout << "Visitando nodo D(4)" << endl;
        }

        if (!colaBFS.estaVacia()) {
            colaBFS.mostrar();
        }
    }

    cout << "BFS completado" << endl;
}

void ejerciciosBasicos() {
    cout << "\n=== EJERCICIOS BÁSICOS DE COLA ===" << endl;

    Cola cola;

    cout << "\n1. Operaciones básicas:" << endl;
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);
    cola.mostrar();

    cout << "\nFrente: " << cola.front() << endl;
    cout << "Final: " << cola.rear() << endl;

    cout << "\n2. Hacer dequeue:" << endl;
    cola.dequeue();
    cola.mostrar();

    cout << "\n3. Más operaciones:" << endl;
    cola.enqueue(40);
    cola.enqueue(50);
    cola.mostrar();

    cout << "¿Está vacía? " << (cola.estaVacia() ? "Sí" : "No") << endl;
    cout << "Tamaño: " << cola.obtenerTamaño() << endl;
}

void ejemploColaArreglo() {
    cout << "\n=== COLA CON ARREGLO CIRCULAR ===" << endl;

    ColaArreglo cola;

    // Llenar la cola
    for (int i = 1; i <= 5; i++) {
        cola.enqueue(i * 10);
        cola.mostrar();
    }

    // Intentar agregar uno más (debería fallar)
    cola.enqueue(60);

    // Quitar algunos
    cola.dequeue();
    cola.dequeue();
    cola.mostrar();

    // Agregar más (demostrar comportamiento circular)
    cola.enqueue(70);
    cola.enqueue(80);
    cola.mostrar();
}

int main() {
    cout << "🎯 COLAS (QUEUE) - CONCEPTOS DE EXAMEN" << endl;
    cout << "=====================================" << endl;

    ejerciciosBasicos();
    simulacionBanco();
    procesamientoPorLotes();
    ejemploBFS();
    ejemploColaArreglo();

    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • FIFO: First In, First Out" << endl;
    cout << "   • Operaciones básicas: enqueue(), dequeue(), front()" << endl;
    cout << "   • enqueue() al final, dequeue() del frente" << endl;
    cout << "   • Dos punteros: frente y final" << endl;
    cout << "   • Aplicaciones: BFS, simulaciones, buffers" << endl;
    cout << "   • Implementación: lista enlazada o arreglo circular" << endl;
    cout << "   • O(1) para todas las operaciones básicas" << endl;

    return 0;
}