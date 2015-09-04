//
//  main.cpp
//  Ordenamiento
//
//  Created by Daniel on 01/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Ordenamiento.h"

//Crear un menu sin necesidad de un switch
typedef bool (*t_compara)(int, int);
typedef void (*t_algoritmo)(int[], int, t_compara);


template <typename T>
void imprime(T [], int);
template <class T>
void binaryTree(T [], int);

void readRandom(string,int[],int);

int main(int argc, const char * argv[])
{
    int alg = 0;
    char temp;
    int num = 10;
    t_algoritmo algoritmo[9];
    algoritmo[0] = Ordenamiento<int>::ordenamientoBurbuja;
    algoritmo[1] = Ordenamiento<int>::ordenamientoinsercion;
    algoritmo[2] = Ordenamiento<int>::ordenamientoSeleccion;
    algoritmo[3] = Ordenamiento<int>::ordenamientoCounting;
    algoritmo[4] = Ordenamiento<int>::ordenamientoCocktail;
    algoritmo[5] = Ordenamiento<int>::ordenamientoBucket;
    algoritmo[6] = Ordenamiento<int>::ordenamientoHeapSort;
    algoritmo[7] = Ordenamiento<int>::ordenamientoRadixSort;
    algoritmo[8] = Ordenamiento<int>::ordenamientoShellSort;

    t_compara compara[2];
    compara[0] = Ordenamiento<int>::asc;
    compara[1] = Ordenamiento<int>::desc;

    if (argc == 2){
        temp = *argv[1];
        alg = temp - '0';
    }
    else{
        cout << "Que algoritmo? ";
        cin>> alg;
    }

    if (alg < 0 || alg > 11){
        cout << alg << endl;
         cout << "no existe" << endl;
     }
     else if (alg == 9){
        for (int i = 1; i <= 6; i++){
            if (i == 6) num = 500000;
            int data[num];
            stringstream ss;
            cout << num << endl;
            ss << num;
            string name = ss.str() + "random.txt";
            readRandom(name,data,num);
            float start = clock();
            binaryTree<int>(data,num);
            cout << "TOTAL TIME (" << ss.str() << "): " <<(clock() - start)/CLOCKS_PER_SEC << "s" << endl;
            num *= 10;
        }
    }
    else if (alg == 10){
        for (int i = 1; i <= 6; i++){
            if (i == 6) num = 500000;
            int data[num];
            stringstream ss;
            cout << num << endl;
            ss << num;
            string name = ss.str() + "random.txt";
            readRandom(name,data,num);
            float start = clock();
            Ordenamiento<int>::ordenamientoQuickSort(data, Ordenamiento<int>::asc, 0,num -1);
            cout << "TOTAL TIME (" << ss.str() << "): " <<(clock() - start)/CLOCKS_PER_SEC << "ms" << endl;
            num *= 10;
        }
    }
    else if (alg == 11){
        for (int i = 1; i <= 6; i++){
            if (i == 6) num = 500000;
            int data[num];
            stringstream ss;
            cout << num << endl;
            ss << num;
            string name = ss.str() + "random.txt";
            readRandom(name,data,num);
            float start = clock();
            Ordenamiento<int>::ordenamientoMergeSort(data, Ordenamiento<int>::asc, 0,num -1, num);
            cout << "TOTAL TIME (" << ss.str() << "): " <<(clock() - start)/CLOCKS_PER_SEC << "ms" << endl;
            num *= 10;
        }
    }
    else{
        for (int i = 1; i <= 6; i++){
            if (i == 6) num = 500000;
            int data[num];
            stringstream ss;
            cout << num << endl;
            ss << num;
            string name = ss.str() + "random.txt";
            readRandom(name,data,num);
            float start = clock();
            algoritmo[alg](data,num, Ordenamiento<int>::asc);
            cout << "TOTAL TIME (" << ss.str() << "): " <<(clock() - start)/CLOCKS_PER_SEC << "ms" << endl;
            num *= 10;
        }

    }
   
    
    //Ordenamiento<int>::ordenamientoQuickSort(enteros, Ordenamiento<int>::asc, 0, N-1);
    //Ordenamiento<int>::ordenamientoMergeSort(enteros, Ordenamiento<int>::asc, 0, N-1, N);
    //Ordenamiento<int>::ordenamientoBurbuja(enteros, N, Ordenamiento<int>::desc);
    
    /* std::cout<<"Escoja el Tipo de ordenamiento\n";
    std::cout<<"1- Burbuja\n2- Insercion\n3- Seleccion\n";
    int opcion;
    std::cin>>opcion;
    std::cout<<"1-Ascendente\n2- Desendente\n";
    int tipo;
    std::cin>>tipo;
    
    imprime(enteros, N);
    */
    //llamar a la funcion desde el arreglo de funciones
    //algoritmo[opcion-1](enteros, N, compara[tipo-1]);
    
    //imprime(enteros, N);
    
    /*Ordenar float*/
    /*float flotantes[N];
    
    for(int i = 0; i< N; i++){
        flotantes[i] = (rand() % 100) *0.1;
    }
    
    std::cout<<"\n----------Ordenamiento de Flotantes--------\n";
    imprime(flotantes, N);
    Ordenamiento<float>::ordenamientoBurbuja(flotantes, N, Ordenamiento<float>::desc);
    imprime(flotantes, N);
	*/
    /*Ordenar clase del usuario*/
    /*const int nlibros = 3;
    Libro biblioteca[nlibros];
    biblioteca[0] =  Libro("Amanecer", "jfk", 250, 2010);
    biblioteca[1] =  Libro("luna", "jfk", 300, 2010);
    biblioteca[2] =  Libro("crepusculo", "jfk", 450, 2010);
    //imprime(biblioteca, nlibros);
    
    //Ordenamiento<Libro>::ordenamientoinsercion(biblioteca, nlibros, Ordenamiento<Libro>::desc);
    //imprime(biblioteca, nlibros);
    
    */
}


void readRandom(string fileName,int data[],int N){
    ifstream read(fileName.c_str());
    int n,i;
    for(int i = 0; i < N; i++)
        read >> data[i];
}

template <typename T>
void imprime(T v[], int n){
    for(int i = 0; i<n; i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
}

struct nodo{
     int nro;
     struct nodo *izq, *der;
};
typedef struct nodo *ABB;
template <class T>
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */
ABB crearNodo(T x){
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
template <class T>
void insertar(ABB &arbol, T x){
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x <= arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}
void enOrden(ABB arbol){
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          //cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}
template <class T>
void binaryTree(T data[], int N){
    ABB arbol = NULL;
    for(int i=0; i<N; i++)
    {
        insertar( arbol, data[i]);
    }
    enOrden(arbol);
}