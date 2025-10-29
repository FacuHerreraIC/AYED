#include <iostream>
using namespace std;

// ===== LABORATORIO AYED - PRUEBAS RÁPIDAS =====
// Usá este archivo para probar conceptos rápidamente

int main() {
    cout << "🚀 ¡Laboratorio AyED funcionando!" << endl;
    cout << "================================" << endl;

    // Esto es practica de la clase 1:

    for (int i = 0; i < 10; ++i) {
        int* ptr = new int;  // Reservar
        *ptr = i;
        std::cout << "Puntero creado. Valor: " << *ptr << std::endl;
        delete ptr;  // ✅ LIBERAR memoria en cada iteración
    }
    return 0;
}