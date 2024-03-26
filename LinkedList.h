#pragma once
#include "TDALista.h"
#include "Nodo.h"
#include "Alumno.h"

class LinkedList : public TDALista {

    //Nodos de inicio y final que se encargan de poner en orden los elementos de la lista
    Nodo* inicio;
    Nodo* ultimo;

public:
    //constructor que inicializa los nodos
    LinkedList();
    //destructor que libera memoria de los nodos
    ~LinkedList();
    //inserta el alumno en la posicion que el usuario escoja, en caso de ponerlo en una posicion que ya exista, corre todos
    //los elementos a la derecha
    bool inserta(Object*, int position);
    //borra un elemento en la posicion que se encuentra en la lista, encargandose de borrar memoria de ese elemento y dejando intactos 
    //sus siguientes y anteriores
    bool suprime(int position);
    //Se encarga de devolver el elemento siguiente a la posicion que ingresó el usuario
    Object* siguiente(int position);
    //Se encarga de devolver el elemento anterior a la posicion que ingresó el usuario
    Object* anterior(int position);
    //Se encarga de vaciar la lista en su totalidad y reiniciando los punteros para volver a usar la lista con normalidad
    void anula();
    //Por medio del numero de cuenta busca un alumno con numero de cuenta igual en la lista
    int busca(Object*);
    //El metodo se encarga de buscar un objeto en la LinkedList por medio de su posicion y retornar ese objeto
    Object* recupera(int position);
    //metodo que se encarga de imprimir los elementos de la lista por medio del toString de la clase Alumno
    void imprime_lista();
    //Metodo que se encarga de revisar si la lista está vacia viendo si el size de la lista es igual a 0
    bool vacia();
    //metodo que retorna el size actual de la lista (se usó más para probar metodos)
    int getSize();

};