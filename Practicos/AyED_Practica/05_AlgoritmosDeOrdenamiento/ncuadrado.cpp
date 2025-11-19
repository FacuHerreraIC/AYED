#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// ===== ALGORITMOS DE ORDENAMIENTO O(n²) =====

// Función auxiliar para imprimir arreglo
void imprimir(const vector<int>& arr, const string& mensaje = "") {
    if (!mensaje.empty()) cout << mensaje << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// ===== BUBBLE SORT =====
// Complejidad: O(n²) en todos los casos (sin optimización)
// Con optimización: O(n) mejor caso si ya está ordenado
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int comparaciones = 0, intercambios = 0;

    for (int i = 0; i < n - 1; i++) {
        bool huboIntercambio = false;  // Optimización

        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;
                huboIntercambio = true;
            }
        }

        // Si no hubo intercambios, ya está ordenado
        if (!huboIntercambio) break;
    }

    cout << "Bubble Sort - Comparaciones: " << comparaciones
         << ", Intercambios: " << intercambios << endl;
}

// ===== SELECTION SORT =====
// Complejidad: O(n²) siempre (no optimizable)
// Mínimo número de intercambios: O(n)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    int comparaciones = 0, intercambios = 0;

    for (int i = 0; i < n - 1; i++) {
        // Encontrar el mínimo en arr[i..n-1]
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Intercambiar si es necesario
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            intercambios++;
        }
    }

    cout << "Selection Sort - Comparaciones: " << comparaciones
         << ", Intercambios: " << intercambios << endl;
}

// ===== INSERTION SORT =====
// Complejidad: Mejor caso O(n), Peor caso O(n²)
// Eficiente para arrays pequeños o casi ordenados
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    int comparaciones = 0, desplazamientos = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Mover elementos mayores que key una posición adelante
        while (j >= 0) {
            comparaciones++;
            if (arr[j] <= key) break;

            arr[j + 1] = arr[j];
            desplazamientos++;
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Insertion Sort - Comparaciones: " << comparaciones
         << ", Desplazamientos: " << desplazamientos << endl;
}

// Shell Sort with Variants

void shellSort(std::vector<int>& arr){
  int n = arr.size();

  for (int gap = n / 2; gap > 0 ; gap /= 2){
    //Ahora va el algoritmo por insercion
    for(int i = gap; i < n ; i++){
        int temp = arr[i];
        int j;
        for ( j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
            arr[j] = arr[j - gap];
        }
        arr[j] = temp;
    }

  }
}

void shellSortHibbard(std::vector<int>& arr) {
    int n = arr.size();

    //Se genera la secuencia de Hibbard: 2k -1
    std::vector<int> gaps;
    for (int k = 1; (1 <<k )- 1 < n; k++) {
        gaps.push_back(((1<<k)-1));
    }

    // Se utilizan los gaps, en orden de mayor a menor
    for (int i = gaps.size() - 1; i >= 0 ; i-- ) {
        int gap = gaps[i];

        for (int j = gap; j < n; j++) {
            int temp = arr[i];
            int k;
            for (k = j; k >= gap && arr[k-gap] > temp; k -= gap) {
                arr[k] = arr[k - gap];
            }
            arr[k]=temp;
        }
    }
}

// ===== ANÁLISIS Y COMPARACIÓN =====
void analizarAlgoritmos() {
    cout << "\n=== ANÁLISIS DE ALGORITMOS O(n²) ===" << endl;

    cout << "\n📊 TABLA COMPARATIVA:" << endl;
    cout << "┌─────────────────┬──────────┬──────────┬──────────┬──────────┬─────────┐" << endl;
    cout << "│ Algoritmo       │ Mejor    │ Promedio │ Peor     │ Espacio  │ Estable │" << endl;
    cout << "├─────────────────┼──────────┼──────────┼──────────┼──────────┼─────────┤" << endl;
    cout << "│ Bubble Sort     │ O(n)*    │ O(n²)    │ O(n²)    │ O(1)     │ SÍ      │" << endl;
    cout << "│ Selection Sort  │ O(n²)    │ O(n²)    │ O(n²)    │ O(1)     │ NO      │" << endl;
    cout << "│ Insertion Sort  │ O(n)     │ O(n²)    │ O(n²)    │ O(1)     │ SÍ      │" << endl;
    cout << "│ Shell Sort      │ O(n log n)│O(n^(4/3))│O(n^(3/2))│ O(1)     │ NO      │" << endl;
    cout << "└─────────────────┴──────────┴──────────┴──────────┴──────────┴─────────┘" << endl;
    cout << "* Con optimización de detección temprana" << endl;
    cout << "** La complejidad de Shell Sort depende de la secuencia de gaps" << endl;

    cout << "\n🎯 CUÁNDO USAR CADA UNO:" << endl;
    cout << "\n• BUBBLE SORT:" << endl;
    cout << "  - Arrays muy pequeños (n < 10)" << endl;
    cout << "  - Propósitos educativos" << endl;
    cout << "  - Casi nunca en producción" << endl;

    cout << "\n• SELECTION SORT:" << endl;
    cout << "  - Cuando el costo de escritura es alto" << endl;
    cout << "  - Mínimo número de intercambios: O(n)" << endl;
    cout << "  - Arrays pequeños con memoria limitada" << endl;

    cout << "\n• INSERTION SORT:" << endl;
    cout << "  - Arrays pequeños o casi ordenados ✅" << endl;
    cout << "  - Datos que llegan en tiempo real" << endl;
    cout << "  - Como parte de algoritmos híbridos (TimSort)" << endl;
    cout << "  - Mejor algoritmo O(n²) en la práctica" << endl;

    cout << "\n• SHELL SORT:" << endl;
    cout << "  - Arrays medianos (mejor que O(n²) simple) ✅" << endl;
    cout << "  - Mejora significativa sobre Insertion Sort" << endl;
    cout << "  - Cuando no puedes usar Merge/Quick (sin recursión)" << endl;
    cout << "  - Código simple pero más eficiente que O(n²)" << endl;
    cout << "  - Útil en sistemas embebidos (in-place, sin recursión)" << endl;
}

// ===== PRUEBAS COMPARATIVAS =====
void pruebasComparativas() {
    cout << "\n\n=== PRUEBAS CON DIFERENTES CASOS ===" << endl;

    // CASO 1: Array aleatorio
    cout << "\n--- CASO 1: Array aleatorio ---" << endl;
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    imprimir(arr1, "Original");

    vector<int> temp1 = arr1;
    bubbleSort(temp1);
    imprimir(temp1, "Bubble");

    temp1 = arr1;
    selectionSort(temp1);
    imprimir(temp1, "Selection");

    temp1 = arr1;
    insertionSort(temp1);
    imprimir(temp1, "Insertion");

    // CASO 2: Array ya ordenado (mejor caso)
    cout << "\n--- CASO 2: Array ya ordenado ---" << endl;
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8};
    imprimir(arr2, "Original (ordenado)");

    temp1 = arr2;
    bubbleSort(temp1);

    temp1 = arr2;
    selectionSort(temp1);

    temp1 = arr2;
    insertionSort(temp1);

    // CASO 3: Array invertido (peor caso)
    cout << "\n--- CASO 3: Array invertido (peor caso) ---" << endl;
    vector<int> arr3 = {8, 7, 6, 5, 4, 3, 2, 1};
    imprimir(arr3, "Original (invertido)");

    temp1 = arr3;
    bubbleSort(temp1);

    temp1 = arr3;
    selectionSort(temp1);

    temp1 = arr3;
    insertionSort(temp1);

    // CASO 4: Array con duplicados
    cout << "\n--- CASO 4: Array con duplicados ---" << endl;
    vector<int> arr4 = {5, 2, 8, 2, 9, 1, 5, 5};
    imprimir(arr4, "Original (duplicados)");

    temp1 = arr4;
    insertionSort(temp1);
    imprimir(temp1, "Resultado");
}

// ===== VISUALIZACIÓN PASO A PASO =====
void visualizarBubbleSort() {
    cout << "\n\n=== VISUALIZACIÓN BUBBLE SORT PASO A PASO ===" << endl;
    vector<int> arr = {5, 2, 8, 1, 9};
    int n = arr.size();

    cout << "Array inicial: ";
    imprimir(arr);

    for (int i = 0; i < n - 1; i++) {
        cout << "\nPasada " << (i + 1) << ":" << endl;
        bool huboIntercambio = false;

        for (int j = 0; j < n - i - 1; j++) {
            cout << "  Comparar " << arr[j] << " y " << arr[j + 1] << ": ";

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cout << "Intercambiar → ";
                huboIntercambio = true;
            } else {
                cout << "No intercambiar → ";
            }
            imprimir(arr);
        }

        if (!huboIntercambio) {
            cout << "  ✅ Ya está ordenado, salir temprano" << endl;
            break;
        }
    }

    cout << "\nArray final: ";
    imprimir(arr);
}

int main() {
    cout << "🎯 UNIDAD 5.1: ALGORITMOS DE ORDENAMIENTO O(n²)" << endl;
    cout << "===============================================" << endl;

    analizarAlgoritmos();
    pruebasComparativas();
    visualizarBubbleSort();

    cout << "\n\n📝 RESUMEN PARA EL EXAMEN:" << endl;
    cout << "• Bubble Sort: Compara adyacentes, burbujea el mayor" << endl;
    cout << "• Selection Sort: Busca mínimo, intercambia con posición actual" << endl;
    cout << "• Insertion Sort: Inserta elemento en posición correcta (como cartas)" << endl;
    cout << "• MEJOR en práctica: Insertion Sort para arrays pequeños" << endl;
    cout << "• Todos son in-place: O(1) espacio extra" << endl;
    cout << "• Estables: Bubble e Insertion (mantienen orden relativo)" << endl;

    return 0;
}

/*
CONCEPTOS CLAVE PARA EL EXAMEN:

1. ESTABILIDAD:
   - Estable: mantiene orden relativo de elementos iguales
   - Bubble e Insertion: estables
   - Selection: NO estable (puede cambiar orden)

2. IN-PLACE:
   - Todos usan O(1) espacio extra
   - No necesitan arrays auxiliares

3. ADAPTIVE:
   - Insertion y Bubble (optimizado): O(n) si casi ordenado
   - Selection: siempre O(n²)

4. NÚMERO DE COMPARACIONES VS INTERCAMBIOS:
   - Bubble: muchas comparaciones, muchos intercambios
   - Selection: muchas comparaciones, POCOS intercambios O(n)
   - Insertion: depende del caso

5. CASOS DE PRUEBA IMPORTANTES:
   - Ya ordenado (mejor caso)
   - Invertido (peor caso)
   - Aleatorio (caso promedio)
   - Con duplicados (probar estabilidad)

6. CUÁNDO USAR EN EXAMEN:
   Si te preguntan "mejor algoritmo para...":
   - Arrays pequeños (n<50): Insertion Sort
   - Minimizar escrituras: Selection Sort
   - Necesitas estabilidad: Bubble o Insertion
   - Array casi ordenado: Insertion Sort
*/
