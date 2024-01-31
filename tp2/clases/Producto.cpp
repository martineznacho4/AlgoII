#include "Producto.h"

Producto::Producto(std::string nombre, double precio_unitario, int descuento, int cantidad){
    this->nombre = nombre;
    this->precio_unitario = precio_unitario;
    this->descuento = descuento;
    this->cantidad = cantidad;
};

Producto::Producto(std::string nombre, int cantidad){
    this->nombre = nombre;
    this->cantidad = cantidad;
}


// Producto::Producto()

std::string Producto::get_nombre(){return this->nombre;};
int Producto::get_precio_u(){return this->precio_unitario;};
int Producto::get_descuento(){return this->descuento;};
int Producto::get_cantidad(){return this->cantidad;};


void Producto::set_nombre(string s){this->nombre = s;};
void Producto::set_precio_u(double p){this->precio_unitario = p;};
void Producto::set_descuento(int n){this->descuento = n;};
void Producto::set_cantidad(int n){this->cantidad = n;}

// Metodos

double Producto::precio_total(){
    return this->cantidad * this->precio_unitario;
};