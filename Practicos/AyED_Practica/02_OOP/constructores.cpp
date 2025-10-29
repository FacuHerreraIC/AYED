//
// Created by facuh on 9/27/25.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ===== UNIDAD 2.4: CONSTRUCTORES =====

class Vehiculo {
private:
    string marca;
    string modelo;
    int año;
    double precio;

public:
    // 1. CONSTRUCTOR POR DEFECTO (sin parámetros)
    Vehiculo() {
        cout << "🚗 Constructor por defecto llamado" << endl;
        marca = "Sin marca";
        modelo = "Sin modelo";
        año = 2000;
        precio = 0.0;
    }

    // 2. CONSTRUCTOR CON PARÁMETROS
    Vehiculo(string m, string mod, int a, double p) {
        cout << "🚗 Constructor con parámetros llamado para " << m << " " << mod << endl;
        marca = m;
        modelo = mod;
        año = a;
        precio = p;
    }

    // 3. CONSTRUCTOR CON PARÁMETROS PARCIALES
    Vehiculo(string m, string mod) {
        cout << "🚗 Constructor parcial llamado para " << m << " " << mod << endl;
        marca = m;
        modelo = mod;
        año = 2020;        // Valores por defecto
        precio = 15000.0;
    }

    // 4. CONSTRUCTOR DE COPIA
    Vehiculo(const Vehiculo& otro) {
        cout << "🚗 Constructor de copia llamado" << endl;
        marca = otro.marca;
        modelo = otro.modelo;
        año = otro.año;
        precio = otro.precio;
    }

    // 5. DESTRUCTOR
    ~Vehiculo() {
        cout << "🗑️ Destructor llamado para " << marca << " " << modelo << endl;
    }

    // Getters
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getAño() const { return año; }
    double getPrecio() const { return precio; }

    // Setters
    void setMarca(string m) { marca = m; }
    void setModelo(string mod) { modelo = mod; }
    void setAño(int a) {
        if (a >= 1900 && a <= 2024) {
            año = a;
        } else {
            cout << "❌ Año inválido" << endl;
        }
    }
    void setPrecio(double p) {
        if (p >= 0) {
            precio = p;
        } else {
            cout << "❌ Precio inválido" << endl;
        }
    }

    // Metodo para mostrar información
    void mostrarInfo() const {
        cout << "Vehículo: " << marca << " " << modelo
             << " (" << año << ") - $" << precio << endl;
    }

    // Metodo para calcular depreciación
    double calcularValorActual(int añoActual = 2024) const {
        int antigüedad = añoActual - año;
        double depreciacion = antigüedad * 0.1; // 10% por año
        if (depreciacion > 0.8) depreciacion = 0.8; // Máximo 80%
        return precio * (1.0 - depreciacion);
    }
};

// Ejemplo con lista de inicialización (forma más eficiente)
class Punto {
private:
    int x, y;
    string nombre;

public:
    // Constructor con lista de inicialización
    Punto(int x_val, int y_val, string nom) : x(x_val), y(y_val), nombre(nom) {
        cout << "📍 Punto " << nombre << " creado en (" << x << ", " << y << ")" << endl;
    }

    // Constructor por defecto con lista de inicialización
    Punto() : x(0), y(0), nombre("Origen") {
        cout << "📍 Punto origen creado" << endl;
    }

    // Constructor de copia con lista de inicialización
    Punto(const Punto& otro) : x(otro.x), y(otro.y), nombre(otro.nombre + "_copia") {
        cout << "📍 Copia de punto creada: " << nombre << endl;
    }

    void mostrarInfo() const {
        cout << "Punto " << nombre << ": (" << x << ", " << y << ")" << endl;
    }

    double distanciaAlOrigen() const {
        return sqrt(x * x + y * y);
    }

    ~Punto() {
        cout << "🗑️ Destruyendo punto " << nombre << endl;
    }
};

// Ejemplo con constructor que llama a otro constructor (C++11)
class Circulo {
private:
    double radio;
    string color;
    Punto centro;

public:
    // Constructor principal
    Circulo(double r, string c, Punto centro_p) : radio(r), color(c), centro(centro_p) {
        cout << "⭕ Círculo creado - radio: " << radio << ", color: " << color << endl;
    }

    // Constructor que llama al principal (delegating constructor)
    Circulo(double r) : Circulo(r, "blanco", Punto()) {
        cout << "⭕ Círculo simple creado" << endl;
    }

    // Constructor de copia
    Circulo(const Circulo& otro) : radio(otro.radio), color(otro.color), centro(otro.centro) {
        cout << "⭕ Copia de círculo creada" << endl;
    }

    double area() const {
        return 3.14159 * radio * radio;
    }

    void mostrarInfo() const {
        cout << "Círculo " << color << " con radio " << radio
             << " y área " << area() << endl;
        cout << "Centro: ";
        centro.mostrarInfo();
    }

    ~Circulo() {
        cout << "🗑️ Destruyendo círculo " << color << endl;
    }
};

// Ejemplo de problema sin constructor de copia adecuado
class ArrayDinamico {
private:
    int* datos;
    int tamaño;

public:
    // Constructor
    ArrayDinamico(int tam) {
        tamaño = tam;
        datos = new int[tamaño];
        for (int i = 0; i < tamaño; i++) {
            datos[i] = i * 10; // Inicializar con valores
        }
        cout << "📊 Array dinámico creado con tamaño " << tamaño << endl;
    }

    // Constructor de copia CORRECTO (deep copy)
    ArrayDinamico(const ArrayDinamico& otro) {
        tamaño = otro.tamaño;
        datos = new int[tamaño]; // Nueva memoria
        for (int i = 0; i < tamaño; i++) {
            datos[i] = otro.datos[i]; // Copiar valores
        }
        cout << "📊 Copia profunda del array creada" << endl;
    }

    // Destructor
    ~ArrayDinamico() {
        delete[] datos;
        cout << "🗑️ Array dinámico destruido" << endl;
    }

    void mostrar() const {
        cout << "Array: [";
        for (int i = 0; i < tamaño; i++) {
            cout << datos[i];
            if (i < tamaño - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    void modificar(int indice, int valor) {
        if (indice >= 0 && indice < tamaño) {
            datos[indice] = valor;
        }
    }
};

void ejemplosBasicosConstructores() {
    cout << "\n=== EJEMPLOS BÁSICOS DE CONSTRUCTORES ===" << endl;

    cout << "\n--- Constructor por defecto ---" << endl;
    Vehiculo v1;
    v1.mostrarInfo();

    cout << "\n--- Constructor con parámetros ---" << endl;
    Vehiculo v2("Toyota", "Corolla", 2020, 25000.0);
    v2.mostrarInfo();

    cout << "\n--- Constructor parcial ---" << endl;
    Vehiculo v3("Honda", "Civic");
    v3.mostrarInfo();

    cout << "\n--- Constructor de copia ---" << endl;
    Vehiculo v4 = v2; // O también: Vehiculo v4(v2);
    v4.mostrarInfo();

    cout << "\n--- Calculando depreciación ---" << endl;
    cout << "Valor actual del " << v2.getMarca() << ": $"
         << v2.calcularValorActual() << endl;
}

void ejemploListaInicializacion() {
    cout << "\n=== EJEMPLO LISTA DE INICIALIZACIÓN ===" << endl;

    Punto p1(10, 20, "Casa");
    Punto p2; // Constructor por defecto
    Punto p3 = p1; // Constructor de copia

    p1.mostrarInfo();
    p2.mostrarInfo();
    p3.mostrarInfo();

    cout << "Distancia de Casa al origen: " << p1.distanciaAlOrigen() << endl;
}

void ejemploConstructorDelegante() {
    cout << "\n=== EJEMPLO CONSTRUCTOR DELEGANTE ===" << endl;

    Punto centro(5, 5, "Centro");
    Circulo c1(10.0, "rojo", centro);
    Circulo c2(7.5); // Usa constructor delegante

    c1.mostrarInfo();
    c2.mostrarInfo();
}

void ejemploCopiaSuperficialVsProfunda() {
    cout << "\n=== COPIA SUPERFICIAL VS PROFUNDA ===" << endl;

    cout << "\n--- Creando array original ---" << endl;
    ArrayDinamico arr1(5);
    arr1.mostrar();

    cout << "\n--- Creando copia (deep copy) ---" << endl;
    ArrayDinamico arr2 = arr1;
    arr2.mostrar();

    cout << "\n--- Modificando original ---" << endl;
    arr1.modificar(2, 999);
    cout << "Original modificado: ";
    arr1.mostrar();
    cout << "Copia sin cambios: ";
    arr2.mostrar();

    cout << "\n--- Los destructores se llamarán automáticamente ---" << endl;
}

// Ejemplo de orden de construcción/destrucción
void ejemploOrdenConstructorDestructor() {
    cout << "\n=== ORDEN DE CONSTRUCCIÓN/DESTRUCCIÓN ===" << endl;

    cout << "\n--- Creando objetos ---" << endl;
    {
        Vehiculo v1("BMW", "X3", 2021, 45000);
        Vehiculo v2("Audi", "A4", 2019, 35000);
        Vehiculo v3 = v1; // Constructor de copia

        cout << "\n--- Los objetos existen aquí ---" << endl;
        v1.mostrarInfo();
        v2.mostrarInfo();
        v3.mostrarInfo();

        cout << "\n--- Saliendo del bloque... ---" << endl;
    } // Aquí se llaman automáticamente los destructores

    cout << "--- Fuera del bloque (objetos destruidos) ---" << endl;
}

void consejosExamen() {
    cout << "\n=== CONSEJOS PARA EL EXAMEN ===" << endl;

    cout << "\n🎯 TIPOS DE CONSTRUCTORES:" << endl;
    cout << "1. Por defecto: ClassName() { ... }" << endl;
    cout << "2. Con parámetros: ClassName(params) { ... }" << endl;
    cout << "3. De copia: ClassName(const ClassName& otro) { ... }" << endl;
    cout << "4. Lista inicialización: ClassName() : var1(val1), var2(val2) { }" << endl;

    cout << "\n🎯 CUÁNDO SE LLAMAN:" << endl;
    cout << "• Por defecto: ClassName obj;" << endl;
    cout << "• Con parámetros: ClassName obj(params);" << endl;
    cout << "• De copia: ClassName obj2 = obj1; o ClassName obj2(obj1);" << endl;

    cout << "\n🎯 REGLAS IMPORTANTES:" << endl;
    cout << "• Si defines un constructor, el por defecto desaparece" << endl;
    cout << "• Constructor de copia: SIEMPRE usar const ClassName&" << endl;
    cout << "• Para memoria dinámica: implementar copia profunda" << endl;
    cout << "• Lista de inicialización es más eficiente" << endl;
    cout << "• Destructor ~ClassName() para limpiar recursos" << endl;
}

int main() {
    cout << "🎯 CONSTRUCTORES - CONCEPTOS DE EXAMEN" << endl;
    cout << "=====================================" << endl;

    ejemplosBasicosConstructores();
    ejemploListaInicializacion();
    ejemploConstructorDelegante();
    ejemploCopiaSuperficialVsProfunda();
    ejemploOrdenConstructorDestructor();
    consejosExamen();

    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • Constructor por defecto vs con parámetros" << endl;
    cout << "   • Constructor de copia para objetos complejos" << endl;
    cout << "   • Lista de inicialización : var(valor)" << endl;
    cout << "   • Destructor ~ClassName() para cleanup" << endl;
    cout << "   • Diferencia entre copia superficial y profunda" << endl;
    cout << "   • Orden de construcción y destrucción" << endl;
    cout << "   • const ClassName& en constructor de copia" << endl;

    return 0;
}