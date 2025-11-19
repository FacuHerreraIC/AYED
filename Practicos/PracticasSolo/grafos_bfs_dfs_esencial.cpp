#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// ===== GRAFO - LO ESENCIAL =====

class Grafo {
private:
    int V;  // Número de vértices
    vector<vector<int>> listaAdyacencia;
    
public:
    Grafo(int vertices) : V(vertices) {
        listaAdyacencia.resize(V);
    }
    
    // Agregar arista (no dirigida)
    void agregarArista(int u, int v) {
        listaAdyacencia[u].push_back(v);
        listaAdyacencia[v].push_back(u);
    }
    
    // ===== BFS (BREADTH-FIRST SEARCH) =====
    // Recorre por NIVELES, usa COLA
    void BFS(int inicio) {
        cout << "\n🔵 BFS desde nodo " << inicio << ":" << endl;
        
        vector<bool> visitado(V, false);
        queue<int> cola;
        
        // Marcar inicio como visitado y agregar a cola
        visitado[inicio] = true;
        cola.push(inicio);
        
        cout << "Orden: ";
        while (!cola.empty()) {
            int nodo = cola.front();
            cola.pop();
            
            cout << nodo << " ";
            
            // Recorrer todos los vecinos
            for (int vecino : listaAdyacencia[nodo]) {
                if (!visitado[vecino]) {
                    visitado[vecino] = true;
                    cola.push(vecino);
                }
            }
        }
        cout << endl;
    }
    
    // ===== DFS (DEPTH-FIRST SEARCH) =====
    // Recorre en PROFUNDIDAD, usa PILA (recursión)
    void DFS(int inicio) {
        cout << "\n🔴 DFS desde nodo " << inicio << ":" << endl;
        
        vector<bool> visitado(V, false);
        cout << "Orden: ";
        DFSRecursivo(inicio, visitado);
        cout << endl;
    }
    
private:
    void DFSRecursivo(int nodo, vector<bool>& visitado) {
        visitado[nodo] = true;
        cout << nodo << " ";
        
        // Visitar todos los vecinos no visitados
        for (int vecino : listaAdyacencia[nodo]) {
            if (!visitado[vecino]) {
                DFSRecursivo(vecino, visitado);
            }
        }
    }
    
public:
    // DFS ITERATIVO (con pila explícita)
    void DFSIterativo(int inicio) {
        cout << "\n🔴 DFS ITERATIVO desde nodo " << inicio << ":" << endl;
        
        vector<bool> visitado(V, false);
        stack<int> pila;
        
        pila.push(inicio);
        visitado[inicio] = true;
        
        cout << "Orden: ";
        while (!pila.empty()) {
            int nodo = pila.top();
            pila.pop();
            
            cout << nodo << " ";
            
            // Agregar vecinos a la pila
            for (int vecino : listaAdyacencia[nodo]) {
                if (!visitado[vecino]) {
                    visitado[vecino] = true;
                    pila.push(vecino);
                }
            }
        }
        cout << endl;
    }
    
    // ===== DETECTAR CICLOS =====
    bool tieneCiclo() {
        vector<bool> visitado(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                if (tieneCicloDFS(i, -1, visitado)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool tieneCicloDFS(int nodo, int padre, vector<bool>& visitado) {
        visitado[nodo] = true;
        
        for (int vecino : listaAdyacencia[nodo]) {
            if (!visitado[vecino]) {
                if (tieneCicloDFS(vecino, nodo, visitado))
                    return true;
            } else if (vecino != padre) {
                // Encontramos un ciclo
                return true;
            }
        }
        return false;
    }
    
public:
    // ===== COMPONENTES CONEXAS =====
    int contarComponentes() {
        vector<bool> visitado(V, false);
        int componentes = 0;
        
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                DFSComponente(i, visitado);
                componentes++;
            }
        }
        
        return componentes;
    }
    
private:
    void DFSComponente(int nodo, vector<bool>& visitado) {
        visitado[nodo] = true;
        for (int vecino : listaAdyacencia[nodo]) {
            if (!visitado[vecino]) {
                DFSComponente(vecino, visitado);
            }
        }
    }
    
public:
    // ===== CAMINO MÁS CORTO (BFS sin pesos) =====
    vector<int> caminoMasCorto(int inicio, int fin) {
        vector<int> distancia(V, -1);
        vector<int> padre(V, -1);
        queue<int> cola;
        
        distancia[inicio] = 0;
        cola.push(inicio);
        
        while (!cola.empty()) {
            int nodo = cola.front();
            cola.pop();
            
            for (int vecino : listaAdyacencia[nodo]) {
                if (distancia[vecino] == -1) {
                    distancia[vecino] = distancia[nodo] + 1;
                    padre[vecino] = nodo;
                    cola.push(vecino);
                }
            }
        }
        
        // Reconstruir camino
        vector<int> camino;
        int actual = fin;
        
        if (distancia[fin] == -1) {
            cout << "No hay camino de " << inicio << " a " << fin << endl;
            return camino;
        }
        
        while (actual != -1) {
            camino.push_back(actual);
            actual = padre[actual];
        }
        
        reverse(camino.begin(), camino.end());
        return camino;
    }
    
    // ===== VISUALIZACIÓN =====
    void mostrarGrafo() {
        cout << "\n📊 ESTRUCTURA DEL GRAFO:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "  " << i << " → ";
            for (int vecino : listaAdyacencia[i]) {
                cout << vecino << " ";
            }
            cout << endl;
        }
    }
};

// ===== MAIN - EJEMPLOS TIPO EXAMEN =====

int main() {
    cout << "╔════════════════════════════════════════════════════╗" << endl;
    cout << "║     GRAFOS BFS/DFS - LO ESENCIAL PARA EXAMEN     ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
    
    // ===== EJERCICIO 1: GRAFO BÁSICO =====
    cout << "\n🎯 EJERCICIO 1: Grafo Básico (6 nodos)" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Grafo g1(6);
    cout << "Aristas: 0-1, 0-2, 1-3, 2-4, 3-5, 4-5" << endl;
    g1.agregarArista(0, 1);
    g1.agregarArista(0, 2);
    g1.agregarArista(1, 3);
    g1.agregarArista(2, 4);
    g1.agregarArista(3, 5);
    g1.agregarArista(4, 5);
    
    g1.mostrarGrafo();
    
    g1.BFS(0);
    g1.DFS(0);
    g1.DFSIterativo(0);
    
    cout << "\nCamino más corto de 0 a 5: ";
    vector<int> camino = g1.caminoMasCorto(0, 5);
    for (int nodo : camino) {
        cout << nodo << " ";
    }
    cout << endl;
    
    // ===== EJERCICIO 2: DETECTAR CICLOS =====
    cout << "\n\n🎯 EJERCICIO 2: Detectar Ciclos" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Grafo g2a(4);
    cout << "\nGrafo SIN ciclos (árbol):" << endl;
    g2a.agregarArista(0, 1);
    g2a.agregarArista(0, 2);
    g2a.agregarArista(1, 3);
    g2a.mostrarGrafo();
    cout << "¿Tiene ciclo? " << (g2a.tieneCiclo() ? "SÍ ✗" : "NO ✓") << endl;
    
    Grafo g2b(4);
    cout << "\nGrafo CON ciclo:" << endl;
    g2b.agregarArista(0, 1);
    g2b.agregarArista(1, 2);
    g2b.agregarArista(2, 3);
    g2b.agregarArista(3, 0);  // Crea ciclo
    g2b.mostrarGrafo();
    cout << "¿Tiene ciclo? " << (g2b.tieneCiclo() ? "SÍ ✓" : "NO ✗") << endl;
    
    // ===== EJERCICIO 3: COMPONENTES CONEXAS =====
    cout << "\n\n🎯 EJERCICIO 3: Componentes Conexas" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Grafo g3(7);
    cout << "Aristas: 0-1, 1-2, 3-4, 5-6" << endl;
    cout << "(Nodos 0,1,2 conectados) (3,4 conectados) (5,6 conectados)" << endl;
    g3.agregarArista(0, 1);
    g3.agregarArista(1, 2);
    g3.agregarArista(3, 4);
    g3.agregarArista(5, 6);
    
    g3.mostrarGrafo();
    cout << "Número de componentes conexas: " << g3.contarComponentes() << endl;
    
    // ===== INFORMACIÓN PARA EL EXAMEN =====
    cout << "\n\n📝 CONCEPTOS CRÍTICOS - MEMORIZA BIEN:" << endl;
    cout << "════════════════════════════════════" << endl;
    
    cout << "\n1️⃣  BFS (BREADTH-FIRST SEARCH):" << endl;
    cout << "  • Recorre por NIVELES (como árbol level-order)" << endl;
    cout << "  • Usa COLA" << endl;
    cout << "  • Orden: primero todos a distancia 1, luego 2, etc." << endl;
    cout << "  • Complejidad: O(V + E)" << endl;
    cout << "  • Uso: camino más corto SIN pesos" << endl;
    cout << "  • Patrón: while cola no vacía → pop → procesar → push vecinos" << endl;
    
    cout << "\n2️⃣  DFS (DEPTH-FIRST SEARCH):" << endl;
    cout << "  • Recorre en PROFUNDIDAD (va lo más profundo posible)" << endl;
    cout << "  • Usa PILA (recursión natural)" << endl;
    cout << "  • Orden: explora rama completa antes de pasar a otra" << endl;
    cout << "  • Complejidad: O(V + E)" << endl;
    cout << "  • Uso: detectar ciclos, componentes, topológico" << endl;
    cout << "  • Patrón: marca visitado → procesa → recursiona vecinos" << endl;
    
    cout << "\n3️⃣  DIFERENCIA BFS vs DFS:" << endl;
    cout << "  BFS:  Cola → por niveles → más cercanos primero" << endl;
    cout << "  DFS:  Pila → profundidad → más lejanos primero" << endl;
    cout << "  Ambas visitan todos los nodos accesibles: O(V+E)" << endl;
    
    cout << "\n4️⃣  DETECTAR CICLOS:" << endl;
    cout << "  • En grafo no dirigido: si hay vecino visitado ≠ padre" << endl;
    cout << "  • En grafo dirigido: más complejo (usar colores)" << endl;
    
    cout << "\n5️⃣  COMPONENTES CONEXAS:" << endl;
    cout << "  • Contar cuántas 'islas' hay" << endl;
    cout << "  • Usar DFS/BFS desde cada nodo no visitado" << endl;
    cout << "  • Incrementar contador cada que inicias nuevo DFS/BFS" << endl;
    
    cout << "\n6️⃣  CAMINO MÁS CORTO:" << endl;
    cout << "  • SIN pesos: usar BFS + padre" << endl;
    cout << "  • CON pesos no negativos: Dijkstra" << endl;
    cout << "  • Reconstruir: seguir padres hacia atrás" << endl;
    
    cout << "\n7️⃣  CASOS TÍPICOS DE EXAMEN:" << endl;
    cout << "  ✓ Implementar BFS/DFS" << endl;
    cout << "  ✓ Recorrer y contar nodos" << endl;
    cout << "  ✓ Detectar ciclos" << endl;
    cout << "  ✓ Contar componentes conexas" << endl;
    cout << "  ✓ Encontrar camino más corto" << endl;
    cout << "  ✓ Verificar conectividad" << endl;
    
    cout << "\n\n✅ ANTES DEL EXAMEN, ASEGÚRATE DE:" << endl;
    cout << "  □ Entender la diferencia BFS vs DFS" << endl;
    cout << "  □ Poder escribir BFS (con cola)" << endl;
    cout << "  □ Poder escribir DFS (recursivo)" << endl;
    cout << "  □ Saber cuándo usar cada uno" << endl;
    cout << "  □ Entender O(V+E)" << endl;
    
    cout << "\n\n💡 TRUCO MEMORY:" << endl;
    cout << "  BFS = Bread (pan) First → Breadth (ancho)" << endl;
    cout << "  DFS = Depth First → más profundo primero" << endl;
    cout << "  BFS = Cola (FIFO)" << endl;
    cout << "  DFS = Pila (LIFO)" << endl;
    
    return 0;
}

/*
COMPARACIÓN RÁPIDA PARA EXAMEN:

┌─────────┬──────────────┬──────────────┬──────────────┐
│ Aspecto │ BFS          │ DFS          │ Diferencia   │
├─────────┼──────────────┼──────────────┼──────────────┤
│ Orden   │ Por niveles  │ Profundidad  │ BFS estrecho │
│ Estr.   │ Cola         │ Pila/Rec.    │ Opuesto      │
│ Uso     │ Camino corto │ Ciclos       │ Diferentes   │
│ Complejidad│ O(V+E)    │ O(V+E)       │ Igual        │
└─────────┴──────────────┴──────────────┴──────────────┘

PYTHON → C++ TRANSLATION:

Python BFS:
from collections import deque
q = deque([inicio])
visited = {inicio}
while q:
    nodo = q.popleft()
    for vecino in grafo[nodo]:
        if vecino not in visited:
            visited.add(vecino)
            q.append(vecino)

C++ BFS:
queue<int> q;
vector<bool> visited(V, false);
q.push(inicio);
visited[inicio] = true;
while (!q.empty()) {
    int nodo = q.front();
    q.pop();
    for (int vecino : grafo[nodo]) {
        if (!visited[vecino]) {
            visited[vecino] = true;
            q.push(vecino);
        }
    }
}
*/