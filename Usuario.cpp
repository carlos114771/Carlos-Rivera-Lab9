#include "Usuario.h"

Usuario::Usuario(string nombre,string contrasena){
	this->nombre=nombre;
	this->contrasena=contrasena;
}
Usuario::Usuario(){

}void Usuario::setNombre(string nombre){
   this-> nombre=nombre;
}
string Usuario::getNombre(){
   return nombre;
}
void Usuario::setContrasena(string contrasena){
   this-> contrasena=contrasena;
}
string Usuario::getContrasena(){
   return contrasena;
}
