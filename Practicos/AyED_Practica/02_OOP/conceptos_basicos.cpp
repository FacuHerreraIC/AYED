//
// Created by facuh on 9/27/25.
//
#include <iostream>
#include <string>
using namespace std;

// ===== UNIDAD 2.1 y 2.2: CLASES Y OBJETOS, MÉTODOS Y ATRIBUTOS =====

// Ejemplo básico de clase
class Persona {
private:
    // Atributos privados - Solo accesibles dentro de la clase
    string nombre;
    int edad;
    double altura;

public:
    // Constructor por defecto
    Persona() {
        nombre = "Sin nombre";
        edad = 0;
        altura = 0.0;
        cout << "Constructor por defecto llamado" << endl;
    }

    // Constructor con parámetros
    Persona(string nom, int ed, double alt) {
        nombre = nom;
        edad = ed;
        altura = alt;
        cout << "Constructor con parámetros llamado para " << nombre << endl;
    }

    // Métodos públicos - Getters
    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }

    double getAltura() {
        return altura;
    }

    // Métodos públicos - Setters
    void setNombre(string nom) {
        if (!nom.empty()) {  // Validación básica
            nombre = nom;
        } else {
            cout << "❌ Nombre no puede estar vacío" << endl;
        }
    }

    void setEdad(int ed) {
        if (ed >= 0 && ed <= 150) {  // Validación básica
            edad = ed;
        } else {
            cout << "❌ Edad inválida" << endl;
        }
    }

    void setAltura(double alt) {
        if (alt > 0 && alt < 3.0) {  // Validación básica
            altura = alt;
        } else {
            cout << "❌ Altura inválida" << endl;
        }
    }

    // Método público - Funcionalidad
    void presentarse() {
        cout << "Hola, soy " << nombre << ", tengo " << edad
             << " años y mido " << altura << " metros" << endl;
    }

    void cumplirAños() {
        edad++;
        cout << nombre << " cumplió años! Ahora tiene " << edad << " años" << endl;
    }

    // Método público - Comparación
    bool esMayorQue(Persona otra) {
        return this->edad > otra.edad;
    }

private:
    // Método privado - Solo para uso interno
    bool validarDatos() {
        return !nombre.empty() && edad >= 0 && altura > 0;
    }
};

// Ejemplo de clase más compleja - Cuenta Bancaria
class CuentaBancaria {
private:
    string numeroCuenta;
    string titular;
    double saldo;
    static int contadorCuentas;  // Atributo estático

public:
    // Constructor
    CuentaBancaria(string titular, double saldoInicial = 0.0) {
        this->titular = titular;
        this->saldo = saldoInicial;
        contadorCuentas++;
        this->numeroCuenta = "CUENTA-" + to_string(contadorCuentas);

        cout << "Cuenta creada: " << numeroCuenta << " para " << titular << endl;
    }

    // Getters
    string getNumeroCuenta() { return numeroCuenta; }
    string getTitular() { return titular; }
    double getSaldo() { return saldo; }

    // Métodos de funcionalidad
    bool depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
            cout << "Depósito exitoso. Nuevo saldo: $" << saldo << endl;
            return true;
        } else {
            cout << "❌ Cantidad inválida para depósito" << endl;
            return false;
        }
    }

    bool retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
            return true;
        } else {
            cout << "❌ Fondos insuficientes o cantidad inválida" << endl;
            return false;
        }
    }

    void transferir(CuentaBancaria& destino, double cantidad) {
        if (this->retirar(cantidad)) {
            destino.depositar(cantidad);
            cout << "Transferencia exitosa de " << this->titular
                 << " a " << destino.titular << endl;
        } else {
            cout << "❌ Transferencia fallida" << endl;
        }
    }

    void mostrarInfo() {
        cout << "\n=== INFORMACIÓN DE CUENTA ===" << endl;
        cout << "Número: " << numeroCuenta << endl;
        cout << "Titular: " << titular << endl;
        cout << "Saldo: $" << saldo << endl;
    }

    // Método estático
    static int getTotalCuentas() {
        return contadorCuentas;
    }
};

// Inicialización de variable estática
int CuentaBancaria::contadorCuentas = 0;

// Ejemplo con arrays de objetos
class Estudiante {
public:
    string nombre;
    int edad;
    double promedio;

    // Constructor
    Estudiante(string nom = "", int ed = 0, double prom = 0.0) {
        nombre = nom;
        edad = ed;
        promedio = prom;
    }

    void mostrarInfo() {
        cout << nombre << " (" << edad << " años) - Promedio: " << promedio << endl;
    }

    bool aprobo() {
        return promedio >= 6.0;
    }
};

void ejemplosBasicos() {
    cout << "\n=== EJEMPLOS BÁSICOS DE CLASES ===" << endl;

    // Crear objetos
    Persona p1;  // Constructor por defecto
    Persona p2("Juan", 25, 1.75);  // Constructor con parámetros

    cout << "\n--- Usando métodos ---" << endl;
    p1.presentarse();
    p2.presentarse();

    cout << "\n--- Modificando con setters ---" << endl;
    p1.setNombre("Ana");
    p1.setEdad(30);
    p1.setAltura(1.65);
    p1.presentarse();

    cout << "\n--- Usando getters ---" << endl;
    cout << "El nombre de p2 es: " << p2.getNombre() << endl;

    cout << "\n--- Comparando objetos ---" << endl;
    if (p1.esMayorQue(p2)) {
        cout << p1.getNombre() << " es mayor que " << p2.getNombre() << endl;
    } else {
        cout << p2.getNombre() << " es mayor que " << p1.getNombre() << endl;
    }

    p2.cumplirAños();
}

void ejemploCuentaBancaria() {
    cout << "\n=== EJEMPLO CUENTA BANCARIA ===" << endl;

    // Crear cuentas
    CuentaBancaria cuenta1("María García", 1000.0);
    CuentaBancaria cuenta2("Carlos López", 500.0);

    cout << "\n--- Estado inicial ---" << endl;
    cuenta1.mostrarInfo();
    cuenta2.mostrarInfo();

    cout << "\n--- Operaciones ---" << endl;
    cuenta1.depositar(300.0);
    cuenta1.retirar(150.0);
    cuenta2.depositar(200.0);

    cout << "\n--- Transferencia ---" << endl;
    cuenta1.transferir(cuenta2, 400.0);

    cout << "\n--- Estado final ---" << endl;
    cuenta1.mostrarInfo();
    cuenta2.mostrarInfo();

    cout << "\nTotal de cuentas creadas: " << CuentaBancaria::getTotalCuentas() << endl;
}

void ejemploArrayObjetos() {
    cout << "\n=== ARRAY DE OBJETOS ===" << endl;

    // Array de estudiantes
    Estudiante estudiantes[4] = {
        Estudiante("Ana", 20, 8.5),
        Estudiante("Luis", 19, 5.2),
        Estudiante("María", 21, 7.8),
        Estudiante("Pedro", 20, 9.1)
    };

    cout << "\n--- Lista de estudiantes ---" << endl;
    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". ";
        estudiantes[i].mostrarInfo();
    }

    cout << "\n--- Estudiantes que aprobaron ---" << endl;
    int aprobados = 0;
    for (int i = 0; i < 4; i++) {
        if (estudiantes[i].aprobo()) {
            cout << "✅ " << estudiantes[i].nombre << endl;
            aprobados++;
        }
    }

    cout << "Total aprobados: " << aprobados << "/4" << endl;
}

// Ejemplo de encapsulamiento
class Rectangulo {
private:
    double largo, ancho;

    // Método privado de validación
    bool dimensionesValidas(double l, double a) {
        return l > 0 && a > 0;
    }

public:
    // Constructor
    Rectangulo(double l, double a) {
        if (dimensionesValidas(l, a)) {
            largo = l;
            ancho = a;
        } else {
            largo = ancho = 1.0;  // Valores por defecto
            cout << "⚠️ Dimensiones inválidas, usando 1x1" << endl;
        }
    }

    // Getters
    double getLargo() { return largo; }
    double getAncho() { return ancho; }

    // Setters con validación
    void setLargo(double l) {
        if (l > 0) {
            largo = l;
        } else {
            cout << "❌ Largo debe ser positivo" << endl;
        }
    }

    void setAncho(double a) {
        if (a > 0) {
            ancho = a;
        } else {
            cout << "❌ Ancho debe ser positivo" << endl;
        }
    }

    // Métodos calculados
    double area() {
        return largo * ancho;
    }

    double perimetro() {
        return 2 * (largo + ancho);
    }

    void mostrarInfo() {
        cout << "Rectángulo " << largo << "x" << ancho
             << " - Área: " << area() << ", Perímetro: " << perimetro() << endl;
    }
};

void ejemploEncapsulamiento() {
    cout << "\n=== EJEMPLO DE ENCAPSULAMIENTO ===" << endl;

    Rectangulo r1(5.0, 3.0);
    Rectangulo r2(-2.0, 4.0);  // Dimensiones inválidas

    r1.mostrarInfo();
    r2.mostrarInfo();

    cout << "\n--- Modificando dimensiones ---" << endl;
    r1.setLargo(8.0);
    r1.setAncho(2.0);
    r1.mostrarInfo();

    // Intentar valor inválido
    r1.setAncho(-5.0);  // Debería dar error
    r1.mostrarInfo();   // Sin cambios
}

int main() {
    cout << "🎯 CLASES Y OBJETOS - CONCEPTOS DE EXAMEN" << endl;
    cout << "=========================================" << endl;

    ejemplosBasicos();
    ejemploCuentaBancaria();
    ejemploArrayObjetos();
    ejemploEncapsulamiento();

    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • class NombreClase { private: ... public: ... };" << endl;
    cout << "   • Atributos privados, métodos públicos" << endl;
    cout << "   • Constructores con y sin parámetros" << endl;
    cout << "   • Getters y setters para encapsulamiento" << endl;
    cout << "   • this-> para referenciar al objeto actual" << endl;
    cout << "   • static para atributos/métodos de clase" << endl;
    cout << "   • Arrays de objetos y comparación de objetos" << endl;

    return 0;
}