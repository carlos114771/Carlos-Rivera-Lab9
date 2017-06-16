#include "Clientes.h"

Clientes::Clientes(string membresia, string nombre, string contrasena):Usuario(nombre,contrasena){
	this->membresia=membresia;
}
Clientes::Clientes(){

}void Clientes::setMembresia(string membresia){
   this-> membresia=membresia;
}
string Clientes::getMembresia(){
   return membresia;
}


string Clientes::getTipoMembresia(string tipo){
	string validar = "Normal";
	if (validar.compare(tipo) == 0){
		return "Normal";
	} else if(validar.compare(tipo)==1){
		return "Gold";
	}else{
		return "Premium";
	}
}
Clientes::~Clientes(){
	
}