#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

int i = 0;

class Server
{
    Server *next;
  public:
    Server()
    {
        next = 0;
    }
    void setNext(Server *n)
    {
        next = n;
    }
    void add(Server *n)
    {
        if (next)
          next->add(n);
        else
          next = n;
    }
    
    virtual void handle(string name, string domi)
    {
        next->handle(name, domi);
    }
};

class DNS1: public Server
{
  public:
     void handle(string name, string domi)
    {
        if (domi == ".com")
        {
            cout << "132.32.43." << i << " encontrado en el servidor 1" << endl;
            i++;
        }
        else
            cout << "No tengo ese dominio" << endl;
            Server::handle(name, domi);
    }
};

class DNS2: public Server
{
  public:
     void handle(string name, string domi)
    {
        if (domi == ".org")
        {
            cout << "132.32.43." << i << " encontrado en el servidor 2" << endl;
            i++;
        }
        else
            cout << "No tengo ese dominio" << endl;
            Server::handle(name, domi);
    }
};

class DNS3: public Server
{
  public:
     void handle(string name, string domi)
    {
        if (domi == ".gob")
        {
            cout << "IP: 132.32.43." << i << " encontrado en el servidor 3" << endl;
            i++;
        }
        else
          cout << "No tengo ese dominio" << endl;
          Server::handle(name, domi);
    }
};

class DNS4: public Server
{
  public:
     void handle(string name, string domi)
    {
        if (domi == ".mx")
        {
            cout << "IP: 132.32.43." << i << " encontrado en el servidor 4" << endl;
            i++;
        }
        else
          cout << "No tengo ese dominio" << endl;
          Server::handle(name, domi);
    }
};

int main()
{
  srand(time(0));
  DNS1 root;
  DNS2 two;
  DNS3 thr;
  DNS4 fou;
  root.add(&two);
  root.add(&thr);
  root.add(&fou);
  //fou.setNext(&root);
  root.handle("www.itesm", ".com");
  cout << '\n';
}