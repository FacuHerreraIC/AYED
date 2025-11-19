#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// ╔════════════════════════════════════════════════════════╗
// ║  GUÍA RÁPIDA - LIBRERÍAS ESENCIALES PARA EXAMEN      ║
// ╚════════════════════════════════════════════════════════╝

int main() {
    
    // ═══════════════════════════════════════════════════════
    // 1️⃣  VECTOR (Lista dinámica - como Python list)
    // ═══════════════════════════════════════════════════════
    
    cout << "\n" << string(60, '=') << endl;
    cout << "1. VECTOR - Lista dinámica" << endl;
    cout << string(60, '=') << endl;
    
    // Crear vector
    vector<int> vec;
    cout << "\nvector<int> vec;" << endl;
    
    // Agregar elementos (push_back = append en Python)
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "\nvec.push_back(10); vec.push_back(20); vec.push_back(30);" << endl;
    cout << "Vector: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // Acceso por índice (como lista en Python)
    cout << "\nvec[0] = " << vec[0] << endl;
    cout << "vec[1] = " << vec[1] << endl;
    cout << "vec.at(2) = " << vec.at(2) << " (con validación)" << endl;
    
    // Información
    cout << "\nInformación:" << endl;
    cout << "  vec.size() = " << vec.size() << " (cantidad elementos)" << endl;
    cout << "  vec.capacity() = " << vec.capacity() << " (memoria asignada)" << endl;
    cout << "  vec.empty() = " << (vec.empty() ? "true" : "false") << endl;
    
    // Primero y último
    cout << "\nvec.front() = " << vec.front() << " (primer elemento)" << endl;
    cout << "vec.back() = " << vec.back() << " (último elemento)" << endl;
    
    // Modificar
    vec[1] = 25;
    cout << "\nvec[1] = 25;" << endl;
    cout << "Vector ahora: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // Eliminar
    vec.pop_back();  // Elimina el último
    cout << "\nvec.pop_back();" << endl;
    cout << "Vector ahora: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // Insertar en posición específica
    vec.insert(vec.begin() + 1, 15);
    cout << "\nvec.insert(vec.begin() + 1, 15);" << endl;
    cout << "Vector ahora: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // Eliminar elemento en posición
    vec.erase(vec.begin() + 2);
    cout << "\nvec.erase(vec.begin() + 2);" << endl;
    cout << "Vector ahora: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // Limpiar
    cout << "\nvec.clear();" << endl;
    vec.clear();
    cout << "Vector vacío, size = " << vec.size() << endl;
    
    // Vector con inicialización
    vector<int> vec2(5, 0);  // 5 elementos inicializados a 0
    cout << "\nvector<int> vec2(5, 0); // 5 ceros:" << endl;
    for (int x : vec2) cout << x << " ";
    cout << endl;
    
    // ═══════════════════════════════════════════════════════
    // 2️⃣  QUEUE (Cola - FIFO, First In First Out)
    // ═══════════════════════════════════════════════════════
    
    cout << "\n\n" << string(60, '=') << endl;
    cout << "2. QUEUE - Cola (FIFO)" << endl;
    cout << string(60, '=') << endl;
    
    queue<int> q;
    cout << "\nqueue<int> q;" << endl;
    
    // Agregar (push = enqueue)
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "\nq.push(1); q.push(2); q.push(3);" << endl;
    
    // Ver frente
    cout << "\nq.front() = " << q.front() << " (primer elemento)" << endl;
    cout << "q.back() = " << q.back() << " (último elemento)" << endl;
    
    // Tamaño
    cout << "q.size() = " << q.size() << endl;
    
    // Procesar (pop = dequeue)
    cout << "\nProcesando cola:" << endl;
    while (!q.empty()) {
        cout << "  q.front() = " << q.front() << endl;
        q.pop();
    }
    
    cout << "Cola vacía, size = " << q.size() << endl;
    
    // CASO DE USO: BFS
    cout << "\n📌 CASO DE USO: BFS (recorrido por niveles)" << endl;
    queue<int> qBFS;
    vector<bool> visitado = {false, false, false, false, false};
    
    qBFS.push(0);
    visitado[0] = true;
    
    cout << "BFS desde nodo 0: ";
    while (!qBFS.empty()) {
        int nodo = qBFS.front();
        qBFS.pop();
        cout << nodo << " ";
        // Aquí iríamos a los vecinos del nodo
    }
    cout << endl;
    
    // ═══════════════════════════════════════════════════════
    // 3️⃣  STACK (Pila - LIFO, Last In First Out)
    // ═══════════════════════════════════════════════════════
    
    cout << "\n\n" << string(60, '=') << endl;
    cout << "3. STACK - Pila (LIFO)" << endl;
    cout << string(60, '=') << endl;
    
    stack<int> s;
    cout << "\nstack<int> s;" << endl;
    
    // Agregar (push)
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "\ns.push(10); s.push(20); s.push(30);" << endl;
    
    // Ver tope
    cout << "\ns.top() = " << s.top() << " (último agregado)" << endl;
    
    // Tamaño
    cout << "s.size() = " << s.size() << endl;
    
    // Procesar (pop)
    cout << "\nProcesando pila:" << endl;
    while (!s.empty()) {
        cout << "  s.top() = " << s.top() << endl;
        s.pop();
    }
    
    cout << "Pila vacía, size = " << s.size() << endl;
    
    // CASO DE USO: DFS
    cout << "\n📌 CASO DE USO: DFS (recorrido en profundidad)" << endl;
    stack<int> sDFS;
    visitado = {false, false, false, false, false};
    
    sDFS.push(0);
    visitado[0] = true;
    
    cout << "DFS desde nodo 0: ";
    while (!sDFS.empty()) {
        int nodo = sDFS.top();
        sDFS.pop();
        cout << nodo << " ";
        // Aquí iríamos a los vecinos del nodo
    }
    cout << endl;
    
    // ═══════════════════════════════════════════════════════
    // 4️⃣  ALGORITHM (Funciones útiles)
    // ═══════════════════════════════════════════════════════
    
    cout << "\n\n" << string(60, '=') << endl;
    cout << "4. ALGORITHM - Funciones útiles" << endl;
    cout << string(60, '=') << endl;
    
    vector<int> arr = {5, 2, 8, 1, 9, 3};
    cout << "\nvector<int> arr = {5, 2, 8, 1, 9, 3};" << endl;
    
    // sort - Ordenar
    vector<int> arr1 = arr;
    sort(arr1.begin(), arr1.end());
    cout << "\nsort(arr.begin(), arr.end());" << endl;
    cout << "Resultado: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    // sort descendente
    vector<int> arr2 = arr;
    sort(arr2.begin(), arr2.end(), greater<int>());
    cout << "\nsort(arr.begin(), arr.end(), greater<int>());" << endl;
    cout << "Resultado (descendente): ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    // max_element - Encontrar máximo
    int maximo = *max_element(arr.begin(), arr.end());
    cout << "\n*max_element(arr.begin(), arr.end()) = " << maximo << endl;
    
    // min_element - Encontrar mínimo
    int minimo = *min_element(arr.begin(), arr.end());
    cout << "*min_element(arr.begin(), arr.end()) = " << minimo << endl;
    
    // find - Buscar elemento
    auto it = find(arr.begin(), arr.end(), 8);
    if (it != arr.end()) {
        cout << "\nfind(arr.begin(), arr.end(), 8);" << endl;
        cout << "Encontrado en posición: " << (it - arr.begin()) << endl;
    }
    
    // count - Contar ocurrencias
    vector<int> arr3 = {1, 2, 2, 3, 2, 4};
    int cuenta = count(arr3.begin(), arr3.end(), 2);
    cout << "\ncount({1,2,2,3,2,4}, 2) = " << cuenta << endl;
    
    // reverse - Invertir
    vector<int> arr4 = {1, 2, 3, 4, 5};
    reverse(arr4.begin(), arr4.end());
    cout << "\nreverse({1,2,3,4,5}):" << endl;
    for (int x : arr4) cout << x << " ";
    cout << endl;
    
    // swap - Intercambiar dos elementos
    vector<int> arr5 = {1, 2, 3};
    swap(arr5[0], arr5[2]);
    cout << "\nswap(arr5[0], arr5[2]); // {1,2,3} → ";
    for (int x : arr5) cout << x << " ";
    cout << endl;
    
    // abs - Valor absoluto
    cout << "\nabs(-5) = " << abs(-5) << endl;
    cout << "abs(10) = " << abs(10) << endl;
    
    // min/max - Comparar dos valores
    cout << "\nmin(5, 3) = " << min(5, 3) << endl;
    cout << "max(5, 3) = " << max(5, 3) << endl;
    
    // ═══════════════════════════════════════════════════════
    // 📝 RESUMEN RÁPIDO
    // ═══════════════════════════════════════════════════════
    
    cout << "\n\n" << string(60, '=') << endl;
    cout << "RESUMEN - CHEAT SHEET" << endl;
    cout << string(60, '=') << endl;
    
    cout << "\n📚 VECTOR (Arreglo dinámico):" << endl;
    cout << "  vec.push_back(x)       - Agregar al final" << endl;
    cout << "  vec.pop_back()         - Eliminar del final" << endl;
    cout << "  vec[i]                 - Acceso por índice" << endl;
    cout << "  vec.size()             - Cantidad elementos" << endl;
    cout << "  vec.front() / back()   - Primero/Último" << endl;
    cout << "  vec.insert/erase()     - Insertar/Eliminar posición" << endl;
    cout << "  vec.clear()            - Limpiar todo" << endl;
    
    cout << "\n📦 QUEUE (Cola FIFO):" << endl;
    cout << "  q.push(x)              - Agregar al final" << endl;
    cout << "  q.pop()                - Eliminar del inicio" << endl;
    cout << "  q.front()              - Ver primero" << endl;
    cout << "  q.back()               - Ver último" << endl;
    cout << "  q.size()               - Cantidad elementos" << endl;
    cout << "  q.empty()              - ¿Está vacía?" << endl;
    cout << "  ➜ USO: BFS" << endl;
    
    cout << "\n📚 STACK (Pila LIFO):" << endl;
    cout << "  s.push(x)              - Agregar al tope" << endl;
    cout << "  s.pop()                - Eliminar del tope" << endl;
    cout << "  s.top()                - Ver tope" << endl;
    cout << "  s.size()               - Cantidad elementos" << endl;
    cout << "  s.empty()              - ¿Está vacía?" << endl;
    cout << "  ➜ USO: DFS, expresiones, undo" << endl;
    
    cout << "\n🔧 ALGORITHM (Funciones útiles):" << endl;
    cout << "  sort(it1, it2)         - Ordenar" << endl;
    cout << "  sort(..., greater<>()) - Ordenar descendente" << endl;
    cout << "  max_element(it1, it2)  - Encontrar máximo" << endl;
    cout << "  min_element(it1, it2)  - Encontrar mínimo" << endl;
    cout << "  find(it1, it2, x)      - Buscar elemento" << endl;
    cout << "  count(it1, it2, x)     - Contar ocurrencias" << endl;
    cout << "  reverse(it1, it2)      - Invertir" << endl;
    cout << "  swap(a, b)             - Intercambiar" << endl;
    
    cout << "\n\n" << string(60, '=') << endl;
    cout << "EQUIVALENCIAS PYTHON → C++" << endl;
    cout << string(60, '=') << endl;
    
    cout << "\nPYTHON                 →  C++" << endl;
    cout << "─────────────────────────────────────────" << endl;
    cout << "lst = []                →  vector<int> v;" << endl;
    cout << "lst.append(x)           →  v.push_back(x);" << endl;
    cout << "lst.pop()               →  v.pop_back();" << endl;
    cout << "len(lst)                →  v.size();" << endl;
    cout << "lst[i]                  →  v[i];" << endl;
    cout << "sorted(lst)             →  sort(v.begin(), v.end());" << endl;
    cout << "max(lst)                →  *max_element(...);" << endl;
    cout << "from collections import deque" << endl;
    cout << "q = deque()             →  queue<int> q;" << endl;
    cout << "q.append(x)             →  q.push(x);" << endl;
    cout << "q.popleft()             →  q.pop();" << endl;
    cout << "q[0]                    →  q.front();" << endl;
    
    cout << "\n\n✅ LISTO PARA USAR EN TUS EJERCICIOS DE EXAMEN!" << endl;
    
    return 0;
}

/*
NOTAS IMPORTANTES:

1. ITERADORES (it1, it2):
   - begin() = primera posición
   - end() = posición DESPUÉS de la última
   - Por eso usamos .begin() y .end()

2. PUNTEROS EN ALGORITMOS:
   - *max_element(...) tiene asterisco porque devuelve puntero
   - Hay que desreferenciar con *

3. FOR LOOP CON VECTOR:
   for (int x : vec) {
       // x es cada elemento
   }
   O también:
   for (int i = 0; i < vec.size(); i++) {
       // vec[i] es cada elemento
   }

4. DIFERENCIA IMPORTANTE:
   - vector: acceso aleatorio, búsqueda O(n)
   - queue: solo frente/final, FIFO
   - stack: solo tope, LIFO
   Elegir correcta para cada caso de uso

5. PARA EXAMEN:
   - Memoriza las operaciones básicas
   - Sabe cuándo usar cada estructura
   - BFS = queue
   - DFS = stack (o recursión)
   - Búsqueda = vector + find
*/