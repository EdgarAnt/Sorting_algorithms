#include <iostream>
#ifndef NODO_H
#define NODO_H
#include "Producto.h"

using namespace std;

class Nodo
{
    public:
        Nodo();
        ~Nodo();

        Producto dato;
        Nodo *sig;
        Nodo *ant;

    //private:
};

#endif // NODO_H
