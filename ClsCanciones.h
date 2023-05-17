#ifndef CLSCANCIONES_H_INCLUDED
#define CLSCANCIONES_H_INCLUDED


class Canciones{
   private:
        int ID;
        char NombreCancion[30];
        char NombreAutor[30];
        int IdInterprete;
        Fecha FechaEstreno;
        bool Estado;
        float Duracion;
        int Genero;

   public:

    ///---------sets--------
    void setID(int i){ID=i;}
    void setNombre(const char *n){strcpy(NombreCancion,n);}
    void setNombreAutor(const char *n){strcpy(NombreAutor,n);}
    void setIdInterprete(int i){IdInterprete=i;}
    ///set de fecha estreno no va aca
    void setEstado(bool e){Estado=e;}
    void setDuracion(float d){Duracion=d;}
    void setGenero(int g){Genero=g;}
    void setFechaEstreno(Fecha f){FechaEstreno=f;}


    ///----------gets-----------
    int getID(){return ID;}
    const char *getNombreCancion(){return NombreCancion;}
    const char *getNombreAutor(){return NombreAutor;}
    int getIdInterprete(){return IdInterprete;}
    Fecha getFechaEstreno(){return FechaEstreno;}
    bool getEstado(){return Estado;}
    float getDuracion(){return Duracion;}
    int getGenero(){return Genero;}

    int Cargar(int id=-1);
    void Mostrar();

    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);

};

void Canciones::Mostrar(){
     cout<<"=========================="<<endl;
     cout<<"ID DE CANCION: "<<ID<<endl;
     cout<<"NOMBRE: "<<NombreCancion<<endl;
     cout<<"NOMBRE DE AUTOR: "<<NombreAutor<<endl;
     cout<<"ID INTERPRETE: "<<IdInterprete<<endl;
     cout<<"FECHA DE ESTRENO: ";
     FechaEstreno.Mostrar();
     cout<<"DURACION: "<<Duracion<<endl;
     cout<<"GENERO: "<<Genero<<endl;
     cout<<"=========================="<<endl;


}



int Canciones::Cargar(int id){

    ID=id;

    cout<<"NOMBRE: ";
    cargarCadena(NombreCancion,29);
    cout<<"NOMBRE DE AUTOR O COMPOSITOR: ";
    cargarCadena(NombreAutor,29);
    cout<<"ID INTERPRETE: ";
    cin>>IdInterprete;
    if(buscarIDinterprete(IdInterprete)==-1||buscarIDinterprete(IdInterprete)==-2){
        cout<<"EL ID INTERPRETE NO EXISTE"<<endl;
        return -1;
    }

    cout<<"FECHA DE ESTRENO: ";
     if(FechaEstreno.Cargar()==-1){
        cout<<"FECHA INVALIDA"<<endl;
        return -1;
    }

    cout<<"DURACION DE LA CANCION(MINUTOS): ";
    cin>>Duracion;
    if(Duracion<0){
        cout<<"DATO INVALIDO(NO PUEDE INGRESAR MINUTOS NEGATIVOS)"<<endl;
        return -1;
    }
    cout<<"GENERO MUSICAL: ";
    cin>>Genero;
    if(Genero<1 || Genero>10){
        cout<<"NUMERO INGRESADO INCORRECTO, DEBE INDICAR EL GENERO CON UN NUMERO ENTRE EL 1 Y 10 "<<endl;
        return -1;
    }

    Estado=true;

    cout<<endl;
    return 0;
}

bool Canciones::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("Canciones.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Canciones), 0); ///sizeof (Canciones) es el tamaño en bytes de un objeto Empresa en memoria
    bool leyo = fread(this, sizeof (Canciones), 1, p);
    fclose(p);
    return leyo;
}


bool Canciones::grabarEnDisco(){
    FILE *p;
    p=fopen("Canciones.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Canciones), 1, p);
    fclose(p);
    return escribio;
}

bool Canciones::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("Canciones.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Canciones), 0);
    bool modifico=fwrite(this, sizeof (Canciones), 1, p);
    fclose(p);
    return modifico;
}



int contarCanciones(){///FUNCION AUTONUMERICA
    int cant=0;
    Canciones obj;
    while(obj.leerDeDisco(cant)){
        cant++;
    }
    return cant;
}


int buscarIDCancion(int id){
    Canciones obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if(obj.getID()==id){
                if(obj.getEstado()==false){///SI EL ESTADO ES FALSE DEVUELVE -1 YA QUE ESTA DADO DE BAJA POR LO CUAL NO DEBE USARSE
                    return -1;
                }

            return pos;//SI EL ESTADO ES VERDADERO DEVUELVE LA POSICION DEL INTERPRETE
        }
        pos++;
    }
    return -1;
}

int buscarIDinterprete(int id){
    Interprete obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if(obj.getID()==id){
                if(obj.getEstado()==false){///SI EL ESTADO ES FALSE DEVUELVE -1 YA QUE ESTA DADO DE BAJA POR LO CUAL NO DEBE USARSE
                    return -1;
                }
            return pos;///SI EL ESTADO ES VERDADERO DEVUELVE LA POSICION DEL INTERPRETE
        }
        pos++;
    }
    return -1;
}
/*
bool CargarCancion(){
    ///CARGAR CANCION
    ///VALIDAR CANCION(ID NO REPETIDO)
    ///GRABAR CANCION SI VALIDO
    Canciones obj;
    int id, pos;

    cout<<"ID DE CANCION: ";
    cin>>id;
    pos=buscarIDCancion(id);
    if(pos>=0){
        cout<<"EL NUMERO DE ID INGRESADO YA EXISTE"<<endl;
        return false;
    }
    if(obj.Cargar(id)!=-1){

    system("cls");
    return obj.grabarEnDisco();

    }

}
*/
bool CargarCancion(){
    ///CARGAR CANCION
    ///VALIDAR CANCION(ID NO REPETIDO)
    ///GRABAR CANCION SI VALIDO
    Canciones obj;
    int id;
    id=contarCanciones();///ESTO ES PARA QUE SEA AUTONUMERICO
    id++;
    cout<<"ID DE CANCION: "<<id<<endl;
    if(obj.Cargar(id)==-1){
        return false;
    }
    else{
        return obj.grabarEnDisco();
    }

    }


int listarCancionID(int id){
    Canciones obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
            if(obj.getID()==id){
                    if(obj.getEstado()==false){
                        return -1;
                    }
                return pos;
            }
        pos++;
    }
    return -1;
}

bool ListarCanciones(){
    Canciones obj;

    FILE *p;
    p=fopen("Canciones.dat", "rb");
    if(p==NULL){return false;}
    while(fread(&obj,sizeof(Canciones),1,p)==1){///SI EL ESTADO ES TRUE LO MUESTRA, SI ES FALSO NO LO MUESTRA
        if(obj.getEstado()==true) obj.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}







#endif // CLSCANCIONES_H_INCLUDED
