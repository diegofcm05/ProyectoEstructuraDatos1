#include "LinkedList.h"

LinkedList::LinkedList() {
    nodo = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
}

bool LinkedList::inserta(Object* dato, int position) {
    if (position < 0 || position > size) {
        return false;
    }

    Nodo* nuevoNodo = new Nodo(dynamic_cast<Alumno*>(dato));
    if (!nuevoNodo) {
        return false;
    }

    if (position == 0) {
        nuevoNodo->setSiguiente(nodo);
        if (nodo)
            nodo->setAnterior(nuevoNodo);
        nodo = nuevoNodo;
    }
    else {
        Nodo* temp = nodo;
        for (int i = 0; i < position - 1; ++i) {
            temp = temp->getSiguiente();
        }
        nuevoNodo->setSiguiente(temp->getSiguiente());
        nuevoNodo->setAnterior(temp);
        if (temp->getSiguiente())
            temp->getSiguiente()->setAnterior(nuevoNodo);
        temp->setSiguiente(nuevoNodo);
    }
    ++size;
    return true;
}

bool LinkedList::suprime(int position) {
    if (position <= 0 || position > size || size == 0) {
        return false;
    }

    Nodo* temp = nodo;

    if (position == 1) {
        nodo = nodo->getSiguiente();
        if (nodo) {
            nodo->setAnterior(nullptr);
        }
    }
    else {
        for (int i = 0; i < position - 1; ++i) {
            temp = temp->getSiguiente();
        }
        temp->getAnterior()->setSiguiente(temp->getSiguiente());
        if (temp->getSiguiente()) {
            temp->getSiguiente()->setAnterior(temp->getAnterior());
        }
    }

    delete temp;
    --size;
    return true;
}

Object* LinkedList::siguiente(int position) {
    if (position <= 0 || position >= size) {
        return nullptr;
    }

    Nodo* temp = nodo;
    for (int i = 1; i < position; ++i) {
        temp = temp->getSiguiente();
    }

    return temp->getSiguiente()->getDato();
}

Object* LinkedList::anterior(int position) {
    if (position <= 1 || position > size) {
        return nullptr;
    }

    Nodo* temp = nodo;
    for (int i = 1; i < position; ++i) {
        temp = temp->getSiguiente();
    }

    return temp->getAnterior()->getDato();
}

void LinkedList::anula() {
    while (nodo) {
        Nodo* temp = nodo;
        nodo = nodo->getSiguiente();
        delete temp;
    }
    size = 0;
}

int LinkedList::busca(Object* obj) {
    Nodo* temp = nodo;
    if (temp->getDato()->equals(obj)) {
        return 1;
    }
    else {
        for (size_t i = 1; i <= size; i++) {
            if (temp->getDato()->equals(obj)) {
                return i;
            }
            else {
                if (temp->getSiguiente() != nullptr) {
                    temp = temp->getSiguiente();
                }
            }
        }
    }
    return -1;
}

Object* LinkedList::recupera(int position) {
    if (position < 0 || position >= size) {
        return nullptr;
    }

    Nodo* temp = nodo;
    for (int i = 0; i < position; ++i) {
        temp = temp->getSiguiente();
    }

    return temp->getDato();
}


void LinkedList::imprime_lista() {
    Nodo* temp = nodo;
    int index = 1;
    while (temp) {
        cout << index << "- " << temp->getDato()->toString() << endl;
        temp = temp->getSiguiente();
        index++;
    }
}

bool LinkedList::vacia()
{
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

int LinkedList::getSize()
{
    return size;
}
