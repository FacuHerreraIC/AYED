//
// Created by facuh on 9/27/25.
//
#include <iostream>
using namespace std;

// ===== UNIDAD 1.2: PASO DE PARÁMETROS MEDIANTE PUNTEROS =====

// 1. PASO POR VALOR (NO modifica la variable original)
void pasoPorValor(int x) {
    cout << "Dentro de pasoPorValor - antes: " << x << endl;
    x = 999;  // Solo modifica la copia local
    cout << "Dentro de pasoPorValor - después: " << x << endl;
}

// 2. PASO POR PUNTERO (SÍ modifica la variable original)
void pasoPorPuntero(int* x) {
    cout << "Dentro de pasoPorPuntero - antes: " << *x << endl;
    *x = 999;  // Modifica la variable original
    cout << "Dentro de pasoPorPuntero - después: " << *x << endl;
}

// 3. PASO POR REFERENCIA (SÍ modifica la variable original) - C++ style
void pasoPorReferencia(int& x) {
    cout << "Dentro de pasoPorReferencia - antes: " << x << endl;
    x = 999;  // Modifica la variable original (sintaxis más limpia)
    cout << "Dentro de pasoPorReferencia - después: " << x << endl;
}

void demostrarPasoParametros() {
    cout << "\n=== COMPARACIÓN DE PASO DE PARÁMETROS ===" << endl;

    int numero1 = 42, numero2 = 42, numero3 = 42;

    cout << "\n--- PASO POR VALOR ---" << endl;
    cout << "Antes de llamar: " << numero1 << endl;
    pasoPorValor(numero1);
    cout << "Después de llamar: " << numero1 << " (NO cambió)" << endl;

    cout << "\n--- PASO POR PUNTERO ---" << endl;
    cout << "Antes de llamar: " << numero2 << endl;
    pasoPorPuntero(&numero2);  // Pasamos la dirección
    cout << "Después de llamar: " << numero2 << " (SÍ cambió)" << endl;

    cout << "\n--- PASO POR REFERENCIA ---" << endl;
    cout << "Antes de llamar: " << numero3 << endl;
    pasoPorReferencia(numero3);  // Sintaxis más limpia
    cout << "Después de llamar: " << numero3 << " (SÍ cambió)" << endl;
}

// EJERCICIO TÍPICO DE EXAMEN: Intercambio de variables
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void intercambiarPorReferencia(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void ejercicioIntercambio() {
    cout << "\n=== EJERCICIO: FUNCIÓN DE INTERCAMBIO ===" << endl;

    int x = 10, y = 20;
    cout << "Antes: x = " << x << ", y = " << y << endl;

    intercambiar(&x, &y);  // Pasamos las direcciones
    cout << "Después (punteros): x = " << x << ", y = " << y << endl;

    // Restauramos para probar con referencias
    x = 10; y = 20;
    cout << "\nAntes: x = " << x << ", y = " << y << endl;
    intercambiarPorReferencia(x, y);  // Sintaxis más simple
    cout << "Después (referencias): x = " << x << ", y = " << y << endl;
}

// EJERCICIO TÍPICO: Modificar múltiples valores
void calcularRectangulo(int largo, int ancho, int* area, int* perimetro) {
    *area = largo * ancho;
    *perimetro = 2 * (largo + ancho);
}

void ejercicioMultiplesRetornos() {
    cout << "\n=== EJERCICIO: MÚLTIPLES VALORES DE RETORNO ===" << endl;

    int largo = 5, ancho = 3;
    int area, perimetro;

    calcularRectangulo(largo, ancho, &area, &perimetro);

    cout << "Rectángulo " << largo << "x" << ancho << ":" << endl;
    cout << "Área: " << area << endl;
    cout << "Perímetro: " << perimetro << endl;
}

// EJERCICIO TÍPICO: Trabajar con arreglos
void modificarArreglo(int arr[], int tamaño) {
    // Los arreglos SIEMPRE se pasan por referencia (como punteros)
    cout << "Modificando arreglo..." << endl;
    for (int i = 0; i < tamaño; i++) {
        arr[i] *= 2;  // Duplicamos cada elemento
    }
}

void ejercicioArreglos() {
    cout << "\n=== EJERCICIO: ARREGLOS Y PUNTEROS ===" << endl;

    int numeros[] = {1, 2, 3, 4, 5};
    int tamaño = 5;

    cout << "Arreglo original: ";
    for (int i = 0; i < tamaño; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    modificarArreglo(numeros, tamaño);

    cout << "Arreglo modificado: ";
    for (int i = 0; i < tamaño; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Demostrar que arr[] es equivalente a *arr
    cout << "numeros[0] = " << numeros[0] << endl;
    cout << "*numeros = " << *numeros << " (equivalente)" << endl;
}

int main() {
    cout << "🎯 PASO DE PARÁMETROS CON PUNTEROS" << endl;
    cout << "===================================" << endl;

    demostrarPasoParametros();
    ejercicioIntercambio();
    ejercicioMultiplesRetornos();
    ejercicioArreglos();

    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • Paso por valor: NO modifica original" << endl;
    cout << "   • Paso por puntero: func(int* x) - SÍ modifica" << endl;
    cout << "   • Paso por referencia: func(int& x) - SÍ modifica" << endl;
    cout << "   • Arreglos siempre se pasan como punteros" << endl;
    cout << "   • Para modificar: usa punteros o referencias" << endl;

    return 0;
}