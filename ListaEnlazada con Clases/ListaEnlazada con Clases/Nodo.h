#pragma once
#include <iostream>
#include <string>

#include "Dato.h"

using namespace std;

// Clase Nodo para lista enlazada
class Nodo {
private:
    Dato dato;
    Nodo* puntero;

public:
    // Constructor
    Nodo();

    // Acceso a dato y puntero
    void setDato(const Dato& d);
    Dato getDato() const;

    void setPuntero(Nodo* p);
    Nodo* getPuntero() const;

    // Métodos estáticos
    static void Encolar(Nodo*& inicio, Nodo*& fin);

    static void MostrarLista(Nodo* inicio);

    static void EliminarPorCodigo(Nodo*& inicio, Nodo*& fin, int codigo);
};


