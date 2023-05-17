#ifndef CLSINTERPRETE_H_INCLUDED
#define CLSINTERPRETE_H_INCLUDED

class Interprete{
  private:
    int ID;
    char NombreInterprete[40];
    int Nacionalidad; //ENTERO ENTRE 1 Y 100
    int TipoInterprete; // entre 1 y 5
    int GeneroPrincipal; //entre 1 y 10
    Fecha FechaInicio;
    bool Estado;


  public:
      ///sets
      void setID(int i){ID=i;}
      void setNombreInterprete(const char *n){strcpy(NombreInterprete,n);}
      void setNacionalidad(int n){Nacionalidad=n;}
      void setTipoInterprete(int t){TipoInterprete=t;}
      void setGeneroPrincipal(int g){GeneroPrincipal=g;}
      void setEstado(bool e){Estado=e;}
      void setFecha(Fecha f){FechaInicio=f;}

      ///gets
      int getID(){return ID;}
      const char *getNombreInterprete(){return NombreInterprete;}
      int getNacionalidad(){return Nacionalidad;}
      int getTipoInterprete(){return TipoInterprete;}
      int getGeneroPrincipal(){return GeneroPrincipal;}
      Fecha getFechaInicio(){return FechaInicio;}
      bool getEstado(){return Estado;}

      int Cargar(int id=-1);
      void Mostrar();


      bool leerDeDisco(int pos);
      bool grabarEnDisco();
      bool modificarEnDisco(int pos);
};


bool Interprete::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("Interpretes.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Interprete), 0); ///sizeof (Interprete) es el tamaño en bytes de un objeto Empresa en memoria
    bool leyo = fread(this, sizeof (Interprete), 1, p);
    fclose(p);
    return leyo;
}

bool Interprete::grabarEnDisco(){
    FILE *p;
    p=fopen("Interpretes.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Interprete), 1, p);
    fclose(p);
    return escribio;
}

bool Interprete::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("Interpretes.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Interprete), 0);
    bool escribio=fwrite(this, sizeof (Interprete), 1, p);
    fclose(p);
    return escribio;
}

int Interprete::Cargar(int id){

    ID=id;

    cout<<"NOMBRE DEL INTERPRETE: ";
    cargarCadena(NombreInterprete,39);
    cout<<"NACIONALIDAD: ";
    cin>>Nacionalidad;
    if(Nacionalidad<0 || Nacionalidad>100){
        cout<<"NACIONALIDAD INVALIDA"<<endl;
        return -1;
    }
    cout<<"TIPO DE INTERPRETE: ";
    cin>>TipoInterprete;
    if(TipoInterprete<1 || TipoInterprete>5){
        cout<<"TIPO DE INTERPRETE INVALIDO "<<endl;
        return -1;
    }
    cout<<"GENERO MUSICAL: ";
    cin>>GeneroPrincipal;
    if(GeneroPrincipal<1 || GeneroPrincipal>10){
        cout<<"GENERO MUSICAL INVALIDO"<<endl;
        return -1;
    }
    cout<<"FECHA DE INICIO ACTIVIDAD: ";
    if(FechaInicio.Cargar()==-1){
        cout<<"FECHA INVALIDA"<<endl;
        return -1;
    }


    Estado=true;

    cout<<endl;
    return 0;
}

int contarInterpretes(){///ESTO ES PARA EL INGRESO AUTONUMERICO
    int cant=0;
    Interprete obj;
    while(obj.leerDeDisco(cant)){
        cant++;
    }
    return cant;
}

void Interprete::Mostrar(){
     cout<<"ID DE INTERPRETE: "<<ID<<endl;
     cout<<"NOMBRE DEL INTERPRETE: "<<NombreInterprete<<endl;
     cout<<"NACIONALIDAD: "<<Nacionalidad<<endl;
     cout<<"TIPO DE INTERPRETE: "<<TipoInterprete<<endl;
     cout<<"GENERO MUSICAL PRINCIPAL: "<<GeneroPrincipal<<endl;
     cout<<"FECHA DE INICIO ACTIVIDAD: ";
     FechaInicio.Mostrar();

}
bool CargarInterprete(){
    ///CARGAR INTERPRETE
    ///VALIDAR INTERPRETE (ID NO REPETIDO)
    ///GRABAR INTERPRETE SI VALIDO
    Interprete obj;
    int id;
    id=contarInterpretes();
    id++;
    cout<<"ID DE INTERPRETE: "<<id<<endl;
    if(obj.Cargar(id)==-1){
        return false;
    }
    else{
    system("cls");
    return obj.grabarEnDisco();
    }
    }



bool ListarInterpretes(){
    Interprete obj;

    FILE *p;
    p=fopen("Interpretes.dat", "rb");
    if(p==NULL){return false;}
    while(fread(&obj,sizeof(Interprete),1,p)==1){///SI EL ESTADO ES TRUE LO MUESTRA, SI ES FALSO NO LO MUESTRA
        if(obj.getEstado()==true){
                cout<<"========================================"<<endl;
                obj.Mostrar();

        }
        cout<<endl;
    }
    fclose(p);
    return true;
}
#endif // CLSINTERPRETE_H_INCLUDED
