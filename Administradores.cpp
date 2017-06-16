#include "Administradores.h"

Administradores::Administradores(string cargo,float numero_seguro, string nombre, string contrasena):Usuario(nombre, contrasena){
	this->cargo=cargo;
	this->numero_seguro=numero_seguro;
}
Administradores::Administradores(){

}void Administradores::setCargo(string cargo){
   this-> cargo=cargo;
}
string Administradores::getCargo(){
   return cargo;
}
void Administradores::setNumero_seguro(float numero_seguro){
   this-> numero_seguro=numero_seguro;
}
float Administradores::getNumero_seguro(){
   return numero_seguro;
}

Administradores::~Administradores(){
	
}