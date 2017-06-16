main:    main.cpp Auto.o Usuario.o Administradores.o Clientes.o 
	g++ main.cpp Auto.o Usuario.o Administradores.o Clientes.o -o main
main.o:	main.cpp Auto.h Usuario.h Administradores.h Clientes.h 
	g++ -c main.cpp
Auto:	Auto.cpp Auto.h
	g++ -c Auto.cppUsuario:	Usuario.cpp Usuario.h
	g++ -c Usuario.cppAdministradores:	Administradores.cpp Administradores.h
	g++ -c Administradores.cppClientes:	Clientes.cpp Clientes.h
	g++ -c Clientes.cpp
clean:
	rm  *.o main 