#include <iostream>
#include <fstream>
#include "./clases/Producto.h"
#include "./clases/Gondola.h"
#include "./clases/Chango.h"

using namespace std;

int main(){
    
    ifstream archivo_productos("productos.txt");
    ifstream archivo_compra("compra.txt");

    Gondola gondola1;
    Chango chango1;

    // Carga de la gondola
    string nombre;
    double precio; 
    int descuento, cantidad;

    while(archivo_productos >> nombre >> precio >> descuento >> cantidad){
        Producto p1 = Producto(nombre,precio,descuento,cantidad);
        gondola1.agregar_producto(p1);
    };
    archivo_productos.close();

    // Carga del Chango
    string nombre_item;
    int cantidad_item;

    while(archivo_compra >>nombre_item >> cantidad_item){
        Producto p2 = Producto(nombre_item, cantidad_item);
        chango1.agregar_producto(p2, gondola1);
    }
    archivo_compra.close();

    chango1.listar_productos();

    gondola1.actualizar_archivo();

    return 0;
}