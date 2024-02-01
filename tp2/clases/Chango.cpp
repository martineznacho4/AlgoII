#include <iostream>
#include <iomanip>
#include "Chango.h"

using namespace std;

// Constructor
Chango::Chango(){
    this->productos = new Producto[1];
    this->tamanio = 0;
};

// Destructor
Chango::~Chango(){
    delete [] this->get_productos();
}

// Getters
Producto* Chango::get_productos(){return this->productos;};
int Chango::get_tamanio(){return this->tamanio;};

// Setters
void Chango::set_productos(Producto *p){this->productos = p;};
void Chango::set_tamanio(int n){this->tamanio = n;};

// Metodos
void Chango::listar_productos(){

    cout << setfill('-');
    cout << setw(100)  << "-" << endl;
    cout << setfill(' ');
    cout << setw(50)  << "Chango" << endl;
    

    int total_chango = 0;
    int ancho_col = 20;
    
    cout << setw(ancho_col) << left <<"Producto"
         << setw(ancho_col) << left << "Precio Unitario" 
         << setw(ancho_col) << left << "Cantidad" 
         << setw(ancho_col) << left << "Descuento" 
         << setw(ancho_col) << left << "Precio total" << endl;

    for (int i = 0; i < this->get_tamanio(); i++){
        Producto item = this->get_productos()[i];
        total_chango += item.precio_total();
        cout << setw(ancho_col) << left <<item.get_nombre()
             << setw(ancho_col) << left <<item.get_precio_u()
             << setw(ancho_col) << left <<item.get_cantidad()
             << setw(ancho_col) << left <<(item.get_descuento() ? "Si" : "No")
             << setw(ancho_col) << left <<item.precio_total() << endl;
    }
    cout << endl;
    cout << "Precio Total: $" << total_chango << endl;
}

void Chango::agregar_producto(Producto &p, Gondola &gondola){

    // Asumo que no hay stock del producto, en caso de encontrarlo actualizo el valor
    // Si el producto no esta en la gondola -> no hay stock
    bool stock = false;
    
    // Busqueda del Producto en la Gondola
    // Al encontrarlo, agrego los atributo faltantes (precio unitario, descuento) y actualizo la cantidad efectiva
    for (int i = 0; i < gondola.get_tamanio(); i++){

        Producto &item = gondola.get_productos()[i];
        if(item.get_nombre() == p.get_nombre()){
    
            stock = true;

            if(item.get_descuento()){
                p.set_precio_u(item.get_precio_u()*0.90);
            }else{
                p.set_precio_u(item.get_precio_u());
            }

            p.set_descuento(item.get_descuento());

            if(p.get_cantidad() > item.get_cantidad()){
                cout << "Del producto " << p.get_nombre() << " solo hay " << item.get_cantidad() << " unidades."<< endl;
                p.set_cantidad(item.get_cantidad());
                item.set_cantidad(0);    
            }else if( p.get_cantidad() <= item.get_cantidad()){
                item.set_cantidad(item.get_cantidad() - p.get_cantidad());
            }

            // Se agrega el prducto al Chango y aumenta el tamanio
            this->get_productos()[this->get_tamanio()] = p;
            this->set_tamanio(this->get_tamanio() + 1);
            this->aumentar_tamanio();    
        }
    }

    if(!stock){
        cout << "No hay stock del producto " << p.get_nombre()<< endl;
    }

    // Actualizo los productos en la Gondola
    gondola.eliminar_producto();

};

void Chango::aumentar_tamanio(){

    Producto *aux = new Producto[this->get_tamanio() + 1];
    for (int i = 0; i < this->get_tamanio(); i++){
        aux[i] = this->get_productos()[i];
    };

    delete [] this->get_productos();
    this->set_productos(aux);
};
