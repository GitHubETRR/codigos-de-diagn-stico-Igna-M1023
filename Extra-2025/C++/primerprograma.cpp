#include <iostream>
#include <iomanip> // Para (estetica) (https://www.geeksforgeeks.org/cpp/iomanip-in-cpp/)
#include <complex> // numeros complejos
using namespace std;

int main() {
    int num = 2;
    cout << "Bienvenido a " << num << " programa"; // imprimir con variable (\n o<<endl)
    cin >> num; // pedir desde el teclado (scanf) 
    cout << "El numero ingresado es: " << num << endl;
    cout << "Bienvenido a " << hex << num << " programa"; // mostrar el numero en base hexa (oct,dec,hex) (desde que se registra hasta volver a cambiarlo)
    return 0;
}


// CLASES Y OBJETOS
// Las clases son plantillas para crear objetos. Un objeto es una instancia de una clase. Las clases encapsulan datos y funciones que operan sobre esos datos.
// Una clase define un tipo de dato abstracto, mientras que un objeto es una instancia concreta de esa clase.

class{      // se parece a una estructura y se accede de la misma forma
    public: // al inicio las clases tienen los datos privados, pque solo lo puede leer la misma clase, pero si pongo public puedo leerlo desde otro lado
        int a;
        int b;
}var1;

// cout << "Val: " << var1.a << endl

class perro{
    private: // para que solo accedan las funciones en la misma clase 
        int edad; 
        int peso;
    public: // para que se pueda acceder desde cualquier ugar
        void ladrar(void){  // Metodo dentro de la clase
            cout << "dl" << endl;
        }
        void cumplirAnios(void){
            edad++;   // cambia el valor de edad en la clase 
            ladrar();
            ladrar();
        }
        void MostrarDatos(void){
            cout << "val: " << edad << endl;
        }
        void IngresarDatos(int edading, int pesoing){  // setter
            edad=edading;
            peso=pesoing;
        }
        int edadperro(void){ // getter
            return edad;
        }
}jo;

// con los datos en privado: jo.IngresarDatos(8,30)
// para acceder, llamar: jo.ladrar();


// metodos 
class perro{
    private: // para que solo accedan las funciones en la misma clase 
        int edad; 
        int peso;
    public: // para que se pueda acceder desde cualquier ugar
        void ladrar(void);
        void cumplirAnios(void);
        void MostrarDatos(void);
        void IngresarDatos(int edading, int pesoing);
        // perro(int edading, int pesoing);
        int edadperro(void);
}jo;

void perro::ladrar(void){  
    cout << "dl" << endl;
}
void perro::cumplirAnios(void){
    edad++;  
    ladrar();
    ladrar();
}
void perro::MostrarDatos(void){
    cout << "val: " << edad << endl;
}
void perro::IngresarDatos(int edading, int pesoing){  // setter
    edad=edading;
    peso=pesoing;
}
int perro::edadperro(void){ // getter
    return edad;
}

// añadir datos de otra forma
 // METODO CONSTRUCTOR
class perro var(8,30);