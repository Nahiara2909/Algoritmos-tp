#include <iostream>
#include <cstring>

using namespace std;

struct datos{
    char nombre[21];
    char apellido[21];
    char dni[9];
};

struct encomienda{
    int short peso;
    char region[2];
    datos destinatario;
    datos remitente;
};

void ingresarEncomiendas(encomienda arreglo[], int n);
encomienda ingresarEncomienda();
void mostrarEncomiendas(encomienda arreglo[],char region[], int n);
void mostrarEncomienda(encomienda paquete);

void ingresarRegion(encomienda &paquete);
void ingresoPeso(encomienda &paquete);
void ingresarDNI(char dni[]);
void ingresarNombreOApellido(char nombre[]);
void ordenarPorPeso(int indRegion[], encomienda arreglo[], int n);

char seleccionarOpcion();

int main(){

    encomienda arreglo[100];
    int contador = 0;
    char opcion(2);
    opcion = seleccionarOpcion();

    while(opcion != 'X'){
        switch(opcion)
		{
		case 'I':
                {
                cout<<"INGRESAR ENCOMIENDA"<<endl;
				arreglo[contador] = ingresarEncomienda();
				cout<<"\n";
				contador++;
				break;
				};
		case 'N':
                {
                cout<<"ENCOMIENDAS DE LA REGION NORTE"<<endl;
                char regionN[2] = "N";
				mostrarEncomiendas(arreglo, regionN, contador);
				cout<<"\n";
				break;
				};
		case 'C':
                {
                cout<<"ENCOMIENDAS DE LA REGION CENTRAL"<<endl;
                char regionC[2] = "C";
				mostrarEncomiendas(arreglo, regionC, contador);
				cout<<"\n";
				break;
                };
        case 'S':
                {
                cout<<"ENCOMIENDAS DE LA REGION SUR"<<endl;
                char regionS[2] = "S";
				mostrarEncomiendas(arreglo, regionS, contador);
				cout<<"\n";
				break;
                };
		default: cout<<"SALIENDO.";
                 cout<<"\n";
		};

		opcion=seleccionarOpcion();
    };

    return 0;
};

//MENU:

char seleccionarOpcion(){
    char opcion(2);

    cout<<"ELIJA UNA OPCION: \n I) INGRESAR UNA ENCOMIENDA\n N) MOSTRAR EL LISTADO DE ENCOMIENDAS DE LA REGION NORTE\n";
    cout<<"C) MOSTRAR EL LISTADO DE ENCOMIENDAS DE LA REGION CENTRAL \n S) MOSTRAR EL LISTADO DE ENCOMIENDAS DE LA REGION SUR\n";
    cout<<"X) SALIR\n";
    cin>>opcion;

    return opcion;
};

//FUNCIONES PRINCIPALES PARA INGRESO Y SALIDA DE INFORMACION

void ingresarEncomiendas(encomienda arreglo[], int n){
    arreglo[n] = ingresarEncomienda();
};

encomienda ingresarEncomienda(){
    encomienda paquete;
    ingresoPeso(paquete);
    ingresarRegion(paquete);

    cout<<"INGRESAR LOS DATOS DEL REMITENTE"<<endl;
    ingresarDNI(paquete.remitente.dni);


    cout<<"Nombre: "<<endl;
    ingresarNombreOApellido(paquete.remitente.nombre);


    cout<<"Apellido: "<<endl;
    ingresarNombreOApellido(paquete.remitente.apellido);


    cout<<"INGRESAR LOS DATOS DEL DESTINATARIO"<<endl;
    ingresarDNI(paquete.destinatario.dni);

    cout<<"Nombre: "<<endl;
    ingresarNombreOApellido(paquete.destinatario.nombre);


    cout<<"Apellido:"<<endl;
    ingresarNombreOApellido(paquete.destinatario.apellido);


    return paquete;
};

void mostrarEncomiendas(encomienda arreglo[],char region[], int n){
    int contador=0;
    int indRegion[n] = {-1};
    for(int i=0; i<n; i++){
        if(strcmp(arreglo[i].region, region)== 0){
            indRegion[contador] = i;
            contador++;
        };
    };
    ordenarPorPeso(indRegion, arreglo, n);


    for(int k=0; k<contador; k++){
        mostrarEncomienda(arreglo[indRegion[k]]);

    }



};

void ordenarPorPeso(int indRegion[], encomienda arreglo[],int n){
    int i=0;
    while(i<n){
        int mover=0;
        for(int j=i; j<n; j++){

            if(arreglo[indRegion[i]].peso > arreglo[indRegion[j]].peso && arreglo[indRegion[i]].peso> -1 && arreglo[indRegion[j]].peso>-1){
                mover=indRegion[i];
                indRegion[i] = indRegion[j];
                indRegion[j] = mover;
            };

        };
        i++;
    };

};

void mostrarEncomienda(encomienda paquete){
    cout<<endl<<"ENCOMIENDA: \n PESO:"<<paquete.peso<<"KG"<<endl;
    cout<<"REGION: "<<paquete.region<<endl;

    cout<<"DATOS DEL REMITENTE: \n NOMBRE: "<<paquete.remitente.nombre<<endl;
    cout<<"APELLIDO: "<<paquete.remitente.apellido<<endl;
    cout<<"DNI: "<<paquete.remitente.dni<<endl;

    cout<<"DATOS DEL DESTINATARIO: \n NOMBRE: "<<paquete.destinatario.nombre<<endl;
    cout<<"APELLIDO: "<<paquete.destinatario.apellido<<endl;
    cout<<"DNI: "<<paquete.destinatario.dni<<endl;


};

//FUNCIONES PARA EN CORRECTO INGRESO DE CADA DATO PEDIDO:

void ingresoPeso(encomienda &paquete){
    cout<<"Ingresar Peso (hasta 20Kg): \n";
    cin>>paquete.peso;
    cin.ignore();

    while(paquete.peso < 1 || paquete.peso > 20){
        cout<<"Incorrecto. Reingrese el peso (hasta 20Kg): ";
        cin>>paquete.peso;
        cin.ignore();
    }
};

void ingresarRegion(encomienda &paquete){
    cout<<"Ingresar Region: (N: Norte, C: Central  ,S: Sur)\n";
    cin>>paquete.region;
    cin.ignore();

    while(paquete.region[0] != 'N' && paquete.region[0] != 'C' && paquete.region[0] != 'S'){
        cout<<"Incorrecto. Reingrese la region (N: Norte, C: Central  ,S: Sur): \n";
        cin>>paquete.region;
        cin.ignore();
    }
};

void ingresarDNI(char dni[]) {

    cout<<"DNI: " << endl;
    cin >>dni;
    cin.ignore();

    while (strlen(dni) != 8) {
        cout << "Reingrese el DNI correctamente (8 caracteres): \n";
        cin >>dni;
        cin.ignore();
    }
};

void ingresarNombreOApellido(char nombre[]){
    cin.getline(nombre,21);

    while(strlen(nombre) < 1){
        cout<<"Incorecto. El texto ingresado no debe estar vacio. Reingrese el texto pedido: \n";
        cin.getline(nombre, 21);
    };
}
