#include <iostream>
#include <fstream>
#include "TablaHashCerrada.h"
#include "TablaHashAbierta.h"

using namespace std;
// Tuve problemas con la entrada.Use cin.ignore para que no quede nada en el bufer de entrada
//ya que no me tomaba bien la opcion que intentaba seleccionar en el menu

template<class T>
void cargarAeropuertosDesdeArchivo(string& nombreArchivo, T& tablaHash){
    ifstream archivo(nombreArchivo);
    string codigoIATA;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidadTerminales;
    int destinosNacionales;
    int destinosInternacionales;
    while (archivo>> codigoIATA>> nombre>> ciudad>> pais>> superficie>> cantidadTerminales>> destinosNacionales>> destinosInternacionales){
        Aeropuerto aeropuerto{codigoIATA, nombre, ciudad, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales};
        tablaHash.insertar(aeropuerto);
    }
    archivo.close();
}


void imprimirAeropuerto(Aeropuerto& aeropuerto){
    cout<<"nombre: "<<aeropuerto.getNombre()<<endl;
    cout<<"ciudad: "<<aeropuerto.getCiudad()<<endl;
    cout<<"pais: "<<aeropuerto.getPais()<<endl;
    cout<<"codigo IATA: "<<aeropuerto.getCodigoIATA()<<endl;
    cout<<"destinos nacionales: "<<aeropuerto.getDestinosNacionales()<<endl;
    cout<<"destinos internacionales: "<<aeropuerto.getDestinosInternacionales()<<endl;
    cout<<"cantidad de terminales: "<<aeropuerto.getCantidadTerminales()<<endl;
    cout<<"superficie: "<<aeropuerto.getSuperficie()<<"km 2"<<endl;
    cout<<""<<endl;
    cout<<endl;
}

template<class T>
void menu(T& tablaHash){
    int opcion;
    //menu principal (el do-while permitira mantenernos en el menu siempre y cuando el usuario no pida salir)
    do{
        cout<<"Ingrese una opcion:"<<endl;
        cout<<"1=Consultar aeropuerto por ciudad"<<endl;
        cout<<"2=Dar de alta un nuevo aeropuerto"<<endl;
        cout<<"3=Dar de baja un aeropuerto"<<endl;
        cout<<"4=Salir"<<endl;
        cout<<""<<endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion){
            //Busco el aeropuerto por ciudad
            case 1:{
                string nombreCiudad;
                cout<<"Ingrese el nombre de la ciudad del aeropuerto a buscar: ";
                getline(cin, nombreCiudad);
                Aeropuerto aeropuertoBuscado=tablaHash.buscar(nombreCiudad);
                if (aeropuertoBuscado.getCodigoIATA()!= ""){
                    cout<<"Aeropuerto consultado:"<<endl;
                    imprimirAeropuerto(aeropuertoBuscado);
                }
                else{
                    cout<<"El aeropuerto no se encuentra en la tabla"<<endl;
                    cout<<""<<endl;
                }
                break;
            }
            //Agrego un nuevo aeropuerto a la tabla
            case 2:{
                string codigoIATA;
                string nombre;
                string ciudad;
                string pais;
                float superficie;
                int cantidadTerminales;
                int destinosNacionales;
                int destinosInternacionales;
		cout<<""<<endl;
                cout<<"NUEVO AEROPUERTO:"<<endl;
                cout<<"Ingrese el codigo IATA del aeropuerto: ";
                cin >> codigoIATA;
                cin.ignore();
                cout<<"Ingrese el nombre del aeropuerto: ";
                getline(cin, nombre);
                cout<<"Ingrese la ciudad del aeropuerto: ";
                getline(cin, ciudad);
                cout<<"Ingrese el pais del aeropuerto: ";
                getline(cin, pais);
                cout<<"Ingrese la superficie del nuevo aeropuerto (km^2): ";
                cin >> superficie;
                cin.ignore();
                cout<<"Ingrese la cantidad de terminales del nuevo aeropuerto: ";
                cin >> cantidadTerminales;
                cin.ignore();
                cout<<"Ingrese la cantidad de destinos nacionales del nuevo aeropuerto: ";
                cin >> destinosNacionales;
                cin.ignore();
                cout<<"Ingrese la cantidad de destinos internacionales del nuevo aeropuerto: ";
                cin >> destinosInternacionales;
                cin.ignore();
                Aeropuerto nuevoAeropuerto{codigoIATA, nombre, ciudad, pais, superficie, cantidadTerminales, destinosNacionales, destinosInternacionales};
                tablaHash.insertar(nuevoAeropuerto);
                break;
            }
            //Elimino un aeropuerto de la tabla
            case 3:{
                string nombreCiudad;
		cout<<""<<endl;
                cout<<"Ingresar la ciudad del aeropuerto a eliminar: ";
                getline(cin, nombreCiudad);
                if (tablaHash.eliminar(nombreCiudad)){
                    cout<<"Aeropuerto eliminado"<<endl;
                    cout<<""<<endl;
                }
                else{
                    cout<<"Aeropuerto no encontrado"<<endl;
                    cout<<""<<endl;
                }
                break;
            }
            //Cierro el programa
            case 4:{
                cout<<"Cerrando el programa"<<endl;
                break;
            }
            //Si ingreso otro numero no valido (no funciona para letras)
            default:{
                cout<<"Opcion invalida "<<endl;
                cout<<""<<endl;
                break;
            }
        }
    }
    while(opcion!=4);
}

int main(){
    int opcionTabla;
    do{
        cout<<"Seleccione el tipo de tabla:"<<endl;
        cout<<"1=Cerrada con direccionamiento abierto"<<endl;
        cout<<"2=Abierta con direccionamiento cerrado"<<endl;
        cout<<""<<endl;
        cin>> opcionTabla;
        cin.ignore();
    } 
    while((opcionTabla != 1) && (opcionTabla != 2));
    if (opcionTabla==1){
        TablaHashCerrada tablaHashCerrada;
        //Puse la ruta completa porque no me reconocia el archivo aún estando en la misma carpeta
        string nombreArchivo="/home/tomas/tp4bilardismo/ej2Giani/aeropuertos.txt";
        cargarAeropuertosDesdeArchivo(nombreArchivo, tablaHashCerrada);
        menu(tablaHashCerrada);
    }
    else{
        TablaHashAbierta tablaHashAbierta;
        string nombreArchivo="/home/tomas/tp4bilardismo/ej2Giani/aeropuertos.txt";
        cargarAeropuertosDesdeArchivo(nombreArchivo, tablaHashAbierta);
        menu(tablaHashAbierta);
    }
    return 0;
}

