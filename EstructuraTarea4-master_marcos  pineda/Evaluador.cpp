#include "Evaluador.h"

void evaluar()
{
    int nota = 0;

    NodoArbolBinario *n11 = new NodoArbolBinario(1);
    NodoArbolBinario *n12 = new NodoArbolBinario(2);
    NodoArbolBinario *n13 = new NodoArbolBinario(3);
    NodoArbolBinario *n14 = new NodoArbolBinario(4);
    NodoArbolBinario *n15 = new NodoArbolBinario(5);

    n11->hijo_izq = n12;
    n11->hijo_der = n13;
    n12->hijo_izq = n14;
    n12->hijo_der = n15;


    NodoArbolBinario *n21 = new NodoArbolBinario(10);
    NodoArbolBinario *n22 = new NodoArbolBinario(20);
    NodoArbolBinario *n23 = new NodoArbolBinario(30);
    NodoArbolBinario *n24 = new NodoArbolBinario(40);

    n21->hijo_izq = n22;
    n21->hijo_der = n23;
    n23->hijo_izq = n24;


    cout<<"Ejercicio suma:\t\t\t";
    if(suma(n11) == 15 && suma(n21) == 100)
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio cantidadNodos:\t";
    if(cantidadNodos(n11) == 5 && cantidadNodos(n21) == 4)
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio promedio:\t\t";
    if(promedio(n11) == 3 && promedio(n21) == 25)
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    NodoArbolBinario *n31 = new NodoArbolBinario(10);
    NodoArbolBinario *n32 = new NodoArbolBinario(5);
    NodoArbolBinario *n33 = new NodoArbolBinario(15);
    NodoArbolBinario *n34 = new NodoArbolBinario(8);

    n31->hijo_izq = n32;
    n31->hijo_der = n33;
    n32->hijo_der = n34;

    NodoArbolBinario *n41 = new NodoArbolBinario(100);
    NodoArbolBinario *n42 = new NodoArbolBinario(50);
    NodoArbolBinario *n43 = new NodoArbolBinario(75);
    NodoArbolBinario *n44 = new NodoArbolBinario(10);
    NodoArbolBinario *n45 = new NodoArbolBinario(5);
    NodoArbolBinario *n46 = new NodoArbolBinario(200);
    NodoArbolBinario *n47 = new NodoArbolBinario(150);

    n41->hijo_izq = n42;
    n41->hijo_der = n46;

    n42->hijo_izq = n44;
    n42->hijo_der = n43;

    n43->hijo_izq = n45;

    n46->hijo_izq = n47;

    cout<<"Ejercicio cuantosPasos:\t\t";
    if(cuantosPasos(n31,8) == 3 && cuantosPasos(n31,15) == 2 && cuantosPasos(n31,10) == 1
        && cuantosPasos(n41,5) == 4 && cuantosPasos(n41,150) == 3 && cuantosPasos(n41,200) == 2 && cuantosPasos(n41,100) == 1)
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio esAVL:\t\t";
    if(!esAVL(n11) && !esAVL(n21) && esAVL(n31) && esAVL(n41) && esAVL(n32) && !esAVL(n12) && esAVL(n42))
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/13"<<endl;
}
