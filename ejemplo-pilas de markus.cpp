#include <iostream>
#include <string>

using namespace std;

// PILA DE DEVOLUCIONES
struct devolucion{
    string libro;
    devolucion *sig;
};

// Registrar devolución
void registrar(devolucion *&pila, string libro){

    devolucion *nuevo = new devolucion;

    nuevo->libro = libro;
    nuevo->sig = pila;

    pila = nuevo;
}

// Mostrar devoluciones
void mostrar(devolucion *pila){

    while(pila != NULL){

        cout << pila->libro << endl;

        pila = pila->sig;
    }

    cout << endl;
}

// Buscar libro
bool buscar(devolucion *pila, string libro){

    while(pila != NULL){

        if(pila->libro == libro){
            return true;
        }

        pila = pila->sig;
    }

    return false;
}

// Contar devoluciones
int contar(devolucion *pila){

    int contador = 0;

    while(pila != NULL){

        contador++;

        pila = pila->sig;
    }

    return contador;
}

// Eliminar última devolución
void eliminar(devolucion *&pila){

    if(pila == NULL){
        return;
    }

    devolucion *aux = pila;

    pila = pila->sig;

    delete aux;
}

// Mostrar última devolución registrada
void mostrarultimo(devolucion *pila){

    if(pila == NULL){
        cout << "No hay devoluciones" << endl;
        return;
    }

    cout << "Ultima devolucion: " << pila->libro << endl;
}

int main(){

    devolucion *pila = NULL;

    registrar(pila, "C++");
    registrar(pila, "Base de Datos");
    registrar(pila, "Estructuras de Datos");

    mostrar(pila);

    eliminar(pila);

    mostrar(pila);

    if(buscar(pila, "C++"))
        cout << "Encontrado" << endl;
    else
        cout << "No encontrado" << endl;

    cout << "Cantidad: " << contar(pila) << endl;

    mostrarultimo(pila);

    return 0;
}
