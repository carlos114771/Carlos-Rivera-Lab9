#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"
using namespace std;

#ifndef ADMINISTRADORES_H
#define ADMINISTRADORES_H
class Administradores: public Usuario{
	private:
		string cargo;
		float numero_seguro;
	public:
		~Administradores();
		Administradores(string,float,string,string);
		Administradores();
		string getCargo();
		void setCargo(string);

		float getNumero_seguro();
		void setNumero_seguro(float);

};
#endif