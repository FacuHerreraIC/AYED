#include <iostream>
using namespace std;

// ===== LABORATORIO AYED - PRUEBAS RÁPIDAS =====
// Usá este archivo para probar conceptos rápidamente

int main() {
    cout << "🚀 ¡Laboratorio AyED funcionando!" << endl;
    cout << "================================" << endl;

    // Esto es practica de la clase 1:

    char miString[9] = {'a','c','b','d','e','f','g','h','i'};
    for (int i = 0; i < 9; i++) {
        cout << miString[i];
    }
    cout << endl;

    int miArray[5] = {1,11,3,4,5};
    cout << miArray << endl;
    cout << *miArray << endl;
    cout << miArray[0] << endl;
    cout << *(miArray+3) << endl;
    cout << &miArray << endl;
    cout << &miArray+1 << endl;
}