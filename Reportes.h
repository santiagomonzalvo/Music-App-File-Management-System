#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void punto1();

void punto2();
     void mostrarVector(int *v, int tam);

void punto3();
     int contarCancionesInterprete(int id);

void punto4();
void punto5();
void punto6();
void punto7();
void punto8();
void puntoP1();
void puntoP2();
void puntoP3();




bool MenuReportes(){
int opc;
while(true){
cout<<"MENU REPORTES "<<endl;
cout<<"-----------------------"<<endl;
cout<<endl;
cout<<"===========PUNTOS DE PRACTICA=============="<<endl;
cout<<"1) LISTAR INTERPRETES DE NACIONALIDAD ARGENTINA "<<endl;
cout<<"2) POR CADA TIPO DE INSTRUMENTACION, MOSTRAR LA CANTIDAD DE GENEROS QUE LA UTILIZA "<<endl;
cout<<"3) CREAR UN ARCHIVO NUEVO DE NOMBRE INTERPRETES2021.dat CON EL SIGUIENTE FORMATO: ID,NOMBRE,CANTIDAD DE CANCIONES "<<endl;
cout<<"4) MOSTRAR ID DE LA CANCION CON DURACION MAS CORTA "<<endl;
cout<<"5) MOSTRAR ID DE LA CANCION CON DURACION MAS LARGA "<<endl;
cout<<"6) MOSTRAR EL TOTAL DE CANCIONES POR INTERPRETE "<<endl;
/*cout<<"7) LISTAR EL INTERPRETE MAS ANTIGUO "<<endl;
cout<<"8) LISTAR EL INTERPRETE MAS RECIENTE "<<endl;
cout<<"9) MOSTRAR LA CANTIDAD DE ANIOS QUE LLEVA UN INTERPRETE INGRESADO POR ID "<<endl;
cout<<"10) LISTAR INTERPRETES QUE NO TENGAN CANCIONES "<<endl;*/
cout<<"============PUNTOS DEL PARCIAL============="<<endl;
cout<<"7) PARCIAL PUNTO 1 "<<endl;
cout<<"8) PARCIAL PUNTO 2 "<<endl;
cout<<"9) PARCIAL PUNTO 3 "<<endl;
cout<<endl;
cout<<endl;
cout<<"-----------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
cout<<"OPCION: ";
cin>>opc;
cout<<endl;
  switch(opc){
  case 1:
        punto1();
    break;
  case 2:
        punto2();
    break;
  case 3:
        punto3();
    break;
  case 4:
        punto4();
    break;
  case 5:
        punto5();
    break;
  case 6:
        punto6();
    break;
  case 7:
        puntoP1();
    break;
  case 8:
        puntoP2();
    break;
  case 9:
       puntoP3();
    break;
  case 0:
      return false;
    break;
  default:
    cout<<"OPCION INCORRECTA"<<endl;
    break;
  }
  system("pause");
  system("cls");
  }
  return 0;
}

void punto1(){
    Interprete obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.getNacionalidad()==5 && obj.getEstado()==true){
            cout<<"============================================"<<endl;
            obj.Mostrar();
            cout<<endl;

        }
    }
}

void punto2(){
     Genero obj;
     int vGenero[5]={0};
     int pos=0;
     while(obj.leerDeDisco(pos++)){
            if(obj.getEstado()==true){
                  vGenero[obj.getTipo()-1]++;
            }
     }
     mostrarVector(vGenero,5);
}

class Interprete2021{
  private:
      int id;
      char nombre[40];
      int cantidadCanciones;
  public:
       void setID(int i){id=i;}
       void setNombre(const char *n){strcpy(nombre,n);}
       void setCantidadCanciones(int c){cantidadCanciones=c;}

       bool grabarEnDisco(){
       FILE *p;
       p=fopen("Interpretes2021.dat","ab");
       if(p==NULL) return false;
       bool escribio = fwrite(this,sizeof(Interprete2021),1,p);
       fclose(p);
       return escribio;
       }

};



void punto3(){
    Interprete obj;
    Interprete2021 aux;
    int pos=0;
    int cantidad;
    while(obj.leerDeDisco(pos++)){
        ///CHEQUEAR QUE HAYA INICIADO SUS ACTIVIDADES EN EL 2021
        if(obj.getFechaInicio().getAnio()==2021 && obj.getEstado()==true){
        ///SI INICIO EN 2021, CONTAR LA CANTIDAD DE CANCIONES
        cantidad=contarCancionesInterprete(obj.getID());
        ///SETEAR OBJ AUX Y GRABAR EN DISCO
        aux.setID(obj.getID());
        aux.setNombre(obj.getNombreInterprete());
        aux.setCantidadCanciones(cantidad);
        aux.grabarEnDisco();

        }

    }
}

void punto4(){
   Canciones obj;
   int pos=0;
   char nombre[30];
   int menosDuracion;
   float MrD=100;
   while(obj.leerDeDisco(pos++)){
    if(obj.getDuracion()<MrD){
        MrD=obj.getDuracion();
        menosDuracion=obj.getID();
        strcpy(nombre,obj.getNombreCancion());
    }
   }
   cout<<"EL ID DE LA CANCION CON MENOR DURACION ES: "<<menosDuracion<<endl;
   cout<<"NOMBRE: "<<nombre<<endl;
}

void punto5(){
   Canciones obj;
   int pos=0;
   char nombre[30];
   int menosDuracion;
   float MrD=0.1;
   while(obj.leerDeDisco(pos++)){
    if(obj.getDuracion()>MrD){
        MrD=obj.getDuracion();
        menosDuracion=obj.getID();
        strcpy(nombre,obj.getNombreCancion());
    }
   }
   cout<<"EL ID DE LA CANCION CON MAYOR DURACION ES: "<<menosDuracion<<endl;
   cout<<"NOMBRE: "<<nombre<<endl;
}

void punto6(){
    Interprete obj;
    Canciones aux;
    int Cantidad=0;
    int pos,pos2;
    while(obj.leerDeDisco(pos++)){
        while(aux.leerDeDisco(pos2++)){
            if(obj.getID()== aux.getIdInterprete()){
                Cantidad++;
            }
        }
        cout<<"========================================"<<endl;
        cout<<"ID DE INTERPRETE: "<<obj.getID()<<endl;
        cout<<"CANTIDAD DE CANCIONES: "<<Cantidad<<endl;
        Cantidad=0;
        pos2=0;

    }

}


void punto7(){
     Interprete obj;
     bool b=true;
     int dia;
     int mes;
     int anio;
     int pos=0;
     int masviejo;
     char nombre[40];

     while(obj.leerDeDisco(pos++)){
            if(b==true){
                dia=obj.getFechaInicio().getDia();
                mes=obj.getFechaInicio().getMes();
                anio=obj.getFechaInicio().getAnio();
                strcpy(nombre,obj.getNombreInterprete());
                b=false;

            }

                   if(obj.getFechaInicio().getAnio()<anio){
                                   anio=obj.getFechaInicio().getAnio();
                                   mes=obj.getFechaInicio().getMes();
                                   dia=obj.getFechaInicio().getDia();
                                   masviejo=obj.getID();
                                   strcpy(nombre,obj.getNombreInterprete());

                   }
                    else{
                        if(obj.getFechaInicio().getAnio()==anio){
                                    if(obj.getFechaInicio().getMes()<mes){
                                        mes=obj.getFechaInicio().getMes();
                                        masviejo=obj.getID();
                                        strcpy(nombre,obj.getNombreInterprete());
                                        }
                                        else{
                                            if(obj.getFechaInicio().getMes()==mes){
                                                                            if(obj.getFechaInicio().getDia()<dia){
                                                                            dia=obj.getFechaInicio().getDia();
                                                                            masviejo=obj.getID();
                                                                            strcpy(nombre,obj.getNombreInterprete());
                                                                            }
                                            }
                                    }
                        }

                }
    }
   cout<<"EL INTERPRETE MAS VIEJO ES EL ID: "<<masviejo<<endl;
   cout<<"NOMBRE: "<<nombre<<endl;
   cout<<"FECHA: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
   system("pause");
}

void punto8(){
     Interprete obj;
     bool b=true;
     int dia;
     int mes;
     int anio;
     int pos=0;
     int masreciente;
     char nombre[40];

     while(obj.leerDeDisco(pos++)){
            if(b==true){
                dia=obj.getFechaInicio().getDia();
                mes=obj.getFechaInicio().getMes();
                anio=obj.getFechaInicio().getAnio();
                strcpy(nombre,obj.getNombreInterprete());
                b=false;

            }
                   if(obj.getFechaInicio().getAnio()>anio){
                                   anio=obj.getFechaInicio().getAnio();
                                   mes=obj.getFechaInicio().getMes();
                                   dia=obj.getFechaInicio().getDia();
                                   masreciente=obj.getID();
                                   strcpy(nombre,obj.getNombreInterprete());

                   }
                    else{
                        if(obj.getFechaInicio().getAnio()==anio){
                                    if(obj.getFechaInicio().getMes()>mes){
                                        mes=obj.getFechaInicio().getMes();
                                        masreciente=obj.getID();
                                        strcpy(nombre,obj.getNombreInterprete());
                                        }
                                        else{
                                            if(obj.getFechaInicio().getMes()==mes){
                                                                            if(obj.getFechaInicio().getDia()>dia){
                                                                            dia=obj.getFechaInicio().getDia();
                                                                            masreciente=obj.getID();
                                                                            strcpy(nombre,obj.getNombreInterprete());
                                                                            }
                                            }
                                    }
                        }

                }
    }
   cout<<"EL INTERPRETE MAS RECIENTE ES EL ID: "<<masreciente<<endl;
   cout<<"NOMBRE: "<<nombre<<endl;
   cout<<"FECHA: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
   system("pause");
}

void puntoP1(){
   Canciones reg;
   int cant=0;
   int posicion=0;
   int opcioni;
   cout<<"ID DE INTERPRETE para listar canciones estrenadas por ese intérprete del año 2010 en adelante: ";
    cin>>opcioni;
    while(reg.leerDeDisco(posicion++)){
            if(reg.getIdInterprete()==opcioni){
                    if(reg.getFechaEstreno().getAnio()>=2010){
                reg.Mostrar();
                    }
            }

    }
}



void puntoP2(){

}

void puntoP3(){


}


































///========================================================================================

int contarCancionesInterprete(int id){
   Canciones obj;
   int pos=0,cantidad=0;
   while(obj.leerDeDisco(pos++)){
    ///POR CADA REGISTRO CHECKEAR SI ES DEL INTERPRETE QUE RECIBI
    if(obj.getIdInterprete()==id && obj.getEstado()==true){
        cantidad++;
    }
   }
   return cantidad;
}

void mostrarVector(int *v,int tam){
    for(int i=0;i<tam;i++){
        cout<<"PARA EL TIPO DE INSTRUMENTACION "<<i+1<<" HAY "<<v[i]<<" GENEROS"<<endl;
    }
}
#endif // REPORTES_H_INCLUDED
