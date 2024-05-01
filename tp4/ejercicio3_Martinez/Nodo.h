#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>

using namespace std;

template < typename Tipo >
class Nodo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo(Tipo nombre);

    //post: devuelve el nodo siguiente.
    Nodo<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    string obtenerNombre();

    Tipo obtenerElemento();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(Nodo<Tipo>* siguiente);

    ~Nodo();
};


template<typename Tipo>
Nodo<Tipo>::Nodo(Tipo nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
Tipo Nodo<Tipo>::obtenerElemento() {
    return *this->elemento;
}

template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo<Tipo>::obtenerNombre() {
    return elemento -> obtenerNombre();
}

template<typename Tipo>
void Nodo<Tipo>::asignarSiguiente(Nodo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
