
#include <iostream>

using namespace std;
class Product
{
public:    
    virtual void operacion1() = 0;
    virtual void operacion2() = 0;
};

template <class Base, class SubClase>
class Clon : public Base
{
public:
    virtual Base* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));    
    }
};

class Producto1 : public Clon<Product, Producto1>
{
    void operacion1()
    {
      cout << "Estoy en operacion 1 Prod 1";
    }
    void operacion2()
    {
      cout << "Estoy en operacion 1 Prod 1";
    }
};

class Producto2 : public Clon<Product, Producto1>
{
    void operacion1()
    {
      cout << "Estoy en operacion 1 Prod 1";
    }
    void operacion2()
    {
      cout << "Estoy en operacion 1 Prod 1";
    }
};

class Creator
{
public:
    virtual Product* factoryMethod(int)=0;
    
    Product* createProduct(int tipo)
    {
        Product* myProduct = factoryMethod(tipo);
        myProduct->operacion1();
        myProduct->operacion2();
        return myProduct;
    }
};

class ConcreteCreator : public Creator
{
public:
    static ConcreteCreator* r;
    
    static ConcreteCreator* getInstance(){
        if(r){
            return r;
        }
        else{
            r = new ConcreteCreator();
            return r;
        }
    }
    Product* factoryMethod(int tipo)
    {
        if(tipo==1)
            return new Producto1;
        else
            return new Producto2;
    }
    
    private: 
        ConcreteCreator(){
            
        }
};

ConcreteCreator* ConcreteCreator::r = 0; //variables estaticas necesitan inicializarse fuera de la clase

int main()
{
    Creator* cliente = ConcreteCreator::getInstance();
    //Creator* cliente = new ConcreteCreator();
    Product* miProducto = cliente->createProduct(1);
    return 1;
}


