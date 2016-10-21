#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subject {
    vector < class Observer * > views; 
    string mensaje;
    string nombre = "Politico";
  public:
    void attach(Observer *obser) {
        views.push_back(obser);
    }
    void setMensaje(string message) {
        mensaje = message;
        notify();
    }
    string getMensaje() {
        return mensaje;
    }
    /*string getNombre(){
      return nombre;
    }*/
    virtual string getNombre() = 0;
    void setNombre(string name){
      nombre = name;
    }
    void notify();
};

class PenaNieto: public Subject{
    string nombre = "Pena Nieto";
public:
    string getNombre(){
      return nombre;
    }
};

class Hilaria: public Subject{
    string nombre = "Hilary";
public:
    string getNombre(){
      return nombre;
    }
};

class DiscursoTrumpados: public Subject{
    string nombre = "Trump";
public:
    string getNombre(){
      return nombre;
    }
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
    virtual void update(string mensajePolitico) = 0;
  protected:
    string getSubject() {
        return sujeto->getNombre();
    }
    string getMensaje() {
        return mensaje;
    }
};

void Subject::notify() {
  for (int i = 0; i < views.size(); i++)
    views[i]->update(this->getMensaje());
}

class MVSNoticias: public Observer {
    string nombrePolitico;
    string nombreNoticiero = "MVSNoticias";
  public:
    MVSNoticias(Subject *suj, string mensaje): Observer(suj, mensaje){
        nombrePolitico = getSubject();
    }
    void update(string mensajePolitico) {
        cout << "En otras noticias " << nombrePolitico << " comunico el siguiente mensaje" << endl;
        cout << mensajePolitico << endl;
        cout << "Recuerden que esta noticia fue proporcionado por " << nombreNoticiero << endl;
        cout << endl;
    }
};

class Televisa: public Observer {
    string nombrePolitico;
    string nombreNoticiero = "Televisa";
  public:
    Televisa(Subject *suj, string mensaje): Observer(suj, mensaje){
        nombrePolitico = getSubject();
    }
    void update(string mensajePolitico) {
        cout << "En otras noticias " << nombrePolitico << " comunico el siguiente mensaje" << endl;
        cout << mensajePolitico << endl;
        cout << "Recuerden que esta noticia fue proporcionado por " << nombreNoticiero << endl;
        cout << endl;
    }
};

class TVAzteca: public Observer {
    string nombrePolitico;
    string nombreNoticiero = "TV Azteca";
  public:
    TVAzteca(Subject *suj, string mensaje): Observer(suj, mensaje){
        nombrePolitico = getSubject();
    }
    void update(string mensajePolitico) {
        cout << "En otras noticias " << nombrePolitico << " comunico el siguiente mensaje" << endl;
        cout << mensajePolitico << endl;
        cout << "Recuerden que esta noticia fue proporcionado por " << nombreNoticiero << endl;
        cout << endl;
    }
};

class RadioFormula: public Observer {
    string nombrePolitico;
    string nombreNoticiero = "Radio Formula";
  public:
    RadioFormula(Subject *suj, string mensaje): Observer(suj, mensaje){
        nombrePolitico = getSubject();
    }
    void update(string mensajePolitico) {
        cout << "En otras noticias " << nombrePolitico << " comunico el siguiente mensaje" << endl;
        cout << mensajePolitico << endl;
        cout << "Recuerden que esta noticia fue proporcionado por " << nombreNoticiero << endl;
        cout << endl;
    }
};

class CNNNoticias: public Observer {
    string nombrePolitico;
    string nombreNoticiero = "CNN Noticias";
  public:
    CNNNoticias(Subject *suj, string mensaje): Observer(suj, mensaje){
        nombrePolitico = getSubject();
        if(nombrePolitico == "Pena Nieto")
            cout << "Error" << endl;
    }
    void update(string mensajePolitico) {
        cout << "En otras noticias " << nombrePolitico << " comunico el siguiente mensaje" << endl;
        cout << mensajePolitico << endl;
        cout << "Recuerden que esta noticia fue proporcionado por " << nombreNoticiero << endl;
        cout << endl;
    }
};

int main() {
  PenaNieto subj1;
  Hilaria subj2;
  DiscursoTrumpados subj3;
  MVSNoticias observador1(&subj1, "Notificacion 1"); 
  Televisa observador2(&subj1, "Notificacion 2"); 
  TVAzteca observador3(&subj1, "Notificacion 3");
  RadioFormula observador4(&subj1, "Notificacion 4");
  subj1.setMensaje("Mis tres libros son...");
  MVSNoticias observador6(&subj2, "Notificacion 6"); 
  Televisa observador7(&subj2, "Notificacion 7"); 
  TVAzteca observador8(&subj2, "Notificacion 8");
  RadioFormula observador9(&subj2, "Notificacion 9");
  CNNNoticias observador10(&subj2, "Notificacion 10");
  subj2.setMensaje("Sere la primera presidenta de Estados Unidos");
  MVSNoticias observador11(&subj3, "Notificacion 11"); 
  Televisa observador12(&subj3, "Notificacion 12"); 
  TVAzteca observador13(&subj3, "Notificacion 13");
  RadioFormula observador14(&subj3, "Notificacion 14");
  CNNNoticias observador15(&subj3, "Notificacion 15");
  subj3.setMensaje("Hare un muro y Mexico lo pagara");
}