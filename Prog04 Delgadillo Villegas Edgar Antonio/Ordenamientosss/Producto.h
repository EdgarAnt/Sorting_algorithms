#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>

using namespace std;

class Producto
{
    public:
        void setId(int numId) {id=numId;}
        void setPrecio(float numPrecio) {precio=numPrecio;}
        int getId(void) {return id;}
        float getPrecio(void) {return precio;}
        string getProductos(void){return Productos;}
        Producto(string,float,int);
        Producto();
        ~Producto();
        void setProductos(string nom) {Productos=nom;}

    private:
        float precio;
        int id;
        string Productos;

};

#endif // PRODUCTO_H
