#ifndef _NODO_H_
#define _NODO_H_

template<typename Dato>
class Nodo {
private:

    // Atributos
    Dato dato;
    Nodo* siguiente;

public:
    // Constructor
    // Pos: Construye un Nodo con un dato d y siguiente en nullptr.
    Nodo(Dato d);

    // METODOS
    Dato obtener_dato();
    Nodo* obtener_siguiente();
    void cambiar_siguiente(Nodo* pn);
};

template<typename Dato>
Nodo<Dato>::Nodo(Dato d) {
    dato = d;
    siguiente = nullptr;
}


template<typename Dato>
Dato Nodo<Dato>::obtener_dato() {
    return dato;
}

template<typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente() {
    return siguiente;
}


template<typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo* pn) {
    siguiente = pn;
}

#endif 
