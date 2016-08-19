
#include <iostream>

using namespace std;
class Computadora
{
public:    
    void seleccion(){
        cout << "Seleccionando componentes" << endl;
    }
    void ensamblado(){
        cout << "Ensamblando componentes" << endl;   
    }
    void instalacion(){
        cout << "Instalando y configurando el software" << endl;
    }
    void empaquetado(){
        cout << "Empaquetando el computador" << endl;
    }
};

class Laptop : public Computadora
{

};

class Netbook : public Computadora
{

};

class Tablet : public Computadora
{

};

class Desktop : public Computadora
{

};

class Creator
{
public:
    static Computadora* factoryMethod(int tipo){
        if(tipo==1)
            return new Desktop;
        else if(tipo == 2)
            return new Netbook;
        else if(tipo == 3)
            return new Tablet;
        else if(tipo == 4)
            return new Laptop;  
    }
    
    static Computadora* createProduct(int tipo)
    {
        Computadora* myProduct = factoryMethod(tipo);
        myProduct->seleccion();
        myProduct->ensamblado();
        myProduct->instalacion();
        myProduct->empaquetado();
        return myProduct;
    }
    
    static Computadora* getInstance(){
        return createProduct(1);
    }
};

class ConcreteCreator : public Creator
{

};

int main()
{
    Creator* cliente = new ConcreteCreator();
    Computadora* miProducto = cliente->createProduct(1);

    return 1;
}



