#include <iostream>
#include <cstring>
#define tope 21

using namespace std;

struct empleado{
    //unsigned short int legajo;
    char dni[9];
    char apellido[tope];
    char nombre[tope];
};

void ingresarEmpleados(empleado arreglo[], int n);
empleado ingresarEmpleado();
void mostrarEmpleados(empleado arreglo[], int n);
void mostrarEmpleado(empleado laburante);
void modificarEmpleado(empleado arreglo[], int n);
int seleccionarOpcion();

int main(){

    const int cant_emp = 20;
    empleado arreglo[cant_emp];
    int opcion;
	opcion=seleccionarOpcion();
    int contador = 0;

    while(opcion >= 1 && opcion <= 3){
		switch(opcion)
		{
		case 1:	cout<<"INGRESAR EMPLEADO/AS"<<endl;
				ingresarEmpleados(arreglo, contador);
				contador++;
				break;
		case 2: cout<<"MODIFICAR UN EMPLEADO/A"<<endl;
				modificarEmpleado(arreglo, contador);
				break;
		case 3:	cout<<"MOSTRAR EMPLEADOS"<<endl;
				mostrarEmpleados(arreglo, contador);
				break;
		default: cout<<"SALIENDO.";
		}

		opcion=seleccionarOpcion();
    }



    return 0;
}

int seleccionarOpcion()
{
int opcion;
cout<<"\nMENU:\n1-REGISTRAR EMPLEADOS\n2-MODIFICAR EMPLEADOS  \n3-MOSTRAR LOS EMPLEADOS REGISTRADOS \n4- SALIR \n";
cin>>opcion;
cin.ignore();
while(opcion<1||opcion>4)
{
            cout<<"OPCION INCORRECTA. REINGRESAR: ";
            cin>>opcion;
            cin.ignore();
}
return opcion;
}

void ingresarEmpleados(empleado arreglo[], int n)
{
    arreglo[n]=ingresarEmpleado();

}

empleado ingresarEmpleado()
{

	empleado laburante;

    cout<<"DNI: "<<endl;
    cin>>laburante.dni;
    cin.ignore();

    while(strlen(laburante.dni) <= 7 || strlen(laburante.dni) > 8){
        cout<<"Reingrese DNI: "<<endl;
        cin>>laburante.dni;
        cin.ignore();
    }

	cout <<"Apellido: ";
 	cin.getline(laburante.apellido,20);

 	while(strlen(laburante.apellido) < 1){
        cout <<"Reingrese Apellido: ";
        cin.getline(laburante.apellido,20);
	}

	cout <<"Nombre: ";
	cin.getline(laburante.nombre,20);

	while(strlen(laburante.nombre) < 1){
        cout <<"Reingrese Nombre: ";
        cin.getline(laburante.nombre,20);
	}
	return laburante;
}

void mostrarEmpleados(empleado arreglo[], int n)
{
	for(int i=0; i<n; i++)
	{
	    cout<<endl<<"Legajo: "<< i+1<<endl;
		mostrarEmpleado(arreglo[i]);
	}
}

void mostrarEmpleado(empleado laburante)
{
	//cout<<"Legajo: "<<laburante.legajo<<"\n";
	cout<<"DNI: "<<laburante.dni<<"\n";
	cout<<"Apellido: "<<laburante.apellido<<"\n";
	cout<<"Nombre: "<<laburante.nombre<<"\n";
}

void modificarEmpleado(empleado arreglo[], int n){
    int legajo_buscado;
    cout<<"Ingrese legajo del empleado/a: "<<endl;
    cin>>legajo_buscado;


    mostrarEmpleado(arreglo[legajo_buscado - 1]);

            cout<<"Modificar Apellido: "<<endl;
            cin>>arreglo[legajo_buscado - 1].apellido;
            cout<<"Modificar Nombre: "<<endl;
            cin>>arreglo[legajo_buscado - 1].nombre;

}
