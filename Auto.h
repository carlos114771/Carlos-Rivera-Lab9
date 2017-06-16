#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef AUTO_H
#define AUTO_H
class Auto{
	protected:
		string placa;
		string marca;
		string modelo;
		string anio;
		double precio_alquiler;
	public:
		Auto(string,string,string,string,double);
		Auto();
		string getPlaca();
		void setPlaca(string);

		string getMarca();
		void setMarca(string);

		string getModelo();
		void setModelo(string);

		string getAnio();
		void setAnio(string);

		double getPrecio_alquiler();
		void setPrecio_alquiler(double);
		bool setEstado();

};
#endif