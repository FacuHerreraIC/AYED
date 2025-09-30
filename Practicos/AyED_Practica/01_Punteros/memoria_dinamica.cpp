//
// Created by facuh on 9/27/25.
//
#include <iostream>
#include <cstdlib>  // Para malloc, free
using namespace std;

// ===== UNIDAD 1.3: USO DINÁMICO DE LA MEMORIA =====

void ejemploNewDelete() {
    cout << "\n=== NEW / DELETE (C++ Style) ===" << endl;

    // Reservar memoria para un entero
    int* numero = new int(42);  // new + valor inicial
    cout << "Valor: " << *numero << endl;
    cout << "Dirección: " << numero << endl;

    // Modificar el valor
    *numero = 100;
    cout << "Nuevo valor: " << *numero << endl;

    // SIEMPRE liberar la memoria
    delete numero;
    cout << "Memoria liberada" << endl;

    // Buena práctica: poner en nullptr después de delete
    numero = nullptr;
}

void ejemploMallocFree() {
    cout << "\n=== MALLOC / FREE (C Style) ===" << endl;

    // Reservar memoria para un entero
    int* numero = (int*)malloc(sizeof(int));

    if (numero != nullptr) {  // SIEMPRE verificar si malloc funcionó
        *numero = 123;
        cout << "Valor: " << *numero << endl;
        cout << "Dirección: " << numero << endl;

        // Liberar memoria
        free(numero);
        cout << "Memoria liberada" << endl;
        numero = nullptr;
    } else {
        cout << "Error: No se pudo reservar memoria" << endl;
    }
}

void ejemploArreglosDinamicos() {
    cout << "\n=== ARREGLOS DINÁMICOS ===" << endl;

    int tamaño;
    cout << "¿Cuántos números querés almacenar? ";
    cin >> tamaño;

    // Reservar memoria para el arreglo
    int* arreglo = new int[tamaño];

    // Llenar el arreglo
    cout << "Ingresá " << tamaño << " números:" << endl;
    for (int i = 0; i < tamaño; i++) {
        cout << "Número " << (i+1) << ": ";
        cin >> arreglo[i];
    }

    // Mostrar el arreglo
    cout << "\nTu arreglo: ";
    for (int i = 0; i < tamaño; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // Calcular suma
    int suma = 0;
    for (int i = 0; i < tamaño; i++) {
        suma += arreglo[i];
    }
    cout << "Suma total: " << suma << endl;

    // IMPORTANTE: delete[] para arreglos
    delete[] arreglo;
    cout << "Memoria del arreglo liberada" << endl;
}

// EJERCICIO TÍPICO DE EXAMEN: Redimensionar arreglo
int* redimensionar(int* arregloOriginal, int tamañoOriginal, int nuevoTamaño) {
    cout << "\nRedimensionando arreglo de " << tamañoOriginal
         << " a " << nuevoTamaño << " elementos" << endl;

    // Crear nuevo arreglo más grande
    int* nuevoArreglo = new int[nuevoTamaño];

    // Copiar elementos del arreglo original
    int elementosACopiar = min(tamañoOriginal, nuevoTamaño);
    for (int i = 0; i < elementosACopiar; i++) {
        nuevoArreglo[i] = arregloOriginal[i];
    }

    // Si el nuevo arreglo es más grande, inicializar en 0
    for (int i = elementosACopiar; i < nuevoTamaño; i++) {
        nuevoArreglo[i] = 0;
    }

    // Liberar el arreglo original
    delete[] arregloOriginal;

    return nuevoArreglo;
}

void ejercicioRedimension() {
    cout << "\n=== EJERCICIO: REDIMENSIONAR ARREGLO ===" << endl;

    // Crear arreglo inicial
    int tamaño = 3;
    int* numeros = new int[tamaño] {10, 20, 30};

    cout << "Arreglo original: ";
    for (int i = 0; i < tamaño; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Redimensionar
    int nuevoTamaño = 5;
    numeros = redimensionar(numeros, tamaño, nuevoTamaño);

    cout << "Arreglo redimensionado: ";
    for (int i = 0; i < nuevoTamaño; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    delete[] numeros;
}

// EJERCICIO TÍPICO: Memory leaks
void ejemploMemoryLeak() {
    cout << "\n=== ERRORES COMUNES: MEMORY LEAKS ===" << endl;

    cout << "\n❌ MAL - Memory leak:" << endl;
    cout << "int* ptr = new int(100);" << endl;
    cout << "// ¡Nunca hicimos delete!" << endl;

    cout << "\n✅ BIEN - Liberación correcta:" << endl;
    int* ptr = new int(100);
    cout << "Valor: " << *ptr << endl;
    delete ptr;
    ptr = nullptr;  // Evita accesos accidentales
    cout << "Memoria liberada correctamente" << endl;
}

void ejemploErroresComunes() {
    cout << "\n=== ERRORES COMUNES CON MEMORIA DINÁMICA ===" << endl;

    cout << "\n1. Double free (liberar dos veces):" << endl;
    int* ptr1 = new int(50);
    delete ptr1;
    // delete ptr1;  // ¡ERROR! Ya fue liberada
    ptr1 = nullptr;  // Esto evita el error

    cout << "\n2. Usar memoria después de liberarla:" << endl;
    int* ptr2 = new int(75);
    delete ptr2;
    // cout << *ptr2;  // ¡ERROR! Memoria ya liberada
    ptr2 = nullptr;

    cout << "\n3. No verificar si malloc funcionó:" << endl;
    int* ptr3 = (int*)malloc(sizeof(int));
    if (ptr3 != nullptr) {  // SIEMPRE verificar
        *ptr3 = 200;
        cout << "malloc exitoso: " << *ptr3 << endl;
        free(ptr3);
    } else {
        cout << "malloc falló" << endl;
    }

    cout << "\nTodos los errores evitados correctamente ✅" << endl;
}

int main() {
    cout << "🎯 MEMORIA DINÁMICA - CONCEPTOS DE EXAMEN" << endl;
    cout << "=========================================" << endl;

    ejemploNewDelete();
    ejemploMallocFree();

    cout << "\n⚠️  Para el ejemplo de arreglos dinámicos," << endl;
    cout << "vas a necesitar ingresar números. ¿Continuar? (s/n): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        ejemploArreglosDinamicos();
    }

    ejercicioRedimension();
    ejemploMemoryLeak();
    ejemploErroresComunes();

    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • new/delete para C++" << endl;
    cout << "   • malloc/free para C" << endl;
    cout << "   • new[] / delete[] para arreglos" << endl;
    cout << "   • SIEMPRE verificar si malloc != nullptr" << endl;
    cout << "   • SIEMPRE liberar memoria reservada" << endl;
    cout << "   • ptr = nullptr después de delete" << endl;
    cout << "   • Evitar double free y memory leaks" << endl;

    return 0;
}