#include <iostream>
#include <cstring>

using namespace std;


struct paquetes{
    short int peso;
    char region[8];
};
struct encomienda{
    char dni[9];
    char nombre[20];
    char apellido[20];
    paquetes paquete;
};

encomienda ingresarEncomienda(encomienda arreglo[]);
void ingresoPeso(encomienda paquete);
void ingresarRegion(encomienda paquete);
void ingreseDNI(encomienda paquete);
void mostrarEncomiendas(encomienda arreglo[]);

char seleccionarOpcion();



int main(){
    encomienda arreglo[100];
    int contador = 0;
    char opcion(2);
    opcion = seleccionarOpcion();

    arreglo[contador]=ingresarEncomienda(arreglo);
    mostrarEncomiendas(arreglo);
    contador++;
    opcion = seleccionarOpcion();

};

char seleccionarOpcion(){
    char opcion(2);

    cout<<"ELIJA UNA OPCION: \n I) INGRESAR UNA ENCOMIENDA\n N) Mostrar el listado de encomiendas de la región norte\n";
    cout<<"C: Mostrar el listado de encomiendas de la región central \n S: Mostrar el listado de encomiendas de la región sur\n";
    cout<<"X: Salir\n";
    cin>>opcion;

    return opcion;
};

encomienda ingresarEncomienda(encomienda arreglo[]){
    encomienda paquete;

    ingresarRegion(paquete);
    ingresoPeso(paquete);
    ingreseDNI(paquete);

    cout<<"Ingrese nombre: ";
    cin>>paquete.nombre;
    while(strlen(paquete.nombre) < 1){
        cout<<"Incorrecto. Reingrese el nombre: \n";
        cin>>paquete.nombre;
    };

    cout<<"Ingrese el Apellido: \n";
    cin>>paquete.apellido;
    while(strlen(paquete.apellido)<0){
        cout<<"Incorrecto. Reingrese el Apellido: ";
        cin>>paquete.apellido;
    };

    return paquete;

};

//FUNCIONES SECUNDARIAS PARA EL CORRECTO INGRESO DE DATOS.

void ingresarRegion(encomienda paquete){
    cout<<"Ingresar Region: (N: Norte, C: Central  ,S: Sur)\n";
    cin>>paquete.paquete.region;
    cin.ignore();
    cout<<paquete.paquete.region;

    /*while(paquete.paquete.region == 'N'){
        cout<<"Incorrecto. Reingresar Region: (N: Norte,C: Central ,S: Sur)\n";
        cin>>paquete.paquete.region;
    };*/
};

void ingresoPeso(encomienda paquete){
    cout<<"Ingresar Peso (hasta 20Kg): \n";
    int peso;
    cin>>peso;

    while(peso < 1 && peso > 20){
        cout<<"Peso Incorrecto \n Reingrese el peso.";
        cin>>peso;
    };

    paquete.paquete.peso = peso;
};

void ingreseDNI(encomienda paquete){

    cout<<"Ingrese el DNI: ";
    cin>>paquete.dni;

    while(strlen(paquete.dni) != 8){
        cout<<"Reingrese el DNI correctamente: \n";
        cin>>paquete.dni;
    };
};


void mostrarEncomiendas(encomienda arreglo[]){

    cout<<"Region \n"<<arreglo[0].paquete.region;
    cout<<"Peso del parquete: \n"<<arreglo[0].paquete.peso;
    cout<<"DNI: \n"<<arreglo[0].dni;
    cout<<"Apellido: \n"<<arreglo[0].nombre;
    cout<<"Nombre: \n"<<arreglo[0].apellido;

}
