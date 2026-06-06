#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *sig;	
};

void insertarinicio(nodo *&lista, int valor){
	nodo *nuevo = new nodo;
	
	nuevo->dato = valor;
	nuevo->sig = lista;
	
	lista = nuevo;	
}

void mostrar(nodo *lista){
	while(lista != NULL){
		cout<<lista->dato<<" ";
		lista = lista->sig;
	}
	cout<<endl;
}

void insertarfinal(nodo *&lista, int valor){
	nodo *nuevo = new nodo;
	
	nuevo->dato = valor;
	nuevo->sig = NULL;	
	
	if(lista == NULL){
		lista = nuevo;
	}
	else{
		nodo *aux = lista;
		
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		
		aux->sig = nuevo;
	}
}

bool buscar(nodo *lista, int valor){
	while(lista != NULL){
		if(lista->dato == valor){
			return true;			
		}
		
		lista = lista->sig;
	}
	
	return false;
	
}

int contar(nodo *lista){
	int contador = 0;
	
	while(lista != NULL){
		contador++;
		lista = lista->sig;
	}	
	
	return contador;
}

//eliminar 1er nodo
void eliminarinicio(nodo *&lista){
	if(lista == NULL){
		return;
	}
	nodo *aux = lista;
	lista = lista->sig;
	
	delete aux;
}

//eliminar nodo en especifico
void eliminar(nodo *&lista, int valor) {

    nodo *aux = lista;
    nodo *anterior = NULL;

    while(aux != NULL && aux->dato != valor) {
        anterior = aux;
        aux = aux->sig;
    }

    if(aux == NULL)
        return;

    if(anterior == NULL)
        lista = aux->sig;
    else
        anterior->sig = aux->sig;

    delete aux;
}

//insertar ordenado(no estudiado)
void insertarordenado(nodo *&lista, int valor) {

    nodo *nuevo = new nodo;

    nuevo->dato = valor;

    nodo *aux = lista;
    nodo *anterior = NULL;

    while(aux != NULL && aux->dato < valor) {
        anterior = aux;
        aux = aux->sig;
    }

    if(anterior == NULL) {

        nuevo->sig = lista;
        lista = nuevo;
    }
    else {

        anterior->sig = nuevo;
        nuevo->sig = aux;
    }
}

//funcion eliminafinal (no estudiado)
void eliminafinal(nodo *&lista) {

    if(lista == NULL)
        return;

    // Caso: solo hay un nodo
    if(lista->sig == NULL) {
        delete lista;
        lista = NULL;
        return;
    }

    nodo *aux = lista;

    while(aux->sig->sig != NULL) {
        aux = aux->sig;
    }

    delete aux->sig;
    aux->sig = NULL;
}

int main(){
	nodo *lista = NULL;
	
	insertarinicio(lista, 10);
	insertarinicio(lista, 20);
	insertarinicio(lista, 30);
	insertarfinal(lista, 40);
	insertarfinal(lista, 50);
	eliminarinicio(lista);
	eliminar(lista, 40);
	eliminar(lista, 10);
	insertarordenado(lista, 30);
	insertarordenado(lista, 40);
	insertarordenado(lista, 10);
	insertarordenado(lista, 20);
	eliminafinal(lista); //quedaria hasta el 40

	if(buscar(lista,20))
		cout<<"Encontrado";
	else
		cout<<"No encontrado";

	mostrar(lista);
	return 0;
}