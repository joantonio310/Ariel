#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subject {
    vector < class Observer * > views; 
    int value;
  public:
    void attach(Observer *obser) {
        views.push_back(obser);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify();
};

class Observer {
    Subject *sujeto;
    string mensaje;
  public:
    Observer(Subject *suj, string men) {
        sujeto = suj;
        mensaje = men;
        sujeto->attach(this);
    }
    virtual void update() = 0;
  protected:
    Subject *getSubject() {
        return sujeto;
    }
    string getMensaje() {
        return mensaje;
    }
};

void Subject::notify() {
  for (int i = 0; i < views.size(); i++)
    views[i]->update();
}

class ConcreteObserverA: public Observer {
  public:
    ConcreteObserverA(Subject *suj, string mensaje): Observer(suj, mensaje){}
    void update() {
        string v = getMensaje();
        cout << v << endl;
    }
};

class ConcreteObserverB: public Observer {
  public:
    ConcreteObserverB(Subject *suj, string mensaje): Observer(suj, mensaje){}
    void update() {
        string v = getMensaje();
        cout << v << endl;
    }
};

int main() {
  Subject subj;
  ConcreteObserverA observador1(&subj, "Notificacion 1"); 
  ConcreteObserverA observador2(&subj, "Notificacion 2"); 
  ConcreteObserverB observador3(&subj, "Notificacion 3");
  subj.setVal(14);
}