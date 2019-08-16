#include <iostream>
#include "CalculoPrestamo.h"

int main() {

	CalculoPrestamo calculoPrestamo(1000)

	std::string reporte;

	reporte = calculoPrestamo.CalculoPrestamo("1A", "30%");
	
	cout << "calcular prestamo" << endl;
	cout << reporte << endl;
    return 0;
}