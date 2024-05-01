#ifndef __ABB_H__
#define __ABB_H__

#include <iostream>
#include "Nodo.h"
using namespace std;

template <class T>
class ABB
{
    private:
        Nodo<T>* raiz;
        int cantidad;

        //PRE: --
        //POST: Agrega un nodo con el dato dado al árbol
        void insertar(Nodo<T>* nodo, T dato, Aeropuerto* datos_aeropuerto);

        //PRE: --
        //POST: Elimina el nodo del árbol, mantiene el arbol ordenado
        void eliminar(Nodo<T>* nodo);

        //PRE: --
        //POST: Recorre desde el nodo en preorden
        void pre_orden(Nodo<T>* nodo);

        //PRE: --
        //POST: Recorre desde el nodo en inorden
        void in_orden(Nodo<T>* nodo);

        //PRE: --
        //POST: Recorre desde el nodo en postorden
        void post_orden(Nodo<T>* nodo);

        //PRE: --
        //POST: Busca el nodo con el dato dado en el árbol, si no lo encuentra devuelve nullptr
        Nodo<T>* buscar(Nodo<T>* nodo, T dato);

        //PRE: --
        //POST: Devuelve el nodo inmediato predecesor al nodo dado
        Nodo<T>* obtener_inmediato_sucesor(Nodo<T>* nodo);

        //PRE: --
        //POST: Devuelve el nodo inmediato sucesor al nodo dado
        Nodo<T>* obtener_inmediato_predecesor(Nodo<T>* nodo);

        //PRE: --
        //POST: Busca el aeropuerto con el dato dado en el árbol, si no lo encuentra devuelve nullptr
        Aeropuerto* buscar_aeropuerto(Nodo<T>* nodo, T dato);
        
    public:

        ABB();

        //PRE: --
        //POST: Agrega el dato al árbol
        void insertar(T dato, Aeropuerto* datos_aeropuerto);

        //PRE: --
        //POST: Elimina el dato del árbol
        void eliminar(T dato);

        //PRE: --
        //POST: Indica si el dato está en el árbol
        bool esta_en_el_arbol(T dato);

        //PRE: --
        //POST: Recorre el árbol en preorden
        void pre_orden();

        //PRE: --
        //POST: Recorre el árbol en inorden
        void in_orden();

        //PRE: --
        //POST: Recorre el árbol en postorden
        void post_orden();

        //PRE: --
        //POST: Devuelve un puntero al aeropuerto buscado.
        Aeropuerto* buscar_aeropuerto(T dato);

        //PRE: --
        //POST: Devuelve un la cantidad de elementos en el árbol.
        int obtener_cantidad();

        ~ABB();
};

template <class T>
ABB<T>::ABB() {
    raiz = nullptr;
    cantidad = 0;
}

template <class T>
ABB<T>::~ABB() {
    delete raiz;
}

template <class T>
int ABB<T>::obtener_cantidad(){
    return cantidad;
}

template <class T>
void ABB<T>::insertar(T dato, Aeropuerto* datos_aeropuerto) {
    if (raiz == nullptr) {
        raiz = new Nodo<T>(dato, datos_aeropuerto);
        cantidad++;
    } else if (!esta_en_el_arbol(dato)){
        insertar(raiz, dato, datos_aeropuerto);
    }
}

template <class T>
void ABB<T>::insertar(Nodo<T>* nodo, T dato, Aeropuerto* datos_aeropuerto) {
    if (dato < nodo->obtener_dato()) {
        if (nodo->obtener_hijo_izquierdo() == nullptr) {
            nodo->asignar_hijo_izquierdo(new Nodo<T>(dato, datos_aeropuerto));
            cantidad++;
        } else {
            insertar(nodo->obtener_hijo_izquierdo(), dato, datos_aeropuerto);
        }
    } else {
        if (nodo->obtener_hijo_derecho() == nullptr) {
            nodo->asignar_hijo_derecho(new Nodo<T>(dato, datos_aeropuerto));
            cantidad++;
        } else {
            insertar(nodo->obtener_hijo_derecho(), dato, datos_aeropuerto);
        }
    }
}

template <class T>
bool ABB<T>::esta_en_el_arbol(T dato) {
    return buscar(raiz, dato) != nullptr;
}

template <class T>
Aeropuerto* ABB<T>::buscar_aeropuerto(T dato){
    return buscar_aeropuerto(raiz, dato);
}

template <class T>
Aeropuerto* ABB<T>::buscar_aeropuerto(Nodo<T>* nodo, T dato){
    if (nodo == nullptr){
        cout << "No existe el aeropuerto";
    }
    if (dato == nodo->obtener_dato()){
        return nodo->obtener_aeropuerto();
    }
    if (dato < nodo->obtener_dato()){
        return buscar_aeropuerto(nodo->obtener_hijo_izquierdo(), dato);
    }
    return buscar_aeropuerto(nodo->obtener_hijo_derecho(), dato);
}


template <class T>
Nodo<T>* ABB<T>::buscar(Nodo<T>* nodo, T dato) {
    if (nodo == nullptr){
        return nullptr;
    }
    if (dato == nodo->obtener_dato()){
        return nodo;
    }
    if (dato < nodo->obtener_dato()){
        return buscar(nodo->obtener_hijo_izquierdo(), dato);
    }
    return buscar(nodo->obtener_hijo_derecho(), dato);
}

template <class T>
Nodo<T>* ABB<T>::obtener_inmediato_predecesor(Nodo<T>* nodo) {
    Nodo<T>* predecesor = nodo->obtener_hijo_izquierdo();
    while (predecesor->obtener_hijo_derecho() != nullptr) {
        predecesor = predecesor->obtener_hijo_derecho();
    }
    return predecesor;
}

template <class T>
Nodo<T>* ABB<T>::obtener_inmediato_sucesor(Nodo<T>* nodo) {
    Nodo<T>* sucesor = nodo->obtener_hijo_derecho();
    while (sucesor->obtener_hijo_izquierdo() != nullptr) {
        sucesor = sucesor->obtener_hijo_izquierdo();
    }
    return sucesor;
}

template <class T>
void ABB<T>::eliminar(T dato)
{
    if (raiz != nullptr)
    {
        Nodo<T> *nodo = buscar(raiz, dato);
        if (nodo != nullptr)
        {
            eliminar(nodo);
            if (nodo == raiz)
            {
                raiz = nullptr;
            }
        }
    }
}

template <class T>
void ABB<T>::eliminar(Nodo<T> *nodo)
{
    if (nodo->obtener_hijo_izquierdo() != nullptr && nodo->obtener_hijo_derecho() != nullptr)
    {
        Nodo<T> *predecesor = obtener_inmediato_predecesor(nodo);
        nodo->asignar_dato(predecesor->obtener_dato());
        nodo->asignar_aeropuerto(predecesor->obtener_aeropuerto());
        eliminar(predecesor);
    }
    else if (nodo->obtener_hijo_izquierdo() != nullptr || nodo->obtener_hijo_derecho() != nullptr)
    {
        if (nodo->obtener_hijo_izquierdo() != nullptr)
        {
            Nodo<T> *predecesor = obtener_inmediato_predecesor(nodo);
            nodo->asignar_dato(predecesor->obtener_dato());
            nodo->asignar_aeropuerto(predecesor->obtener_aeropuerto());
            eliminar(predecesor);
        }
        else
        {
            Nodo<T> *sucesor = obtener_inmediato_sucesor(nodo);
            nodo->asignar_dato(sucesor->obtener_dato());
            nodo->asignar_aeropuerto(sucesor->obtener_aeropuerto());
            eliminar(sucesor);
        }
    }
    else if (nodo == raiz)
    {
        delete raiz;
        raiz = nullptr;
        cantidad--;
    }
    else
    {
        nodo->obtener_padre()->remover_hijo(nodo);
        delete nodo;
        cantidad--;
    }
}


template <class T>
void ABB<T>::pre_orden() {
    pre_orden(raiz);
    std::cout << "\n";
}

template <class T>
void ABB<T>::pre_orden(Nodo<T>* nodo) {
    if (nodo != nullptr){
        std::cout << nodo->obtener_dato() << " ";
        pre_orden(nodo->obtener_hijo_izquierdo());
        pre_orden(nodo->obtener_hijo_derecho());
    }
}

template <class T>
void ABB<T>::in_orden() {
    in_orden(raiz);
    std::cout << "\n";
}

template <class T>
void ABB<T>::in_orden(Nodo<T>* nodo) {
    if (nodo != nullptr){
        in_orden(nodo->obtener_hijo_izquierdo());
        std::cout << nodo->obtener_dato() << " ";
        in_orden(nodo->obtener_hijo_derecho());
    }
}

template <class T>
void ABB<T>::post_orden() {
    post_orden(raiz);
    std::cout << "\n";
}

template <class T>
void ABB<T>::post_orden(Nodo<T>* nodo) {
    if (nodo != nullptr){
        post_orden(nodo->obtener_hijo_izquierdo());
        post_orden(nodo->obtener_hijo_derecho());
        std::cout << nodo->obtener_dato() << " ";
    }
}


#endif
