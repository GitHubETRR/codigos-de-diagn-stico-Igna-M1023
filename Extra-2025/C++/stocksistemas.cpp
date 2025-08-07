#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip> 
using namespace std;

class stock {
    private:
        string nombrecliente;
    public:
        int id;
        string tipoproducto;
        string estado;
        string descripcion;

        stock(int uid, string ucliente, string utipo, string udescripcion){
            id = uid;
            nombrecliente = ucliente;
            tipoproducto = utipo;
            estado = "Registrado";
            descripcion = udescripcion;
        }
        string obtenerCliente() const{
            return nombrecliente;
        }
        void mostrar() const{
            cout << "---------------------------------\n";
            cout << "ID de Ingreso: " << id << "\n";
            cout << "Cliente:       " << obtenerCliente() << "\n";
            cout << "Producto:      " << tipoproducto << "\n";
            cout << "Estado:        " << estado << "\n";
            cout << "Descripcion:   " << descripcion << "\n";
        }
};

void NuevoIngreso(vector<stock>& lista, int& proximoId);
void MostrarIngresos(const vector<stock>& lista);
void menu(vector<stock>& lista, int& proximoId);


typedef enum {
    NINGRESO = 1,
    EDITARE,
    MINGRESO,
    EINGRESO,
    MSTOCK,
    SALIR
} opciones_t;


void menu(vector<stock>& lista, int& proximoId) {
    int opcion;
    opciones_t op;
    do {
        cout << "Eliga una opcion:\n";
        cout << "1. Nuevo Ingreso\n";
        cout << "2. Editar Estado\n";
        cout << "3. Mostrar Ingresos\n";
        cout << "4. Eliminar Ingreso\n";
        cout << "5. Mostrar Stock de Productos\n";
        cout << "6. Salir\n";
        scanf("%d", &opcion);
        op = (opciones_t)opcion;
        while (getchar() != '\n'); 
        switch (op) {
            case NINGRESO:
                NuevoIngreso(lista, proximoId);
                break;
            case MINGRESO:
                MostrarIngresos(lista);
                break;
            case SALIR:
                break;
        }
    } while (op != SALIR);
}

int main() {
    system("cls");
    vector<stock> listaDeStock; 
    int proximoId = 1;
    cout << "Bienvenido al programa de gestion\n";  
    menu(listaDeStock, proximoId);
    return 0;
}

void NuevoIngreso(vector<stock>& lista, int& proximoId) {
    string cliente, tipo, desc;
    int tipoNum = 0;

    cout << "\n--- Creando Nuevo Ingreso ---\n";
    cout << "Nombre del cliente: ";
    getline(cin, cliente);
    cout << "Descripcion del problema/dispositivo: ";
    getline(cin, desc);

    do {
        cout << "Seleccione el tipo de producto:\n";
        cout << "  1. Telefono\n";
        cout << "  2. PC\n";
        cout << "  3. Televisor\n";
        cout << "Opcion: ";
        cin >> tipoNum;

        if (cin.fail()) {
            cout << "\nError: Debe ingresar un numero.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            tipoNum = 0; 
        }
        else if (tipoNum < 1 || tipoNum > 3) {
            cout << "\nError: Opcion no valida. Por favor, elija 1, 2 o 3.\n";
        }

    } while (tipoNum < 1 || tipoNum > 3); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (tipoNum) {
        case 1:
            tipo = "Telefono";
            break;
        case 2:
            tipo = "PC";
            break;
        case 3:
            tipo = "Televisor";
            break;
    }

    stock nuevo(proximoId, cliente, tipo, desc);
    lista.push_back(nuevo);

    cout << "\n>> Ingreso registrado con exito con ID: " << proximoId << endl;
    proximoId++;
}

void MostrarIngresos(const vector<stock>& lista) {
    cout << "\n--- Lista Completa de Ingresos ---\n";
    if (lista.empty()) {
        cout << "No hay ingresos registrados.\n";
    } else {
        for (size_t i = 0; i < lista.size(); ++i) {
            lista[i].mostrar();
            cin.get();
        }
    }
}