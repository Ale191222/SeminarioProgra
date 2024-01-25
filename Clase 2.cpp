#include <iostream>

class persona{
private:
    int edad;
    std::string nombre;
public:
    persona(){edad=0; nombre=" ";}
    persona(int e, std::string n){edad=e; nombre=n;}
    friend std::ostream& operator <<(std::ostream &o, persona &p){
    o<<"\n Edad: "<<p.edad;
    o<<"\n Nombre: "<<p.nombre;
    }
    friend std::istream& operator >>(std::istream &i, persona &p){
    std::cout<<"\n Ingresa nombre: ";
    i>>p.nombre;
    std::cout<<"\n Ingresa edad: ";
    i>>p.edad;
    }
    bool operator == (persona & p){
    return (nombre==p.nombre&&edad == p.edad);
    }
};

int main ()
{
    persona x;
    std::cin>>x;
    std::cout<<"El valor de x: "<<x;
    return 0;
}

//ostream e istream son metodos de la librería iostream, ostream es para salida e istream es para entrada
