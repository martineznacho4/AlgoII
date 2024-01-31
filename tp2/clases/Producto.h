#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto {
    private:
        string nombre;
        double precio_unitario;
        int descuento;
        int cantidad;
    
    public:
        // Constructor
        // PRE: -
        // POS: Inicializa un Producto con sus valores por defecto
        Producto() = default;

        // Constructor
        // PRE: -
        // POS: Inicializa un Producto para la carga de la Gondola
        Producto(string nombre, double precio_unitario, int descuento, int cantidad);

        // Constructor
        // PRE: -
        // POS: Inicializa un Producto para la carga del Chango
        Producto(string nombre, int cantidad);

        // Getters
        string get_nombre();
        int get_precio_u();
        int get_descuento();
        int get_cantidad();

        // Setters
        void set_nombre(string s);
        void set_precio_u(double p);
        void set_descuento(int n);
        void set_cantidad(int n);

        // PRE: -
        // POS: Devuelve el producto entre la cantidad y el precio unitario
        double precio_total();
        
};



#endif