#pragma once
#include "TDALista.h"
#include "Nodo.h"
#include "Alumno.h"

class LinkedList : public TDALista {
public:
    Nodo* nodo;
    LinkedList();
    ~LinkedList();
    bool inserta(Object*, int position);
    bool suprime(int position);
    Object* siguiente(int position);
    Object* anterior(int position);
    void anula();
    int busca(Object*);
    Object* recupera(int position);
    void imprime_lista();
    bool vacia();
    int getSize();

};
