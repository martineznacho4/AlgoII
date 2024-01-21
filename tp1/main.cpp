#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const unsigned int MAXIMO =  100000000;

bool es_primo(int n);

// Estructura de numeros primos hasta 10.000 (raiz de 100 millones)
struct primos {
    int lista[1229];
    int cantidad = 0;
} primos;

int total_primos = 0;

int main (){
    unsigned int ti = clock();
    ofstream archivo("primos.txt");

    // Asumo el primer primo como 2
    archivo << 2 << endl;
    primos.lista[0] = 2;
    total_primos++;
    primos.cantidad++;

    for (int i = 2; i <= MAXIMO; i++){
        if(es_primo(i)){
            if(primos.cantidad < 1229){
                primos.lista[primos.cantidad] = i;
                primos.cantidad++;
            }
            archivo << i << endl;
            total_primos++;
        }
    }

    archivo.close();
    unsigned int tf = clock();
    double tiempo_total = (double(tf -ti)) / CLOCKS_PER_SEC;
    cout << "El programa tardo: "<<tiempo_total << " segundos" << endl;
    
    return 0;
}


bool es_primo(int n){

    bool res= true;
    
    int i = 0;
    while(res && i < primos.cantidad){
        if(n % primos.lista[i] == 0){
            res = false;
        }
        i++;
    }
    
    return res;
}