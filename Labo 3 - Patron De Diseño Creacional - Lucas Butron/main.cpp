#include <iostream>
using namespace std;

class Producto {
public:
    virtual ~Producto(){}
    virtual string Operacion() const = 0;

};

class ProductoConcreto1 : public Producto {
public:
    string Operacion() const override {
        return "{Resultado de ProductoConcreto1}";
    }
};

class ProductoConcreto2 : public Producto {
public:
    string Operacion() const override {
        return "{Resultado de ProductoConcreto2}";
    }
};

class Creador {
public:
    virtual ~Creador() {};
    virtual Producto* FactoryMethod() const = 0;
    string AlgunaOperacion() const {
        Producto* producto = this->FactoryMethod();
        string resultado = "Creador: El mismo codigo del creador acaba de funcionar con" + producto->Operacion();
    }
};

class CreadorConcreto1 : public Creador {
public:
    Producto* FactoryMethod() const override {
        return new ProductoConcreto1();
    }
};

class CreadorConcreto2 : public Creador {
public:
    Producto* FactoryMethod() const override {
        return new ProductoConcreto2();
    }
};

void CodigoCliente(const Creador& creador) {
    cout << "Cliente: No estoy al tanto de la clase Creador, pero aun funciona" << endl;
}

int main() {
    cout << "App: Corriendo con CreadorConcreto1" << endl;
    Creador* creador = new CreadorConcreto1();
    CodigoCliente(*creador);
    cout << endl;
    cout << "App: Corriendo con CreadorConcreto2" << endl;
    Creador* creador2 = new CreadorConcreto2();
    CodigoCliente(*creador2);

    delete creador;
    delete creador2;
    return 0;
}






