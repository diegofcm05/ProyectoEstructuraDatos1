#include <iostream>
#include <string>
#include <locale>
#include "Alumno.h"
#include "TDAPila.h"
#include "TDACola.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "LinkedList.h"
#include "TDALista.h"
#include "ArrayList.h"


using namespace std;

TDAPila* Pila; //Pila global usada en el programa
TDACola* aq;   //Cola que se convertira en ArrayQueue global usado en el programa
TDACola* lq;   //Cola que se convertira en LinkedQueue global
Object* temporalsym; //Simbolo temporal, usado cuando se crean nuevos simbolos
Object* symsacado;  //Simbolo sacado cuando se usa "pop"
Object* topeActS;   //Guarda el tope actual de la pila de Simbolos

//Metodo que valida las entradas de opciones, verifica que lo que ingresa el usuario son digitos.
bool isDigit(string aValidar) {
    if (aValidar == "") {
        return false;
    }
    for (int i = 0; i < aValidar.size(); i++)
    {
        if (aValidar[i] < 48 || aValidar[i] > 57) {
            return false;
        }
    }
    return true;
}

//Metodo externo para crear Alumno
Alumno* crearAlumno() {
    string nombre;
    string cuenta;
    cout << "Ingrese el nombre del alumno: " << endl;
    getline(cin, nombre);
    cout << "Ingrese la cuenta del alumno: " << endl;
    getline(cin, cuenta);
    Alumno* alumno = new Alumno(nombre, cuenta);
    return alumno;
}

//Menu interno de ArrayList
void menuInternoAL() {
    //variables de inicializacion
    string checkPos = "";
    string valid = "";
    int opc = 1;
    string nombre = "";
    string nCuenta = "";
    Alumno* alumno = new Alumno();
    ArrayList* lista = new ArrayList();
    bool seguir = true;
    int found = 0;
    string respuesta = "";
    int pos = 0;

    while (opc != 10) {
        seguir = true;
        cout << "----- Operaciones de Listas -----" << endl;
        cout << "1. Insertar Elemento" << endl;
        cout << "2. Imprimir Elementos" << endl;
        cout << "3. Buscar Elemento" << endl;
        cout << "4. Borrar Elemento" << endl;
        cout << "5. Ver si esta vacia" << endl;
        cout << "6. Obtener elemento por posicion" << endl;
        cout << "7. Obtener Siguiente" << endl;
        cout << "8. Obtener Anterior" << endl;
        cout << "9. Borrar todos los elementos (anula)" << endl;
        cout << "10. Regresar al menu anterior" << endl;

        getline(cin, valid);

        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 10) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {
        case 1://En esta opcion se hace el agregado de un alumno
            cout << "Opcion 1 - Insertar" << endl;
            cout << "---- En listas, unicamente es posible insertar Alumnos ----" << endl;

            //creacion del objeto "Alumno"

            while (seguir) {
                cout << "Ingrese el nombre del alumno: ";
                getline(cin, nombre);


                cout << "Ingrese el numero de cuenta: ";
                getline(cin, nCuenta);

                alumno = new Alumno(nombre, nCuenta);

                //pide la posicion donde se desea ingresar el alumno
                cout << "Ingrese la posicion en donde desea agregar el alumno (Ingrese solo numeros!): ";
                getline(cin, checkPos);

                while (!isDigit(checkPos)) {
                    cout << "Ingrese solo numeros!!" << endl;
                    getline(cin, checkPos);
                }

                pos = stoi(checkPos);

                while (pos < 1 || pos > lista->getSize() + 1) {
                    cout << "Posición inválida" << endl;
                    cout << "Ingrese la posicion en donde desea agregar el alumno: ";
                    getline(cin, checkPos);

                    while (!isDigit(checkPos)) {
                        cout << "Ingrese solo numeros!!" << endl;
                        getline(cin, checkPos);
                    }

                    pos = stoi(checkPos);
                }
                if (lista->inserta(alumno, pos)) {
                    cout << "Se ha agregado el elemento exitosamente!" << endl;
                }
                else {
                    cout << "Error al agregar el elemento." << endl;
                }
                do {
                    cout << "Desea continuar (Ingrese Si/No): ";
                    getline(cin, respuesta);

                    if (respuesta == "si" || respuesta == "Si") {
                        seguir = true;
                        break;
                    }
                    else if (respuesta == "no" || respuesta == "No") {
                        seguir = false;
                        break;
                    }
                    else {
                        cout << "Respuesta invalida, intente nuevamente" << endl;

                    }
                } while (seguir);

            }
            break;
        case 2://En el caso 2, se imprime la lista completa
            cout << "Opcion 2 - Imprimir Elementos" << endl;
            if (!lista->vacia()) {
                cout << "Alumnos existentes en la lista:" << endl;

                lista->imprime_lista();
            }
            else {
                cout << "No hay elementos en la lista para mostrar." << endl;
            }

            break;
        case 3://En el caso 3, se trata de buscar un alumno mediante su numero de cuenta.
            cout << "Opcion 3 - Buscar" << endl;
            cout << "Introduzca el numero de cuenta que desea consultar: ";
            getline(cin, nCuenta);

            alumno = new Alumno(".", nCuenta);

            pos = lista->busca(alumno);

            alumno = dynamic_cast<Alumno*>(lista->recupera(pos));

            if (!alumno) {
                cout << "No hay ningun elemento con el dato ingresado" << endl;
            }
            else {
                cout << "Alumno encontrado: " << endl;
                cout << alumno->toString() << "\nSe encontro en la posicion " << pos << endl;
            }
           
            break;

        case 4://En esta opcion, se borra un elemento que el usuario desee hacer eso con.
            cout << "Opcion 4 - Eliminar elemento" << endl;
            if (!lista->vacia()) {
                cout << "Ingrese la posicion que desea eliminar: ";
                cin >> pos;

                if (lista->suprime(pos))
                    cout << "Elemento eliminado correctamente" << endl;
                else {
                    cout << "No se pudo eliminar el elemento " << endl;
                }
            }
            else {
                cout << "La lista esta vacia, no hay nada que eliminar!" << endl;
            }
            cin.ignore();

            break;
        case 5://En el caso 5, se verifica si la lista esta vacia o no.
            cout << "Opcion 5 - Verificar si esta vacia" << endl;
            if (lista->vacia())
                cout << "La lista esta vacia" << endl;
            else
                cout << "Actualmente hay " << lista->getSize() << " elementos" << endl; //Si no esta vacia, imprime los elementos que hay.
            break;
        case 6://En el caso 6, se busca un elemento.
            cout << "Opcion 6 - Obtener elemento por posicion" << endl;
            if (!lista->vacia()) {
                cout << "Ingrese la posicion que desea recuperar: ";
                cin >> pos;

                alumno = dynamic_cast<Alumno*>(lista->recupera(pos));

                if (!alumno) {
                    cout << "Posicion invalida" << endl;
                }
                else {
                    cout << alumno->toString() << endl;
                }
                cin.ignore();
            }
            else {
                cout << "La lista esta vacia!!\n";
            }
            break;
        case 7://Retorna el elemento siguiente a la posicion establecida por el usuario.
            cout << "Opcion 7 - Recuperar Siguiente" << endl;
            if (!lista->vacia()) {
                cout << "Ingrese la posicion que desea recuperar el elemento siguiente a ese: ";
                cin >> pos;

                alumno = dynamic_cast<Alumno*>(lista->siguiente(pos));

                if (!alumno) {
                    cout << "El elemento siguiente esta vacio" << endl;
                }
                else {
                    cout << alumno->toString() << endl;
                }


            }
            cin.ignore();
            break;

        case 8://Retorna el elemento anterior a la posicion establecida por el usuario.
            cout << "Opcion 8 - Recuperar Anterior" << endl;
            if (!lista->vacia()) {

                cout << "Ingrese la posicion que desea recuperar el elemento anterior a ese: ";
                cin >> pos;

                alumno = dynamic_cast<Alumno*>(lista->anterior(pos));

                if (!alumno) {
                    cout << "El elemento anterior esta vacio" << endl;
                }
                else {
                    cout << alumno->toString() << endl;
                }

            }
            cin.ignore();
            break;
        case 9://En el caso 9, la lista se vacia completamente.
            cout << "Opcion 9 - Borrar todos los elementos" << endl;
            if (!lista->vacia()) {
                lista->anula();

                cout << "Los elementos se han eliminado exitosamente!" << endl;
            }
            break;
        case 10://Se sale al menu exterior a este.
            cout << "Saldra al menu de tipo de listas" << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

//Menu interno de LinkedList
void menuInternoLL() {
    //Inicialización de variables
    LinkedList* lista = new LinkedList();
    Alumno* alumno;
    int opc = 1;
    int posicion;
    string nombre, nCuenta, respuesta;
    string valid = "";
    bool seguir = true;
    int pos;
    //Menu que se repetirá hasta ingresar la opcion 10 o regresar al menu anterior
    while (opc != 10) {
        seguir = true;
        cout << "----- Operaciones de Listas -----" << endl;
        cout << "1. Insertar Elemento" << endl;
        cout << "2. Imprimir Elementos" << endl;
        cout << "3. Buscar Elemento" << endl;
        cout << "4. Borrar Elemento" << endl;
        cout << "5. Ver si esta vacia" << endl;
        cout << "6. Obtener elemento por posicion" << endl;
        cout << "7. Obtener Siguiente" << endl;
        cout << "8. Obtener Anterior" << endl;
        cout << "9. Borrar todos los elementos (anula)" << endl;
        cout << "10. Regresar al menu anterior" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 10) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {
        case 1://En esta opcion se hace el agregado de un alumno
            cout << "Opcion 1 - Insertar" << endl;
            while (seguir) {
                cout << "Ingrese el nombre del alumno: ";
                getline(cin, nombre);
                cout << "Ingrese el número de cuenta del alumno: ";
                getline(cin, nCuenta);

                alumno = new Alumno(nombre, nCuenta);

                //posicion
                cout << "Ingrese la posicion en donde desea agregar el alumno: ";
                cin >> pos;

                while (pos < 1 || pos > lista->getSize() + 1) {
                    cout << "Posición inválida" << endl;
                    cout << "Ingrese la posicion en donde desea agregar el alumno: ";
                    cin >> pos;
                }
                if (lista->inserta(alumno, pos)) {
                    cout << "Se ha agregado el elemento exitosamente!" << endl;
                }
                else {
                    cout << "Error al agregar el elemento." << endl;
                }
                cin.ignore();
                do {
                    cout << "Desea continuar (Ingrese Si/No): ";
                    getline(cin, respuesta);

                    if (respuesta == "si" || respuesta == "Si") {
                        seguir = true;
                        break;
                    }
                    else if (respuesta == "no" || respuesta == "No") {
                        seguir = false;
                        break;
                    }
                    else {
                        cout << "Respuesta invalida, intente nuevamente" << endl;

                    }
                } while (seguir);

            }


            break;

        case 2://En el caso 2, se imprime la lista completa
            cout << "Opcion 2 - Imprimir Elementos" << endl;
            if (lista->vacia())
            {
                cout << "LISTA VACIA" << endl;
                cout << "Tiene que agregar elementos a la lista primero" << endl;
                cout << endl;
            }
            else {
                cout << "Elementos de la lista:" << endl;
                lista->imprime_lista();
                cout << endl;
            }

            break;

        case 3://En el caso 3, se trata de buscar un alumno mediante su numero de cuenta.
            cout << "Opcion 3 - Buscar" << endl;
            cout << "Ingrese el número de cuenta del alumno a buscar: ";
            getline(cin, nCuenta);
            alumno = new Alumno("", nCuenta);

            posicion = lista->busca(alumno);
            if (posicion != -1) {
                cout << "El alumno es " << lista->recupera(posicion - 1)->toString() << " y se encuentra en la posición " << posicion << endl;
            }
            else {
                cout << "El alumno no se encuentra en la lista." << endl;
            }
            break;

        case 4://En esta opcion, se borra un elemento que el usuario desee hacer eso con.
            cout << "Opcion 4 - Eliminar elemento" << endl;
            int posicion;
            int index;
            lista->imprime_lista();
            cout << "Ingrese la posición del elemento a borrar: ";
            cin >> posicion;
            if (lista->suprime(posicion)) {
                cout << "Elemento borrado exitosamente." << endl;
            }
            else {
                cout << "No se pudo borrar el elemento. Verifique la posición." << endl;
            }
            cin.ignore();

            break;

        case 5://En el caso 5, se verifica si la lista esta vacia o no.
            cout << "Opcion 5 - Verificar si esta vacia" << endl;
            cout << (lista->vacia() ? "Está vacia" : "No está vacia") << endl;
            cout << endl;
            break;

        case 6://En el caso 6, se busca un elemento.
            cout << "Opcion 6 - Obtener elemento por posicion" << endl;
            lista->imprime_lista();
            cout << "Ingrese la posición del elemento a obtener: ";
            cin >> posicion;
            alumno = dynamic_cast<Alumno*>(lista->recupera(posicion - 1));
            if (alumno != nullptr) {
                cout << "El elemento en la posición " << posicion << " es: " << alumno->toString() << endl;
            }
            else {
                cout << "No se pudo obtener el elemento. Verifique la posición." << endl;
            }
            cin.ignore();

            break;

        case 7://Retorna el elemento siguiente a la posicion establecida por el usuario.
            cout << "Opcion 7 - Recuperar Siguiente" << endl;
            lista->imprime_lista();
            cout << "Ingrese la posición del elemento del cual desea obtener el siguiente: ";
            cin >> posicion;
            alumno = dynamic_cast<Alumno*>(lista->siguiente(posicion - 1));
            if (alumno != nullptr) {
                cout << "El siguiente elemento después de la posición " << posicion << " es: " << alumno->toString() << endl;
            }
            else {
                cout << "No hay siguiente elemento o la posición es inválida." << endl;
            }
            cin.ignore();

            break;

        case 8://Retorna el elemento anterior a la posicion establecida por el usuario.
            cout << "Opcion 8 - Recuperar Anterior" << endl;
            lista->imprime_lista();
            cout << "Ingrese la posición del elemento del cual desea obtener el anterior: ";
            cin >> posicion;
            alumno = dynamic_cast<Alumno*>(lista->anterior(posicion - 1));
            if (alumno != nullptr) {
                cout << "El elemento anterior a la posición " << posicion << " es: " << alumno->toString() << endl;
            }
            else {
                cout << "No hay elemento anterior o la posición es inválida." << endl;
            }
            cin.ignore();

            break;

        case 9://En el caso 9, la lista se vacia completamente.
            cout << "Opcion 9 - Borrar todos los elementos" << endl;
            lista->anula();
            break;

        case 10://Se sale al menu exterior a este.
            cout << "Regresando al menú anterior..." << endl;
            break;

        default:
            cout << "Opción no válida. Por favor, intente de nuevo." << endl;
        }
    }
}

//Menu interno de ArrayStack
void menuInternoAP() {
    int opc = 1;
    string valid = "";
    string newSimb = "";
    while (opc != 7) {
        cout << "----- Operaciones de Pilas -----" << endl;
        cout << "1. Empujar (push)" << endl;
        cout << "2. Sacar (pop)" << endl;
        cout << "3. Ver tope" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Imprimir Elementos" << endl;
        cout << "6. Borrar todos los elementos" << endl;
        cout << "7. Regresar al Menu Anterior" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 7) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {
        case 1://Primera opcion: Se empuja (o ingresa) un elemento "Simbolo" al stack.
            cout << "Opcion 1 - Empujar dentro del stack" << endl;
            cout << "A continuacion va a empujar un nuevo elemento dentro del stack." << endl;
            cout << "Ingrese el simboolo que le gustaria insertar (1 caracter): ";
            getline(cin, newSimb);

            while (newSimb.size() > 1) {
                
                cout << "Recuerde que solo puede ingresar un caracter. Intente de nuevo: ";
                getline(cin, newSimb);
            }

            temporalsym = new Simbolo(newSimb[0]);
            Pila->push(temporalsym);
            cout << "\nExitoso. El simbolo ha sido agregado al stack.\n";
            break;

        case 2://Se saca un elemento del stack.
            cout << "Opcion 2 - Sacar un elemento" << endl;
            symsacado = Pila->pop();
            if (symsacado) {
                cout << "Ha sacado el ultimo elemento en entrar al stack.\nEl elemento sacado fue " << symsacado->toString() << endl;
            }
            break;

        case 3://Se revisa cual es el tope del stack, SIN sacarlo.
            cout << "Opcion 3 - Ver Tope" << endl;
            topeActS = Pila->top();
            if (topeActS) {
                cout << "El tope actual de la pila es: " << topeActS->toString() << endl;
            }
            break;

        case 4://Se revisa si la pila esta vacia.
            cout << "Opcion 4 - Revisar pila vacia" << endl;
            if (Pila->isEmpty()) {
                cout << "La pila esta vacia.\n";
            }
            else
                cout << "La pila no esta vacia, actualmente contiene por lo menos un elemento.\n";
            break;

        case 5://Se imprimen todos los elementos del stack actual.
            cout << "Opcion 5 - Imprimir elementos de pila" << endl;
            Pila->print();
            break;

        case 6://Se limpia el stack, se borran los elementos y se libera memoria internamente.
            cout << "Opcion 6 - Borrar elementos de pila" << endl;
            Pila->clear();
            cout << "Se han borrado todos los elementos actuales de la lista.\nSu size ahora es 0. " << endl;
            break;

        case 7://Opcion para salir a un menu exterior.
            cout << "Saldra al menu de tipo de pilas." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

//Menu interno de LinkedStack
void menuInternoLP() {
    string valid = "";
    string caracter;
    int opc = 1;
    while (opc != 7) {
        cout << "----- Operaciones de Pilas -----" << endl;
        cout << "1. Empujar (push)" << endl;
        cout << "2. Sacar (pop)" << endl;
        cout << "3. Ver tope" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Imprimir Elementos" << endl;
        cout << "6. Borrar todos los elementos" << endl;
        cout << "7. Regresar al Menu Anterior" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 7) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {
        case 1://Primera opcion: Se empuja (o ingresa) un elemento "Simbolo" al stack.
            cout << "Opcion 1 - Empujar dentro del stack" << endl;
            caracter = '\0';
            cout << "A continuación se agregara un simbolo nuevo a la pila." << endl;
            cout << "Ingrese el simbolo que desea almacenar en la pila: ";

            getline(cin, caracter);
            while (caracter.size() > 1) {
                cout << "Recuerde que solo puede ingresar un caracter. Intente de nuevo: ";
                getline(cin, caracter);
            }
            cout << endl;
            Pila->push(new Simbolo(caracter[0]));
            cout << "El simbolo se ha almacenado exitosamente!" << endl;
            break;

        case 2://Se saca un elemento del stack.
            cout << "Opcion 2 - Sacar un elemento" << endl;
            if (!Pila->isEmpty()) {
                cout << "A continuación se sacara el objeto ultimo almacenado en la pila" << endl;
                Simbolo* sacadePila = dynamic_cast<Simbolo*>(Pila->pop());
                cout << "El simbolo sacado de la pila fue " << sacadePila->toString() << endl;
            }
            else
                cout << "La pila esta vacia" << endl;

            break;

        case 3://Se revisa cual es el tope del stack, SIN sacarlo.
            cout << "Opcion 3 - Ver Tope" << endl;
            if (!Pila->isEmpty())
                cout << "El Simbolo que esta en la cima de la pila es: " << dynamic_cast<Simbolo*>(Pila->top())->getSimbolo() << endl;
            else
                cout << "La pila esta vacia." << endl;
            break;

        case 4://Se revisa si la pila esta vacia.
            cout << "Opcion 4 - Revisar pila vacia" << endl;
            if (!Pila->isEmpty())
                cout << "La pila No esta vacia." << endl;
            else
                cout << "La pila esta vacia." << endl;
            break;

        case 5://Se imprimen todos los elementos del stack actual.
            cout << "Opcion 5 - Imprimir elementos de pila" << endl;
            if (!Pila->isEmpty())
                Pila->print();
            else
                cout << "La pila esta vacia." << endl;
            break;

        case 6://Se limpia el stack, se borran los elementos y se libera memoria internamente.
            cout << "Opcion 6 - Borrar elementos de pila" << endl;
            if (!Pila->isEmpty()) {
                Pila->clear();
                cout << "La pila se ha vaciado con éxito!" << endl;
            }
            else
                cout << "La pila ya esta vacia." << endl;
            break;

        case 7://Opcion para salir a un menu exterior.
            cout << "Saldra al menu de tipo de pilas." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

//Menu interno de ArrayQueue
void menuInternoAC() {
    string valid = "";
    int opc = 1;
    while (opc != 7) {
        cout << "----- Operaciones de Colas -----" << endl;
        cout << "1. Encolar (queue)" << endl;
        cout << "2. Desencolar (dequeue)" << endl;
        cout << "3. Ver Frente (peek)" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Imprimir Elementos" << endl;
        cout << "6. Borrar los elementos" << endl;
        cout << "7. Regresar al Menu Anterior" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 7) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);
        }

        switch (opc) {

        case 1: {//Case que sirve para insertar un alumno a la queue
            cout << "Opcion 1 - Encolar" << endl;
            Alumno* insertar = crearAlumno();
            aq->queue(insertar);
            break;
        }
        case 2: {//Case que sirve para quitar un alumno de la queue
            cout << "Opcion 2 - Desencolar" << endl;
            Alumno* recibir = aq->dequeue();
            if (recibir) {
                cout << "El alumno que se acaba de quitar es: " << recibir->toString() << endl;
            }
            break;
        }
        case 3: {//Se mira cual es el frente de la cola
            cout << "Opcion 3 - Ver Frente" << endl;
            aq->peek();
            break;
        }
        case 4: {//Verifica si la cola esta o no esta vacia
            cout << "Opcion 4 - Verificar si la cola esta vacia" << endl;
            string imprimir = aq->vacia() ? "Esta vacia" : "No esta vacia";
            cout << imprimir << endl;
            break;
        }
        case 5: {//Imprime toda la cola.
            cout << "Opcion 5 - Imprimir elementos de cola" << endl;
            aq->imprimir();
            break;
        }
        case 6: {//Vacia la cola.
            cout << "Opcion 6 - Borrar elementos de cola" << endl;
            aq->anula();
            cout << "La cola se vacio con exito" << endl;
            break;
        }
        case 7: {//Sale al menu exterior de tipos de colas
            cout << "Saldra al menu de tipo de colas." << endl;
            break;
        }
        default: {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        }
    }
}

//Menu interno de LinkedQueue
void menuInternoLC() {
    string valid = "";
    int opc = 1;
    while (opc != 7) {
        cout << "----- Operaciones de Colas -----" << endl;
        cout << "1. Encolar (queue)" << endl;
        cout << "2. Desencolar (dequeue)" << endl;
        cout << "3. Ver Frente (peek)" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Imprimir Elementos" << endl;
        cout << "6. Borrar los elementos" << endl;
        cout << "7. Regresar al Menu Anterior" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 7) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {
        case 1: {//Case que sirve para insertar un alumno a la queue
            cout << "Opcion 1 - Encolar" << endl;
            Alumno* insertar = crearAlumno();
            lq->queue(insertar);
            break;
        }
        case 2: {//Case que sirve para quitar un alumno de la queue
            cout << "Opcion 2 - Desencolar" << endl;
            Alumno* recibir = lq->dequeue();
            if (recibir)
                cout << "El siguiente alumno es: " << recibir->toString() << endl;
            break;
        }
        case 3: {//Se mira cual es el frente de la cola
            cout << "Opcion 3 - Ver Frente" << endl;
            lq->peek();
            break;
        }
        case 4: {//Verifica si la cola esta o no esta vacia
            cout << "Opcion 4 - Verificar si la cola esta vacia" << endl;
            string imprimir = lq->vacia() ? "Esta Vacia" : "No esta vacia";
            cout << imprimir << endl;
            break;
        }
        case 5: {//Imprime toda la cola.
            cout << "Opcion 5 - Imprimir elementos de cola" << endl;
            lq->imprimir();
            break;
        }
        case 6: {//Vacia la cola.
            cout << "Opcion 6 - Borrar elementos de cola" << endl;
            lq->anula();
            cout << "La cola fue vaciada con exito." << endl;
            break;
        }
        case 7: {//Sale al menu exterior de tipos de colas
            cout << "Saldra al menu de tipo de colas." << endl;
            break;
        }
        default: {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        }
    }
}

//Primer menu de listas, donde se escoge entre trabajar con ArrayList o LinkedList
void menuTipoListas() {
    string valid = "";
    int opc = 1;
    while (opc != 3) {
        cout << "----- Menu Tipo de Lista -----" << endl;
        cout << "1. Trabajar con ArrayList" << endl;
        cout << "2. Trabajar con LinkedList" << endl;
        cout << "3. Regresar al Menú Principal" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 3) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {
        case 1:
            menuInternoAL();
            break;
        case 2:
            menuInternoLL();
            break;
        case 3:
            cout << "Ha salido del menu de tipo de listas.\n" << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

//Primer menu de pilas, donde se escoge entre trabajar con ArrayStack o LinkedStack
void menuTipoPilas() {
    string valid = "";
    int opc = 1;
    while (opc != 3) {
        cout << "----- Menu Tipo de Pila -----" << endl;
        cout << "1. Trabajar con ArrayStack" << endl;
        cout << "2. Trabajar con LinkedStack" << endl;
        cout << "3. Regresar al Menú Principal" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 3) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {
        case 1:
            Pila = new ArrayStack();
            menuInternoAP();
            break;
        case 2:
            Pila = new LinkedStack();
            menuInternoLP();
            break;
        case 3:
            cout << "Ha salido del menu de tipo de pilas.\n" << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

//Primer menu de colas, donde se escoge entre trabajar con ArrayQueue o LinkedQueue
void menuTipoColas() {
    string valid = "";
    int opc = 1;
    while (opc != 3) {
        cout << "----- Menu Tipo de Cola -----" << endl;
        cout << "1. Trabajar con ArrayQueue" << endl;
        cout << "2. Trabajar con LinkedQueue" << endl;
        cout << "3. Regresar al Menú Principal" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 3) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {
        case 1:
            aq = new ArrayQueue();
            menuInternoAC();
            break;
        case 2:
            lq = new LinkedQueue();
            menuInternoLC();
            break;
        case 3:
            cout << "Ha salido del menu de tipo de colas.\n" << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

//Menú principal del proyecto
void menuPrincipal() {
    string valid = "";
    int opc = 1;
    while (opc != 4) {
        cout << "----- MENU PRINCIPAL -----" << endl;
        cout << "1. Trabajar con Listas" << endl;
        cout << "2. Trabajar con Pilas" << endl;
        cout << "3. Trabajar con Colas" << endl;
        cout << "4. Salir" << endl;

        getline(cin, valid);
        while (!isDigit(valid))//Revisa que lo que ingreso el usuario sean numeros sin espacios.
        {
            cout << "Ingrese solo numeros!!\n";
            getline(cin, valid);
        }

        opc = stoi(valid);

        while (opc < 1 || opc > 4) {//Revisa, despues de revisar que solo son numeros, que esten dentro del rango establecido.
            cout << "Ingrese una opcion valida.\n";
            getline(cin, valid);

            while (!isDigit(valid))
            {
                cout << "Ingrese solo numeros!!\n";
                getline(cin, valid);
            }
            opc = stoi(valid);

        }

        switch (opc) {//Switch que dependiendo de lo que escogio el usuario lo lleva a una opcion mas interna.
        case 1:
            menuTipoListas();
            break;
        case 2:
            menuTipoPilas();
            break;
        case 3:
            menuTipoColas();
            break;
        case 4:
            cout << "Ha salido del programa" << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }

}

//Metodo main
int main()
{
    setlocale(LC_ALL, "spanish");
    menuPrincipal();
}

