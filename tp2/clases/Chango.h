#ifndef CHANGO_H
#define CHANGO_H

#include "Producto.h"
#include "Gondola.h"

// class Producto;
// class Gondola;

class Chango {
    private:
        Producto *productos;
        int tamanio;
    
    public:

        // Constructor
        // PRE: -
        // POS: Inicializa un Chango con capacidad para 1 Producto
        Chango();

        // Constructor
        // PRE: -
        // POS: Liberacion de memoria
        ~Chango();

        // Getters
        Producto* get_productos();
        int get_tamanio();

        // Setters
        void set_productos(Producto *p);
        void set_tamanio(int n);

        // PRE: -
        // POS: Muestra por consola una representacion del Chango con sus Productos y el precio total del Chango
        void listar_productos();
        
        // PRE: El Producto p tiene al menos nombre y cantidad
        // POS: Agrega un Producto p que se encuentre en la Gondola g al Chango, completando sus atributos (precio unitario y descuento) y aumenta la capacidad del Chango en 1. 
            // Tambien elimina la cantidad deseada de la Gondola
        void agregar_producto(Producto &p, Gondola &g);

        // PRE: -
        // POS: Aumenta dinamicamente el tamanio del Chango en 1
        void aumentar_tamanio();

};



#endif