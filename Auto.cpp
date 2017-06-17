#include "Auto.h"

Auto::Auto(string placa,string marca,string modelo,string anio,double precio_alquiler){
	this->placa=placa;
	this->marca=marca;
	this->modelo=modelo;
	this->anio=anio;
	this->precio_alquiler=precio_alquiler;
}
Auto::Auto(){

}void Auto::setPlaca(string placa){
   this-> placa=placa;
}
string Auto::getPlaca(){
   return placa;
}
void Auto::setMarca(string marca){
   this-> marca=marca;
}
string Auto::getMarca(){
   return marca;
}
void Auto::setModelo(string modelo){
   this-> modelo=modelo;
}
string Auto::getModelo(){
   return modelo;
}
void Auto::setAnio(string anio){
   this-> anio=anio;
}
string Auto::getAnio(){
   return anio;
}
void Auto::setPrecio_alquiler(double precio_alquiler){
   this-> precio_alquiler=precio_alquiler;
}
double Auto::getPrecio_alquiler(){
   return precio_alquiler;
}

bool Auto::estaalquilado(){
   alquilado =false;
}

