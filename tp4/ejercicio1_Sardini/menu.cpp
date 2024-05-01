#include "menu.h"

MENU::MENU(){}

MENU::~MENU(){}

void MENU::generar_abb(Lista<Lista<string>*>* lista_codigo_ciudad, ABB<std::string> &abb){
    Aeropuerto* punt_aeropuerto;
    Lista<string>* iata_ciudad;
    int cont = 1;
    std::ifstream archivo_aeropuertos; 
    archivo_aeropuertos.open(ARCHIVO_AEROPUERTOS);
    if (!archivo_aeropuertos.is_open())
    {
        std::cout << "Error al abrir el archivo" << std::endl;
        exit(1);
    }
    std::string clave, nombre, ciudad, pais;
    double superficie;
    int cantidad_terminales, destinos_nacionales, destinos_internacionales;
    while (archivo_aeropuertos >> clave >> nombre >> ciudad >> pais >> superficie >> cantidad_terminales >> destinos_nacionales >> destinos_internacionales)
    {
        punt_aeropuerto = new Aeropuerto(clave, nombre, ciudad, pais, superficie, cantidad_terminales, destinos_nacionales, destinos_internacionales);
        iata_ciudad = new Lista<string>();
        iata_ciudad->alta(clave, 1);
        iata_ciudad->alta(ciudad,2);
        lista_codigo_ciudad->alta(iata_ciudad, cont);
        abb.insertar(punt_aeropuerto->get_clave(), punt_aeropuerto);
        cont++;
    }
    cout << "Se agregaron " << abb.obtener_cantidad() << " datos al ABB.\nQuedó formado de la siguiente manera:" << endl;     
    abb.in_orden();
    archivo_aeropuertos.close();
}

void MENU::consulta_aeropuerto(Lista<Lista<string>*>* lista_codigo_ciudad, ABB<std::string> &abb){
    string nombre_ciudad;
    int cont = 1;
    bool encontrado = false;
    char opcion;
    std::cout << "\nEscriba el nombre de la ciudad por la que quiere consultar (Se debe respetar su ortografía, mayúsculas y su nombre debe estar todo junto (si es más de una palabra, deben estar separadas por guiones)): ";
    std::cin >> nombre_ciudad;
    while (encontrado == false && cont <= lista_codigo_ciudad->obtener_cantidad())
    {
        if(lista_codigo_ciudad->obtener_nodo(cont)->obtener_dato()->obtener_nodo(2)->obtener_dato() == nombre_ciudad){
            encontrado = true;
        }else{
            cont++;
        }
    }
    if (encontrado == true)
    {   
        std::cout << "El aeropuerto de la ciudad " << nombre_ciudad << " está en el ABB.\nPresione 's' para visualizar sus datos o cualquier otra letra en caso contrario.\n";
        std::cin >> opcion;
        if (opcion == 's')
        {
            abb.buscar_aeropuerto(lista_codigo_ciudad->obtener_nodo(cont)->obtener_dato()->obtener_nodo(1)->obtener_dato())->imprimir_aeropuerto();
        }
    }else if (encontrado == false)
    {
        std::cout << "El aeropuerto no se encuentra en el ABB\n";
    }
}

void MENU::corregir_archivo_alta(std::string iata, std::string nombre, std::string ciudad, std::string pais, double superficie, int cantidad_terminales, int destinos_nacionales, int destinos_internacionales){
    std::cout << "ACTUALIZANDO EL ARCHIVO 'aeropuertos.txt'..." << std::endl;
    std::ofstream archivo;
    archivo.open(ARCHIVO_AEROPUERTOS, ios::app);
    if(!archivo.is_open()){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        exit(1);
    }
    archivo << iata << " " << nombre << " " << ciudad << " " << pais << " " << superficie << " " << cantidad_terminales << " " << destinos_nacionales << " " << destinos_internacionales << std::endl;
    std::cout << "ARCHIVO ACTUALIZADO." << std::endl << std::endl;
    archivo.close();
}

void MENU::corregir_archivo_baja(ABB<std::string> &abb, string iata){
    Lista<string>* lista_iatas;
    int cont = 1;
    std::cout << "ACTUALIZANDO EL ARCHIVO 'aeropuertos.txt'..." << std::endl;
        std::ifstream archivo;
        lista_iatas = new Lista<string>();
        archivo.open(ARCHIVO_AEROPUERTOS);
        if(!archivo.is_open()){
            std::cout << "No se pudo abrir el archivo" << std::endl;
            exit(1);
        }
        std::string clave_archivo, nombre_archivo, ciudad_archivo, pais_archivo;
        double superficie_archivo;
        int cantidad_terminales_archivo, destinos_nacionales_archivo, destinos_internacionales_archivo;
        while(archivo >> clave_archivo >> nombre_archivo >> ciudad_archivo >> pais_archivo >> superficie_archivo >> cantidad_terminales_archivo >> destinos_nacionales_archivo >> destinos_internacionales_archivo){
            if(clave_archivo != iata){
                lista_iatas->alta(clave_archivo, cont);
                cont++;
            } else{
                cont--;
            }
        }
        lista_iatas->cambiar_cantidad(cont);
        for (int i = 1; i <= lista_iatas->obtener_cantidad(); i++)
        {
            std::cout << lista_iatas->consulta(i);
        }
        
        archivo.close();
        std::ofstream archivo_actualizar;
        archivo_actualizar.open(ARCHIVO_AEROPUERTOS);
        if(!archivo_actualizar.is_open()){
            std::cout << "No se pudo abrir el archivo" << std::endl;
            exit(1);
        }
        archivo_actualizar << "";
        for (int i = 1; i <= lista_iatas->obtener_cantidad(); i++)
        {
            archivo_actualizar << abb.buscar_aeropuerto(lista_iatas->consulta(i))->get_clave() << " " << abb.buscar_aeropuerto(lista_iatas->consulta(i))->get_nombre() << " " << abb.buscar_aeropuerto(lista_iatas->consulta(i))->get_ciudad() << " " << abb.buscar_aeropuerto(lista_iatas->consulta(i))->get_pais() << " " << abb.buscar_aeropuerto(lista_iatas->consulta(i))->get_superficie() << " " << abb.buscar_aeropuerto(lista_iatas->consulta(i))->get_terminales() << " " << abb.buscar_aeropuerto(lista_iatas->consulta(i))->get_dest_nacionales() << " " << abb.buscar_aeropuerto(lista_iatas->consulta(i))->get_dest_internacionales() << "\n";
        }
        delete lista_iatas;
        archivo_actualizar.close();
}

void MENU::alta_aeropuerto(Lista<Lista<string>*>* lista_codigo_ciudad, ABB<std::string> &abb){
    string iata, nombre, ciudad, pais;
    double superficie;
    int cantidad_terminales, destinos_nacionales, destinos_internacionales;
    std::cout << "Para dar de alta un aeropuerto en el ABB, ingrese su código IATA: ";
    std::cin >> iata;
    if(abb.esta_en_el_arbol(iata)){
        std::cout << "El aeropuerto ya se encuentra en el ABB\n";
    } else{
        std::cout << "Le pedimos a continuación que ingrese los siguientes datos sobre el aeropuerto a agregar:\n" << "Nombre: ";
        std::cin >> nombre;
        std::cout << "Ciudad: ";
        std::cin >> ciudad;
        std::cout << "País: ";
        std::cin >> pais;
        std::cout << "Superficie: ";
        std::cin >> superficie;
        std::cout << "Cantidad de terminales: ";
        std::cin >> cantidad_terminales;
        std::cout << "Cantidad de destinos nacionales: ";
        std::cin >> destinos_nacionales;
        std::cout << "Cantidad de destinos internacionales: ";
        std::cin >> destinos_internacionales;
        Aeropuerto* aeropuerto = new Aeropuerto(iata, nombre, ciudad, pais, superficie, cantidad_terminales, destinos_nacionales, destinos_internacionales);
        abb.insertar(iata, aeropuerto);
        Lista<string>* codigo_ciudad = new Lista<string>();
        codigo_ciudad->alta(iata,1);
        codigo_ciudad->alta(ciudad,2);
        lista_codigo_ciudad->alta(codigo_ciudad, lista_codigo_ciudad->obtener_cantidad()+1);
        std::cout << "\n\nEL AEROPUERTO FUE CORRECTAMENTE AGREGADO\n\n";
        corregir_archivo_alta(iata, nombre, ciudad, pais, superficie, cantidad_terminales, destinos_nacionales, destinos_internacionales);
        }
    std::cout << "El ABB quedó:\n";
    abb.in_orden();
}

void MENU::baja_aeropuerto(Lista<Lista<string>*>* lista_codigo_ciudad, ABB<std::string> &abb){
    std::string iata;
    std::cout << "Para dar de baja un aeropuerto en el ABB, ingrese su código IATA: ";
    std::cin >> iata;
    std::string ciudad =  abb.buscar_aeropuerto(iata)->get_ciudad();
    if(!abb.esta_en_el_arbol(iata)){
        std::cout << "El aeropuerto no se encuentra en el ABB\n";
    } else{
        abb.eliminar(iata);
        std::cout << "\n\nEL AEROPUERTO FUE CORRECTAMENTE ELIMINADO\n\n";
        corregir_archivo_baja(abb, iata);
        corregir_lista_baja(lista_codigo_ciudad);
    }
    std::cout << "El ABB quedó: ";
    abb.in_orden();
}


void MENU::corregir_lista_baja(Lista<Lista<string>*>* lista_codigo_ciudad){
    Lista<string>* cod_ciud;
    int cont = 1;
    for (int i = 1; i <= lista_codigo_ciudad->obtener_cantidad(); i++)
    {
        delete lista_codigo_ciudad->obtener_nodo(i)->obtener_dato();
    }
    std::ifstream archivo_aeropuertos; 
    archivo_aeropuertos.open(ARCHIVO_AEROPUERTOS);
    if (!archivo_aeropuertos.is_open())
    {
        std::cout << "Error al abrir el archivo" << std::endl;
        exit(1);
    }
    std::string clave, nombre, ciudad, pais;
    double superficie;
    int cantidad_terminales, destinos_nacionales, destinos_internacionales;
    while (archivo_aeropuertos >> clave >> nombre >> ciudad >> pais >> superficie >> cantidad_terminales >> destinos_nacionales >> destinos_internacionales)
    {
        cod_ciud = new Lista<string>();
        cod_ciud->alta(clave, 1);
        cod_ciud->alta(ciudad,2);
        lista_codigo_ciudad->alta(cod_ciud, cont);
        cont++;
    }
    lista_codigo_ciudad->cambiar_cantidad(cont-1);    
    for (int i = 1; i <= lista_codigo_ciudad->obtener_cantidad(); i++)
        {
            std::cout << lista_codigo_ciudad->obtener_nodo(i)->obtener_dato()->obtener_nodo(2)->obtener_dato() << std::endl;
        }
    archivo_aeropuertos.close();
}

void MENU::menu_abb(){
    ABB<string> abb;
    Lista<Lista<string>*>* lista_iata_ciudad = new Lista<Lista<string>*>();
    std::cout << "Bienvenido al programa\n";
    generar_abb(lista_iata_ciudad, abb);
    char opcion;
    std::cout << "A continuación elija entre las siguientes opciones:\n- Si desea consultar por un aeropuerto, presione 'c'\n- Si desea dar de alta un nuevo aeropuerto, presione 'a'\n- Si desea dar de baja un aeropuerto, presione 'b'\n";
    std::cin >> opcion;
    while (opcion != 's')
    {
        if (opcion == 'c')
        {
            consulta_aeropuerto(lista_iata_ciudad, abb);
        } else if (opcion == 'a')
        {
            alta_aeropuerto(lista_iata_ciudad, abb);
        } else if (opcion == 'b')
        {
            baja_aeropuerto(lista_iata_ciudad, abb);
        
        } else{
            std::cout << "Opción no válida.";
        }
        std::cout << "Elija entre las siguientes opciones para realizar otra operación o salir del programa:\n- Si desea consultar por un aeropuerto, presione 'c'\n- Si desea dar de alta un nuevo aeropuerto, presione 'a'\n- Si desea dar de baja un aeropuerto, presione 'b'\n- Si desea salir del programa, presione 's'\n";
        std::cin >> opcion;
    }
    for (int i = 1; i <= lista_iata_ciudad->obtener_cantidad(); i++)
    {
        delete lista_iata_ciudad->obtener_nodo(i)->obtener_dato();
    }
    delete lista_iata_ciudad;

    std::cout << "FIN DEL PROGRAMA";
}