#include "NodoHash.h"
NodoHash::NodoHash() : aeropuerto("", "", "", "", 0, 0, 0, 0), ocupado(false){}
void NodoHash::setAeropuerto(Aeropuerto& aeropuerto){
    this->aeropuerto = aeropuerto;
}
Aeropuerto NodoHash::getAeropuerto() const{
    return aeropuerto;
}
void NodoHash::setOcupado(bool estaOcupado){
    this->ocupado = estaOcupado;
}
bool NodoHash::getOcupado() const{
    return ocupado;
}