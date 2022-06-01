#include "lista.h"
#include "Producto.h"
#include <iostream>

using namespace std;



void listaD::insertaPos(Producto pro, int pos)
{
    Nodo *tmp = new Nodo();
    tmp->dato = pro;
    Nodo *aux = h;
    bool band = true;
    int i = 1;
    if(vacia())
    {
        h=tmp;
        t=tmp;
    }
    else
    {
        while(aux && band)
        {
            if(i == pos)
            {
                band = false;
            }
            else
            {
                aux = aux->sig;
            }
            i++;
        }
        if(aux==nullptr)
        {
            t->sig=tmp;
            tmp->ant=t;
            t=tmp;
            cout << "Posicion no valida, se ha agregado al final." << endl << endl;
        }
        else if(aux->ant==nullptr)
        {
            tmp->sig=h;
            h->ant=tmp;
            h=tmp;
        }
        else
        {
            tmp->sig=aux->ant->sig;
            aux->ant->sig=tmp;
            tmp->ant=aux->ant;
            aux->ant=tmp;
        }
    }
}


void listaD::insertaInicio(Producto pro)
{
    Nodo *tmp = new Nodo();
    tmp->dato = pro;
    if (vacia())
    {
        h = tmp;
        t = tmp;
    }
    else
    {
        tmp->sig = h;
        h->ant = tmp;
        h = tmp;
    }
}


Nodo* listaD::siguiente(string pro)
{
	Nodo *aux = h;
	bool band=true;
	if(h)
    {
        while(aux && band)
        {
            if(aux->dato.getProductos()!=pro)
            {
                aux=aux->sig;
            }
            else
            {
                band=false;
            }
        }
        if(aux==nullptr)
        {
            cout << "Producto no existe" << endl;
            return nullptr;
        }
        else if(aux->sig==nullptr)
        {
            cout << "No hay producto " << endl;
            return nullptr;
        }
        else
        {
            cout << "Producto " << pro << " es: "<< aux->sig->dato.getProductos() << ", Precio: $" << aux->sig->dato.getPrecio() << ", ID: " << aux->sig->dato.getId() << ". " << endl;
        }
    }
    else
    {
        cout << "Lista vacia " << endl;
        return nullptr;
    }
}


void listaD::insertaFinal(Producto pro)
{
    Nodo *tmp = new Nodo();
    tmp->dato = pro;
    if(vacia())
    {
        h = tmp;
        t = tmp;
    }
    else
    {
        t->sig = tmp;
        tmp->ant = t;
        t = tmp;
    }
}

void listaD::eliminar(string pro)
{
    Nodo *aux=h;
    bool band=true;

    if(aux)
    {
        while(aux && band)
        {
            if(aux->dato.getProductos()==pro)
            {
                band=false;
            }
            else
            {
                aux=aux->sig;
            }
        }
        if((aux==h)and(aux==t))
        {
            delete aux;
            Inicializa();
        }
        else
        {
            if (aux==nullptr)
            {
                cout << "Producto no encontrado" <<endl<<endl;
            }
            else if(aux==h)
            {
                h=h->sig;
                if(h)
                    h->ant=nullptr;
                delete(aux);
            }
            else if(aux==t)
            {
                t=t->ant;
                if(t)
                    t->sig=nullptr;
                delete(aux);
            }
            else
            {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
                delete(aux);
            }
        }

    }
    else
    {
        cout;
    }
}

void listaD::Buscar(string pro)
{
    Nodo *aux = h;
    int cont = 1;
    int cont2 = 0;

    while (aux)
    {
          if (aux->dato.getProductos() == pro)
          {
              cout << "El producto " << pro << " se encuentra en la posicion: " << cont << endl;
              cont2++;
          }
          aux = aux->sig;
          cont++;
    }
    if (cont2 == 0)
    {
        cout << "No existe el producto" << endl;
    }
}

bool listaD::vacia()
{
    if(h==nullptr and t==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void listaD::Inicializa()
{
    h = nullptr;
    t = nullptr;
}

Nodo* listaD::primero()
{
    Nodo *primero=new Nodo();
    if(vacia())
    {
        cout << "Lista vacia" << endl;
        return nullptr;
    }
    else
        primero=h;
        return primero;
}

Nodo* listaD::ultimo()
{
    Nodo *ultimo = new Nodo();
    if(vacia())
    {
        cout << "Lista vacia" << endl;
        return nullptr;
    }
    else
    {
        ultimo=t;
        return ultimo;
    }
}

Nodo* listaD::anterior(string pro)
{
	Nodo *aux = h;
	bool band = true;

	if(aux)
    {
		while(aux && band)
		{
			if(aux->dato.getProductos() != pro)
			{
				aux = aux->sig;
			}
			else
			{
				band = false;
			}
        }

		if(aux == h)
        {
			cout << "Es el primer producto " << endl;
			return aux;
		}
		else if(aux == nullptr)
		{
			cout << "No existe " << endl;
			return nullptr;
		}
		else
		{
				cout << "Producto anterior a " << pro << " es: "<< aux->ant->dato.getProductos() << ", Precio: " << aux->ant->dato.getPrecio() << ", ID: " << aux->ant->dato.getId() << ". " << endl;
				return aux->ant;
		}
	}
	else
	{
	    cout << "Lista vacia" << endl;
	    return nullptr;
	}
}


void listaD::mostrarTodo()
{
    Nodo *aux = h;
    if(aux)
    {
        while(aux)
        {
            cout << "Producto: " << aux->dato.getProductos() << ", Precio: " << aux->dato.getPrecio() << ", ID: " << aux->dato.getId() << ". " << endl;
            aux = aux->sig;
        }
        cout << endl;
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}



int listaD::tamano()
{
    int cont = 0;
    Nodo *aux = h;
    while(aux)
    {
        cont++;
        aux = aux->sig;
    }
    cout <<  "Numero de productos: " << cont << endl;
    return cont;
}

void listaD::select()
{
    Nodo *tmp,*tmp2=new Nodo();
    Producto aux;
    if(vacia())
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        tmp=h;
        while(tmp)
        {
            tmp2=tmp->sig;
            while(tmp2)
            {
                if ((tmp->dato.getId())>(tmp2->dato.getId()))
                {
                    aux = tmp2->dato;
                    tmp2->dato = tmp->dato;
                    tmp->dato = aux;
                }
                tmp2=tmp2->sig;
            }
            tmp=tmp->sig;
        }
    }
}



void listaD::eliminarTodo()
{
    Nodo *aux=new Nodo();
    if(vacia())
        cout << "La lista esta vacia" << endl;
    else
    {
        while(h!=nullptr)
        {
            aux=h;
            h=aux->sig;
            delete aux;
        }
        cout << "La lista ha sido vaciada" << endl;
    }
}

void listaD::intercambio(Nodo *a, Nodo *b)
{
    Producto aux;
    aux=a->dato;
    a->dato=b->dato;
    b->dato=aux;
}

Nodo* listaD::particion(Nodo *cabeza, Nodo *cola)
{
    Nodo *pivote = cola;
    Nodo *i;
    i=cabeza->ant;
    Nodo *j=cabeza;
    while(j!=cola)
    {
        if (j->dato.getId() <= pivote->dato.getId())
        {
            if(i==nullptr)
            {
                i=cabeza;
            }
            else
            {
                i=i->sig;
            }
        }
        j = j->sig;
    }
    if(i==nullptr)
    {
        i=cabeza;
    }
    else
    {
        i=i->sig;
    }
    intercambio(i, pivote);
    return i;
}

void listaD::quick(Nodo *cabeza, Nodo *cola)
{
    if (cola != nullptr && cabeza != cola && cabeza != cola->sig)
    {
        Nodo *p = particion(cabeza, cola);
        quick(cabeza, p->ant);
        quick(p->sig, cola);
    }

}

listaD::listaD()
{
    Inicializa();
    //ctor
}

listaD::~listaD()
{
    //dtor
}
