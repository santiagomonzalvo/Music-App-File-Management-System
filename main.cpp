#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

#include "Prototipos.h"
#include "ClsFecha.h"
#include "ClsInterprete.h"
#include "ClsGenero.h"
#include "ClsCanciones.h"
#include "Backups.h"
#include "Reportes.h"

///COMANDO PARA BACKUPS system("copy Canciones.dat Canciones.bkp");
///BORRAR CARPETAS BIN Y OBJ ANTES DE ENTREGAR

//explicacion de restricciones cerca del final del video https://www.youtube.com/watch?v=-hm3AG5bT1s&ab_channel=MaximilianoWenner

int main()
{
    int opc;
    while(true){
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<endl;
    cout<<"1) MENU CANCIONES "<<endl;
    cout<<"2) MENU INTERPRETES "<<endl;
    cout<<"3) MENU GENEROS "<<endl;
    cout<<"4) REPORTES "<<endl;
    cout<<"5) CONFIGURACION "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0) FIN DEL PROGRAMA "<<endl;
    cout<<endl;
    cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
    cin>>opc;
      switch(opc){
      case 1:
            system("cls");
            MenuCanciones();
          break;
      case 2:
            system("cls");
            MenuInterpretes();
          break;
      case 3:
          system("cls");
            MenuGeneros();
          break;
      case 4:
           system("cls");
           MenuReportes();
          break;
      case 5:
          system("cls");
           MenuConfiguracion();
          break;
      case 0:
          system("cls");
          return false;
          break;
      default:
          cout<<endl;
          cout<<"OPCION INCORRECTA"<<endl;
          break;
      }
      //system("pause");
      system("cls");
    }
    return 0;
}



bool MenuCanciones(){
    Canciones obj;
    Fecha fecha;
    int opc,id;
    int aux;
    int cantidad;
while(true){
cout<<"MENU CANCIONES "<<endl;
cout<<"-----------------------"<<endl;
cout<<endl;
cout<<"1) AGREGAR CANCION "<<endl;
cout<<"2) LISTAR CANCION POR ID "<<endl;
cout<<"3) LISTAR TODAS LAS CANCIONES "<<endl;
cout<<"4) MODIFICAR FECHA DE ESTRENO "<<endl;
cout<<"5) ELIMINAR CANCION "<<endl;///baja logica
cout<<"--------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
cout<<" OPCION: ";
cin>>opc;
  switch(opc){
      case 1:
          if(CargarCancion()==true){
            cout<<"CANCION AGREGADA EXITOSAMENTE "<<endl;
          }
          else{
            cout<<"NO SE PUDO AGREGAR LA CANCION "<<endl;
          }
          break;
      case 2:
          cout<<endl;
          cout<<"INGRESE ID DE LA CANCION A BUSCAR: ";
          cin>>id;
          aux=listarCancionID(id);
          if(aux==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
          }
          else{
            obj.leerDeDisco(aux);
            obj.Mostrar();
          }
          break;
      case 3:ListarCanciones();
          break;
      case 4:
          cout<<"INGRESE ID DE LA CANCION A MODIFICAR SU FECHA DE ESTRENO: ";
          cin>>id;
          aux=listarCancionID(id);
          if(aux==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
          }
          else{
            obj.leerDeDisco(aux);
            if(fecha.Cargar()==-1){
                    cout<<"FECHA INVALIDA"<<endl;
            }
            else{
            obj.setFechaEstreno(fecha);
            if(obj.modificarEnDisco(aux)==false){
                cout<<"ERROR AL MODIFICAR FECHA DE ESTRENO"<<endl;
            }
            else{
                cout<<"FECHA MODIFICADA EXITOSAMENTE"<<endl;
            }
          }
          }
          break;
      case 5:
          cout<<"INGRESE ID DE LA CANCION A ELIMINAR: ";
          cin>>id;
          aux=listarCancionID(id);
          if(aux==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
          }
          else{
            obj.leerDeDisco(aux);
            obj.setEstado(false);
            if(obj.modificarEnDisco(aux)==false){
                cout<<"ERROR AL ELIMINAR CANCION"<<endl;
            }
            else{
                cout<<"CANCION ELIMINADA CORRECTAMENTE"<<endl;
            }
          }
          break;
      case 6:
        cantidad=contarCanciones();
        system("cls");
        cout<<"CANTIDAD DE CANCIONES: "<<cantidad<<endl;
        system("pause");

      case 0:

            system("cls");
            return false;
          break;
      default:
          cout<<endl;
          cout<<"OPCION INCORRECTA"<<endl;
          break;
      }
      system("pause");
      system("cls");
 }
}


bool MenuInterpretes(){
    int opc,aux,aux2;
    int id;
    Interprete obj;
while(true){
cout<<"MENU INTERPRETES "<<endl;
cout<<"-----------------------"<<endl;
cout<<endl;
cout<<"1) AGREGAR INTERPRETE "<<endl;
cout<<"2) LISTAR INTERPRETE POR ID "<<endl;
cout<<"3) LISTAR TODOS LOS INTERPRETES "<<endl;
cout<<"4) MODIFICAR GENERO MUSICAL PRINCIPAL "<<endl;
cout<<"5) ELIMINAR INTERPRETE "<<endl;///baja logica
cout<<"--------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
cout<<" OPCION: ";
cin>>opc;
  switch(opc){
      case 1:
          if(CargarInterprete()==true){
            cout<<"INTERPRETE AGREGADO EXITOSAMENTE "<<endl;
          }
          else{
            cout<<"NO SE PUDO AGREGAR EL INTERPRETE"<<endl;
          }
          break;
      case 2:
        cout<<"INGRESE ID DE INTERPRETE A LISTAR: "<<endl;
        cin>>id;
        aux=buscarIDinterprete(id);
        if(aux==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
        }
        else{
        obj.leerDeDisco(aux);
        obj.Mostrar();
        }
          break;
      case 3:
          ListarInterpretes();
          break;
      case 4:
            cout<<"INGRESE ID DE INTERPRETE A MODIFICAR GENERO PRINCIPAL: ";
          cin>>id;
          aux=buscarIDinterprete(id);
          if(aux==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
          }
          else{
            obj.leerDeDisco(aux);
            cout<<"INGRESE SU NUEVO GENERO PRINCIPAL: ";
            cin>>aux2;
            if(aux2<1 || aux2>10){
                cout<<"GENERO INGRESADO INVALIDO(DEBE SER ENTRE 1 Y 10)"<<endl;
            }
            else{
            obj.setGeneroPrincipal(aux2);
            if(obj.modificarEnDisco(aux)==false){
                cout<<"ERROR AL MODIFICAR GENERO PRINCIPAL"<<endl;
            }
            else{
                cout<<"GENERO MODIFICADO EXITOSAMENTE"<<endl;
            }
          }
          }
          break;
      case 5:
          cout<<"INGRESE ID DEL INTERPRETE A ELIMINAR: ";
          cin>>id;
          aux=buscarIDinterprete(id);

          if(aux==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
          }
          else{
            obj.leerDeDisco(aux);
            obj.setEstado(false);
            if(obj.modificarEnDisco(aux)==false){
                cout<<"ERROR AL ELIMINAR INTERPRETE"<<endl;
            }
            else{
                cout<<"INTERPRETE ELIMINADO CORRECTAMENTE"<<endl;
            }
          }
          break;
      case 0:
            system("cls");
            return false;
          break;
      default:
          cout<<endl;
          cout<<"OPCION INCORRECTA"<<endl;
          break;
      }
      system("pause");
      system("cls");
 }
}

///--------------PARTE 2----------------------

bool MenuGeneros(){
    int opc,aux,aux2;
    int id;
    Genero obj;
while(true){
cout<<"MENU GENEROS "<<endl;
cout<<"-----------------------"<<endl;
cout<<endl;
cout<<"1) AGREGAR GENERO "<<endl;
cout<<"2) LISTAR GENERO POR ID "<<endl;
cout<<"3) LISTAR TODOS LOS GENEROS "<<endl;
cout<<"4) MODIFICAR TIPO DE INSTRUMENTACION "<<endl;

cout<<"--------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
cout<<" OPCION: ";
cin>>opc;
  switch(opc){
  case 1:
       if(CargarGenero()==true){
        cout<<"GENERO AGREGADO EXITOSAMENTE"<<endl;
       }
       else{
        cout<<"ERROR AL AGREGAR GENERO"<<endl;
       }
       break;
  case 2:
        cout<<"INGRESE ID DE GENERO A LISTAR: "<<endl;
        cin>>id;
        aux=buscarIDGeneros(id);
        if(aux==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
        }
        else{
        obj.leerDeDisco(aux);
        obj.Mostrar();
        }
       break;
  case 3:
      ListarGeneros();
       break;
  case 4:
      cout<<"INGRESE ID DEL GENERO A MODIFICAR TIPO DE INSTRUMENTO PRINCIPAL: ";
          cin>>id;
          aux=buscarIDGeneros(id);
          if(aux==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
          }
          else{
            obj.leerDeDisco(aux);
            cout<<"INGRESE SU NUEVO TIPO DE INSTRUMENTO PRINCIPAL: ";
            cin>>aux2;
            if(aux2<1 || aux2>5){
                cout<<"TIPO DE INSTRUMENTO INGRESADO INCORRECTO (DEBE SER ENTRE 1 Y 5)"<<endl;
            }
            else{
            obj.setTipo(aux2);
            if(obj.modificarEnDisco(aux)==false){
                cout<<"ERROR AL MODIFICAR TIPO DE INSTRUMENTO PRINCIPAL"<<endl;
            }
            else{
                cout<<"TIPO DE INSTRUMENTO MODIFICADO EXITOSAMENTE"<<endl;
            }
          }
          }
       break;
  case 0:
    system("cls");
    return false;
    break;
  default:
    cout<<"OPCION INCORRECTA"<<endl;
    break;
  }
  system("pause");
  system("cls");
}
}


bool MenuConfiguracion(){
    int opc;
while(true){
cout<<"MENU CONFIGURACION "<<endl;
cout<<"-----------------------"<<endl;
cout<<endl;
cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES "<<endl;
cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES "<<endl;
cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS "<<endl;
cout<<"4) RESTAURAR EL ARCHIVO DE CANCIONES "<<endl;
cout<<"5) RESTAURAR EL ARCHIVO DE INTERPRETES "<<endl;
cout<<"6) RESTAURAR EL ARCHIVO DE GENEROS "<<endl;
cout<<"7) ESTABLECER DATOS DE INICIO "<<endl;
cout<<"--------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
cout<<" OPCION: ";
cin>>opc;
  switch(opc){
  case 1:
      if(CopiaCanciones()==true){
        cout<<"COPIA DE SEGURIDAD Canciones.bkp CREADA EXITOSAMENTE "<<endl;
      }
      else{
        cout<<"HUBO UN ERROR DURANTE LA COPIA DE SEGURIDAD "<<endl;
      }
     break;
  case 2:
         if(CopiaInterpretes()==true){
        cout<<"COPIA DE SEGURIDAD Interpretes.bkp CREADA EXITOSAMENTE "<<endl;
      }
      else{
        cout<<"HUBO UN ERROR DURANTE LA COPIA DE SEGURIDAD "<<endl;
      }
     break;
  case 3:
         if(CopiaGeneros()==true){
        cout<<"COPIA DE SEGURIDAD Generos.bkp CREADA EXITOSAMENTE "<<endl;
      }
      else{
        cout<<"HUBO UN ERROR DURANTE LA COPIA DE SEGURIDAD "<<endl;
      }
     break;
  case 4:
        if(RestaurarCanciones()==true){
        cout<<"RESTAURACION DE Canciones.dat COMPLETADA EXITOSAMENTE "<<endl;
      }
      else{
        cout<<"HUBO UN ERROR DURANTE LA RESTAURACION "<<endl;
      }
     break;
  case 5:
         if(RestaurarInterpretes()==true){
        cout<<"RESTAURACION DE Interpretes.dat COMPLETADA EXITOSAMENTE "<<endl;
      }
      else{
        cout<<"HUBO UN ERROR DURANTE LA RESTAURACION "<<endl;
      }
     break;
  case 6:
         if(RestaurarGeneros()==true){
        cout<<"RESTAURACION DE Generos.dat COMPLETADA EXITOSAMENTE "<<endl;
      }
      else{
        cout<<"HUBO UN ERROR DURANTE LA RESTAURACION "<<endl;
      }
     break;
  case 7:
      RestablecerDatosDeInicio();
     break;
  case 0:
    system("cls");
    return false;
    break;
  default:
    cout<<"OPCION INCORRECTA"<<endl;
    break;
  }
  system("pause");
  system("cls");
}
}
