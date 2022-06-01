#ifndef lista_H
#define lista_H

#include "Nodo.h"
#include "Producto.h"

using namespace std;

class listaD
{
    public:
        listaD();
        ~listaD();
        void insertaPos(Producto, int);
        void eliminar(string);
        void Buscar(string);
        void insertaInicio(Producto);
        void quick(Nodo*, Nodo*);
        void select();
        void insertaFinal(Producto);
        bool vacia();
        Nodo* anterior(string);
        Nodo* siguiente(string);
        int tamano();
        void Inicializa();
        Nodo* primero();
        Nodo* ultimo();
        void eliminarTodo();
        void mostrarTodo();
        Nodo* particion(Nodo*, Nodo*);
        void intercambio(Nodo*, Nodo*);


    private:
        Nodo *h;
        Nodo *t;
};

#endif // lista_H
