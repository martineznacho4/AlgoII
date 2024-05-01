#ifndef __NODO_H__
#define __NODO_H__

#include <iostream>
#include "aeropuerto.h"

template <class T>
class Nodo
{
    private:
        T dato; //esto va a ser la clave del aeropuerto
        Nodo<T>* hijo_izquierdo;
        Nodo<T>* hijo_derecho;
        Nodo<T>* padre;
        Aeropuerto* datos_aeropuerto; //puntero a todos los datos del aeropuerto
    public:
        /*
        Pre: Recibe por parámetro un dato y un puntero a Aeropuerto.
        Post: Genera el nodo con los parámetros recibidos.
        */
        Nodo(T dato, Aeropuerto* datos_aeropuerto);

        /*
        Pre: - 
        Post: Se encarga de liberar la memoria.
        */
        ~Nodo();

        /*
        Pre: - 
        Post: Devuelve el dato que contiene el nodo.
        */
        T obtener_dato();

        /*
        Pre: - 
        Post: Devuelve el hijo izquierdo del nodo.
        */
        Nodo<T>* obtener_hijo_izquierdo();

        /*
        Pre: - 
        Post: Devuelve el hijo derecho del nodo.
        */
        Nodo<T>* obtener_hijo_derecho();

        /*
        Pre: Recibe un dato por parámetro.
        Post: Asigna el dato recibido por parámetro al nodo.
        */
        void asignar_dato(T dato);

        /*
        Pre: Recibe un puntero a Nodo por parámetro.
        Post: Asigna el Nodo recibido al hijo izquierdo del nodo.
        */
        void asignar_hijo_izquierdo(Nodo<T>* hijo_izquierdo);

        /*
        Pre: Recibe un puntero a Nodo por parámetro.
        Post: Asigna el Nodo recibido al hijo derecho del nodo.
        */
        void asignar_hijo_derecho(Nodo<T>* hijo_derecho);

        /*
        Pre: Recibe un puntero a Nodo por parámetro.
        Post: Asigna el Nodo recibido al padre del nodo.
        */
        void asignar_padre(Nodo<T>* padre);

        /*
        Pre: - 
        Post: Devuelve el padre del nodo.
        */
        Nodo<T>* obtener_padre();

        /*
        Pre: - 
        Post: Devuelve el puntero al aeropuerto que contiene el nodo.
        */
        Aeropuerto* obtener_aeropuerto();

        /*
        Pre: Recibe un puntero a Nodo por parámetro.
        Post: Remueve el hijo recibido por parámtro al nodo.
        */
        void remover_hijo(Nodo<T>* hijo);

        /*
        Pre: El parámetro debe ser un puntero a aeropuerto.
        Post: Asigna al Nodo el aeropuerto recibido.
        */
        void asignar_aeropuerto(Aeropuerto* aeropuerto);
};

template <class T>
Nodo<T>::Nodo(T dato, Aeropuerto* datos_aeropuerto) {
    this->dato = dato;
    this->hijo_izquierdo = nullptr;
    this->hijo_derecho = nullptr;
    this->datos_aeropuerto = datos_aeropuerto;
}

template <class T>
Nodo<T>::~Nodo() {
    delete hijo_izquierdo;
    delete hijo_derecho;
    delete datos_aeropuerto;
}

template <class T>
T Nodo<T>::obtener_dato() {
    return dato;
}

template <class T>
Aeropuerto* Nodo<T>::obtener_aeropuerto() {
    return datos_aeropuerto;
}

template <class T>
Nodo<T>* Nodo<T>::obtener_hijo_izquierdo() {
    return hijo_izquierdo;
}

template <class T>
Nodo<T>* Nodo<T>::obtener_hijo_derecho() {
    return hijo_derecho;
}

template <class T>
Nodo<T>* Nodo<T>::obtener_padre() {
    return padre;
}

template <class T>
void Nodo<T>::asignar_dato(T dato) {
    this->dato = dato;
}

template <class T>
void Nodo<T>::asignar_aeropuerto(Aeropuerto* aeropuerto){
    this->datos_aeropuerto = aeropuerto;
}

template <class T>
void Nodo<T>::asignar_hijo_izquierdo(Nodo<T> *hijo_izquierdo)
{
    this->hijo_izquierdo = hijo_izquierdo;
    if (hijo_izquierdo != nullptr)
    {
        hijo_izquierdo->asignar_padre(this);
    }
}

template <class T>
void Nodo<T>::asignar_hijo_derecho(Nodo<T> *hijo_derecho)
{
    this->hijo_derecho = hijo_derecho;
    if (hijo_derecho != nullptr)
    {
        hijo_derecho->asignar_padre(this);
    }
}

template <class T>
void Nodo<T>::asignar_padre(Nodo<T> *padre)
{
    this->padre = padre;
}

template <class T>
void Nodo<T>::remover_hijo(Nodo<T> *hijo)
{
    if (hijo == hijo_izquierdo)
    {
        if (hijo_izquierdo != nullptr)
        {
            hijo_izquierdo->asignar_aeropuerto(nullptr);
            hijo_izquierdo->asignar_padre(nullptr);
        }
        hijo_izquierdo = nullptr;
    }
    else if (hijo == hijo_derecho)
    {
        if (hijo_derecho != nullptr)
        {
            hijo_derecho->asignar_aeropuerto(nullptr);
            hijo_derecho->asignar_padre(nullptr);
        }
        hijo_derecho = nullptr;
    }
}

#endif