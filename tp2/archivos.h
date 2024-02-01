#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "./clases/Gondola.h"
#include "./clases/Chango.h"

// PRE: Existe un archivo fuente valido con el formato "Producto - precio unitario - descuento(1/0) - stock"
// POS: Carga los datos del archivo fuente de productos en la Gondola
void cargar_gondola(Gondola &g);

// PRE: Existe un archivo fuente valido con el formato "Producto - Cantidad"
// POS: Carga los productos del archivo fuente a un Chango sujeto a disponibilidad de la Gondola
void cargar_chango(Chango &c, Gondola &g);

#endif