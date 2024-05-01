#include <iostream>
#include "lista.h"

using namespace std;

int main(){
    
// Listas desordenadas
    // Lista lista_prueba;
    // lista_prueba.alta(9,1);
    // lista_prueba.alta(6,2);
    // lista_prueba.alta(4,3);
    // lista_prueba.alta(10,4);
    // lista_prueba.alta(8,5);
    // lista_prueba.alta(3,6);
    // lista_prueba.alta(3,7);
    // lista_prueba.alta(7,8);

    // cout<< "Prueba: " << endl;
    // lista_prueba.mostrar();


    // Lista lista_nueva;
    // lista_nueva.alta(8,1);
    // lista_nueva.alta(3,2);
    // lista_nueva.alta(4,3);
    // lista_nueva.alta(10,4);
    // lista_nueva.alta(5,5);
    // lista_nueva.alta(14,6);
    // lista_nueva.alta(20,7);
    // lista_nueva.alta(9,8);

    // cout<< "Nueva: " << endl;
    // lista_nueva.mostrar();

    // Lista *resultado = lista_prueba.interseccion_A(lista_nueva);

    // cout << "Resultado: " << endl;
    // resultado->mostrar();
  
    // delete resultado;


// Listas Ordenadas
    Lista l1 = Lista();
    Lista l2 = Lista();
    
    l1.alta(1,1);
    l1.alta(3,2);
    l1.alta(4,3);
    l1.alta(7,4);
    l1.alta(8,5);
    l1.alta(45,6);
    

    l2.alta(3,1);
    l2.alta(4,2);
    l2.alta(8,3);
    l2.alta(10,4);
    l2.alta(13,5);
    l2.alta(15,6);
    l2.alta(16,7);
    l2.alta(18,8);
    l2.alta(20,9);
    l2.alta(25,10);
    l2.alta(26,11);
    l2.alta(27,12);
    l2.alta(36,13);
    l2.alta(38,14);
    l2.alta(45,15);

    Lista *nueva = l1.interseccion_B(l2);
    nueva->mostrar();


    delete nueva;

    return 0;
}