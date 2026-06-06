#include <iostream>
#include <string>
using namespace std;
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
int main(){
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