#include <iostream>
#include <string>

using namespace std;

//SISTEMA DE MENUS
void menu(){
    cout<<"1. Libros"<<endl;
    cout<<"2. Colas"<<endl;
    cout<<"3. Devoluciones"<<endl;
    cout<<"0. Salir"<<endl;
}
void menulibros(){
    cout<<"1. Agregar libros"<<endl;
    cout<<"2. Mostrar Libros"<<endl;
    cout<<"3. Buscar libro"<<endl;
    cout<<"4. Eliminar libro"<<endl;
    cout<<"0. atras"<<endl;
}
void menucola(){
    cout<<"1. Agregar estudiante a la cola"<<endl;
    cout<<"2. Atender estudiante"<<endl;
    cout<<"3. Mostrar cola"<<endl;
    cout<<"0. Atras"<<endl;
}
void menudevolucion(){
    cout<<"1. Registrar devolucion"<<endl;
    cout<<"2. Mostrar devoluciones"<<endl;
    cout<<"3. Buscar devolucion"<<endl;
    cout<<"4. Contar devoluciones"<<endl;
    cout<<"5. Eliminar ultima devolucion"<<endl;
    cout<<"0. Atras"<<endl;
}



//LISTAS LIBROS (insertar, mostrar, buscar y borrar)
struct Libro{
	int id;
	string titulo;
	string autor;
	
	Libro *sig;	
};

void insertarlibro(Libro *&lista, int id, string titulo, string autor){
	Libro *nuevo = new Libro;
	
	nuevo->id = id;
	nuevo->titulo = titulo;
	nuevo->autor = autor;

	nuevo->sig = lista;
	
	lista = nuevo;	
}

void mostrarLibros(Libro *lista){

    Libro *aux = lista;

    cout<<"\nLIBROS REGISTRADOS\n\n";

    while(aux != NULL){
        cout<<"------------------\n";
        cout<<"ID: "<<aux->id<<endl;
        cout<<"Titulo: "<<aux->titulo<<endl;
        cout<<"Autor: "<<aux->autor<<endl;
        cout<<"------------------\n";

        aux = aux->sig;
    }
}

void buscarlibro(Libro *lista, string titulo){

    while(lista != NULL){

        if(lista->titulo == titulo){
            cout<<"Libro encontrado\n";
            cout<<"------------------\n";
            cout<<"ID: "<<lista->id<<endl;
            cout<<"Titulo: "<<lista->titulo<<endl;
            cout<<"Autor: "<<lista->autor<<endl;
            cout<<"------------------\n";
            return;
        }

        lista = lista->sig;
    }

    cout<<"Libro no encontrado\n";
}

void eliminarlibro(Libro *lista, int id){
	Libro *aux = lista;
	Libro *anterior = NULL;
	
	while(aux != NULL && aux->id != id){
		anterior = aux;
		aux = aux->sig;		
	}
	if (aux == NULL)
		return;
	
	if(anterior == NULL)
		lista = aux->sig;
	else
		anterior->sig = aux->sig;
		
	delete aux;
}

//struct para colas (insertar, mostrar, buscar y borrar)
struct estudiante{
	string nombre;
	
	estudiante *sig;
	
};

//struct para pilas (insertar, mostrar, buscar y borrar)
struct devolucion{
	string libro;
	
	devolucion *sig;
};

// ===== PILA DE DEVOLUCIONES - FUNCIONES STACK =====
// Registrar devolución (push)
void registrar(devolucion *&pila, string libro){

    devolucion *nuevo = new devolucion;

    nuevo->libro = libro;
    nuevo->sig = pila;

    pila = nuevo;
}

// Mostrar todas las devoluciones
void mostrarDevoluciones(devolucion *pila){

    if(pila == NULL){
        cout << "No hay devoluciones registradas" << endl;
        return;
    }

    while(pila != NULL){
        cout << "- " << pila->libro << endl;
        pila = pila->sig;
    }

    cout << endl;
}

// Buscar libro en devoluciones
bool buscarDevolucion(devolucion *pila, string libro){

    while(pila != NULL){

        if(pila->libro == libro){
            return true;
        }

        pila = pila->sig;
    }

    return false;
}

// Contar total de devoluciones
int contarDevoluciones(devolucion *pila){

    int contador = 0;

    while(pila != NULL){

        contador++;

        pila = pila->sig;
    }

    return contador;
}

// Eliminar última devolución (pop)
void eliminarDevolucion(devolucion *&pila){

    if(pila == NULL){
        cout << "No hay devoluciones para eliminar" << endl;
        return;
    }

    devolucion *aux = pila;
    cout << "Eliminando devolucion: " << aux->libro << endl;

    pila = pila->sig;

    delete aux;
}

// Mostrar última devolución registrada
void mostrarUltimo(devolucion *pila){

    if(pila == NULL){
        cout << "No hay devoluciones" << endl;
        return;
    }

    cout << "Ultima devolucion registrada: " << pila->libro << endl;
}

int main(){
	Libro *lista = NULL;
	devolucion *pila = NULL;
	
	//MENU GLOBAL
    int op;
    int subop;
    do{
        menu();
        cout<<"Ingrese opcion: ";
        cin>>op;
        switch(op){
        
        case 1:
            do{
            menulibros();
            cout<<"Ingrese opcion: ";
            cin>>subop;
            switch(subop){
            	case 1:{
            		int id;
            		string titulo;
            		string autor;
            		
            		cout<<"ID: ";
            		cin>>id;
            		
            		cin.ignore();
            		
            		cout<<"Titulo: ";
            		getline(cin, titulo);
            		
            		cout<<"Autor: ";
            		getline(cin, autor);
            		
            		insertarlibro(lista, id, titulo, autor);
            		cout<<"Libro Ingresado Correctamente.\n";
					break;
				}
				case 2:{
					mostrarLibros(lista);
					break;
				}
				case 3:{
					//buscarlibro
					string titulo;

    				cin.ignore();

    				cout<<"Ingrese el titulo a buscar: ";
    				getline(cin, titulo);

    				buscarlibro(lista, titulo);
    				break;
				}
			}
            
            }while (subop!=0);
            break;
        case 2:
            do{
                menucola();
                cout<<"Ingrese opcion: ";
                cin>>subop;
            }while(subop!=0);
            break;
        case 3:
            do{
                menudevolucion();
                cout<<"Ingrese opcion: ";
                cin>>subop;
                
                switch(subop){
                    case 1:{
                        string libro;
                        cin.ignore();
                        cout<<"Ingrese nombre del libro a devolver: ";
                        getline(cin, libro);
                        registrar(pila, libro);
                        cout<<"Devolucion registrada.\n";
                        break;
                    }
                    case 2:{
                        cout<<"\nDEVOLUCIONES REGISTRADAS:\n";
                        mostrarDevoluciones(pila);
                        break;
                    }
                    case 3:{
                        string libro;
                        cin.ignore();
                        cout<<"Ingrese nombre del libro a buscar: ";
                        getline(cin, libro);
                        if(buscarDevolucion(pila, libro))
                            cout<<"Devolucion encontrada.\n";
                        else
                            cout<<"Devolucion no encontrada.\n";
                        break;
                    }
                    case 4:{
                        cout<<"Total de devoluciones: "<<contarDevoluciones(pila)<<endl;
                        break;
                    }
                    case 5:{
                        eliminarDevolucion(pila);
                        break;
                    }
                }
            }while(subop!=0);
            break;
        }
    }while (op!=0);
    return 0;
}
