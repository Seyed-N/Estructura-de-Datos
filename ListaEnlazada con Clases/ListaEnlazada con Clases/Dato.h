#pragma once
#include <iostream>
#include <string>

using namespace std;

class Dato {
private:
    int codigo;
    string nombre;
    string carrera;

public:
    // Constructor por defecto
    Dato();

    // Setters
    void setCodigo(int c);
        void setNombre(const string& n);
        void setCarrera(const string& c);

        // Getters
        int getCodigo() const;
        string getNombre() const;
        string getCarrera() const;
};
