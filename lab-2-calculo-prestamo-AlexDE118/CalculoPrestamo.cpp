//
// Created by Maikol Guzman  on 2019-08-08.
//

#include <iostream>
#include "CalculoPrestamo.h"

//usar .find(), substrg y std::stof() / casting
// casting string->int stoi()

float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT)
{
	float porcentaje = 0;
	int porcentajeEnString = porcentajeTXT.find("%"); // PorcentajeEnString se refiere al simbolo % ||busca y devuelve la posicion de "%" en el string.

	if (porcentajeEnString > 0)
		porcentaje=std::stof(porcentajeTXT.substr(0, porcentajeEnString)) // substr busca los valores desde pos 0 hasta la pocision antes de "%", ejemplo
																		  // "30%", .find busca lo que esta antes de "%". El substr dentro del cast devuele las posiciones 0 (valor 3) y 1 (valor 0) para devolver 30
		if (porcentaje > 0) {
			porcentaje = porcentaje / 100;
		}
	return porcentaje
}

int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT)
{
	int meses = 0;
	int anno = 0;

	int buscaMesEnString = tiempoTXT.find("M");
	int buscaAnnoEnString = tiempoTXT.find("A");
	
	if (buscaAnnoEnString > 0) {
		anno = stoi(tiempoTXT.substr(0, buscaAnnoEnString));
		if (anno > 0) {
			meses = anno * 12;
		}
	}
	else if (buscaMesEnString > 0) {
		meses = stoi(tiempoTXT.substr(0, buscaMesEnString))
	}

	return meses;
}

float CalculoPrestamo::calcularInteresMensual(float balance, float TasaAnual)
{
	tasaMensual = TasaAnual / 12;
	interes = balance * tasaMensual;
	return interes;
}



CalculoPrestamo::CalculoPrestamo() {
	monto = 0;
}

CalculoPrestamo::CalculoPrestamo(int64_t monto) {
	monto = monto;
}

string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT)
{
	//mostrar tasa[X](porcentajeTXT) | Mes[X](to_string(i) ) | Balance inicial [X](to_string(monto) ) | interes[X] (to_string(y) ) | Nuevo balance [X] (to_string(z) )
	
	std::string reporte = "";
	int meses = calcularTiempoEnMeses(tiempoTXT);
	float porcentaje = obtenerPorcentaje(porcentajeTXT);
	float balance = monto;
	float nuevoBalance = monto;

	for (int mes = 1; mes <= meses; mes++)
	{
		float interes = calcularInteresMensual(nuevoBalance, porcentaje);
		balance = nuevoBalance;
		nuevoBalance = balance + interes

			reporte = reporte + "Tasa[" + porcentajeTXT + "], Mes[" + std::to_string(mes) + "], Balance Inicial[" + std::to_string(balance) + "], Interes[" + to_string(interes) + "], Nuevo Blance[" + std::to_string(nuevoBalance) + "]. \n";
	}
	return reporte;
}

float CalculoPrestamo::getMonto()
{
	return monto;
}

void CalculoPrestamo::setMonto(float monto)
{
	monto = monto;
}

