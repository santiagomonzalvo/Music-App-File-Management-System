#ifndef CLSGENERO_H_INCLUDED
#define CLSGENERO_H_INCLUDED


class Genero{
   private:
       int ID;
       char NombreGenero[40];
       int Pais;
       int Tipo;
       bool estado;
   public:
         ///sets
        void setID(int d){ID=d;}
        void setNombreGenero(const char *n){strcpy(NombreGenero,n);}
        void setPais(int d){Pais=d;}
        void setTipo(int d){Tipo=d;}
        void setEstado(bool d){estado=d;}

        ///gets
        int getID(){return ID;}
        const char *getNombreGenero(){return NombreGenero;}
        int getPais(){return Pais;}
        int getTipo(){return Tipo;}
        bool getEstado(){return estado;}


        int Cargar(int id=-1);
        void Mostrar();

        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        bool modificarEnDisco(int pos);

};

void Genero::Mostrar(){
     cout<<endl;
     cout<<"ID DE GENERO: "<<ID<<endl;
     cout<<"NOMBRE: "<<NombreGenero<<endl;
     cout<<"PAIS DE ORIGEN: "<<Pais<<endl;
     cout<<"TIPO DE INSTRUMENTACION "<<Tipo<<endl;
     cout<<endl;

}



int Genero::Cargar(int id){

    ID=id;

    cout<<"NOMBRE: ";
    cargarCadena(NombreGenero,39);
    cout<<"PAIS DE ORIGEN ";
    cin>>Pais;
    if(Pais<1 || Pais>100){
        cout<<"EL NUMERO DE PAIS INGRESADO ES INCORRECTO (DEBE SER ENTRE 1 Y 100)"<<endl;
        return -1;
    }
    cout<<"TIPO DE INSTRUMENTACION: ";
    cin>>Tipo;
    if(Tipo<1 || Tipo>5){
        cout<<"EL NUMERO DE TIPO DE INSTRUMENCACION INGRESADO ES INCORRECTO(DEBE SER ENTRE 1 Y 5)";
        return -1;
    }
    estado=true;

    cout<<endl;
    return 0;
}

bool Genero::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("Generos.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Genero), 0); ///sizeof
    bool leyo = fread(this, sizeof (Genero), 1, p);
    fclose(p);
    return leyo;
}

bool Genero::grabarEnDisco(){
    FILE *p;
    p=fopen("Generos.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Genero), 1, p);
    fclose(p);
    return escribio;
}

bool Genero::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("Generos.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Genero), 0);
    bool modifico=fwrite(this, sizeof (Genero), 1, p);
    fclose(p);
    return modifico;
}

bool ListarGeneros(){
    Genero obj;

    FILE *p;
    p=fopen("Generos.dat", "rb");
    if(p==NULL){return false;}
    while(fread(&obj,sizeof(Genero),1,p)==1){///SI EL ESTADO ES TRUE LO MUESTRA, SI ES FALSO NO LO MUESTRA
        if(obj.getEstado()==true){
                cout<<"========================================"<<endl;
                obj.Mostrar();

        }
        cout<<endl;
    }
    fclose(p);
    return true;
}

int buscarIDGeneros(int id){
    Genero obj;
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

int contarGeneros(){///ESTO ES PARA EL INGRESO AUTONUMERICO
    int cant=0;
    Genero obj;
    while(obj.leerDeDisco(cant)){
        cant++;
    }
    return cant;
}

bool CargarGenero(){
    ///CARGAR GENEROS
    ///VALIDAR INTERPRETE (ID NO REPETIDO)
    ///GRABAR GENERO SI VALIDO
    Genero obj;
    int id;
    id=contarGeneros();
    id++;
    cout<<"ID DE GENERO: "<<id<<endl;
    if(obj.Cargar(id)==-1){
        return false;
    }
    else{
    system("cls");
    return obj.grabarEnDisco();
    }
}
#endif // CLSGENERO_H_INCLUDED
