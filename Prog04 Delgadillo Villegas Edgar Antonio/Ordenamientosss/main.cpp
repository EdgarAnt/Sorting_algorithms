#include <iostream>
#include <stdio.h>
#include "lista.h"
#include "Producto.h"

using namespace std;

int main()
{

    int opc, opc1, pos, id;
    float precio;
    string pro;
    Nodo *inicio, *fin;
    Producto Producto;
    listaD *lista = new listaD();
    do
    {
        system("cls");
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"                                       MENU                               "<<endl;
        cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
        cout <<"1) Insertar"<<endl;
        cout<<"2) Eliminar"<<endl;
        cout<<"3) Buscar"<<endl;
        cout<<"4) Vacia"<<endl;
        cout<<"5) Primero"<<endl;
        cout<<"6) Ultimo"<<endl;
        cout<<"7) Anterior"<<endl;
        cout<<"8) Siguiente"<<endl;
        cout<<"9) Tamanio"<<endl;
        cout<<"10) vaciar"<<endl;
        cout<<"11) Select sort"<<endl;
        cout<<"12) Quick sort"<<endl;
        cout<<"13) Mostrar lista"<<endl;
        cout<<"14) Salir"<<endl<<endl;
        cout<<"Opcion: ";
        cin >> opc;
        switch(opc)
        {
        case 1:
            {
                cout << endl;
                cout << "Opcion a insertar"<<endl;
                cout<<"1) Inicio"<<endl;
                cout<<"2) Final"<<endl<<endl;
                cout<<"Opcion: ";
                cin >> opc1;
                if(opc1==1)
                {
                    cout << endl;
                    cout << "Producto: ";
                    cin.ignore();
                    getline(cin, pro);
                    cout << "ID: ";
                    cin>>id;
                    cout << "Precio: ";
                    cin>>precio;
                    Producto.setProductos(pro);
                    Producto.setId(id);
                    Producto.setPrecio(precio);
                    cout << endl;
                    lista->insertaInicio(Producto);
                    lista->mostrarTodo();
                }
                else if(opc1==2)
                {
                    cout << endl;
                    cout << "Producto: ";
                    cin.ignore();
                    getline(cin, pro);
                    cout << "ID: ";
                    cin>>id;
                    cout << "Precio: ";
                    cin>>precio;
                    Producto.setProductos(pro);
                    Producto.setPrecio(precio);
                    Producto.setId(id);
                    cout << endl;
                    lista->insertaFinal(Producto);
                    lista->mostrarTodo();
                }
                else
                {
                    cout << endl;
                    cout << "No existe opcion...." << endl << endl;
                }
            break;
            }
        case 2:
            {
                cout << endl;
                cout << "¿Eliminar:   ";
                cin.ignore();
                getline(cin, pro);
                cout << endl;
                lista->eliminar(pro);
                lista->mostrarTodo();
            break;
            }
        case 3:
            {
                cout << endl;
                cout << "Producto:  ";
                cin.ignore();
                getline(cin, pro);
                cout << endl;
                lista->Buscar(pro);
                cout << endl;
            break;
            }
        case 4:
            {
                cout << endl;
                if(lista->vacia())
                    cout << "Lista vacia" << endl;
                else
                    cout << "Lista vacia" << endl;
            cout << endl;
            break;
            }
        case 5:
            {
                cout << endl;
                inicio=lista->primero();
                if(inicio)
                    cout << ", Precio: " << inicio->dato.getPrecio() << ", ID: " << inicio->dato.getId()<< "Producto: " << inicio->dato.getProductos()  << " " << endl;
                cout << endl;
            break;
            }
        case 6:
            {
                cout << endl;
                fin=lista->ultimo();
                if(fin)
                    cout  << ", Precio: $" << fin->dato.getPrecio() << ", ID: " << fin->dato.getId()<< "Producto: " << fin->dato.getProductos() << " " << endl;
                cout << endl;
            break;
            }
        case 7:
            {
                cout << endl;
                cout << "Deme el nombre de un producto: ";
                cin.ignore();
                getline(cin, pro);
                cout << endl;
                lista->anterior(pro);
                cout << endl;
            break;
            }
        case 8:
            {
                cout << endl;
                cout << "Deme el nombre de un producto: ";
                cin.ignore();
                getline(cin, pro);
                cout << endl;
                lista->siguiente(pro);
                cout << endl;
            break;
            }
        case 9:
            {
                cout << endl;
                lista->tamano();
                cout << endl;
            break;
            }
        case 10:
            {
                cout << endl;
                lista->eliminarTodo();
                cout << endl;
            break;
            }
        case 11:
            {
                cout << endl;
                lista->select();
            break;
            }
        case 12:
            {
                 cout << endl;
                 lista->quick(lista->primero(),lista->ultimo());
            break;
            }
        case 13:
            {
                system("cls");
                 cout << endl;
                 lista->mostrarTodo();
                    system("pause");
            break;
            }
        case 14:
            {
                cout << endl;
            break;
            }
        default:
            cout << endl << "Opcion no existe....." << endl << endl;
        }
    }while(opc!=14);
    return 0;
}
