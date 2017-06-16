#include <iostream>
#include <string>
#include "Auto.h"
#include "Usuario.h"
#include "Administradores.h"
#include "Clientes.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <typeinfo>
using namespace std;

int menu();
int menuUsuario();
int menuAutos();
int main(){
	vector<Usuario*> listausuario;
	vector<Auto*> listaautos; 
	bool salirTodo =false;
	while(!salirTodo){
		switch(menu()){
			case 1:{
				bool salirUsuario=false;
				while(!salirUsuario){
					switch(menuUsuario()){
						case 1:{
							string cargo;
							float numero_seguro;
							string nombre;
							string contrasena;
							cout<<"Ingrese su cargo: "<<endl;
							cin>>cargo;
							cout<<"Ingrese su numero de seguro: "<<endl;
							cin>>numero_seguro;
							cout<<"Ingrese su nombre de usuario: "<<endl;
							cin>>nombre;
							cout<<"Ingrese su contraña: "<<endl;
							cin>>contrasena;
							listausuario.push_back(new Administradores(cargo,numero_seguro,nombre,contrasena));
							break;
						}
						case 2:{
							string nombre;
							string contrasena;
							string membresia;
							cout<<"Ingrese su nombre de usuario: "<<endl;
							cin>>nombre;
							cout<<"Ingrese su contraseña: "<<endl;
							cin>>contrasena;
							cout<<"Tipo de Membresia: ";
							cin>>membresia;
							listausuario.push_back(new Clientes(membresia,nombre,contrasena));
							break;
						}
						case 3:{
							salirUsuario=true;
							break;
						}
					}
				}
				break;
			}	
			case 2:{
				string nombre,contrasena;
				cout<<"Ingrese su nombre de usuario: "<<endl;
				cin>>nombre;
				cout<<"Ingrese su contraseña: "<<endl;
				cin>>contrasena;

				if(typeid(listausuario)==typeid(Administradores)){

				}
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				break;
			}
			case 5:{
				salirTodo=true;
				break;
			}
		}
	}
     
     
     return 0;
}

int menu(){
	int opcion;
	bool valido = false;
	do {
		cout<< "-----MENU-----" << endl
			<< "1.- Crear Usuario " << endl
			<< "2.- Crear Autos " << endl
			<< "3.- Listar  " << endl
			<< "4.- Guardar " << endl
			<< "5.- Salir" << endl;
		
		cout<< "Ingrese una opcion: ";
		cin>>opcion;
		if (opcion > 0 && opcion <= 5)
			valido = true;
		else {
			cout << "Opcion no valida, intente de nuevo..." << endl;
		}

	} while (!valido);
	return opcion;
}

int menuUsuario(){
	int opcion;
	bool valido = false;
	do {
		cout<< "-----MENU DE USUARIO-----" << endl
			<< "1.- Administrador " << endl
			<< "2.- Cliente " << endl
			<< "3.- Salir" << endl;
		
		cout<< "Ingrese una opcion: ";
		cin>>opcion;
		if (opcion > 0 && opcion <= 3)
			valido = true;
		else {
			cout << "Opcion no valida, intente de nuevo..." << endl;
		}

	} while (!valido);
	return opcion;
}

int menuAutos(){
	int opcion;
	bool valido = false;
	do {
		cout<< "-----MENU DE AUTOS-----" << endl
			<< "1.- Agregar " << endl
			<< "2.- Modificar " << endl
			<< "3.- Eliminar " << endl
			<< "4.- Salir" << endl;
		
		cout<< "Ingrese una opcion: ";
		cin>>opcion;
		if (opcion > 0 && opcion <= 4)
			valido = true;
		else {
			cout << "Opcion no valida, intente de nuevo..." << endl;
		}

	} while (!valido);
	return opcion;
}