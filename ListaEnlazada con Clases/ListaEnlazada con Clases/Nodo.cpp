#include "Nodo.h"
#include "Dato.h"
#include <iostream>
#include <string>


using namespace std;

Nodo::Nodo() {
    puntero = nullptr;
}

// Acceso a dato y puntero
void Nodo::setDato(const Dato& d) { 
    dato = d; 
}

Dato Nodo::getDato() const { 
    return dato; 
}

void Nodo::setPuntero(Nodo* p) {
    puntero = p; 
}

Nodo* Nodo::getPuntero() const { 
    return puntero; 
}

// Métodos estáticos
void Nodo::Encolar(Nodo*& inicio, Nodo*& fin) {
    Nodo* nuevo = new Nodo();
    Dato d;
    int codigo;
    string nombre, carrera;

    cout << "Codigo: ";
    cin >> codigo;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Carrera: ";
    getline(cin, carrera);

    d.setCodigo(codigo);
    d.setNombre(nombre);
    d.setCarrera(carrera);
    nuevo->setDato(d);

    if (inicio == nullptr) {
        inicio = fin = nuevo;
    }
    else {
        fin->setPuntero(nuevo);
        fin = nuevo;
    }
}

void Nodo::MostrarLista(Nodo* inicio) {
    if (inicio == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

    Nodo* actual = inicio;
    while (actual != nullptr) {
        Dato d = actual->getDato();
        cout << "\nCodigo: " << d.getCodigo() << endl;
        cout << "Nombre: " << d.getNombre() << endl;
        cout << "Carrera: " << d.getCarrera() << endl;
        cout << "--------------------------\n";
        actual = actual->getPuntero();
    }
}

void Nodo::EliminarPorCodigo(Nodo*& inicio, Nodo*& fin, int codigo) {
    Nodo* actual = inicio;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->getDato().getCodigo() != codigo) {
        anterior = actual;
        actual = actual->getPuntero();
    }

    if (actual == nullptr) {
        cout << "No se encontro un nodo con ese codigo.\n";
        return;
    }

    if (anterior == nullptr) {
        inicio = actual->getPuntero();
        if (inicio == nullptr) fin = nullptr;
    }
    else {
        anterior->setPuntero(actual->getPuntero());
        if (actual == fin) fin = anterior;
    }

    delete actual;
    cout << "Nodo eliminado correctamente.\n";
}