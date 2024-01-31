#ifndef GONDOLA_H
#define GONDOLA_H

#include <iostream> 
#include "Producto.h"

using namespace std;


class Gondola {
    private:
        Producto* productos;
        int tamanio;
        int tope;
    
    public:
        
        // Constructor
        // PRE: -
        // POS: Inicializa una Gondola con capacidad para 5 elementos
        Gondola();

        // PRE: -
        // POS: Liberacion de memoria
        ~Gondola();


        // Getters
        Producto* get_productos();
        int get_tamanio();
        int get_tope();
        
        // Setters
        void set_productos(Producto* ptr);
        void set_tamanio(int n);
        // PRE: -
        // POS: Multiplica el tope actual por el recibido n.
        void set_tope(double n);
        
        // Metodos

        // PRE: -
        // POS: Agrega un nuevo Producto en la ultima posicion del vector productos. Si la cantidad de productos es mayor que el tope, duplica el tope.
        void agregar_producto(Producto &p);
        
        // PRE: -
        // POS: Imprime una representacion de la Gondola.
        void mostrar();

        // PRE: -
        // POS: Aumenta la capacidad de la Gondola en el doble.
        void aumentar_tamanio();
        
        // PRE: -
        // POS: Elimina los productos cuyo stock haya llegado a 0 unidades. Si la cantidad de productos es menor a la mitad del tope, reduce su capacidad a la mitad.
        void eliminar_producto();
        
        // PRE: -
        // POS: Actualiza la informacion del archivo 'productos.txt' con los datos de la Gondola.
        void actualizar_archivo();

};

#endif