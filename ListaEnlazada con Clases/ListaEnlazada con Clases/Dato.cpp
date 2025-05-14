#include "Dato.h"
#include <iostream>
#include <string>

using namespace std;

Dato::Dato() {
    codigo = 0;
    nombre = "Unknown";
    carrera = "Unknown";
}

// Setters
void Dato::setCodigo(int c) { 
    codigo = c; 
}

void Dato::setNombre(const string& n) { 
    nombre = n; 
}

void Dato::setCarrera(const string& c) { 
    carrera = c; 
}

// Getters
int Dato::getCodigo() const { 
    return codigo; 
}

string Dato::getNombre() const { 
    return nombre; 
}

string Dato::getCarrera() const { 
    return carrera; 
}