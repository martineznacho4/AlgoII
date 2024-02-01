#include <iostream>
#include <fstream>
#include "archivos.h"

const string PRODUCTOS = "productos.txt";
const string COMPRA = "compra.txt";


void cargar_gondola(Gondola &gondola1){

    ifstream archivo_productos(PRODUCTOS);

    string nombre;
    double precio; 
    int descuento, cantidad;

    while(archivo_productos >> nombre >> precio >> descuento >> cantidad){
        Producto p1 = Producto(nombre,precio,descuento,cantidad);
        gondola1.agregar_producto(p1);
    };
    archivo_productos.close();

}

void cargar_chango(Chango &chango1, Gondola &gondola1){

    ifstream archivo_compra(COMPRA);

    string nombre_item;
    int cantidad_item;

    while(archivo_compra >>nombre_item >> cantidad_item){
        Producto p2 = Producto(nombre_item, cantidad_item);
        chango1.agregar_producto(p2, gondola1);
    }
    archivo_compra.close();

}