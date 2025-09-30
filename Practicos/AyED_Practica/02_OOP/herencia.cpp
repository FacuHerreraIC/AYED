#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// ===== UNIDAD 2.3: HERENCIA =====

// CLASE BASE (PADRE)
class Animal {
protected:  // Accesible por las clases hijas
    string nombre;
    int edad;
    double peso;
    
private:    // Solo accesible por la clase Animal
    string id;
    
public:
    // Constructor de la clase base
    Animal(string nom, int ed, double p) {
        nombre = nom;
        edad = ed;
        peso = p;
        id = "ANIMAL_" + nom;
        cout << "🐾 Animal constructor: " << nombre << " creado" << endl;
    }
    
    // Constructor por defecto
    Animal() {
        nombre = "Sin nombre";
        edad = 0;
        peso = 0.0;
        id = "ANIMAL_DEFAULT";
        cout << "🐾 Animal constructor por defecto" << endl;
    }
    
    // Destructor virtual (importante para herencia)
    virtual ~Animal() {
        cout << "🐾 Animal destructor: " << nombre << endl;
    }
    
    // Getters públicos
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    double getPeso() const { return peso; }
    string getId() const { return id; }
    
    // Setters públicos
    void setNombre(string nom) { nombre = nom; }
    void setEdad(int ed) { if (ed >= 0) edad = ed; }
    void setPeso(double p) { if (p > 0) peso = p; }
    
    // Métodos virtuales (pueden ser sobrescritos)
    virtual void hacerSonido() {
        cout << nombre << " hace algún sonido genérico" << endl;
    }
    
    virtual void moverse() {
        cout << nombre << " se mueve de alguna manera" << endl;
    }
    
    // Método virtual puro (clase abstracta)
    virtual void alimentar() = 0;  // Hace la clase abstracta
    
    // Método no virtual (común a todos)
    void mostrarInfo() {
        cout << "Animal: " << nombre << ", " << edad << " años, " << peso << " kg" << endl;
    }
    
    void dormir() {
        cout << nombre << " está durmiendo... 😴" << endl;
    }
    
    // Método estático
    static void infoClase() {
        cout << "📚 Clase Animal - Base para todos los animales" << endl;
    }
};

// CLASE DERIVADA 1: PERRO
class Perro : public Animal {  // Herencia pública
private:
    string raza;
    bool entrenado;
    
public:
    // Constructor que llama al constructor de la clase base
    Perro(string nom, int ed, double p, string r, bool ent = false) 
        : Animal(nom, ed, p) {  // Llamada al constructor padre
        raza = r;
        entrenado = ent;
        cout << "🐕 Perro constructor: " << nombre << " (" << raza << ")" << endl;
    }
    
    // Constructor por defecto
    Perro() : Animal() {
        raza = "Mestizo";
        entrenado = false;
        cout << "🐕 Perro constructor por defecto" << endl;
    }
    
    // Destructor
    ~Perro() {
        cout << "🐕 Perro destructor: " << nombre << endl;
    }
    
    // Getters específicos
    string getRaza() const { return raza; }
    bool isEntrenado() const { return entrenado; }
    
    // Setters específicos
    void setRaza(string r) { raza = r; }
    void entrenar() { 
        entrenado = true; 
        cout << nombre << " ha sido entrenado! 🎾" << endl;
    }
    
    // Sobrescribir métodos virtuales (override)
    virtual void hacerSonido() override {
        cout << nombre << " dice: ¡Guau guau! 🐕" << endl;
    }
    
    virtual void moverse() override {
        cout << nombre << " corre y salta alegremente! 🏃‍♂️" << endl;
    }
    
    virtual void alimentar() override {
        cout << nombre << " come croquetas de perro 🦴" << endl;
    }
    
    // Métodos específicos de Perro
    void buscarPelota() {
        if (entrenado) {
            cout << nombre << " busca la pelota! 🎾" << endl;
        } else {
            cout << nombre << " no sabe buscar la pelota (necesita entrenamiento)" << endl;
        }
    }
    
    void darLaMano() {
        cout << nombre << " da la mano! 🐾" << endl;
    }
    
    // Método que usa atributos protegidos del padre
    void mostrarInfoCompleta() {
        cout << "=== INFORMACIÓN DEL PERRO ===" << endl;
        cout << "Nombre: " << nombre << " (acceso directo a protected)" << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Raza: " << raza << endl;
        cout << "Entrenado: " << (entrenado ? "Sí" : "No") << endl;
        // cout << "ID: " << id << endl;  // ERROR! id es private
    }
};

// CLASE DERIVADA 2: GATO
class Gato : public Animal {
private:
    bool interior;  // ¿Vive en interior?
    int vidasRestantes;
    
public:
    // Constructor
    Gato(string nom, int ed, double p, bool int_vida = true) 
        : Animal(nom, ed, p) {
        interior = int_vida;
        vidasRestantes = 9;  // Los gatos tienen 9 vidas 😸
        cout << "🐱 Gato constructor: " << nombre << endl;
    }
    
    // Destructor
    ~Gato() {
        cout << "🐱 Gato destructor: " << nombre << endl;
    }
    
    // Getters
    bool isInterior() const { return interior; }
    int getVidasRestantes() const { return vidasRestantes; }
    
    // Sobrescribir métodos virtuales
    virtual void hacerSonido() override {
        cout << nombre << " dice: ¡Miau miau! 🐱" << endl;
    }
    
    virtual void moverse() override {
        cout << nombre << " camina sigilosamente... 🐾" << endl;
    }
    
    virtual void alimentar() override {
        cout << nombre << " come pescado y croquetas de gato 🐟" << endl;
    }
    
    // Métodos específicos de Gato
    void ronronear() {
        cout << nombre << " está ronroneando... purrrrr 😸" << endl;
    }
    
    void arañarSofa() {
        cout << nombre << " está arañando el sofá! 😾" << endl;
    }
    
    void perderVida() {
        if (vidasRestantes > 1) {
            vidasRestantes--;
            cout << nombre << " perdió una vida. Vidas restantes: " << vidasRestantes << endl;
        } else {
            cout << nombre << " usó su última vida! 😿" << endl;
        }
    }
};

// CLASE DERIVADA 3: PÁJARO
class Pajaro : public Animal {
private:
    double envergaduraAlas;
    bool puedeVolar;
    
public:
    // Constructor
    Pajaro(string nom, int ed, double p, double env, bool vuela = true) 
        : Animal(nom, ed, p) {
        envergaduraAlas = env;
        puedeVolar = vuela;
        cout << "🐦 Pájaro constructor: " << nombre << endl;
    }
    
    // Destructor
    ~Pajaro() {
        cout << "🐦 Pájaro destructor: " << nombre << endl;
    }
    
    // Sobrescribir métodos virtuales
    virtual void hacerSonido() override {
        cout << nombre << " dice: ¡Pío pío! 🐦" << endl;
    }
    
    virtual void moverse() override {
        if (puedeVolar) {
            cout << nombre << " vuela por el cielo! ✈️" << endl;
        } else {
            cout << nombre << " camina por el suelo" << endl;
        }
    }
    
    virtual void alimentar() override {
        cout << nombre << " come semillas y granos 🌾" << endl;
    }
    
    // Métodos específicos
    void volar() {
        if (puedeVolar) {
            cout << nombre << " está volando con " << envergaduraAlas 
                 << " metros de envergadura! 🦅" << endl;
        } else {
            cout << nombre << " no puede volar 😢" << endl;
        }
    }
    
    void construirNido() {
        cout << nombre << " está construyendo un nido 🥚" << endl;
    }
};

// CLASE DERIVADA 4: PEZ (HERENCIA MULTINIVEL)
class Pez : public Animal {
protected:
    string tipoAgua;  // dulce o salada
    double profundidadMaxima;
    
public:
    Pez(string nom, int ed, double p, string agua, double prof) 
        : Animal(nom, ed, p) {
        tipoAgua = agua;
        profundidadMaxima = prof;
        cout << "🐠 Pez constructor: " << nombre << endl;
    }
    
    virtual void alimentar() override {
        cout << nombre << " come plancton y algas 🌊" << endl;
    }
    
    virtual void nadar() {
        cout << nombre << " está nadando en agua " << tipoAgua << endl;
    }
};

// HERENCIA MULTINIVEL: PEZ DORADO
class PezDorado : public Pez {
private:
    string color;
    
public:
    PezDorado(string nom, int ed, double p, string col) 
        : Pez(nom, ed, p, "dulce", 10.0) {
        color = col;
        cout << "🐟 PezDorado constructor: " << nombre << " color " << color << endl;
    }
    
    virtual void hacerSonido() override {
        cout << nombre << " hace: glug glug! 💦" << endl;
    }
    
    virtual void moverse() override {
        cout << nombre << " nada elegantemente en la pecera 🏊‍♂️" << endl;
    }
    
    void brillar() {
        cout << nombre << " brilla con su color " << color << " ✨" << endl;
    }
};

// Función que demuestra polimorfismo
void hacerSonarAnimales(Animal* animales[], int cantidad) {
    cout << "\n=== POLIMORFISMO EN ACCIÓN ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        animales[i]->mostrarInfo();
        animales[i]->hacerSonido();  // Polimorfismo!
        animales[i]->moverse();      // Polimorfismo!
        animales[i]->alimentar();    // Polimorfismo!
        cout << endl;
    }
}

// Función template para mostrar información de cualquier animal
template<typename T>
void mostrarAnimalEspecifico(const T& animal) {
    cout << "=== INFORMACIÓN ESPECÍFICA ===" << endl;
    animal.mostrarInfo();
    animal.hacerSonido();
}

void ejemplosBasicosHerencia() {
    cout << "\n=== EJEMPLOS BÁSICOS DE HERENCIA ===" << endl;
    
    cout << "\n--- Creando animales ---" << endl;
    Perro rex("Rex", 3, 25.0, "Golden Retriever");
    Gato mishi("Mishi", 2, 4.5, true);
    Pajaro tweety("Tweety", 1, 0.1, 0.15, true);
    PezDorado nemo("Nemo", 1, 0.5, "naranja");
    
    cout << "\n--- Usando métodos heredados ---" << endl;
    rex.mostrarInfo();    // Método del padre
    rex.dormir();         // Método del padre
    
    cout << "\n--- Usando métodos sobrescritos ---" << endl;
    rex.hacerSonido();    // Método sobrescrito
    mishi.hacerSonido();  // Método sobrescrito
    tweety.hacerSonido(); // Método sobrescrito
    nemo.hacerSonido();   // Método sobrescrito
    
    cout << "\n--- Usando métodos específicos ---" << endl;
    rex.darLaMano();
    rex.buscarPelota();   // No está entrenado
    rex.entrenar();       // Entrenar
    rex.buscarPelota();   // Ahora sí puede
    
    mishi.ronronear();
    mishi.arañarSofa();
    mishi.perderVida();
    
    tweety.volar();
    tweety.construirNido();
    
    nemo.nadar();
    nemo.brillar();
}

void ejemploPolimorfismo() {
    cout << "\n=== EJEMPLO DE POLIMORFISMO ===" << endl;
    
    // Array de punteros a la clase base
    Animal* zoologico[5];
    
    // Crear diferentes tipos de animales
    zoologico[0] = new Perro("Bobby", 4, 20.0, "Labrador");
    zoologico[1] = new Gato("Luna", 3, 3.5, false);
    zoologico[2] = new Pajaro("Águila", 5, 2.5, 2.0, true);
    zoologico[3] = new PezDorado("Dory", 2, 0.3, "azul");
    zoologico[4] = new Perro("Max", 6, 30.0, "Pastor Alemán", true);
    
    // Polimorfismo: cada animal hace su sonido específico
    hacerSonarAnimales(zoologico, 5);
    
    cout << "\n--- Acceso a métodos específicos (downcast) ---" << endl;
    // Para acceder a métodos específicos, necesitamos cast
    Perro* perroPtr = dynamic_cast<Perro*>(zoologico[0]);
    if (perroPtr) {
        perroPtr->darLaMano();
        perroPtr->mostrarInfoCompleta();
    }
    
    Gato* gatoPtr = dynamic_cast<Gato*>(zoologico[1]);
    if (gatoPtr) {
        gatoPtr->ronronear();
        gatoPtr->perderVida();
    }
    
    // Limpiar memoria
    cout << "\n--- Liberando memoria ---" << endl;
    for (int i = 0; i < 5; i++) {
        delete zoologico[i];
    }
}

void ejemploSmartPointers() {
    cout << "\n=== SMART POINTERS Y HERENCIA ===" << endl;
    
    // Usando unique_ptr (C++11)
    vector<unique_ptr<Animal>> animales;
    
    animales.push_back(make_unique<Perro>("Rocky", 2, 15.0, "Bulldog"));
    animales.push_back(make_unique<Gato>("Simba", 1, 3.0, true));
    animales.push_back(make_unique<Pajaro>("Piolín", 1, 0.2, 0.1, true));
    
    cout << "--- Recorriendo con smart pointers ---" << endl;
    for (auto& animal : animales) {
        animal->mostrarInfo();
        animal->hacerSonido();
        cout << endl;
    }
    // No necesitamos delete - se libera automáticamente
}

void ejemploAccesoMiembros() {
    cout << "\n=== EJEMPLO DE ACCESO A MIEMBROS ===" << endl;
    
    Perro firulais("Firulais", 5, 15.0, "Chihuahua");
    
    cout << "\n--- Acceso público (desde fuera) ---" << endl;
    cout << "Nombre: " << firulais.getNombre() << endl;  // OK
    cout << "Edad: " << firulais.getEdad() << endl;      // OK
    
    cout << "\n--- Método que accede a miembros protected ---" << endl;
    firulais.mostrarInfoCompleta();  // OK - accede a nombre, edad, peso
    
    // cout << firulais.nombre;     // ERROR! protected no accesible desde fuera
    // cout << firulais.id;         // ERROR! private no accesible
}

void ejemploConstructoresDestructores() {
    cout << "\n=== ORDEN DE CONSTRUCTORES/DESTRUCTORES ===" << endl;
    
    cout << "\n--- Creando objeto derivado ---" << endl;
    {
        Perro max("Max", 6, 30.0, "Pastor Alemán", true);
        max.hacerSonido();
        cout << "\n--- Saliendo del ámbito ---" << endl;
    } // Aquí se llaman los destructores
    
    cout << "--- Objeto destruido ---" << endl;
}

void consejosExamen() {
    cout << "\n=== CONSEJOS PARA EL EXAMEN ===" << endl;
    
    cout << "\n🎯 SINTAXIS DE HERENCIA:" << endl;
    cout << "class Hija : public Padre {" << endl;
    cout << "    // Constructor: Hija() : Padre() { }" << endl;
    cout << "};" << endl;
    
    cout << "\n🎯 NIVELES DE ACCESO:" << endl;
    cout << "• public: accesible desde cualquier lado" << endl;
    cout << "• protected: accesible por la clase y sus hijas" << endl;
    cout << "• private: solo accesible por la propia clase" << endl;
    
    cout << "\n🎯 MÉTODOS VIRTUALES:" << endl;
    cout << "• virtual en clase base para polimorfismo" << endl;
    cout << "• override en clase derivada (C++11)" << endl;
    cout << "• Destructor virtual ~ClassName() para herencia" << endl;
    cout << "• virtual void metodo() = 0; // Método puro" << endl;
    
    cout << "\n🎯 POLIMORFISMO:" << endl;
    cout << "• Puntero a base puede apuntar a derivada" << endl;
    cout << "• Métodos virtuales se llaman según el tipo real" << endl;
    cout << "• dynamic_cast para conversiones seguras" << endl;
    
    cout << "\n🎯 CONSTRUCTORES/DESTRUCTORES:" << endl;
    cout << "• Orden: Base → Derivada (construcción)" << endl;
    cout << "• Orden: Derivada → Base (destrucción)" << endl;
}

int main() {
    cout << "🎯 HERENCIA - CONCEPTOS DE EXAMEN" << endl;
    cout << "=================================" << endl;
    
    // Método estático
    Animal::infoClase();
    
    ejemplosBasicosHerencia();
    ejemploPolimorfismo();
    ejemploSmartPointers();
    ejemploAccesoMiembros();
    ejemploConstructoresDestructores();
    consejosExamen();
    
    cout << "\n✅ Conceptos clave para el examen:" << endl;
    cout << "   • class Hija : public Padre" << endl;
    cout << "   • Constructor hijo llama constructor padre" << endl;
    cout << "   • protected: accesible por clases hijas" << endl;
    cout << "   • virtual para métodos polimórficos" << endl;
    cout << "   • override para sobrescribir métodos" << endl;
    cout << "   • Destructor virtual en clase base" << endl;
    cout << "   • dynamic_cast para downcasting seguro" << endl;
    cout << "   • Smart pointers para gestión automática de memoria" << endl;
    
    return 0;
}