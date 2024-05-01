#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include <iostream>


const std::string ARCHIVO_AEROPUERTOS = "aeropuertos.txt";

class Aeropuerto{
    private:
        //Atributos
        std::string clave;
        std::string nombre;
        std::string ciudad;
        std::string pais;
        double superficie;
        int cantidad_terminales;
        int destinos_nacionales;
        int destinos_internacionales;
    public:
        //Constructor:
        /*
        PRE: Recibe como parametro los datos de clave, nombre, ciudad y pais, los cuales son strings, el dato de superficie, que es double, 
        y los datos de cantidad de terminales, destinos nacionales y destinos internacionales que son de tipo int.
        POST: Genera el aeropuerto según los datos recibidos por parámetro. 
        */
        Aeropuerto(std::string clave, std::string nombre, std::string ciudad, std::string pais, double superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales);

        //Constructor sin parámetros
        /*
        PRE: - 
        POST: Crea un objeto de clase Aeropuerto con sus atributos inicializados por defecto.
        */
        Aeropuerto();

        //Destructor:
        ~Aeropuerto();

        //Getters
        /*
        Pre: - 
        Post: Devuelve el codigo IATA del aeropuerto.
        */
        std::string get_clave();

        /*
        Pre: - 
        Post: Devuelve el nombre del aeropuerto.
        */
        std::string get_nombre();

        /*
        Pre: - 
        Post: Devuelve la ciudad del aeropuerto.
        */
        std::string get_ciudad();

        /*
        Pre: - 
        Post: Devuelve el pais del aeropuerto.
        */
        std::string get_pais();


        /*
        Pre: - 
        Post: Devuelve la superficie del aeropuerto.
        */
        double get_superficie();

        /*
        Pre: - 
        Post: Devuelve la cantidad de terminales del aeropuerto.
        */
        int get_terminales();

        /*
        Pre: - 
        Post: Devuelve la cantidad de destinos nacionales.
        */
        int get_dest_nacionales();


        /*
        Pre: - 
        Post: Devuelve la cantidad de destinos internacionales.
        */
        int get_dest_internacionales();

        /*
        Pre: - 
        Post: Imprime los datos del aeropuerto.
        */
        void imprimir_aeropuerto();
};

#endif //AEROPUERTO_H
