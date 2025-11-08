#include <iostream>
#include <string>
using namespace std;

struct Direccion {
    string calle;
    int num;
    string ciudad;
};

struct Estudiante {
    string nombre;
    int edad;
    float notas[5];
    Direccion direccion;
};

void ingresarEstudiantes(Estudiante* estudiantes, int cantidad);
void mostrarEstudiantes(Estudiante* estudiantes, int cantidad);
void buscarEstudiante(Estudiante* estudiantes, int cantidad);
void modificarEstudiante(Estudiante* estudiantes, int cantidad);

int main() {
    int cantidad;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidad;
    cin.ignore();

    Estudiante* estudiantes = new Estudiante[cantidad];

    int opcion;
    do {
        cout << "    MENU PRINCIPAL    " << endl << endl;
        cout << "1 <--- Ingresar estudiantes" << endl;
        cout << "2 <--- Mostrar estudiantes" << endl;
        cout << "3 <--- Buscar estudiante" << endl;
        cout << "4 <--- Modificar estudiante" << endl;
        cout << "5 <--- Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                ingresarEstudiantes(estudiantes, cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                buscarEstudiante(estudiantes, cantidad);
                break;
            case 4:
                modificarEstudiante(estudiantes, cantidad);
                break;
            case 5:
                cout << "Cerrando el programa." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    delete[] estudiantes; 
    return 0;
}

void ingresarEstudiantes(Estudiante* estudiantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << " Estudiante " << i + 1 << endl;
        cout << "Nombre: ";
        getline(cin, estudiantes[i].nombre);
        cout << "Edad: ";
        cin >> estudiantes[i].edad;
        cin.ignore();

        cout << "Ingrese 5 calificaciones:" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "  Calificacion " << j + 1 << ": ";
            cin >> estudiantes[i].notas[j];
        }
        cin.ignore();

        cout << "Calle: ";
        getline(cin, estudiantes[i].direccion.calle);
        cout << "Numero: ";
        cin >> estudiantes[i].direccion.num;
        cin.ignore();
        cout << "Ciudad: ";
        getline(cin, estudiantes[i].direccion.ciudad);
    }
}

void mostrarEstudiantes(Estudiante* estudiantes, int cantidad) {
    cout << "    LISTA DE ESTUDIANTES    " << endl << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < 5; j++) {
            cout << estudiantes[i].notas[j] << " ";
        }
        cout << "Direccion: " << estudiantes[i].direccion.calle << " "
             << estudiantes[i].direccion.num << ", "
             << estudiantes[i].direccion.ciudad << endl;
    }
}

void buscarEstudiante(Estudiante* estudiantes, int cantidad) {
    string nombreBuscado;
    cout << "Ingrese el nombre del estudiante a buscar: " << endl;
    getline(cin, nombreBuscado);

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "Estudiante encontrado:" << endl;
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Calificaciones: ";
            for (int j = 0; j < 5; j++)
                cout << estudiantes[i].notas[j] << " ";
            cout << "Direccion: " << estudiantes[i].direccion.calle << " "
                 << estudiantes[i].direccion.num << ", "
                 << estudiantes[i].direccion.ciudad << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
        cout << "Estudiante no encontrado." << endl;
}

void modificarEstudiante(Estudiante* estudiantes, int cantidad) {
    string nombreBuscado;
    cout << "Ingrese el nombre del estudiante a modificar: ";
    getline(cin, nombreBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "Ingrese los nuevos datos:" << endl;
            cout << "Nuevo nombre: ";
            getline(cin, estudiantes[i].nombre);
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;
            cin.ignore();
            cout << "Nuevas calificaciones:" << endl;
            for (int j = 0; j < 5; j++) {
                cout << "  Calificacion " << j + 1 << ": ";
                cin >> estudiantes[i].notas[j];
            }
            cin.ignore();
            cout << "Nueva calle: ";
            getline(cin, estudiantes[i].direccion.calle);
            cout << "Nuevo numero: ";
            cin >> estudiantes[i].direccion.num;
            cin.ignore();
            cout << "Nueva ciudad: ";
            getline(cin, estudiantes[i].direccion.ciudad);

            cout << "Los datos fueron modificados." << endl;
            return;
        }
    }
    cout << "Estudiante no encontrado." << endl;
}