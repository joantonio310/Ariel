#include<iostream>
#include<string>
using namespace std;

class Computadora{
    private:
        string nombre;
    public:
        void crear(string nombre){
            setNombre(nombre);
            cout << nombre << " creada" << endl;
            cout << "Seleccion de componentes. Completado" << endl;
            cout << "Ensamblado de componentes. Completado" << endl;
            cout << "instalacion y configuracion de Software. Completado" << endl;
            cout << "Empaquetado del computador. Completado" << endl;
        }
        
        void setNombre(string _nombre){
            nombre = _nombre;
        }
        string getNombre(){
            return nombre;
        }
};

int main(){
    Computadora a;
    a.crear("Laptop");
    return 0;
}