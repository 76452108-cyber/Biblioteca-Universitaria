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


int main(){
	Libro *lista = NULL;
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
            }while(subop!=0);
            break;
        }
    }while (op!=0);
    return 0;
}
	
	//lista enlazada
	
	
	//cola
	//estudiante *frente = NULL;
	//estudiante *anterior = NULL;
	
	//pila
	//devolucion *tope = NULL;