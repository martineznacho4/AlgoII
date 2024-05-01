#ifndef _NODO_H_
#define _NODO_H_

template <typename Dato>
class Nodo_Lista
{
    private:
        Dato dato;
        Nodo_Lista *siguiente;

    public:
        // CONSTRUCTOR
        /*
        PRE: Recibe como parámetro un Dato.
        POST: Construye un nodo con el Dato recibido por parámetro y un puntero a nullptr.
        */
        Nodo_Lista(Dato d);

        ~Nodo_Lista();

        // METODOS
        /*
        PRE: -
        POST: Devuelve el Dato que guarda el nodo.
        */
        Dato obtener_dato();

        /*
        PRE: -
        POST: Devuelve el nodo siguiente.
        */
        Nodo_Lista *obtener_siguiente();

        /*
        PRE: Recibe un puntero a nodo como parámetro.
        POST: Cambia el puntero al que apunta el nodo actual al recibido por parámetro.
        */
        void cambiar_siguiente(Nodo_Lista *pn);
};

template <typename Dato>
Nodo_Lista<Dato>::Nodo_Lista(Dato d)
{
    dato = d;
    siguiente = nullptr;
}

template <typename Dato>
Nodo_Lista<Dato>::~Nodo_Lista(){}

template <typename Dato>
Dato Nodo_Lista<Dato>::obtener_dato()
{
    return dato;
}

template <typename Dato>
Nodo_Lista<Dato>* Nodo_Lista<Dato>::obtener_siguiente()
{
    return siguiente;
}

template <typename Dato>
void Nodo_Lista<Dato>::cambiar_siguiente(Nodo_Lista *pn)
{
    siguiente = pn;
}

#endif // _NODO_H_
