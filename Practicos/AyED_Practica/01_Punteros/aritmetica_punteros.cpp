//
// Created by facuh on 9/27/25.
//
#include <iostream>
using namespace std;

// ===== UNIDAD 1.4: ARITMÉTICA DE PUNTEROS =====

void ejemploBasicoAritmetica() {
    cout << "\n=== ARITMÉTICA BÁSICA DE PUNTEROS ===" << endl;

    int arreglo[] = {10, 20, 30, 40, 50};
    int* ptr = arreglo;  // ptr apunta al primer elemento

    cout << "Arreglo: ";
    for (int i = 0; i < 5; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    cout << "\nRecorrido con aritmética de punteros:" << endl;
    cout << "ptr apunta a: " << *ptr << " (dirección: " << ptr << ")" << endl;

    ptr++;  // Avanza al siguiente elemento
    cout << "ptr++ apunta a: " << *ptr << " (dirección: " << ptr << ")" << endl;

    ptr += 2;  // Avanza 2 elementos más
    cout << "ptr += 2 apunta a: " << *ptr << " (dirección: " << ptr << ")" << endl;

    ptr--;  // Retrocede un elemento
    cout << "ptr-- apunta a: " << *ptr << " (dirección: " << ptr << ")" << endl;

    // Volver al inicio
    ptr = arreglo;
    cout << "\nVolviendo al inicio: " << *ptr << endl;
}

void ejemploRecorridoConPunteros() {
    cout << "\n=== RECORRIDO DE ARREGLO CON PUNTEROS ===" << endl;

    int numeros[] = {100, 200, 300, 400, 500};
    int tamaño = 5;

    cout << "\nMétodo 1 - Con índices:" << endl;
    for (int i = 0; i < tamaño; i++) {
        cout << "numeros[" << i << "] = " << numeros[i] << endl;
    }

    cout << "\nMétodo 2 - Con aritmética de punteros:" << endl;
    int* ptr = numeros;
    for (int i = 0; i < tamaño; i++) {
        cout << "*(ptr + " << i << ") = " << *(ptr + i) << endl;
    }

    cout << "\nMétodo 3 - Incrementando el puntero:" << endl;
    ptr = numeros;  // Resetear al inicio
    for (int i = 0; i < tamaño; i++) {
        cout << "*ptr = " << *ptr << ", dirección: " << ptr << endl;
        ptr++;  // Avanzar al siguiente elemento
    }
}

void ejemploEquivalencias() {
    cout << "\n=== EQUIVALENCIAS IMPORTANTES ===" << endl;

    int datos[] = {1, 2, 3, 4, 5};
    int* p = datos;

    cout << "Arreglo: ";
    for (int i = 0; i < 5; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;

    cout << "\nEquivalencias (todas dan el mismo resultado):" << endl;
    cout << "datos[2] = " << datos[2] << endl;
    cout << "*(datos + 2) = " << *(datos + 2) << endl;
    cout << "p[2] = " << p[2] << endl;
    cout << "*(p + 2) = " << *(p + 2) << endl;

    cout << "\nDiferencias de direcciones:" << endl;
    cout << "datos = " << datos << endl;
    cout << "datos + 1 = " << (datos + 1) << endl;
    cout << "datos + 2 = " << (datos + 2) << endl;
    cout << "Diferencia en bytes: " << (char*)(datos + 1) - (char*)datos
         << " (sizeof(int))" << endl;
}

// EJERCICIO TÍPICO DE EXAMEN: Función con punteros
void imprimirArreglo(int* arr, int tamaño) {
    cout << "Imprimiendo con puntero: ";
    for (int i = 0; i < tamaño; i++) {
        cout << *(arr + i) << " ";  // Equivale a arr[i]
    }
    cout << endl;
}

void encontrarMaximo(int* arr, int tamaño, int* maximo, int* posicion) {
    *maximo = *arr;  // Primer elemento como máximo inicial
    *posicion = 0;

    for (int i = 1; i < tamaño; i++) {
        if (*(arr + i) > *maximo) {
            *maximo = *(arr + i);
            *posicion = i;
        }
    }
}

void ejerciciosFunciones() {
    cout << "\n=== EJERCICIOS CON FUNCIONES Y PUNTEROS ===" << endl;

    int numeros[] = {45, 23, 78, 12, 89, 34};
    int tamaño = 6;

    cout << "Arreglo original: ";
    imprimirArreglo(numeros, tamaño);

    int maximo, posicion;
    encontrarMaximo(numeros, tamaño, &maximo, &posicion);

    cout << "Máximo: " << maximo << " en posición " << posicion << endl;
}

// EJERCICIO TÍPICO: Invertir arreglo con punteros
void invertirArreglo(int* inicio, int* fin) {
    while (inicio < fin) {
        // Intercambiar elementos
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;

        // Mover punteros hacia el centro
        inicio++;
        fin--;
    }
}

void ejercicioInvertir() {
    cout << "\n=== EJERCICIO: INVERTIR ARREGLO ===" << endl;

    int numeros[] = {1, 2, 3, 4, 5, 6};
    int tamaño = 6;

    cout << "Arreglo original: ";
    for (int i = 0; i < tamaño; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Llamar función con puntero al inicio y al final
    invertirArreglo(numeros, numeros + tamaño - 1);

    cout << "Arreglo invertido: ";
    for (int i = 0; i < tamaño; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
}

void ejemploDiferenciaTipos() {
    cout << "\n=== ARITMÉTICA CON DIFERENTES TIPOS ===" << endl;

    // Con enteros (4 bytes cada uno)
    int enteros[] = {10, 20, 30};
    int* ptrInt = enteros;

    // Con chars (1 byte cada uno)
    char caracteres[] = {'A', 'B', 'C'};
    char* ptrChar = caracteres;

    cout << "Enteros:" << endl;
    cout << "ptrInt = " << (void*)ptrInt << endl;
    cout << "ptrInt + 1 = " << (void*)(ptrInt + 1) << endl;
    cout << "Diferencia: " << (char*)(ptrInt + 1) - (char*)ptrInt << " bytes" << endl;

    cout << "\nCaracteres:" << endl;
    cout << "ptrChar = " << (void*)ptrChar << endl;
    cout << "ptrChar + 1 = " << (void*)(ptrChar + 1) << endl;
    cout << "Diferencia: " << (ptrChar + 1) - ptrChar << " bytes" << endl;
}

int main() {
    cout << "🎯 ARITMÉTICA DE PUNTEROS - CONCEPTOS DE EXAMEN" << endl;
    cout << "===============================================" << endl;

    ejemploBasicoAritmetica();
    ejemploRecorridoConPunteros();
    ejemploEquivalencias();
    ejerciciosFunciones();
    ejercicioInvertir();
    ejemploDiferenciaTipos();

    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • ptr++ avanza al siguiente elemento" << endl;
    cout << "   • ptr + n avanza n elementos" << endl;
    cout << "   • arr[i] ≡ *(arr + i)" << endl;
    cout << "   • Los punteros 'saben' el tamaño del tipo" << endl;
    cout << "   • Se puede usar aritmética para recorrer" << endl;
    cout << "   • inicio < fin para comparar posiciones" << endl;
    cout << "   • Útil para algoritmos in-place" << endl;

    return 0;
}