#include <iostream>
#include <string>

class Materia{
private:
    int Clave;
    std::string Nombre, ProfesorTit, LibroTexto;

public:
    Materia(int clave, const std::string&nombre, const std::string& profesortit, const std::string& librotexto)
        : Clave(clave), Nombre(nombre), ProfesorTit(profesortit), LibroTexto(librotexto){}
    void Imprime(){
        std::cout << "\nClave de la materia: " << Clave << "\nNombre de la Materia: " << Nombre << "\nProfesor Titular: " << ProfesorTit << "\nLibro de Texto: " << LibroTexto << std::endl;
    }
    void CambiaClave(int nuevaclave) {
        Clave = nuevaclave;
    }
    void CambiaProf(std::string& nuevoprof) {
        ProfesorTit = nuevoprof;
    }
    void CambiaLibro(std::string& nuevolibro) {
        LibroTexto = nuevolibro;
    }
};

int main() {
    Materia Programacion(1, "Programacion", "Mario Aguilar", "El lenguaje de programacion C++");
    Materia BasesDeDatos(2, "Bases de Datos", "Jaime Covarrubias", "Introduccion a los sistemas de bases de datos");
    int opcion;
    std::cout << "\nLas claves de las Materias actualmente registradas son: \n1: Programacion \n2: Bases de datos";
    do {
        std::cout << "\n\nMenu:\n1. Cambiar la clave de Programacion\n2. Cambiar el nombre del profesor de Bases de datos\n3. Imprimir datos\n0. Salir\n";
        std::cout << "Ingrese la opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                {int clavemateria;
                int nuevaclave;
                std::cout << "\nIngrese la clave de la materia: ";
                std::cin >> clavemateria;
                std::cout << "Ingrese la nueva clave: ";
                std::cin.ignore();
                std::cin >> nuevaclave;
                if (clavemateria == 1)
                    Programacion.CambiaClave(nuevaclave);
                else std::cout << "Solo es posible cambiar la clave de la materia PROGRAMACION";}
                break;
            case 2:
                {int claveprof;
                std::string nuevoprof;
                std::cout << "\nIngrese la clave de la materia: ";
                std::cin >> claveprof;
                std::cout << "\nIngrese el nuevo nombre del profesor: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoprof);
                if (claveprof == 2)
                    BasesDeDatos.CambiaProf(nuevoprof);
                else
                std::cout << "Solo es posible cambiar el profesor de la materia BASES DE DATOS";}
                break;
            case 3:
                {int claveImprimir;
                std::cout << "\nIngrese la clave de la materia: ";
                std::cin >> claveImprimir;
                if (claveImprimir == 1)
                    Programacion.Imprime();
                else if (claveImprimir == 2)
                    BasesDeDatos.Imprime();}
                break;
            case 0:
                {std::cout << "Saliendo del programa...\n";}
                break;
            default:
                std::cout << "Opción no valida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
    return 0;
}
