//
// Created by facuh on 9/27/25.
//
#include <iostream>
using namespace std;

// ===== UNIDAD 1.1: VARIABLES, MEMORIA Y DIRECCIONES =====

void ejemploBasicoPunteros() {
    cout << "\n=== PUNTEROS BÁSICOS ===" << endl;

    // Variable normal
    int numero = 42;

    // Puntero que apunta a la variable
    int* ptr = &numero;  // & = operador de dirección

    cout << "Variable 'numero': " << numero << endl;
    cout << "Dirección de 'numero': " << &numero << endl;
    cout << "Valor del puntero 'ptr': " << ptr << endl;
    cout << "Valor al que apunta 'ptr': " << *ptr << endl;  // * = operador de desreferencia

    // Modificar a través del puntero
    *ptr = 100;
    cout << "Después de modificar con *ptr = 100:" << endl;
    cout << "numero = " << numero << endl;
}

void ejemploPunterosAVariables() {
    cout << "\n=== PUNTEROS A DIFERENTES TIPOS ===" << endl;

    int entero = 10;
    float decimal = 3.14f;
    char caracter = 'A';

    int* ptrInt = &entero;
    float* ptrFloat = &decimal;
    char* ptrChar = &caracter;

    cout << "Entero: " << *ptrInt << " en dirección: " << ptrInt << endl;
    cout << "Float: " << *ptrFloat << " en dirección: " << ptrFloat << endl;
    cout << "Char: " << *ptrChar << " en dirección: " << (void*)ptrChar << endl;

    // Tamaños de los punteros (todos iguales en la misma arquitectura)
    cout << "\nTamaños de punteros:" << endl;
    cout << "sizeof(int*): " << sizeof(int*) << " bytes" << endl;
    cout << "sizeof(float*): " << sizeof(float*) << " bytes" << endl;
    cout << "sizeof(char*): " << sizeof(char*) << " bytes" << endl;
}

void ejemploPunterosNulos() {
    cout << "\n=== PUNTEROS NULOS Y VALIDACIÓN ===" << endl;

    int* ptrNulo = nullptr;  // C++11 style
    int* ptrNulo2 = NULL;    // C style

    cout << "Puntero nulo (nullptr): " << ptrNulo << endl;
    cout << "Puntero nulo (NULL): " << ptrNulo2 << endl;

    // SIEMPRE validar antes de desreferenciar
    if (ptrNulo != nullptr) {
        cout << "Valor: " << *ptrNulo << endl;
    } else {
        cout << "⚠️  Puntero nulo - no se puede desreferenciar" << endl;
    }

    // Ejemplo con puntero válido
    int valor = 123;
    int* ptrValido = &valor;

    if (ptrValido != nullptr) {
        cout << "Puntero válido, valor: " << *ptrValido << endl;
    }
}

// EJERCICIO TÍPICO DE EXAMEN
void ejercicioIntercambio() {
    cout << "\n=== EJERCICIO: INTERCAMBIO CON PUNTEROS ===" << endl;

    int a = 5, b = 10;
    cout << "Antes: a = " << a << ", b = " << b << endl;

    // Intercambio usando punteros
    int* ptrA = &a;
    int* ptrB = &b;

    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    cout << "Después: a = " << a << ", b = " << b << endl;
}

int main() {
    cout << "🎯 PUNTEROS BÁSICOS - EJERCICIOS DE EXAMEN" << endl;
    cout << "==========================================" << endl;

    ejemploBasicoPunteros();
    ejemploPunterosAVariables();
    ejemploPunterosNulos();
    ejercicioIntercambio();

    cout << "\n✅ Conceptos clave dominados:" << endl;
    cout << "   • Declaración de punteros: int* ptr" << endl;
    cout << "   • Obtener dirección: &variable" << endl;
    cout << "   • Desreferenciar: *puntero" << endl;
    cout << "   • Validación: ptr != nullptr" << endl;
    cout << "   • Modificación indirecta" << endl;

    return 0;
}