#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip> 
#include <fstream>
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
            cout << "Id de ingreso: " << id << "\n";
            cout << "Cliente:       " << obtenerCliente() << "\n";
            cout << "Producto:      " << tipoproducto << "\n";
            cout << "Estado:        " << estado << "\n";
            cout << "Descripcion:   " << descripcion << "\n";
        }
};

void NuevoIngreso(vector<stock>& lista, int& proximoId);
void MostrarIngresos(const vector<stock>& lista);
void EditarIngreso(vector<stock>& lista);
void EliminarIngreso(vector<stock>& lista);
void menu(vector<stock>& lista, int& proximoId);
void GuardarArchivo(const vector<stock>& lista, const string& filename);
void CargarArchivo(vector<stock>& lista, int& proximoId, const string& filename);

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
                GuardarArchivo(lista, "servicio_db.txt");
                break;
            case EDITARE:
                EditarIngreso(lista);
                GuardarArchivo(lista, "servicio_db.txt");
                break;
            case MINGRESO:
                MostrarIngresos(lista);
                break;
            case EINGRESO:
                EliminarIngreso(lista);
                GuardarArchivo(lista, "servicio_db.txt");
                break;
            case MSTOCK:
            
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
    CargarArchivo(listaDeStock, proximoId, "servicio_db.txt");
    menu(listaDeStock, proximoId);
    GuardarArchivo(listaDeStock, "servicio_db.txt"); // ************* GUARDAR AL SALIR *************
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

void EditarIngreso(vector<stock>& lista) {
    if (lista.empty()) {
        cout << "\nNo hay ingresos para editar.\n";
        return;
    }

    int idBuscar;
    cout << "\n--- Editar Estado de Ingreso ---\n";
    cout << "Ingrese el ID del ingreso a editar: ";
    cin >> idBuscar;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (size_t i = 0; i < lista.size(); ++i) {
        if (lista[i].id == idBuscar) {
            cout << "Ingreso encontrado:\n";
            lista[i].mostrar();

            string nuevoEstado;
            cout << "Ingrese el nuevo estado: ";
            getline(cin, nuevoEstado);
            lista[i].estado  = nuevoEstado;

            cout << "Estado actualizado con exito.\n";
            return;
        }
    }
    cout << "No se encontro un ingreso con el ID proporcionado.\n";
}

void EliminarIngreso(vector<stock>& lista) {
    if (lista.empty()) {
        cout << "\nNo hay ingresos para eliminar.\n";
        return;
    }

    int idBuscar;
    cout << "\n--- Eliminar Ingreso ---\n";
    cout << "Ingrese el ID del ingreso a eliminar: ";
    cin >> idBuscar;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (size_t i = 0; i < lista.size(); ++i) {
        if (lista[i].id == idBuscar) {
            cout << "Ingreso encontrado:\n";
            lista[i].mostrar();

            char confirmacion;
            cout << "Esta seguro que desea eliminar este ingreso? (s/n): ";
            cin >> confirmacion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (confirmacion == 's' || confirmacion == 'S') {
                lista.erase(lista.begin() + i); 
                cout << "Ingreso eliminado con exito.\n";
            } else {
                cout << "Eliminacion cancelada.\n";
            }
            return;
        }
    }
    cout << "No se encontro un ingreso con el ID proporcionado.\n";
}

void GuardarArchivo(const vector<stock>& lista, const string& filename) {
    // Abrir/crear el archivo para escritura, truncando su contenido si existe
    ofstream out(filename, ios::out | ios::trunc);
    // Si no se pudo abrir el archivo, salir de la función
    if (!out) return;
    // Recorrer cada elemento de la lista de stock
    for (const stock &s : lista) {
        // Escribir el id seguido de un salto de línea
        out << s.id << '\n';
        // Escribir el nombre del cliente seguido de un salto de línea
        out << s.obtenerCliente() << '\n';
        // Escribir el tipo de producto seguido de un salto de línea
        out << s.tipoproducto << '\n';
        // Escribir el estado seguido de un salto de línea
        out << s.estado << '\n';
        // Escribir la descripción seguida de un salto de línea
        out << s.descripcion << '\n';
    }
}

void CargarArchivo(vector<stock>& lista, int& proximoId, const string& filename) {
    // Abrir el archivo para lectura
    ifstream in(filename);
    // Si no existe o no se puede abrir, salir (no es error)
    if (!in) return;
    // Vaciar la lista actual antes de cargar
    lista.clear();
    // Reiniciar el siguiente id por defecto
    proximoId = 1;
    // Variables temporales para leer las 5 líneas de cada registro
    string idLine, cliente, tipo, estado, descripcion;
    // Leer bloques de 5 líneas hasta el final del archivo
    while (getline(in, idLine)) {
        // Leer la línea del cliente; si falla, salir del bucle
        if (!getline(in, cliente)) break;
        // Leer la línea del tipo de producto; si falla, salir
        if (!getline(in, tipo)) break;
        // Leer la línea del estado; si falla, salir
        if (!getline(in, estado)) break;
        // Leer la línea de la descripción; si falla, salir
        if (!getline(in, descripcion)) break;
        // Intentar convertir la primera línea (id) a entero
        int id = 0;
        try { id = stoi(idLine); } catch(...) { continue; }
        // Construir un objeto stock con los datos leídos
        stock s(id, cliente, tipo, descripcion);
        // Asignar el estado leído (sobrescribe el default 'Registrado')
        s.estado = estado;
        // Añadir el objeto a la lista
        lista.push_back(s);
        // Actualizar proximoId para no repetir ids (mantener el mayor + 1)
        if (id >= proximoId) proximoId = id + 1;
    }
}