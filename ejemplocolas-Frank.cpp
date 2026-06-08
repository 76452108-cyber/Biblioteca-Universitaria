include <iostream>
using namespace std;

//estructura de la cola
struct estudiante{
    string nombre;
    estudiante *sig;
};


//atender estudiante
void atenderEstudiante(estudiante *&frente, estudiante *&final){
    if(frente == NULL){
        cout << "La cola esta vacia\n";
        return;
    }

    estudiante *aux = frente;

    cout << "Estudiante atendido: " << frente->nombre << endl;

    frente = frente->sig;

    if(frente == NULL){
        final = NULL;
    }

    delete aux;
}

//mostrar cola
void mostrarCola(estudiante *frente){
    if(frente == NULL){
        cout << "La cola esta vacia\n";
        return;
    }

    estudiante *aux = frente;

    cout << "\nCOLA DE ESTUDIANTES\n";

    while(aux != NULL){
        cout << aux->nombre << endl;
        aux = aux->sig;
    }
}
