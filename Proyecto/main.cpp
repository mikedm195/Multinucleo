#include <iostream>
#include <fstream>
#include <stdio.h>
#include "sha256.h"
#include "md5.h"

#define maxChar '~'
#define minChar ' '

void combinaciones(int len, int algoritmo, std::ofstream& a){
    char letras[len];
    //inicializar letras de arreglo a 'a'
    for(int i = 0; i < len; i++)
        letras[i] = minChar;

    //Recorre para encontrar todas las posibilidades
    while(letras[0] <= maxChar){
        if(algoritmo == 0)
            a << letras << "," << md5(letras) << "\n";
        else
            a << letras << "," << sha256(letras) << "\n";
        for(int i = len-1; i >= 0; i--){
            if(letras[i] >= maxChar && i != 0){
                letras[i] = minChar;
            }else{
                letras[i]++;
                break;
            }

        }
    }
}

int main(int argc, char *argv[]){

    if(argc != 2 ){
        std::cout << "./RainbowTable 0|1 (MD5|SHA)" << std::endl;
        return -1;
    }

    std::ofstream a;


    int algoritmo = atoi(argv[1]);
    if(algoritmo == 0)
        a.open("MD5.csv");
    else if(algoritmo == 1)
        a.open("SHA.csv");

    a << "Input" << "," << "Value" << "\n";
    clock_t begin = clock();

    for(int i = 1; i < 9; i++)
        combinaciones(i, algoritmo, a);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    std::cout << elapsed_secs << " s" <<  std::endl;

    a.close();
    return 0;
}
