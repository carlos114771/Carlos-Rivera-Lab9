#include <iostream>
#include <string>
#include "Auto.h"
#include "Usuario.h"
#include "Administradores.h"
#include "Clientes.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <typeinfo>
using namespace std;

void escribirCliente();
int menu();
int menuUsuario();
int menuCliente();
int menuAdministrador();
int menuAutos();
void lista(vector<Auto*>);
string randomS();
int main(){
	vector<Usuario*> listausuario;
	vector<Auto*> listaautos; 
	ofstream archivo1,archivo2;
	archivo1.open("Administradores.txt",ios::app);
	archivo2.open("Clientes.txt",ios::app);
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
							archivo1<<"Cargo: "<<cargo<<" Numero de Seguro: "<<numero_seguro<<" Nombre de Usuario: "<<nombre<<" Contraseña: "<<contrasena<<endl;
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
							escribirCliente();
							archivo2<<"Nombre de Usuario: "<<nombre<<" Contraseña: "<<contrasena<<" Membresia "<<membresia<<endl;

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
				string contrasena;
				string nombre;
				cout<<"Ingrese su nombre de usuario: "<<endl;
				cin>>nombre;
				cout<<"Ingrese su contraseña: "<<endl;
				cin>>contrasena;
				for (int i = 0; i < listausuario.size(); ++i) {
	    			if (listausuario.at(i) -> getNombre() == nombre && listausuario.at(i) -> getContrasena() == contrasena) {
						if(dynamic_cast<Administradores*>(listausuario.at(i))) {
							bool salirAdmin = false;
							while(!salirAdmin){
								switch(menuAdministrador()){
									case 1:{
										string placa;
										string marca;
										string modelo;
										string anio;
										double precio;

										cout<<"Placa"<<endl;
										randomS();
										cout<<"Ingrese la marca del auto "<<endl;
										cin>>marca;
										cout<<"Ingrese el modelo del auto "<<endl;
										cin>>modelo;
										cout<<"Ingrese el año del auto "<<endl;
										cin>>anio;
										cout<<"Ingrese el precio del auto "<<endl;
										cin>>precio;
										listaautos.push_back(new Auto(randomS(),marca,modelo,anio,precio));

										break;
									}
									case 2:{
										break;
									}
									case 3:{
									    int opcion;
            							cout<<"Ingrese la posicion a eliminar"<<endl;
            							cin>>opcion;
            							listaautos.erase(listaautos.begin()+opcion);
										break;
									}
									case 4:{
										lista(listaautos);
										break;
									}
									case 5:{
										salirAdmin=true;
										break;
									}
								}
							}
						}
						if(dynamic_cast<Clientes*>(listausuario.at(i))){
							bool salirCliente = false;
							while(!salirCliente){
								switch(menuCliente()){
									case 1:{
										lista(listaautos);
										int posicion;
										cout<<"Seleccione el carro a rentar";
										cin>>posicion;
										listaautos.erase(listaautos.begin()+posicion);
										break;
									}
									case 2:{

										break;
									}
									case 3:{
										break;
									}
									case 4:{
										salirCliente=true;
										break;
									}
								}
							}
						}	
	    			}
	    		}
				//if(nombre.compare())
				
				break;
			}
			case 3:{
				break;
			}
			case 4:{
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
			<< "2.- Log In" << endl
			<< "3.- Guardar " << endl
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


int menuCliente(){
	int opcion;
	bool valido = false;
	do {
		cout<< "-----MENU DE CLIENTES-----" << endl
			<< "1.- Rentar Autos " << endl
			<< "2.- Guardar Factura " << endl
			<< "3.- Listar Autos "<<endl
			<< "4.- Eliminar " << endl
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

int menuAdministrador(){
	int opcion;
	bool valido = false;
	do {
		cout<< "-----MENU DE ADMINISTRADORES-----" << endl
			<< "1.- Agregar Auto " << endl
			<< "2.- Modificar Auto " << endl
			<< "3.- Eliminar Auto " << endl
			<< "4.- Listar "<<endl
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

string randomS() {
	int random;
	stringstream random1;
	string random2;
	for (int i = 0; i < 3; ++i){
		random = rand() % 25 + 0;
		if (random == 10){
			random1 << "A";
		} else if (random == 1){
			random1 << "B";
		} else if (random == 2){
			random1 << "C";
		} else if (random == 3){
			random1 << "D";
		} else if (random == 4){
			random1 << "E";
		} else if (random == 5){
			random1 << "F";
		} else if(random == 6){
			random1<< "G";
		}else if(random== 7){
			random1<< "H";
		}else if(random==8){
			random1<< "I";
		}else if(random==9){
			random1<< "J";
		}else if(random==10){
			random1<< "K";
		}else if(random==11){
			random1<< "L";
		}else if(random==12){
			random1<< "M";
		}else if(random==13){
			random1<< "N";
		}else if(random==14){
			random1<< "O";
		}else if(random==15){
			random1<< "P";
		}else if(random==16){
			random1<< "Q";
		}else if(random==17){
			random1<< "R";
		}else if(random==18){
			random1<< "S";
		}else if(random==19){
			random1<< "T";
		}else if(random==20){
			random1<< "U";
		}else if(random==21){
			random1<< "V";
		}else if(random==22){
			random1<< "W";
		}else if(random==23){
			random1<< "X";
		}else if(random==24){
			random1<< "Y";
		}else if(random==25){
			random1<< "Z";
		}
		random1<<"-";
		for (int i = 0; i < 4; ++i)
		{
			random = rand() % 9 + 1;
			random1<<random;
		}
		
	}
	random2 = random1.str();
	return random2;
}

void lista(vector<Auto*> listaauto){
    cout<<"Obras en el Museo"<<endl;
    for(int i=0;i<listaauto.size();i++){
        cout<<"Placa: "<<(i)<<endl;
        cout<<"Marca: "<<listaauto.at(i)->getMarca()<<endl;
        cout<<"Modelo: "<<listaauto.at(i)->getModelo()<<endl;
        cout<<"Año: "<<listaauto.at(i)->getAnio()<<endl;
        cout<<"Precio de Alquiler: "<<listaauto.at(i)->getPrecio_alquiler()<<endl;
    }

}

void escribirCliente(){
	ofstream archivo;
	//string nombreArchivo,frase;
	//cout<<"Digite el nombre del archivo ";
	//getline(cin, nombreArchivo);
	archivo.open("Cliente.txt", ios::out);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo ";
		exit(1);
	}
	//cout<<"\n Digite la frase ";
	//getline(cin,frase);
	//archivo<<frase;
	archivo.close();
}

vector<Clientes*> cargarCliente(vector<Clientes*> listausuario){
		
		
	ifstream archivo("Clientes.txt"); //
   		
   	while(!archivo.eof()){

   		string contrasena;
   		string nombre;
   		string membresia;
 
   		archivo >> nombre;
   		archivo >> contrasena;
 		archivo >> membresia;
 		Clientes* clientes = new Clientes(membresia,nombre,contrasena);
		listausuario.push_back(clientes);
	}	

	return listausuario;		
}


vector<Administradores*> cargarAdministrador(vector<Administradores*> listausuario){
		
		
	ifstream archivo("Clientes.txt"); //
   		
   	while(!archivo.eof()){

   		string contrasena;
   		string nombre;
   		string membresia;
   		string cargo;
   		float numero_seguro;
 
   		archivo >> nombre;
   		archivo >> contrasena;
 		archivo >> membresia;
 		Administradores* administradores = new Administradores(cargo,numero_seguro,nombre,contrasena);
		listausuario.push_back(administradores);
	}	

	return listausuario;		
}

vector<Auto*> cargarAuto(vector<Auto*> listaauto){

	ifstream archivo("Clientes.txt"); //
   		
   	while(!archivo.eof()){

   		string placa;
   		string modelo;
   		string marca;
   		string anio;
   		double precio;
 
   		archivo >> placa;
   		archivo >> modelo;
 		archivo >> marca;
 		archivo >> anio;
 		archivo >> precio;
 		Auto* autos = new Auto(placa,marca,modelo,anio,precio);
		listaauto.push_back(autos);
	}	

	return listaauto;	
}