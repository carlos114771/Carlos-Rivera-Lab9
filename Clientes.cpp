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
