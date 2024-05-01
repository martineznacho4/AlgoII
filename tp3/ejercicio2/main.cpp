#include <iostream>
#include "lista.h"

using namespace std;

int main(){
    
    ListaCircular l1 = ListaCircular();

    l1.alta(1);
    l1.alta(2);
    l1.alta(3);
    l1.alta(4);
    l1.alta(5);
    l1.alta(6);
    l1.mostrar();
    cout << "El mas antiguo es: " << l1.mas_antiguo() << endl;
    cout << "Promedio: " << l1.promedio() << endl;
    // l1.alta(7);
    // l1.alta(8);
    // l1.alta(9);
    // l1.alta(10);
    // l1.mostrar();
    
    // cout << "El mas antiguo es: " << l1.mas_antiguo() << endl;
    // l1.mostrar();
    // cout << "Consulta: "<<l1.consulta(3)<<endl;
    

    // cout << l1.obtener_nodo(7)->obtener_siguiente()->obtener_dato() <<endl;
    

    return 0;
}