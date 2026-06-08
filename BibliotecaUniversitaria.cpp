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

void eliminarlibro(Libro *&lista, int id){
	Libro *aux = lista;
	Libro *anterior = NULL;
	
	while(aux != NULL && aux->id != id){
		anterior = aux;
		aux = aux->sig;		
	}
	if (aux == NULL){
		cout<<"Libro no encontrado\n";
		return;
	}
	
	if(anterior == NULL)
		lista = aux->sig;
	else
		anterior->sig = aux->sig;
		
	delete aux;
	cout<<"Libro eliminado correctamente\n";
}

//struct para colas (insertar, mostrar, buscar y borrar)
struct estudiante{
	string nombre;
	
	estudiante *sig;
	
};

//FUNCIONES PARA COLA
void insertarEstudiante(estudiante *&frente, estudiante *&final, string nombre){
	estudiante *nuevo = new estudiante;
	nuevo->nombre = nombre;
	nuevo->sig = NULL;
	
	if(frente == NULL){
		frente = nuevo;
	}else{
		final->sig = nuevo;
	}
	final = nuevo;
}

void atenderEstudiante(estudiante *&frente){
	if(frente == NULL){
		cout<<"No hay estudiantes en la cola\n";
		return;
	}
	
	estudiante *aux = frente;
	cout<<"Estudiante atendido: "<<frente->nombre<<endl;
	frente = frente->sig;
	delete aux;
}

void mostrarCola(estudiante *frente){
	estudiante *aux = frente;
	
	cout<<"\nCOLA DE ESTUDIANTES\n\n";
	
	if(frente == NULL){
		cout<<"La cola esta vacia\n";
		return;
	}
	
	while(aux != NULL){
		cout<<"------------------\n";
		cout<<"Estudiante: "<<aux->nombre<<endl;
		cout<<"------------------\n";
		
		aux = aux->sig;
	}
}

//struct para pilas (insertar, mostrar, buscar y borrar)
struct devolucion{
	string libro;
	
	devolucion *sig;
};

//FUNCIONES PARA PILA (Stack de devoluciones)
void insertarDevolucion(devolucion *&tope, string libro){
	devolucion *nuevo = new devolucion;
	
	nuevo->libro = libro;
	nuevo->sig = tope;
	
	tope = nuevo;
}

void mostrarDevoluciones(devolucion *tope){
	devolucion *aux = tope;
	
	cout<<"\nDEVOLUCIONES REGISTRADAS\n\n";
	
	while(aux != NULL){
		cout<<"------------------\n";
		cout<<"Libro: "<<aux->libro<<endl;
		cout<<"------------------\n";
		
		aux = aux->sig;
	}
}

void extraerDevolucion(devolucion *&tope){
	if(tope == NULL){
		cout<<"No hay devoluciones registradas\n";
		return;
	}
	
	devolucion *aux = tope;
	cout<<"Devolucion extraida: "<<tope->libro<<endl;
	tope = tope->sig;
	delete aux;
}

void vaciarPila(devolucion *&tope){
	while(tope != NULL){
		devolucion *aux = tope;
		tope = tope->sig;
		delete aux;
	}
	cout<<"Pila vaciada correctamente\n";
}

int main(){
	Libro *lista = NULL;
	estudiante *frente = NULL;
	estudiante *final = NULL;
	devolucion *tope = NULL;
	
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
				case 4:{
					int id;
					cout<<"Ingrese el ID del libro a eliminar: ";
					cin>>id;
					eliminarlibro(lista, id);
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
                switch(subop){
                	case 1:{
                		string nombre;
                		cin.ignore();
                		cout<<"Ingrese nombre del estudiante: ";
                		getline(cin, nombre);
                		insertarEstudiante(frente, final, nombre);
                		cout<<"Estudiante agregado a la cola\n";
                		break;
					}
					case 2:{
						atenderEstudiante(frente);
						break;
					}
					case 3:{
						mostrarCola(frente);
						break;
					}
				}
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
                		insertarDevolucion(tope, libro);
                		cout<<"Devolucion registrada\n";
                		break;
					}
					case 2:{
						mostrarDevoluciones(tope);
						break;
					}
				}
            }while(subop!=0);
            break;
        }
    }while (op!=0);
    
    vaciarPila(tope);
    return 0;
}
