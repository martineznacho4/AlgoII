#ifndef _NODO_H_
#define _NODO_H_

typedef int Dato;

class Nodo {
private:
    
    // ATRIBUTOS
    Dato dato;
    Nodo* siguiente;

public:
    
    // CONSTRUCTORES

    // pos: construye un Nodo con un dato d y siguiente en nullptr.
    Nodo(Dato d);
    // pos: construye un Nodo con un dato d y siguiente en pn
    Nodo(Dato d, Nodo* pn);

    // METODOS
    Dato obtener_dato();

    Nodo* obtener_siguiente();

    void cambiar_dato(Dato d);

    void cambiar_siguiente(Nodo* pn);
};

#endif // _NODO_H_