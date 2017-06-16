#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef CLIENTES_H
#define CLIENTES_H
class Clientes: public Usuario{
	private:
		string membresia;
	public:
		Clientes(string,string,string);
		Clientes();
		string getMembresia();
		void setMembresia(string);

};
#endif