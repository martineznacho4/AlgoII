#include <iostream>
#include <fstream>
#include "Gondola.h"

using namespace std;


// Constructor
Gondola::Gondola(){
    this->productos = new Producto[5];
    this->tamanio = 0;
    this->tope = 5;
};

// Destructor
Gondola::~Gondola(){
    delete [] this->get_productos();
}

// Getters
Producto* Gondola::get_productos(){return this->productos;};
int Gondola::get_tamanio(){return this->tamanio;};
int Gondola::get_tope(){return this->tope;};

// Setters
void Gondola::set_productos(Producto* ptr_productos){this->productos = ptr_productos;};
void Gondola::set_tamanio(int n){this->tamanio = n;};
void Gondola::set_tope(double n){this->tope *= n;};

// Metodos
void Gondola::agregar_producto(Producto &p){
    // Al alcanzar el tope se duplica la capacidad
    if(this->get_tamanio() == this->get_tope() ){  
        this->aumentar_tamanio();
    }
    
    this->get_productos()[this->get_tamanio()] = p;
    this->set_tamanio(this->get_tamanio() + 1);
};

void Gondola::mostrar(){
    for (int i = 0; i < this->get_tamanio(); i++){
        cout << this->get_productos()[i].get_nombre() << " - " <<this->get_productos()[i].get_cantidad()<< " - "<< this->get_productos()[i].get_precio_u()<< endl;
    }
};

void Gondola::aumentar_tamanio(){
    // Se duplica el tope
    this->set_tope(2);

    // Creo un nuevo vector con mas capacidad y copio los elementos
    Producto *aux = new Producto[this->get_tope()];
    for (int i = 0; i < this->get_tamanio(); i++){
        aux[i] = this->get_productos()[i];
    }

    // Se libera la memoria y actualizo la referencia
    delete [] this->get_productos();
    this->set_productos(aux);
};

void Gondola::eliminar_producto(){
    // Si el tamanio de la gondola se reduce a menos de la mitad del tope se achica la gondola
    if (this->get_tamanio() <= this->get_tope()/2){
        this->set_tope(0.5);
    }

    // Creo una copia solo con los productos que si tengan stock
    Producto *aux = new Producto[this->get_tope()];
    int tam_aux = 0;

    for (int i = 0; i < this->get_tamanio(); i++){
        if(this->get_productos()[i].get_cantidad() > 0){
            aux[tam_aux] = this->get_productos()[i];
            tam_aux++;
        }
    }
    
    // Liberacion de memoria y actualizacion de referencia
    delete [] this->get_productos();
    this->set_tamanio(tam_aux);
    this->set_productos(aux);
};

void Gondola::actualizar_archivo(){

    ofstream archivo("productos.txt");

    for (int i = 0; i < this->get_tamanio(); i++){
        Producto item = this->get_productos()[i];
        archivo << item.get_nombre() << "    "
                << item.get_precio_u() << "    "
                << (item.get_descuento() ? 1 : 0) << "    "
                << item.get_cantidad() << endl;
    }
    archivo.close();
};


