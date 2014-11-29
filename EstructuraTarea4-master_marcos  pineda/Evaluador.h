#ifndef EVALUADOR_H
#define EVALUADOR_H

#include "NodoArbolBinario.h"
#include <iostream>       // std::cin, std::cout

using namespace std;

void evaluar();

int suma(NodoArbolBinario* raiz);

int cantidadNodos(NodoArbolBinario* raiz);

int promedio(NodoArbolBinario* raiz);

int cuantosPasos(NodoArbolBinario* raiz,int num);

bool esAVL(NodoArbolBinario* raiz);

#endif // EVALUADOR_H
