#include <string>
#include <iostream>

using namespace std;

template<class T>
class Iterator;

template<class T>
class Aggregate
{
public:
    friend class Iterator<T>;
    Aggregate()
    {
        pos = 0;
        size = 10; //tamaño predefinido, pero deberíamos hacer que el arreglo fuera dinámico
        lista = new T[size];
    }
    void add(T element)
    {
        if(pos < size)            
            lista[pos++] = element; 
    }
    void imprimir(){
        cout << "El total de pasteles es " << pos << endl;
    }
    Iterator<T>* getIterator()
    {
        return new Iterator<T>(this);
    }
    
    ~Aggregate()
    {
        delete [] lista;
    }

    T getElementAt(int pos){
        return lista[pos];
    }

    int getPos()
    {
        return pos;
    }  

private:
    T* lista;
    int size;
    int pos;
};

template<class T>
class Iterator
{
public:
    Iterator(Aggregate<T>* aggregate) : idx(0), aggregate(aggregate)
    {}
    
    T next()
    {
        if(hasNext())
            //return aggregate->getElementAt(idx++);
            return aggregate->lista[idx++];
        else
            return 0;
    }
    
    bool hasNext()
    {
        return (idx < aggregate->getPos());
    }
    ~Iterator(){}

private:
    Iterator(){}
    Aggregate<T>* aggregate;
    int idx;
};

class Pastel
{
public:    
    virtual void batido() = 0;
    virtual void amasado() = 0;
    virtual void horneado() = 0;
    virtual void decorado() = 0;
    virtual void empacado() = 0;
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

class TresLeches : public Clon<Pastel, TresLeches>
{
    void batido()
    {
      cout << "Estoy en proceso de batido" << endl;
    }
    void amasado()
    {
      cout << "Estoy en proceso de amasado" << endl;
    }
    void horneado()
    {
        cout << "Estoy en proceso de horneado" << endl;
    }
    void decorado()
    {
        cout << "Estoy en proceso de decorado" << endl;
    }
    void empacado()
    {
        cout << "Estoy en proceso de empacado" << endl;
    }
};

class Sacher : public Clon<Pastel, Sacher>
{
    void batido()
    {
      cout << "Estoy en proceso de batido" << endl;
    }
    void amasado()
    {
      cout << "Estoy en proceso de amasado" << endl;
    }
    void horneado()
    {
        cout << "Estoy en proceso de horneado" << endl;
    }
    void decorado()
    {
        cout << "Estoy en proceso de decorado" << endl;
    }
    void empacado()
    {
        cout << "Estoy en proceso de empacado" << endl;
    }
};

class Imposible : public Clon<Pastel, Imposible>
{
    void batido()
    {
      cout << "Estoy en proceso de batido" << endl;
    }
    void amasado()
    {
      cout << "Estoy en proceso de amasado" << endl;
    }
    void horneado()
    {
        cout << "Estoy en proceso de horneado" << endl;
    }
    void decorado()
    {
        cout << "Estoy en proceso de decorado" << endl;
    }
    void empacado()
    {
        cout << "Estoy en proceso de empacado" << endl;
    }
};

class Sucursal
{
public:
    virtual Pastel* factoryMethod(int)=0;
    
    Pastel* crearPastel(int tipo)
    {
        Pastel* miPastel = factoryMethod(tipo);
        miPastel->batido();
        miPastel->amasado();
        miPastel->horneado();
        miPastel->decorado();
        miPastel->empacado();
        return miPastel;
    }
};

class SucursalAguascalientes : public Sucursal
{
public:
    static SucursalAguascalientes* r;
    
    static SucursalAguascalientes* getInstance(){
        if(r){
            return r;
        }
        else{
            r = new SucursalAguascalientes();
            return r;
        }
    }
    Pastel* factoryMethod(int tipo)
    {
        if(tipo==1){
            cout << "En creacion pastel tres leches con los ingredientes leche, huevo y mantequilla" << endl;
            cout << "Sucursal Aguascalientes" << endl;
            return new TresLeches;
        }
        else if(tipo==2){
            cout << "En creacion pastel Sacher con los ingredientes leche, huevo y mantequilla" << endl;
            cout << "Sucursal Aguascalientes" << endl;
            return new Sacher;
        }
        else{
            cout << "En creacion pastel Imposible con los ingredientes leche, huevo y mantequilla" << endl;
            cout << "Sucursal Aguascalientes" << endl;
            return new Imposible;
        }
    }
    
    private: 
    SucursalAguascalientes(){
        
    }
};

class SucursalCDMX : public Sucursal
{
public:
    static SucursalCDMX* c;
    
    static SucursalCDMX* getInstance(){
        if(c){
            return c;
        }
        else{
            c = new SucursalCDMX();
            return c;
        }
    }
    Pastel* factoryMethod(int tipo)
    {
        if(tipo==1){
            cout << "En creacion pastel tres leches con los ingredientes chocolate, frutas y merengue" << endl;
            cout << "Sucursal CDMX" << endl;
            return new TresLeches;
        }
        else if(tipo==2){
            cout << "En creacion pastel Sacher con los ingredientes chocolate, frutas y merengue" << endl;
            cout << "Sucursal CDMX" << endl;
            return new Sacher;
        }
        else{
            cout << "En creacion pastel Imposible con los ingredientes chocolate, frutas y merengue" << endl;
            cout << "Sucursal CDMX" << endl;
            return new Imposible;
        }
    }
    
    private: 
    SucursalCDMX(){
        
    }
};

SucursalAguascalientes* SucursalAguascalientes::r = 0; //variables estaticas necesitan inicializarse fuera de la clase
SucursalCDMX* SucursalCDMX::c = 0; 

int main()
{
    Sucursal* cliente = SucursalAguascalientes::getInstance();
    Pastel* miProducto = cliente->crearPastel(1);
    
    Sucursal* cliente2 = SucursalCDMX::getInstance();
    Pastel* miProducto2 = cliente2->crearPastel(2);
    
    Aggregate<Pastel*> p;
    p.add(miProducto);
    p.add(miProducto2);
    p.imprimir();
    return 1;
}