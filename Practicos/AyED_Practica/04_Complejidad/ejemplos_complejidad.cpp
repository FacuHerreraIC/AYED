#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
using namespace chrono;

// ===== UNIDAD 4: COMPLEJIDAD ALGORÍTMICA =====

void explicacionNotaciones() {
    cout << "\n=== NOTACIONES ASINTÓTICAS ===" << endl;
    cout << "• Big O (O): Cota superior - peor caso" << endl;
    cout << "• Omega (Ω): Cota inferior - mejor caso" << endl;
    cout << "• Theta (Θ): Cota ajustada - caso promedio" << endl;
    cout << "\nOrden de crecimiento (de mejor a peor):" << endl;
    cout << "O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ)" << endl;
}

// ===== EJEMPLOS O(1) - CONSTANTE =====
void ejemploO1() {
    cout << "\n=== O(1) - TIEMPO CONSTANTE ===" << endl;
    
    int arreglo[] = {10, 20, 30, 40, 50};
    
    // Acceso directo por índice - SIEMPRE O(1)
    cout << "Primer elemento: " << arreglo[0] << endl;
    cout << "Último elemento: " << arreglo[4] << endl;
    
    // Push/Pop en pila - O(1)
    cout << "Push/Pop en pila: O(1)" << endl;
    
    // Insertar al inicio en lista enlazada - O(1)
    cout << "Insertar al inicio en lista: O(1)" << endl;
    
    cout << "✅ No importa el tamaño de n, siempre toma el mismo tiempo" << endl;
}

// ===== EJEMPLOS O(n) - LINEAL =====
void ejemploOn() {
    cout << "\n=== O(n) - TIEMPO LINEAL ===" << endl;
    
    int numeros[] = {15, 3, 9, 12, 6, 21, 8};
    int tamaño = 7;
    
    // Búsqueda lineal - O(n)
    int buscado = 12;
    cout << "Buscando " << buscado << " en el arreglo:" << endl;
    
    for (int i = 0; i < tamaño; i++) {
        cout << "Comparando con posición " << i << ": " << numeros[i] << endl;
        if (numeros[i] == buscado) {
            cout << "✅ Encontrado en posición " << i << endl;
            break;
        }
    }
    
    // Sumar todos los elementos - O(n)
    int suma = 0;
    for (int i = 0; i < tamaño; i++) {
        suma += numeros[i];
    }
    cout << "Suma total (recorrió todo): " << suma << endl;
    
    cout << "✅ Si duplicamos n, el tiempo se duplica" << endl;
}

// ===== EJEMPLOS O(n²) - CUADRÁTICO =====
void ejemploOn2() {
    cout << "\n=== O(n²) - TIEMPO CUADRÁTICO ===" << endl;
    
    int arreglo[] = {5, 2, 8, 1, 9};
    int n = 5;
    
    cout << "Bubble Sort - O(n²):" << endl;
    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) cout << arreglo[i] << " ";
    cout << endl;
    
    int comparaciones = 0;
    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambiar
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
        cout << "Pasada " << (i + 1) << ": ";
        for (int k = 0; k < n; k++) cout << arreglo[k] << " ";
        cout << endl;
    }
    
    cout << "Total de comparaciones: " << comparaciones << endl;
    cout << "✅ Para n=5: " << comparaciones << " comparaciones ≈ n²" << endl;
    
    // Ejemplo de matriz - también O(n²)
    cout << "\nRecorrer matriz 3x3 - O(n²):" << endl;
    int matriz[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int operaciones = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
            operaciones++;
        }
        cout << endl;
    }
    cout << "Operaciones: " << operaciones << " = 3² = 9" << endl;
}

// ===== EJEMPLOS O(log n) - LOGARÍTMICO =====
void ejemploOlogN() {
    cout << "\n=== O(log n) - TIEMPO LOGARÍTMICO ===" << endl;
    
    int arreglo[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Ordenado
    int n = 10;
    int buscado = 7;
    
    cout << "Búsqueda binaria - O(log n):" << endl;
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) cout << arreglo[i] << " ";
    cout << endl;
    cout << "Buscando: " << buscado << endl;
    
    int izq = 0, der = n - 1;
    int comparaciones = 0;
    
    while (izq <= der) {
        comparaciones++;
        int medio = (izq + der) / 2;
        cout << "Comparación " << comparaciones << ": medio=" << medio 
             << ", valor=" << arreglo[medio] << endl;
        
        if (arreglo[medio] == buscado) {
            cout << "✅ Encontrado en posición " << medio << endl;
            break;
        } else if (arreglo[medio] < buscado) {
            izq = medio + 1;
            cout << "   Buscar en mitad derecha" << endl;
        } else {
            der = medio - 1;
            cout << "   Buscar en mitad izquierda" << endl;
        }
    }
    
    cout << "Total comparaciones: " << comparaciones << " << " << n << endl;
    cout << "✅ Divide el problema a la mitad cada vez" << endl;
}

// ===== EJEMPLOS O(n log n) - LINEARÍTMICO =====
void ejemploOnLogN() {
    cout << "\n=== O(n log n) - TIEMPO LINEARÍTMICO ===" << endl;
    cout << "Algoritmos típicos con O(n log n):" << endl;
    cout << "• Merge Sort" << endl;
    cout << "• Quick Sort (caso promedio)" << endl;
    cout << "• Heap Sort" << endl;
    
    // Simulación simplificada de Merge Sort
    cout << "\nMerge Sort conceptual:" << endl;
    cout << "1. Dividir arreglo por la mitad → O(log n) niveles" << endl;
    cout << "2. En cada nivel, fusionar toma O(n) tiempo" << endl;
    cout << "3. Total: O(log n) × O(n) = O(n log n)" << endl;
    
    vector<int> datos = {8, 3, 1, 7, 0, 10, 2};
    cout << "Ejemplo con " << datos.size() << " elementos:" << endl;
    cout << "Niveles de recursión: ~" << (int)ceil(log2(datos.size())) << endl;
    cout << "✅ Mucho mejor que O(n²) para arreglos grandes" << endl;
}

// ===== COMPARACIÓN PRÁCTICA DE COMPLEJIDADES =====
void compararComplejidades() {
    cout << "\n=== COMPARACIÓN PRÁCTICA ===" << endl;
    cout << "Para diferentes valores de n:" << endl;
    cout << "n\tO(1)\tO(log n)\tO(n)\tO(n log n)\tO(n²)" << endl;
    cout << "------------------------------------------------" << endl;
    
    int valores[] = {1, 10, 100, 1000};
    
    for (int n : valores) {
        int log_n = (n == 1) ? 1 : (int)ceil(log2(n));
        int n_log_n = n * log_n;
        int n_cuadrado = n * n;
        
        cout << n << "\t1\t" << log_n << "\t\t" << n 
             << "\t" << n_log_n << "\t\t" << n_cuadrado << endl;
    }
    
    cout << "\n🚨 ¡Diferencia dramática con n grandes!" << endl;
    cout << "Para n=1000: O(n²)=1,000,000 vs O(n log n)≈10,000" << endl;
}

// ===== ANÁLISIS DE ESTRUCTURAS DE DATOS =====
void complejidadEstructuras() {
    cout << "\n=== COMPLEJIDAD DE ESTRUCTURAS DE DATOS ===" << endl;
    
    cout << "\n📚 ARREGLOS:" << endl;
    cout << "• Acceso por índice: O(1)" << endl;
    cout << "• Búsqueda lineal: O(n)" << endl;
    cout << "• Insertar al final: O(1)" << endl;
    cout << "• Insertar en medio: O(n)" << endl;
    
    cout << "\n🔗 LISTAS ENLAZADAS:" << endl;
    cout << "• Acceso por posición: O(n)" << endl;
    cout << "• Insertar al inicio: O(1)" << endl;
    cout << "• Insertar al final: O(n) sin tail, O(1) con tail" << endl;
    cout << "• Eliminar elemento: O(n)" << endl;
    
    cout << "\n📚 PILAS:" << endl;
    cout << "• Push: O(1)" << endl;
    cout << "• Pop: O(1)" << endl;
    cout << "• Top: O(1)" << endl;
    
    cout << "\n📚 COLAS:" << endl;
    cout << "• Enqueue: O(1)" << endl;
    cout << "• Dequeue: O(1)" << endl;
    cout << "• Front/Rear: O(1)" << endl;
}

// ===== EJERCICIOS TÍPICOS DE EXAMEN =====
void ejerciciosAnalisisComplejidad() {
    cout << "\n=== EJERCICIOS DE ANÁLISIS ===" << endl;
    
    cout << "\n🎯 EJERCICIO 1: Analizar estos códigos:" << endl;
    
    cout << "\nCódigo A:" << endl;
    cout << "for (int i = 0; i < n; i++) {" << endl;
    cout << "    cout << arr[i];" << endl;
    cout << "}" << endl;
    cout << "Respuesta: O(n) - Un solo bucle que recorre n elementos" << endl;
    
    cout << "\nCódigo B:" << endl;
    cout << "for (int i = 0; i < n; i++) {" << endl;
    cout << "    for (int j = 0; j < n; j++) {" << endl;
    cout << "        cout << arr[i][j];" << endl;
    cout << "    }" << endl;
    cout << "}" << endl;
    cout << "Respuesta: O(n²) - Dos bucles anidados" << endl;
    
    cout << "\nCódigo C:" << endl;
    cout << "for (int i = 0; i < n; i++) {" << endl;
    cout << "    for (int j = i; j < n; j++) {" << endl;
    cout << "        cout << arr[i] + arr[j];" << endl;
    cout << "    }" << endl;
    cout << "}" << endl;
    cout << "Respuesta: O(n²) - Aunque j empieza en i, sigue siendo cuadrático" << endl;
    
    cout << "\nCódigo D (búsqueda binaria):" << endl;
    cout << "while (izq <= der) {" << endl;
    cout << "    int medio = (izq + der) / 2;" << endl;
    cout << "    if (arr[medio] == x) return medio;" << endl;
    cout << "    else if (arr[medio] < x) izq = medio + 1;" << endl;
    cout << "    else der = medio - 1;" << endl;
    cout << "}" << endl;
    cout << "Respuesta: O(log n) - Divide el espacio de búsqueda a la mitad" << endl;
}

// ===== CONSEJOS PARA EL EXAMEN =====
void consejosExamen() {
    cout << "\n=== CONSEJOS PARA EL EXAMEN ===" << endl;
    
    cout << "\n🎯 CÓMO ANALIZAR COMPLEJIDAD:" << endl;
    cout << "1. Contar bucles anidados:" << endl;
    cout << "   • Un bucle → O(n)" << endl;
    cout << "   • Dos anidados → O(n²)" << endl;
    cout << "   • Tres anidados → O(n³)" << endl;
    
    cout << "\n2. Operaciones que dividen:" << endl;
    cout << "   • Búsqueda binaria → O(log n)" << endl;
    cout << "   • Merge Sort → O(n log n)" << endl;
    
    cout << "\n3. Ignorar constantes y términos menores:" << endl;
    cout << "   • 3n + 5 → O(n)" << endl;
    cout << "   • n² + n + 1 → O(n²)" << endl;
    
    cout << "\n🚨 ERRORES COMUNES:" << endl;
    cout << "• Confundir mejor, peor y caso promedio" << endl;
    cout << "• No considerar el caso peor para Big O" << endl;
    cout << "• Incluir constantes en la notación" << endl;
    cout << "• No distinguir entre diferentes operaciones" << endl;
}

int main() {
    cout << "🎯 COMPLEJIDAD ALGORÍTMICA - CONCEPTOS DE EXAMEN" << endl;
    cout << "================================================" << endl;
    
    explicacionNotaciones();
    ejemploO1();
    ejemploOn();
    ejemploOn2();
    ejemploOlogN();
    ejemploOnLogN();
    compararComplejidades();
    complejidadEstructuras();
    ejerciciosAnalisisComplejidad();
    consejosExamen();
    
    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • Big O describe el crecimiento en el peor caso" << endl;
    cout << "   • Ignorar constantes: 5n → O(n)" << endl;
    cout << "   • Tomar el término dominante: n² + n → O(n²)" << endl;
    cout << "   • Bucles anidados → multiplicar complejidades" << endl;
    cout << "   • Divide y vencerás → O(log n) o O(n log n)" << endl;
    cout << "   • Conocer complejidad de estructuras básicas" << endl;
    cout << "   • Saber analizar código simple paso a paso" << endl;
    
    return 0;
}