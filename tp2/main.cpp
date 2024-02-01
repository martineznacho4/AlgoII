#include <iostream>
#include <fstream>
#include "archivos.h"
#include "./clases/Producto.h"
#include "./clases/Gondola.h"
#include "./clases/Chango.h"

using namespace std;

int main(){

    Gondola gondola1;
    Chango chango1;

    cargar_gondola(gondola1);
    cargar_chango(chango1, gondola1);

    chango1.listar_productos();

    gondola1.actualizar_archivo();

    return 0;
}