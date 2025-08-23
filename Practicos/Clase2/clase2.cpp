#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

struct Persona {
    int edad;
    std::string nombre;

    Persona(int edadP = 0, const std::string& nombreP = "") {
        edad = edadP;
        nombre = nombreP;
    }

    Persona &operator=(Persona * persona);
};

struct

struct PersonaConst {
    int edad;
    std::string nombre;

    PersonaConst() = delete;
    PersonaConst(int i, const std::string& n) {
        edad = 0;
        nombre = n;
    };
};

int main() {
    // Creación correcta de Personas
    Persona p(0, "");  // Usando el constructor con parámetros
    std::cout << p.edad << std::endl;
    std::cout << p.nombre << std::endl;

    Persona p1;  // Ahora funciona porque los parámetros tienen valores por defecto
    std::cout << p1.edad << std::endl;
    std::cout << p1.nombre << std::endl;

    p1.edad = 22;
    p1.nombre = "John";

    Persona p2 = p1;

    p1.edad = 33;
    p1.nombre = "Juan";

    Persona p3;
    p3 = p1;

    // Ejemplo de PersonaConst
    PersonaConst pc("Nombre");  // Usando el constructor disponible
    // PersonaConst pc2;  // Esto daría error porque el constructor por defecto está eliminado

    Persona personas[5];
    for (int i = 0; i < 5; i++) {
        personas[i] = new Persona(i,"persona");
        std::cout << personas[i].edad << std::endl;
        std::cout << personas[i].nombre << std::endl;
    }

}
