#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

int i = 0;

class Servidor
{
    Servidor *siguiente;
  public:
    Servidor()
    {
        siguiente = 0;
    }
    void setSiguiente(Servidor *n)
    {
        siguiente = n;
    }
    void agregar(Servidor *n)
    {
        if (siguiente)
          siguiente->agregar(n);
        else
          siguiente = n;
    }
    
    virtual void manejar(string name, string domi)
    {
        siguiente->manejar(name, domi);
    }
};

class DNS1: public Servidor
{
  public:
     void manejar(string name, string domi)
    {
        if (domi == ".com")
        {
            cout << "132.32.43." << i << " encontrado en el servidor 1" << endl;
            i++;
        }
        else
            cout << "No tengo ese dominio" << endl;
            Servidor::manejar(name, domi);
    }
};

class DNS2: public Servidor
{
  public:
     void manejar(string name, string domi)
    {
        if (domi == ".org")
        {
            cout << "132.32.43." << i << " encontrado en el servidor 2" << endl;
            i++;
        }
        else
            cout << "No tengo ese dominio" << endl;
            Servidor::manejar(name, domi);
    }
};

class DNS3: public Servidor
{
  public:
     void manejar(string name, string domi)
    {
        if (domi == ".gob")
        {
            cout << "IP: 132.32.43." << i << " encontrado en el servidor 3" << endl;
            i++;
        }
        else
          cout << "No tengo ese dominio" << endl;
          Servidor::manejar(name, domi);
    }
};

class DNS4: public Servidor
{
  public:
     void manejar(string name, string domi)
    {
        if (domi == ".mx")
        {
            cout << "IP: 132.32.43." << i << " encontrado en el servidor 4" << endl;
            i++;
        }
        else
          cout << "No tengo ese dominio" << endl;
          Servidor::manejar(name, domi);
    }
};

int main()
{
  srand(time(0));
  DNS1 prueba1;
  DNS2 prueba2;
  DNS3 prueba3;
  DNS4 prueba4;
  prueba1.agregar(&prueba2);
  prueba1.agregar(&prueba3);
  prueba1.agregar(&prueba4);
  prueba1.manejar("www.itesm", ".com");
  cout << '\n';
}