#include <iostream>
#include <string>
#include <locale>
#include "Alumno.h"
#include "TDAPila.h"
#include "TDACola.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "TDALista.h"
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

TDAPila* Pila;
TDACola* aq;
TDACola* lq;
Object* temporalsym;
Object* symsacado;
Object* topeActS;

bool isDigit(string aValidar) {
    for (int i = 0; i < aValidar.size(); i++)
    {
        if (aValidar[i] < 48 || aValidar[i] > 57) {
            return false;
        }
    }
    return true;
}

Alumno* crearAlumno() {
    string nombre;
    string cuenta;
    cout << "Ingrese el nombre del alumno: " << endl;
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese la cuenta del alumno: " << endl;
    getline(cin, cuenta);
    Alumno* alumno = new Alumno(nombre, cuenta);
    return alumno;
}

void menuInternoAL() {
    //variables de inicializacion
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

        cin >> opc;
        while (opc < 1 || opc > 10) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

        }

        switch (opc) {
        case 1:

            cout << "---- En listas, unicamente es posible insertar Alumnos ----" << endl;

            //creacion dle objeto "Alumno"

            while (seguir) {
                cout << "Ingrese el nombre del alumno: ";
                cin >> nombre;

                

                cout << "Ingrese el numero de cuenta: ";
                cin >> nCuenta;

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

                do {
                    cout << "Desea continuar (Ingrese Si/No): ";
                    cin >> respuesta;

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
                } while (true);

            }

            break;
        case 2:
            if (!lista->vacia()) {
                cout << "Alumnos" << endl;

                lista->imprime_lista();
            }
            else {
                cout << "No hay elementos en la lista para mostrar" << endl;
            }

            break;
        case 3:
            cout << "Introduzca el numero de cuenta que desea consultar: ";
            cin >> nCuenta;

            alumno = new Alumno(".", nCuenta);

            pos = lista->busca(alumno);

            alumno = dynamic_cast<Alumno*>(lista->recupera(pos));

            if (!alumno) {
                cout << "No hay ningun elemento con el dato ingresado" << endl;
            }
            else {
                cout << alumno->toString() << endl;
            }
            break;
        case 4:
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

            break;
        case 5:

            if (lista->vacia())
                cout << "La lista esta vacia" << endl;
            else
                cout << "Actualmente hay " << lista->getSize() << " elementos" << endl;
            break;
        case 6:
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

            }

            break;
        case 7:
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
            break;
        case 8:
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
            break;
        case 9:
            if (!lista->vacia()) {
                lista->anula();

                cout << "Los elementos se han eliminado exitosamente!" << endl;
            }
            break;
        case 10:
            cout << "Saldra al menu de tipo de listas" << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

void menuInternoLL() {
    LinkedList* lista = new LinkedList();
    int opc = 1;
    while (opc != 10) {
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

        cin >> opc;
        while (opc < 1 || opc > 10) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

        }

        switch (opc) {
        case 1:
        {
            string nombre, numCuenta;
            cout << "Ingrese el nombre del alumno: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el número de cuenta del alumno: ";
            getline(cin, numCuenta);
            Alumno* alumno = new Alumno(nombre, numCuenta);
            lista->inserta(alumno, lista->getSize());
            break;
        }
        case 2: {
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
        }
        case 3: {
            string numCuenta;
            cout << "Ingrese el número de cuenta del alumno a buscar: ";
            cin.ignore();
            getline(cin, numCuenta);
            Alumno alumno("", numCuenta);
            int posicion = lista->busca(&alumno);
            if (posicion != -1) {
                cout << "El alumno se encuentra en la posición " << posicion << endl;
            }
            else {
                cout << "El alumno no se encuentra en la lista." << endl;
            }
            break;
        }
        case 4: {
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


            break;
        }
        case 5: {
            cout << "La lista está vacía: " << (lista->vacia() ? "Sí" : "No") << endl;
            break;
        }
        case 6: {
            int posicion;
            int index;
            lista->imprime_lista();
            cout << "Ingrese la posición del elemento a obtener: ";
            cin >> posicion;
            Alumno* alumno = dynamic_cast<Alumno*>(lista->recupera(posicion));
            if (alumno != nullptr) {
                cout << "El elemento en la posición " << posicion << " es: " << alumno->toString() << endl;
            }
            else {
                cout << "No se pudo obtener el elemento. Verifique la posición." << endl;
            }


            break;
        }
        case 7: {
            int posicion;
            int index;
            lista->imprime_lista();
            cout << "Ingrese la posición del elemento del cual desea obtener el siguiente: ";
            cin >> posicion;
            Alumno* siguiente = dynamic_cast<Alumno*>(lista->siguiente(posicion));
            if (siguiente != nullptr) {
                cout << "El siguiente elemento después de la posición " << posicion << " es: " << siguiente->toString() << endl;
            }
            else {
                cout << "No hay siguiente elemento o la posición es inválida." << endl;
            }


            break;
        }
        case 8: {
            int posicion;
            int index;
            lista->imprime_lista();
            cout << "Ingrese la posición del elemento del cual desea obtener el anterior: ";
            cin >> posicion;
            Alumno* anterior = dynamic_cast<Alumno*>(lista->anterior(posicion));
            if (anterior != nullptr) {
                cout << "El elemento anterior a la posición " << posicion << " es: " << anterior->toString() << endl;
            }
            else {
                cout << "No hay elemento anterior o la posición es inválida." << endl;
            }


            break;
        }
        case 9: {
            lista->anula();
            cout << "Se han borrado todos los elementos de la lista." << endl;
            break;
        }
        case 10: {
            cout << "Regresando al menú anterior..." << endl;
            break;
        }
        default:
            cout << "Opción no válida. Por favor, intente de nuevo." << endl;
        }
    }
}

void menuInternoAP() {
    int opc = 1;

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

        cin >> opc;
        while (opc < 1 || opc > 7) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

        }

        switch (opc) {
        case 1:
            cin.ignore();
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

        case 2:

            symsacado = Pila->pop();
            if (symsacado) {
                cout << "Ha sacado el ultimo elemento en entrar al stack. El elemento sacado fue " << symsacado->toString() << endl;
            }
            break;

        case 3:

            topeActS = Pila->top();
            if (topeActS) {
                cout << "El tope actual de la pila es: " << topeActS->toString() << endl;
            }
            break;

        case 4:
            if (Pila->isEmpty()) {
                cout << "La pila esta vacia.\n";
            }
            else
                cout << "La pila no esta vacia, actualmente contiene por lo menos un elemento.\n";
            break;

        case 5:

            Pila->print();
            break;

        case 6:

            Pila->clear();
            cout << "Se han borrado todos los elementos actuales de la lista. Su size ahora es " << Pila->size << endl;
            break;

        case 7:
            cout << "Saldra al menu de tipo de pilas." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

void menuInternoLP() {
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

        cin >> opc;
        while (opc < 1 || opc > 7) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

        }

        switch (opc) {
        case 1:
            caracter = '\0';
            cout << "A continuación se agregara un simbolo nuevo a la pila." << endl;
            cout << "Ingrese el simbolo que desea almacenar en la pila: ";
            cin.ignore();
            getline(cin, caracter);
            while (caracter.size() > 1) {
                cout << "Recuerde que solo puede ingresar un caracter. Intente de nuevo: ";
                getline(cin, caracter);
            }
            cout << endl;
            Pila->push(new Simbolo(caracter[0]));
            cout << "El simbolo se ha almacenado exitosamente!" << endl;
            break;

        case 2:
            if (!Pila->isEmpty()) {
                cout << "A continuación se sacara el objeto ultimo almacenado en la pila" << endl;
                Simbolo* sacadePila = dynamic_cast<Simbolo*>(Pila->pop());
            }
            else
                cout << "La pila esta vacia" << endl;

            break;

        case 3:
            if (!Pila->isEmpty())
                cout << "El Simbolo que esta en la cima de la pila es: " << dynamic_cast<Simbolo*>(Pila->top())->getSimbolo() << endl;
            else
                cout << "La pila esta vacia." << endl;
            break;

        case 4:
            if (!Pila->isEmpty())
                cout << "La pila No esta vacia." << endl;
            else
                cout << "La pila esta vacia." << endl;
            break;

        case 5:
            if (!Pila->isEmpty())
                Pila->print();
            else
                cout << "La pila esta vacia." << endl;
            break;

        case 6:
            if (!Pila->isEmpty()) {
                Pila->clear();
                cout << "La pila se ha vaciado con éxito!" << endl;
            }
            else
                cout << "La pila ya esta vacia." << endl;
            break;

        case 7:
            cout << "Saldra al menu de tipo de pilas." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

void menuInternoAC() {
    
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

        cin >> opc;
        while (opc < 1 || opc > 7) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

        }

        switch (opc) {

        case 1: {
            Alumno* insertar = crearAlumno();
            aq->queue(insertar);
            break;
        }
        case 2: {
            Alumno* recibir = aq->dequeue();
            if (recibir) {
                cout << "El siguiente alumno es: " << recibir->toString() << endl;
            }
            break;
        }
        case 3: {
            aq->peek();
            break;
        }
        case 4: {
            string imprimir = aq->vacia() ? "Esta vacia" : "No esta vacia";
            cout << imprimir << endl;
            break;
        }
        case 5: {
            aq->imprimir();
            break;
        }
        case 6: {
            aq->anula();
            cout << "La lista se vacio con exito" << endl;
            break;
        }
        case 7: {
            cout << "Saldra al menu de tipo de colas." << endl;
            break;
        }
        default: {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        }
    }
}

void menuInternoLC() {
    
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

        cin >> opc;
        while (opc < 1 || opc > 7) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

        }

        switch (opc) {
        case 1: {
            Alumno* insertar = crearAlumno();
            lq->queue(insertar);
            break;
        }
        case 2: {
            Alumno* recibir = lq->dequeue();
            if (recibir)
                cout << "El siguiente alumno es: " << recibir->toString() << endl;
            break;
        }
        case 3: {
            lq->peek();
            break;
        }
        case 4: {
            string imprimir = lq->vacia() ? "Esta Vacia" : "No esta vacia";
            cout << imprimir << endl;
            break;
        }
        case 5: {
            lq->imprimir();
            break;
        }
        case 6: {
            lq->anula();
            cout << "La cola fue vaciada con exito." << endl;
            break;
        }
        case 7: {
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

    int opc = 1;
    while (opc != 3) {
        cout << "----- Menu Tipo de Lista -----" << endl;
        cout << "1. Trabajar con ArrayList" << endl;
        cout << "2. Trabajar con LinkedList" << endl;
        cout << "3. Regresar al Menú Principal" << endl;

        cin >> opc;
        while (opc < 1 || opc > 3) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

        }

        switch (opc) {
        case 1:
            menuInternoAL();
            break;
        case 2:
            menuInternoLL();
            break;
        case 3:
            cin.ignore();
            cout << "Ha salido del menu de tipo de listas.\n" << endl;
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
}

void menuTipoPilas() {
    int opc = 1;
    while (opc != 3) {
        cout << "----- Menu Tipo de Pila -----" << endl;
        cout << "1. Trabajar con ArrayStack" << endl;
        cout << "2. Trabajar con LinkedStack" << endl;
        cout << "3. Regresar al Menú Principal" << endl;

        cin >> opc;
        while (opc < 1 || opc > 3) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

        }

        switch (opc) {
        case 1:
            Pila = new ArrayStack();
            menuInternoAP();
            break;
        case 2:
            //Pila = new LinkedStack();
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

void menuTipoColas() {
    //TDACola* Cola;
    int opc = 1;
    while (opc != 3) {
        cout << "----- Menu Tipo de Cola -----" << endl;
        cout << "1. Trabajar con ArrayQueue" << endl;
        cout << "2. Trabajar con LinkedQueue" << endl;
        cout << "3. Regresar al Menú Principal" << endl;

        cin >> opc;
        while (opc < 1 || opc > 3) {
            cin.ignore();
            cout << "Ingrese una opcion valida.\n";
            cin >> opc;

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

void menuPrincipal() {//Menú principal del proyecto
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


int main()
{
    setlocale(LC_ALL, "spanish");
    menuPrincipal();
}

