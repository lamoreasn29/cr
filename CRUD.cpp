//Registro de estudiantes
#include<iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif
using namespace std;
class menu
{
private:
    char codigo[30];
    char nombre[30];
    char apellidos[30];
    char direccion[30];
    char telefono[30];

public:
    void registrar();
    void retirar();
    void modificar_estudiante();
    void lista_estudiantes();
    void menuPrincipal();
    void detalle_estudiante();
    void mostarRegistro(char codigo [30]);
};

void pausa();
void error();
int main()
{
    system ("color 0f");
    menu inicio;
    inicio.menuPrincipal();
    return 0;
}
void menu::menuPrincipal()
{
    int opcion;
    do
    {
        cout<<" \t\t************ REGISTRO DE ESTUDIANTES ************\t\n\n";
        cout<<"\t\t\t1. REGISTRAR AL ESTUDIANTE \n\n";
        cout<<"\t\t\t2. MOSTRAR DETALLES DEL ESTUDIANTE\n\n";
        cout<<"\t\t\t3. LISTA DE ESTUDIANTES \n\n";
        cout<<"\t\t\t4. RETIRAR DE LA LISTA\n\n";
        cout<<"\t\t\t5. MODIFICAR DATOS\n\n";
        cout<<"\t\t\t6. SALIR\n\n";
        cout<<"\t\t\tOpci\242n: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {

        case 1:
            registrar();
            break;

        case 2:
            detalle_estudiante();
            break;

        case 3:
            lista_estudiantes();
            break;

        case 4:
            retirar();
            break;

        case 5:
            modificar_estudiante();
            break;

        case 6:
            break;
            
        default:
            cout<<"\nHa ingresado una opci\242n invalida\n\n";
            break;
        }
    }
    while(opcion!=6);
}

void menu::registrar()
{
    ofstream escritura;
    ifstream verificador;
    char auxCodigo[30];
    bool coincidencia=false;
    verificador.open("estudiantes.txt",ios::in);
    escritura.open("estudiantes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t---REGISTRAR AL ESTUDIANTE---\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el c\242digo del estudiante: ";
        cin.getline(auxCodigo,30);
        if(strcmp(auxCodigo,"")==0)
            do
            {
                cout<<"c\242digo del estudiante no v\240lido!, intentalo nuevamente: ";
                cin.getline(auxCodigo,30);
            }
            while(strcmp(auxCodigo,"")==0);
        do
        {
            verificador.seekg(0);
            verificador>>codigoCliente;
            while(!verificador.eof())
            {
                verificador>>nombre>>domicilio>>celular>>FechaPago;

                if(strcmp(codigoCliente,auxCodigo)==0)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un estudiante con ese c\242digo\n\n";
                    cout<<"El estudiante con ese c\242digo es: "<<nombre<<"\n\n";
                    cout<<"Ingresa un c\242digo v\240lido!: ";
                    cin.getline(auxCodigo,30);
                    if(strcmp(auxCodigo,"")==0)
                        do
                        {
                            cout<<"\nc\242digo del estudiante no v\240lido!, intentalo nuevamente: ";
                            cin.getline(auxCodigo,30);
                        }
                        while(strcmp(auxCodigo,"")==0);

                    break;
                }

                verificador>>codigoCliente;
            }

            if(verificador.eof()&&strcmp(auxCodigo,codigoCliente)!=0)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        strcpy(codigoCliente,auxCodigo);
        cout<<"\t\t\t\t***registrar el codigo del estudiante***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del estudiante: ";
        cout<<codigoCliente;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del estudiante: ";
        cin.getline(nombre,30);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el apellido del estudiante: ";
        cin.getline(domicilio,30);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el n\243mero de telefono del estudiante: ";
        cin.getline(celular,20);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la direccion\242n del estudiante: ";
        cin.getline(FechaPago,30);
        cout<<"\n\n";

        escritura<<codigoCliente<<"\n\n"<<nombre<<"\n\n"<<apellido<<"\n\n"<<telefono
                 <<"\n\n"<<direccion<<"\n\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}

void menu::retirar()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    char auxCodigo[30];
    char respuesta[5];
    lectura.open("estudiantes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***RETIRAR DE LA LISTA***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del alumno que deseas retirar: ";
        cin.getline(auxCodigo,30);
        lectura>>codigoCliente;
        while(!lectura.eof())
        {
            lectura>>nombre>>apellido>>telefono>>direccion;
            if(strcmp(auxCodigo,codigoCliente)==0)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoCliente<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<apellido<<endl;
                cout<<"Celular: "<<telefono<<endl;
                cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas retirar de la lista: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl estudiante fue retirado correctamente\n\n";
                }

                else
                {

                    cout<<"\n\nEstudiante conservado\n\n";
                    auxiliar<<codigoCliente<<"\n\n"<<nombre<<"\n\n"<<apellido<<"\n\n"<<telefono
                            <<"\n\n"<<FechaPago<<"\n\n";

                }

            }
            else
            {
                auxiliar<<codigoCliente<<"\n\n"<<nombre<<"\n\n"<<apellido<<"\n\n"<<telefono
                        <<"\n\n"<<FechaPago<<"\n\n";
            }
            lectura>>codigoCliente;
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("estudiantes.txt");
    rename("auxiliar.txt","estudiantes.txt");
    pausa();
}

void menu::detalle_estudiante()
{
    char auxCodigo [30];
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("estudiantes.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***CONSULTAR DETALLES DE UN ESTUDIANTE***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del estudiante que deseas consultar detalles: ";
        cin.getline(auxCodigo,30);
        mostrar>>codigoCliente;
        while(!mostrar.eof())
        {
            mostrar>>nombre>>apellido>>telefono>>direccion;
            if(strcmp(auxCodigo,codigoCliente)==0)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoCliente<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<apellido<<endl;
                cout<<"Celular: "<<telefono<<endl;
                cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
                cout<<"\n\n";
            }

            mostrar>>codigoCliente;
        }

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}

void menu::modificar_estudiante()
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    char auxCodigo[30];
    char codigoModif[30];
    char auxNombre[30];
    char auxapellido[30];
    char auxtelefono[20];
    char auxdireccion[30];
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("estudiantes.txt",ios::in);
    verificador.open("estudiantes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***MODIFICAR LOS DATOS UN ESTUDIANTE***\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del estudiante que deseas modificar: ";
        cin.getline(auxCodigo,30);

        if(strcmp(auxCodigo,"")==0)
        {
            do
            {
                cout<<"c\242digo del estudiante no v\240lido!, intentalo nuevamente: ";
                cin.getline(auxCodigo,30);
            }
            while(strcmp(auxCodigo,"")==0);
        }

        strcpy(codigoModif,auxCodigo);

        lectura>>codigoCliente;
        while(!lectura.eof())
        {
            lectura>>nombre>>apellido>>telefono>>direccion;
            if(strcmp(auxCodigo,codigoCliente)==0)
            {
                encontrado=true;
                mostarRegistro(codigoModif);

                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"INGRESE LA NUEVA INFORMACI\242N PARA EL ESTUDIANTE\n\n";
                fflush(stdin);
                cout<<"Ingresa el c\242digo del estudiante: ";
                cin.getline(auxCodigo,30);
                if(strcmp(auxCodigo,codigoModif)==0)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(strcmp(auxCodigo,codigoModif)==0)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        verificador>>codigoCliente;
                        while(!verificador.eof())
                        {
                            verificador>>nombre>>apellido>>telefono>>direccion;

                            if(strcmp(codigoCliente,auxCodigo)==0)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un estudiante con ese c\242digo!\n\n";
                                cout<<"El estudiante con ese c\242digo es: "<<nombre<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                cin.getline(auxCodigo,30);

                                if(strcmp(auxCodigo,"")==0)
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de estudiante no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        cin.getline(auxCodigo,30);
                                    }
                                    while(strcmp(auxCodigo,"")==0);
                                }
                                break;
                            }

                            verificador>>codigoCliente;
                        }

                        if(verificador.eof()&&strcmp(auxCodigo,codigoCliente)!=0)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***MODIFICAR LOS DATOS DEL ESTUDIANTE***\n\n";
                cout<<"Ingresa el c\242digo del estudiante que deseas modificar: ";
                cout<<codigoModif;
                mostarRegistro(codigoModif);
                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el estudiante\n\n";
                cout<<"Ingresa el c\242digo del estudiante: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del estudiante: ";
                cin.getline(auxNombre,30);
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa el apellido del estudiante: ";
                cin.getline(auxDomicilio,30);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el n\243mero de telefono del estudiante: ";
                cin.getline(auxCelular,20);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la direccion del estudiante: ";
                cin.getline(auxFecha,30);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n\n"<<auxNombre<<"\n\n"<<auxapellido<<"\n\n"<<auxtelefono
                        <<"\n\n"<<auxFecha<<"\n\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }


            else
            {

                auxiliar<<codigoCliente<<"\n\n"<<nombre<<"\n\n"<<apellido<<"\n\n"<<telefono
                        <<"\n\n"<<FechaPago<<"\n\n";
            }


            lectura>>codigoCliente;
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("estudiantes.txt");
    rename("auxiliar.txt","estudiantes.txt");
    pausa();
}

void menu::lista_estudiantes()
{
    int i=0;
    ifstream lectura;
    lectura.open("estudiantes.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***LISTA DE ESTUDIANTE***\t\t\t\t\n\n";
        lectura>>codigoCliente;
        while(!lectura.eof())
        {
            i++;
            lectura>>nombre>>apellido>>telefono>>direccion;
            cout<<"C\242digo: "<<codigoCliente<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Domicilio: "<<apellido<<endl;
            cout<<"Celular: "<<telefono<<endl;
            cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
            cout<<"\n\n";
            lectura>>codigoCliente;
        }

        if(i==1)
            cout<<"Hay un solo estudiante registrado\n\n";

        else

            cout<<"Hay un total de "<<i<<" estudiante registrados\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);
}
void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"estudiantes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void menu::mostarRegistro(char codigo[30])
{

    ifstream mostrar;
    mostrar.open("estudiantes.txt",ios::in);
    mostrar>>codigoCliente;
    while(!mostrar.eof())
    {
        mostrar>>nombre>>apellido>>telefono>>direccion;
        if(strcmp(codigo,codigoCliente)==0)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"C\242digo: "<<codigoCliente<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Domicilio: "<<apellido<<endl;
            cout<<"Celular: "<<telefono<<endl;
            cout<<"Fecha de inscripci\242n: "<<FechaPago<<endl;
            cout<<"\n\n";
        }
        mostrar>>codigoCliente;
    }
    mostrar.close();
}
