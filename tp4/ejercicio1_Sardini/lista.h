#ifndef _LISTA_H_
#define _LISTA_H_

#include "nodo_lista.h"

template<typename Dato>
class Lista {
private:
    Nodo_Lista<Dato>* primero;
    Nodo_Lista<Dato>* cursor;
    int cantidad;

public:
    /*
    PRE: -
    POST: Construye una lista con los atributos dados por defecto.
    */
    Lista();

    ~Lista();

    /*
    PRE: Recibe como parámetro un Dato y un entero.
    POST: Da de alta un dato en la posición de la lista deseada.
    */
    void alta(Dato d, int pos);

    /*
    PRE: Recibe como parámetro un entero.
    POST: Da de baja el dato de la posición recibida en la lista.
    */
    void baja(int pos);

    /*
    PRE: Recibe como parámetro un enterp.
    POST: Devuelve el dato contenido en la posición de la lista.
    */
    Dato consulta(int pos);

    /*
    PRE: -
    POST: Devuelve la cantidad de elementos de la lista.
    */
    int obtener_cantidad();

    /*
    PRE: Recibe como parámetro un entero.
    POST: Devuelve un puntero al Nodo ubicado en la posición recibida.
    */
    Nodo_Lista<Dato>* obtener_nodo(int pos);

    /*
    PRE: -
    POST: Pone el cursor en primero.
    */
    void reiniciar_cursor();

    /*
    PRE: Ingresar una cantidad positiva como parámetro.
    POST: Modifica la cantidad de la lista según la recibida por parámetro.
    */
    void cambiar_cantidad(int cantidad);

};

template<typename Dato>
Lista<Dato>::Lista() {
    primero = nullptr;
    cursor = primero;
    cantidad = 0;
}


template<typename Dato>
void Lista<Dato>::alta(Dato d, int pos) {
    Nodo_Lista<Dato>* nuevo = new Nodo_Lista<Dato>(d);
    if (cantidad == 0)
        cursor = nuevo;
    if (pos == 1){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo_Lista<Dato>* anterior = obtener_nodo(pos-1);
        Nodo_Lista<Dato>* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

template<typename Dato>
void Lista<Dato>::baja(int pos) {
    Nodo_Lista<Dato>* borrar = primero;
    if (pos == 1) {
        primero = borrar->obtener_siguiente();
        cursor = primero;
    } else {
        Nodo_Lista<Dato>* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo_Lista<Dato>* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;
    cantidad--;
}

template<typename Dato>
Dato Lista<Dato>::consulta(int pos) {
    Nodo_Lista<Dato>* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

template<typename Dato>
int Lista<Dato>::obtener_cantidad() {
    return cantidad;
}
template<typename Dato>
void Lista<Dato>::reiniciar_cursor() {
    cursor = primero;
}

template<typename Dato>
Lista<Dato>::~Lista() {
    while (cantidad > 0)
        baja(1);
}

template<typename Dato>
Nodo_Lista<Dato>* Lista<Dato>::obtener_nodo(int pos){
    Nodo_Lista<Dato>* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

template<typename Dato>
void Lista<Dato>::cambiar_cantidad(int cantidad) {
    this->cantidad = cantidad;
}

#endif // _LISTA_H_
