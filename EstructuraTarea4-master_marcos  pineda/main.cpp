#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
   // creamos las variables para hacer la respectiva suma
    int resultado =0;
    int suma_izq =0;
    int suma_der =0;
    int padre =0;

    if(raiz==NULL)  //miramos  a ver si existe algun valor en la raiz
       return 0;  //si no que retorne cero

    padre = raiz->num;    //guardamos los valores de la raiz q estan dentro de la raiz
    suma_izq += suma(raiz->hijo_izq); // hacemos recursividad y guardamos  en la variable   los hijos de la izquierda
    suma_der += suma(raiz->hijo_der);   // hacemos recursividad y guardamos en la variable  los hijos de la derecha

    resultado = padre + suma_der + suma_izq;  //  sumamos y guardamos  todos los nodos de la  raiz  dada  en la variable resultado

    return resultado;  // rotornamos resultado
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{

     int contador=0;  // creamos  un contador para que cuente la cantidad de nodos  que hay en el arbol

    if(raiz==NULL) // miramos si el valor de la raiz existe
        return 0;  //  si  no  existe que retorne  cero

    contador+=cantidadNodos(raiz->hijo_izq) + cantidadNodos(raiz->hijo_der); // sumamos  los  nodos del lado  izquierda y derecho atravez de la recursividad

    contador++;

    return contador;  //  retornamos el  valor de los nodos
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{

    return suma(raiz)/cantidadNodos(raiz);  //  volvemos a usar las  funciones de suma  y cantidad de nodos para sacar el promedio

}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
int contador =1; // creando una variable que cuentes los pasos
    if(raiz==NULL) // verificar si la raiz existe
    return contador; // sino existe retornamos el valor del contador

    if(raiz->num == num) // si el valor de la raiz es el num que buscamos retorne el contador
        return contador; // retorna 1


    if(num>raiz->num) // verificamos si el numero es mayor que la raiz
        contador += cuantosPasos(raiz->hijo_der,num); // si es mayor buscamos por los hijos de la derecha y se cuentan los pasos

    if(num<raiz->num) // verificamos si el numero es menor que la raiz
        contador += cuantosPasos(raiz->hijo_izq,num); // si es menor buscamos por los hijos de la izquierda y se cuentan los pasos

    return contador; // retorna los pasos
}

//Devuelve verdadero si el arbol dado esta ordenado estilo AVL, de lo contrario devuelve falso.
bool esAVL(NodoArbolBinario* raiz)
{
    if(raiz==NULL) // Revisamos si la arbol ya se encuentra vacio
    return true; // retornamos true si llega al ultimo elemento

     if(raiz->hijo_izq !=NULL && raiz->hijo_izq->num>raiz->num or raiz->hijo_der!=NULL && raiz->hijo_der->num<raiz->num) // revisando que exista el hijo derecho o izquierdo, y negando el orden AVL para los dos
            return false; // si esto resulta (incorrecto) entonces el arbol no esta ordenado

        return esAVL(raiz->hijo_izq) && esAVL(raiz->hijo_der); // recorremos cada nodo mediante recursividad

}

int main ()
{

    //Funcion evaluadora
    evaluar();
    return 1;
}
