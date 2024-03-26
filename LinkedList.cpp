#include "LinkedList.h"

//constructor que inicializa los nodos que se van a utilizar en todo el programa
LinkedList::LinkedList() {
    inicio = nullptr;
    ultimo = nullptr;
    size = 0;
}
// Manda a llamar el metodo anula que se encarga de borrar todos los nodos en cascada y se encarga de borrar memoria
LinkedList::~LinkedList() {
    anula();
}

//inserta el alumno en la posicion que el usuario escoja, en caso de ponerlo en una posicion que ya exista, corre todos
//los elementos a la derecha
bool LinkedList::inserta(Object* dato, int position) {
    if (position < 1 || position > size + 1) {
        // Verificar si la posición es válida
        return false;
    }

    Nodo* nuevoNodo = new Nodo(dato); // Crear un nuevo nodo con el dato proporcionado
    Nodo* temp = nullptr;
    if (position == 1) {
        // Insertar al principio de la lista

        if (inicio != nullptr) {
            temp = inicio;
            inicio = nuevoNodo;
            inicio->setSiguiente(temp);
            temp->setAnterior(inicio);
        }
        else {
            inicio = nuevoNodo;
            ultimo = nuevoNodo;
        }
    }//Inserta al final de la lista
    else if (position >= size) {
        if (position == size + 1) {
            ultimo->setSiguiente(nuevoNodo);
            temp = ultimo;
            ultimo = nuevoNodo;
            nuevoNodo->setAnterior(temp);
        }
        else {
            temp = ultimo;
            ultimo->getAnterior()->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(ultimo->getAnterior());
            ultimo->setAnterior(nuevoNodo);
            nuevoNodo->setSiguiente(temp);
        }
    }
    else {
        // Insertar en una posición diferente del inicio de la lista
        temp = inicio;
        for (int i = 0; i <= position - 1; i++) {
            temp = temp->getSiguiente();
        }
        temp->getAnterior()->setSiguiente(nuevoNodo);
        temp->setAnterior(nuevoNodo);
        nuevoNodo->setSiguiente(temp);
    }
    ++size; // Incrementar el tamaño de la lista
    return true;
}
//borra un elemento en la posicion que se encuentra en la lista, encargandose de borrar memoria de ese elemento y dejando intactos 
//sus siguientes y anteriores
bool LinkedList::suprime(int position) {
    if (position < 1 || position > size) {
        return false; // Si la posición es inválida, retorna falso
    }

    Nodo* temp = nullptr;

    if (position == 1 && size == 1) {//Si la posicion es la primera y solo existe ese elemento
        delete inicio;
        inicio = nullptr;
        ultimo = nullptr;
        size = 0;
        return true;
    }
    if (position == 1) { // Eliminar el primer elemento                        
        temp = inicio;
        inicio = inicio->getSiguiente();
        inicio->setAnterior(nullptr);
        temp->setSiguiente(nullptr);
        delete temp; // Liberar memoria del nodo eliminado
        temp = nullptr;
    }
    else if (position == size) {
        temp = ultimo;
        ultimo = ultimo->getAnterior();
        temp->setAnterior(nullptr);
        ultimo->setSiguiente(nullptr);
        delete temp; // Liberar memoria del nodo eliminado
        temp = nullptr;
    }
    else {
        Nodo* current = inicio;
        for (int i = 1; i < position; i++) {
            current = current->getSiguiente();
        }
        temp = current;
        current = current->getAnterior();
        current->setSiguiente(temp->getSiguiente());
        temp->getSiguiente()->setAnterior(current);
        temp->setSiguiente(nullptr);
        temp->setAnterior(nullptr);
        delete temp; // Liberar memoria del nodo eliminado
        temp = nullptr;
    }


    --size; // Disminuir el tamaño de la lista
    return true;
}

//Se encarga de devolver el elemento siguiente a la posicion que ingresó el usuario
Object* LinkedList::siguiente(int position) {
    if (position < 0 || position >= size - 1) {
        return nullptr; // Posición inválida
    }

    Nodo* temp = inicio;
    //Recorre toda la lista para encontrar el siguiente de la posicion ingresada
    for (int i = 0; i < position; i++) {
        temp = temp->getSiguiente();
    }
    //Si no encuentra nada entonces no hay un siguiente elemento
    if (temp->getSiguiente() == nullptr) {
        return nullptr; // No hay siguiente elemento
    }

    return temp->getSiguiente()->getDato();
}
//Se encarga de devolver el elemento anterior a la posicion que ingresó el usuario
Object* LinkedList::anterior(int position) {
    if (position < 0 || position > size) {
        return nullptr; // Posición inválida
    }

    Nodo* temp = inicio;
    //Recorre toda la lista para encontrar el anterior de la posicion ingresada
    for (int i = 0; i < position; i++) {
        temp = temp->getSiguiente();
    }
    //Si no encuentra nada entonces no hay un anterior elemento
    if (temp->getAnterior() == nullptr) {
        return nullptr; // No hay elemento anterior
    }

    return temp->getAnterior()->getDato();
}
//Se encarga de vaciar la lista en su totalidad y reiniciando los punteros para volver a usar la lista con normalidad
void LinkedList::anula() {
    if (size == 0) {
        cout << "La lista ya esta vacia." << endl;
    }
    else {
        delete inicio;
        inicio = nullptr;
        ultimo = nullptr;
        size = 0;
        cout << "Se han borrado todos los elementos de la lista." << endl;
    }
    
}



//Por medio del numero de cuenta busca un alumno con numero de cuenta igual en la lista
int LinkedList::busca(Object* obj) {
    if (size == 0) {
        cout << "La lista esta vacia" << endl;
        return -1;
    }

    Nodo* temp = inicio;
    //Retorna la primera posicion por si estaba en la primera posicion
    if (temp->getDato()->equals(obj)) {
        return 1;
    }
    else {
        //Si no estaba en la primera posicion recorre toda la lista hasta encontrar un objeto igual y retorna su posicion
        //en la lista
        for (size_t i = 1; i <= size; i++) {
            if (temp->getDato()->equals(obj)) {
                return i;
            }
            else {
                //Si no lo encuentra solo devuelve el siguiente
                if (temp->getSiguiente() != nullptr) {
                    temp = temp->getSiguiente();
                }
            }
        }
    }
    return -1;
}
//El metodo se encarga de buscar un objeto en la LinkedList por medio de su posicion y retornar ese objeto
Object* LinkedList::recupera(int position) {
    if (position < 0 || position >= size) {
        return nullptr; //validacion de que si la posicion existe
    }

    Nodo* temp = inicio;
    //for que recorre la lista y encuentra el objeto buscando desde el inicio de la lista hasta la posicion
    for (int i = 0; i < position; ++i) {
        temp = temp->getSiguiente();
    }

    return temp->getDato();
}

//metodo que se encarga de imprimir los elementos de la lista por medio del toString de la clase Alumno
void LinkedList::imprime_lista() {
    Nodo* temp = inicio;
    int index = 1;
    while (temp) {
        cout << index << "- " << temp->getDato()->toString() << endl;
        temp = temp->getSiguiente();
        index++;
    }
}

//Metodo que se encarga de revisar si la lista está vacia viendo si el size de la lista es igual a 0
bool LinkedList::vacia()
{
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

//metodo que retorna el size actual de la lista (se usó más para probar metodos)
int LinkedList::getSize()
{
    return size;
}