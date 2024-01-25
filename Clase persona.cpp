#include <iostream>
#include <string>

class Empleado {
private:
    int ClaveEmpleado;
    std::string Nombre, Domicilio, ReportaA;
    float Sueldo;

public:
    Empleado(int clave, const std::string& nombre, const std::string& domicilio, float sueldo, const std::string& reportaA)
        : ClaveEmpleado(clave), Nombre(nombre), Domicilio(domicilio), Sueldo(sueldo), ReportaA(reportaA) {}
    void Imprime(){
        std::cout << "\nClave: " << ClaveEmpleado << "\nNombre: " << Nombre << "\nDomicilio: " << Domicilio
                  << "\nSueldo: " << Sueldo << "\nReporta a: " << ReportaA << std::endl;
    }
    void CambiaDomic(std::string& nuevoDomicilio) {
        Domicilio = nuevoDomicilio;
    }
    void CambiaReportaA(std::string& nuevaPersona) {
        ReportaA = nuevaPersona;
    }
    void ActualSueldo(float porcentajeIncremento) {
        Sueldo += Sueldo * (porcentajeIncremento / 100);
    }
};

int main() {
    Empleado JefePlanta(1, "Jefe Planta", "Calle 36, Colon Industrial", 5000.0, "Gerente General");
    Empleado JefePersonal(2, "Jefe Personal", "Sta. Clemencia 1968, Talpita", 6000.0, "Gerente General");

    int opcion;
    std::cout << "\nLas claves de los Empleados actualmente registrados son: 1, 2";
    do {
        std::cout << "\n\nMenu:\n1. Cambiar domicilio\n2. Actualizar sueldo\n3. Imprimir datos\n4. Cambiar persona a quien reporta\n0. Salir\n";
        std::cout << "Ingrese la opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                {int claveDomicilio;
                std::string nuevoDomicilio;
                std::cout << "\nIngrese la clave del empleado: ";
                std::cin >> claveDomicilio;
                std::cout << "Ingrese el nuevo domicilio: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoDomicilio);
                if (claveDomicilio == 1)
                    JefePlanta.CambiaDomic(nuevoDomicilio);
                else if (claveDomicilio == 2)
                    JefePersonal.CambiaDomic(nuevoDomicilio);}
                break;
            case 2:
                int claveSueldo;
                float porcentajeIncremento;
                std::cout << "\nIngrese la clave del empleado: ";
                std::cin >> claveSueldo;
                std::cout << "\nIngrese el porcentaje de incremento: ";
                std::cin >> porcentajeIncremento;
                if (claveSueldo == 1)
                    JefePlanta.ActualSueldo(porcentajeIncremento);
                else if (claveSueldo == 2)
                    JefePersonal.ActualSueldo(porcentajeIncremento);
                break;
            case 3:
                int claveImprimir;
                std::cout << "\nIngrese la clave del empleado: ";
                std::cin >> claveImprimir;
                if (claveImprimir == 1)
                    JefePlanta.Imprime();
                else if (claveImprimir == 2)
                    JefePersonal.Imprime();
                break;
            case 4:
                {int claveReportaA;
                std::string nuevaPersona;
                std::cout << "\nIngrese la clave del empleado: ";
                std::cin >> claveReportaA;
                std::cout << "\nIngrese la nueva persona a quien reporta: ";
                std::cin.ignore();
                std::getline(std::cin, nuevaPersona);
                if (claveReportaA == 1)
                    JefePlanta.CambiaReportaA(nuevaPersona);
                else if (claveReportaA == 2)
                    JefePersonal.CambiaReportaA(nuevaPersona);}
                break;
            case 0:
                {std::cout << "Saliendo del programa...\n";}
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
    return 0;
}
