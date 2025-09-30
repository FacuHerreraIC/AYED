//
// Created by facuh on 9/27/25.
//
#include <iostream>
using namespace std;

// ===== UNIDAD 3.3: PILAS (STACK) - LIFO =====
// Last In, First Out - El último que entra es el primero que sale

struct NodoPila {
    int dato;
    NodoPila* siguiente;

    NodoPila(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

class Pila {
private:
    NodoPila* tope;  // Puntero al elemento del tope
    int tamaño;

public:
    // Constructor
    Pila() {
        tope = nullptr;
        tamaño = 0;
    }

    // Destructor
    ~Pila() {
        while (!estaVacia()) {
            pop();
        }
    }

    // PUSH - Insertar elemento en el tope O(1)
    void push(int valor) {
        NodoPila* nuevo = new NodoPila(valor);
        nuevo->siguiente = tope;
        tope = nuevo;
        tamaño++;
        cout << "Push: " << valor << " agregado al tope" << endl;
    }

    // POP - Quitar elemento del tope O(1)
    int pop() {
        if (estaVacia()) {
            cout << "❌ Error: Pila vacía (stack underflow)" << endl;
            return -1;
        }

        int valor = tope->dato;
        NodoPila* temp = tope;
        tope = tope->siguiente;
        delete temp;
        tamaño--;
        cout << "Pop: " << valor << " removido del tope" << endl;
        return valor;
    }

    // TOP/PEEK - Ver elemento del tope sin quitarlo O(1)
    int top() {
        if (estaVacia()) {
            cout << "❌ Error: Pila vacía" << endl;
            return -1;
        }
        return tope->dato;
    }

    // Verificar si está vacía
    bool estaVacia() {
        return tope == nullptr;
    }

    // Obtener tamaño
    int obtenerTamaño() {
        return tamaño;
    }

    // Mostrar pila completa (desde tope hacia abajo)
    void mostrar() {
        if (estaVacia()) {
            cout << "Pila vacía: []" << endl;
            return;
        }

        cout << "Pila (tope -> base): [";
        NodoPila* actual = tope;
        while (actual != nullptr) {
            cout << actual->dato;
            if (actual->siguiente != nullptr) {
                cout << " | ";
            }
            actual = actual->siguiente;
        }
        cout << "] (tamaño: " << tamaño << ")" << endl;
    }
};

// EJERCICIO TÍPICO DE EXAMEN: Verificar paréntesis balanceados
bool verificarParentesis(string expresion) {
    Pila pila;

    cout << "\nVerificando: " << expresion << endl;

    for (char c : expresion) {
        if (c == '(' || c == '[' || c == '{') {
            pila.push(c);
            cout << "Encontrado '" << c << "' - push a pila" << endl;
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (pila.estaVacia()) {
                cout << "❌ Error: '" << c << "' sin apertura" << endl;
                return false;
            }

            char ultimo = pila.top();
            pila.pop();

            bool coincide = (c == ')' && ultimo == '(') ||
                           (c == ']' && ultimo == '[') ||
                           (c == '}' && ultimo == '{');

            if (!coincide) {
                cout << "❌ Error: '" << ultimo << "' no coincide con '" << c << "'" << endl;
                return false;
            }
            cout << "Encontrado '" << c << "' - coincide con '" << ultimo << "'" << endl;
        }
    }

    bool balanceado = pila.estaVacia();
    cout << (balanceado ? "✅ Paréntesis balanceados" : "❌ Paréntesis no balanceados") << endl;
    return balanceado;
}

// EJERCICIO TÍPICO: Evaluar expresión postfija (notación polaca)
int evaluarPostfija(string expresion) {
    Pila pila;
    cout << "\nEvaluando expresión postfija: " << expresion << endl;

    for (int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];

        if (c == ' ') continue;  // Ignorar espacios

        if (isdigit(c)) {
            // Es un número
            int num = c - '0';  // Convertir char a int
            pila.push(num);
            cout << "Número " << num << " -> push" << endl;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Es un operador
            if (pila.obtenerTamaño() < 2) {
                cout << "❌ Error: No hay suficientes operandos" << endl;
                return -1;
            }

            int b = pila.top(); pila.pop();
            int a = pila.top(); pila.pop();
            int resultado;

            switch (c) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/':
                    if (b == 0) {
                        cout << "❌ Error: División por cero" << endl;
                        return -1;
                    }
                    resultado = a / b;
                    break;
            }

            cout << a << " " << c << " " << b << " = " << resultado << " -> push" << endl;
            pila.push(resultado);
        }
    }

    if (pila.obtenerTamaño() != 1) {
        cout << "❌ Error: Expresión inválida" << endl;
        return -1;
    }

    return pila.top();
}

// EJERCICIO TÍPICO: Invertir string con pila
string invertirString(string texto) {
    Pila pila;

    // Push todos los caracteres
    for (char c : texto) {
        pila.push(c);
    }

    // Pop para formar string invertido
    string invertido = "";
    while (!pila.estaVacia()) {
        invertido += (char)pila.pop();
    }

    return invertido;
}

void ejerciciosBasicos() {
    cout << "\n=== EJERCICIOS BÁSICOS DE PILA ===" << endl;

    Pila pila;

    cout << "\n1. Operaciones básicas:" << endl;
    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.mostrar();

    cout << "\nTope actual: " << pila.top() << endl;

    cout << "\n2. Hacer pop:" << endl;
    pila.pop();
    pila.mostrar();

    cout << "\n3. Más operaciones:" << endl;
    pila.push(40);
    pila.push(50);
    pila.mostrar();

    cout << "¿Está vacía? " << (pila.estaVacia() ? "Sí" : "No") << endl;
    cout << "Tamaño: " << pila.obtenerTamaño() << endl;
}

void ejerciciosAvanzados() {
    cout << "\n=== EJERCICIOS AVANZADOS ===" << endl;

    cout << "\n1. Verificar paréntesis balanceados:" << endl;
    verificarParentesis("((()))");
    verificarParentesis("([{}])");
    verificarParentesis("((()]");
    verificarParentesis("([)]");

    cout << "\n2. Evaluar expresión postfija:" << endl;
    // "5 3 + 2 *" = (5 + 3) * 2 = 16
    int resultado = evaluarPostfija("5 3 + 2 *");
    cout << "Resultado final: " << resultado << endl;

    cout << "\n3. Invertir string:" << endl;
    string original = "ALGORITMOS";
    string invertido = invertirString(original);
    cout << "Original: " << original << endl;
    cout << "Invertido: " << invertido << endl;
}

// Implementación con arreglo (alternativa común en exámenes)
class PilaArreglo {
private:
    static const int MAXSIZE = 100;
    int elementos[MAXSIZE];
    int tope;

public:
    PilaArreglo() {
        tope = -1;  // -1 indica pila vacía
    }

    bool push(int valor) {
        if (tope >= MAXSIZE - 1) {
            cout << "❌ Stack overflow" << endl;
            return false;
        }
        elementos[++tope] = valor;
        return true;
    }

    int pop() {
        if (tope < 0) {
            cout << "❌ Stack underflow" << endl;
            return -1;
        }
        return elementos[tope--];
    }

    int top() {
        if (tope < 0) return -1;
        return elementos[tope];
    }

    bool estaVacia() {
        return tope < 0;
    }

    void mostrar() {
        cout << "Pila (arreglo): [";
        for (int i = tope; i >= 0; i--) {
            cout << elementos[i];
            if (i > 0) cout << " | ";
        }
        cout << "]" << endl;
    }
};

void ejemploPilaArreglo() {
    cout << "\n=== PILA CON ARREGLO (ALTERNATIVA) ===" << endl;

    PilaArreglo pila;
    pila.push(100);
    pila.push(200);
    pila.push(300);
    pila.mostrar();

    cout << "Pop: " << pila.pop() << endl;
    pila.mostrar();
}

int main() {
    cout << "🎯 PILAS (STACK) - CONCEPTOS DE EXAMEN" << endl;
    cout << "=====================================" << endl;

    ejerciciosBasicos();
    ejerciciosAvanzados();
    ejemploPilaArreglo();

    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • LIFO: Last In, First Out" << endl;
    cout << "   • Operaciones básicas: push(), pop(), top()" << endl;
    cout << "   • push() y pop() son O(1)" << endl;
    cout << "   • Aplicaciones: paréntesis, expresiones, recursión" << endl;
    cout << "   • Stack overflow: pila llena" << endl;
    cout << "   • Stack underflow: pila vacía" << endl;
    cout << "   • Implementación: lista enlazada o arreglo" << endl;

    return 0;
}