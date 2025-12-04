#include <iostream>
#include <vector>
using namespace std;

int PedirNotas(vector<float>& notas, vector<float>& porcentajes) {
    int numNotas;
    cout << "Bienvenido al programa Calculadora de Notas\n";
    cout << "Introduzca el numero de notas a calcular: ";
    cin >> numNotas;
    notas.resize(numNotas);
    porcentajes.resize(numNotas);
    numNotas++;
    for (size_t i = 1; i < numNotas; i++){
        cout << "Introduzca la nota Numero " << i << ": "<< endl;
        cin >> notas[i];
        cout << "Introduzca el valor en (%) de esta nota: "; 
        cin >> porcentajes[i];
    }
}

float CalcularPromedio(vector<float> notas, vector<float> porcentajes) {
    float suma = 0;
    for (size_t i = 0; i < notas.size(); i++) {
        suma += notas[i] * (porcentajes[i] / 100);
    }
    return suma;
}

int main() {
    vector<float> notas;
    vector<float> porcentajes;
    system("cls");
    PedirNotas(notas, porcentajes);
    float final = CalcularPromedio(notas, porcentajes);
    cout << "Tu promedio final es: " << final << endl; 
}
