#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// ===== ÁRBOL BINARIO - LO ESENCIAL =====

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    
    Nodo(int v) : dato(v), izq(nullptr), der(nullptr) {}
};

class ArbolBinario {
private:
    Nodo* raiz;
    
public:
    ArbolBinario() : raiz(nullptr) {}
    
    // ===== INSERCIÓN =====
    void insertar(int valor) {
        raiz = insertarRec(raiz, valor);
    }
    
private:
    Nodo* insertarRec(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return new Nodo(valor);
        }
        if (valor < nodo->dato) {
            nodo->izq = insertarRec(nodo->izq, valor);
        } else if (valor > nodo->dato) {
            nodo->der = insertarRec(nodo->der, valor);
        }
        return nodo;
    }
    
    // ===== ALTURA =====
public:
    int altura() {
        return alturaRec(raiz);
    }
    
private:
    int alturaRec(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + max(alturaRec(nodo->izq), alturaRec(nodo->der));
    }
    
    // ===== RECORRIDOS =====
public:
    // IN-ORDER: Izq - Raíz - Der (BST ordenado)
    void inOrder() {
        cout << "In-Order: ";
        inOrderRec(raiz);
        cout << endl;
    }
    
private:
    void inOrderRec(Nodo* nodo) {
        if (nodo != nullptr) {
            inOrderRec(nodo->izq);
            cout << nodo->dato << " ";
            inOrderRec(nodo->der);
        }
    }
    
    // PRE-ORDER: Raíz - Izq - Der
public:
    void preOrder() {
        cout << "Pre-Order: ";
        preOrderRec(raiz);
        cout << endl;
    }
    
private:
    void preOrderRec(Nodo* nodo) {
        if (nodo != nullptr) {
            cout << nodo->dato << " ";
            preOrderRec(nodo->izq);
            preOrderRec(nodo->der);
        }
    }
    
    // POST-ORDER: Izq - Der - Raíz
public:
    void postOrder() {
        cout << "Post-Order: ";
        postOrderRec(raiz);
        cout << endl;
    }
    
private:
    void postOrderRec(Nodo* nodo) {
        if (nodo != nullptr) {
            postOrderRec(nodo->izq);
            postOrderRec(nodo->der);
            cout << nodo->dato << " ";
        }
    }
    
    // LEVEL-ORDER: Por niveles (BFS con cola)
public:
    void levelOrder() {
        if (raiz == nullptr) {
            cout << "Árbol vacío" << endl;
            return;
        }
        
        cout << "Level-Order: ";
        queue<Nodo*> q;
        q.push(raiz);
        
        while (!q.empty()) {
            Nodo* actual = q.front();
            q.pop();
            
            cout << actual->dato << " ";
            
            if (actual->izq) q.push(actual->izq);
            if (actual->der) q.push(actual->der);
        }
        cout << endl;
    }
    
    // ===== BÚSQUEDA =====
public:
    bool buscar(int valor) {
        return buscarRec(raiz, valor);
    }
    
private:
    bool buscarRec(Nodo* nodo, int valor) {
        if (nodo == nullptr) return false;
        if (nodo->dato == valor) return true;
        if (valor < nodo->dato) return buscarRec(nodo->izq, valor);
        return buscarRec(nodo->der, valor);
    }
    
    // ===== BALANCEADO =====
public:
    bool esBalanceado() {
        return esBalanceadoRec(raiz) != -1;
    }
    
private:
    int esBalanceadoRec(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        
        int alturaIzq = esBalanceadoRec(nodo->izq);
        if (alturaIzq == -1) return -1;
        
        int alturaDer = esBalanceadoRec(nodo->der);
        if (alturaDer == -1) return -1;
        
        if (abs(alturaIzq - alturaDer) > 1) return -1;
        
        return 1 + max(alturaIzq, alturaDer);
    }
    
    // ===== MÁXIMO Y MÍNIMO =====
public:
    int minimo() {
        Nodo* actual = raiz;
        while (actual && actual->izq) {
            actual = actual->izq;
        }
        return actual ? actual->dato : -1;
    }
    
    int maximo() {
        Nodo* actual = raiz;
        while (actual && actual->der) {
            actual = actual->der;
        }
        return actual ? actual->dato : -1;
    }
    
    // ===== VISUALIZACIÓN =====
public:
    void visualizar() {
        cout << "\n🌳 ÁRBOL:" << endl;
        visualizarRec(raiz, "", false);
    }
    
private:
    void visualizarRec(Nodo* nodo, string prefijo, bool esIzquierdo) {
        if (nodo == nullptr) return;
        
        cout << prefijo;
        cout << (esIzquierdo ? "├──" : "└──") << nodo->dato << endl;
        
        if (nodo->izq || nodo->der) {
            if (nodo->izq) {
                visualizarRec(nodo->izq, prefijo + (esIzquierdo ? "│   " : "    "), true);
            }
            if (nodo->der) {
                visualizarRec(nodo->der, prefijo + (esIzquierdo ? "│   " : "    "), false);
            }
        }
    }
};

// ===== MAIN - EJEMPLOS TIPO EXAMEN =====

int main() {
    cout << "╔════════════════════════════════════════════════════╗" << endl;
    cout << "║   ÁRBOLES BINARIOS - LO ESENCIAL PARA EXAMEN      ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
    
    // ===== EJERCICIO 1: OPERACIONES BÁSICAS =====
    cout << "\n🎯 EJERCICIO 1: Operaciones Básicas" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    ArbolBinario arbol1;
    cout << "Insertando: 50, 30, 70, 20, 40, 60, 80" << endl;
    arbol1.insertar(50);
    arbol1.insertar(30);
    arbol1.insertar(70);
    arbol1.insertar(20);
    arbol1.insertar(40);
    arbol1.insertar(60);
    arbol1.insertar(80);
    
    arbol1.visualizar();
    
    cout << "\nRecorridos:" << endl;
    arbol1.inOrder();     // 20 30 40 50 60 70 80 (ordenado)
    arbol1.preOrder();    // 50 30 20 40 70 60 80
    arbol1.postOrder();   // 20 40 30 60 80 70 50
    arbol1.levelOrder();  // 50 30 70 20 40 60 80
    
    cout << "\nInfo del árbol:" << endl;
    cout << "  Altura: " << arbol1.altura() << endl;
    cout << "  ¿Balanceado? " << (arbol1.esBalanceado() ? "SÍ ✓" : "NO ✗") << endl;
    cout << "  Mínimo: " << arbol1.minimo() << endl;
    cout << "  Máximo: " << arbol1.maximo() << endl;
    cout << "  ¿Existe 40? " << (arbol1.buscar(40) ? "SÍ ✓" : "NO ✗") << endl;
    cout << "  ¿Existe 999? " << (arbol1.buscar(999) ? "SÍ ✓" : "NO ✗") << endl;
    
    // ===== EJERCICIO 2: ÁRBOL DEGENERADO (PEOR CASO) =====
    cout << "\n\n🎯 EJERCICIO 2: Árbol Degenerado (Lista)" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    ArbolBinario arbol2;
    cout << "Insertando en orden: 1, 2, 3, 4, 5" << endl;
    arbol2.insertar(1);
    arbol2.insertar(2);
    arbol2.insertar(3);
    arbol2.insertar(4);
    arbol2.insertar(5);
    
    arbol2.visualizar();
    cout << "\nAltura: " << arbol2.altura() << " (peor caso: O(n))" << endl;
    cout << "¿Balanceado? " << (arbol2.esBalanceado() ? "SÍ ✓" : "NO ✗") << endl;
    
    // ===== EJERCICIO 3: ÁRBOL BALANCEADO =====
    cout << "\n\n🎯 EJERCICIO 3: Árbol Balanceado (Ideal)" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    ArbolBinario arbol3;
    cout << "Insertando en orden óptimo: 4, 2, 6, 1, 3, 5, 7" << endl;
    arbol3.insertar(4);
    arbol3.insertar(2);
    arbol3.insertar(6);
    arbol3.insertar(1);
    arbol3.insertar(3);
    arbol3.insertar(5);
    arbol3.insertar(7);
    
    arbol3.visualizar();
    cout << "\nAltura: " << arbol3.altura() << " (óptimo: log n)" << endl;
    cout << "¿Balanceado? " << (arbol3.esBalanceado() ? "SÍ ✓" : "NO ✗") << endl;
    
    // ===== INFORMACIÓN PARA EL EXAMEN =====
    cout << "\n\n📝 CONCEPTOS CRÍTICOS PARA EL EXAMEN:" << endl;
    cout << "════════════════════════════════════" << endl;
    
    cout << "\n1️⃣  RECORRIDOS (MEMORIZA BIEN):" << endl;
    cout << "  IN-ORDER    → Izq, Raíz, Der    → Da BST ORDENADO" << endl;
    cout << "  PRE-ORDER   → Raíz, Izq, Der    → Útil para COPIAR" << endl;
    cout << "  POST-ORDER  → Izq, Der, Raíz    → Útil para ELIMINAR" << endl;
    cout << "  LEVEL-ORDER → Por NIVELES (BFS) → Usa COLA" << endl;
    
    cout << "\n2️⃣  BST PROPIEDADES:" << endl;
    cout << "  • Izquierda < Raíz < Derecha" << endl;
    cout << "  • In-Order produce secuencia ORDENADA" << endl;
    cout << "  • Búsqueda O(log n) promedio, O(n) peor" << endl;
    
    cout << "\n3️⃣  ALTURA vs PROFUNDIDAD:" << endl;
    cout << "  • Altura: distancia al nodo más profundo" << endl;
    cout << "  • Profundidad: distancia desde raíz" << endl;
    cout << "  • Árbol vacío: altura = 0" << endl;
    cout << "  • Un nodo: altura = 1" << endl;
    
    cout << "\n4️⃣  BALANCEADO (IMPORTANTE):" << endl;
    cout << "  • Factor = |altura(izq) - altura(der)| ≤ 1" << endl;
    cout << "  • Para TODOS los nodos" << endl;
    cout << "  • Garantiza O(log n) operaciones" << endl;
    
    cout << "\n5️⃣  COMPLEJIDADES:" << endl;
    cout << "  • BST balanceado: O(log n)" << endl;
    cout << "  • BST degenerado: O(n)" << endl;
    cout << "  • Búsqueda lineal en árbol: O(n)" << endl;
    cout << "  • Altura árbol perfecto: O(log n)" << endl;
    
    cout << "\n6️⃣  CASOS TÍPICOS DE EXAMEN:" << endl;
    cout << "  ✓ Implementar recorridos" << endl;
    cout << "  ✓ Calcular altura" << endl;
    cout << "  ✓ Verificar si está balanceado" << endl;
    cout << "  ✓ Encontrar máximo/mínimo" << endl;
    cout << "  ✓ Insertar/Buscar/Eliminar" << endl;
    cout << "  ✓ Contar nodos con condición" << endl;
    
    cout << "\n\n✅ ANTES DEL EXAMEN, ASEGÚRATE DE:" << endl;
    cout << "  □ Conocer los 4 recorridos DE MEMORIA" << endl;
    cout << "  □ Poder escribir altura() recursivo" << endl;
    cout << "  □ Saber qué es factor de balance" << endl;
    cout << "  □ Entender cuándo un árbol es BST" << endl;
    cout << "  □ Poder hacer búsqueda/inserción" << endl;
    
    return 0;
}

/*
NOTAS IMPORTANTES PARA ESTUDIAR:

1. ESTRUCTURA EN HASKELL vs C++:
   Haskell:  data Tree a = Empty | Node a (Tree a) (Tree a)
   C++:      struct Nodo { int dato; Nodo* izq; Nodo* der; }
   Mismo concepto, distinta sintaxis

2. RECORRIDOS - MNEMOTÉCNIA:
   - IN: "en medio" → Raíz está en MEDIO
   - PRE: "antes" → Raíz está ANTES
   - POST: "después" → Raíz está DESPUÉS
   - LEVEL: "por niveles" → Usa COLA (como BFS)

3. ALTURA vs NODOS:
   Árbol con 1 nodo: altura = 1
   Árbol con 3 nodos: altura = 2
   Árbol con 7 nodos: altura = 3 (perfecto)
   Árbol con n nodos degenerado: altura = n

4. FACTOR DE BALANCE (AVL):
   FB = altura(izq) - altura(der)
   Balanceado si: -1 ≤ FB ≤ 1

5. EJERCICIOS TÍPICOS:
   - "Implementa in-order recursivo"
   - "¿Cuál es la altura de...?"
   - "¿Está balanceado?"
   - "Cuenta nodos donde dato > X"
   - "¿Es un BST válido?"
*/