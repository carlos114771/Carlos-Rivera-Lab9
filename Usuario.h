#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef USUARIO_H
#define USUARIO_H
class Usuario{
	protected:
		string nombre;
		string contrasena;
	public:
		virtual ~Usuario();
		Usuario(string,string);
		Usuario();
		string getNombre();
		void setNombre(string);

		string getContrasena();
		void setContrasena(string);

};
#endif