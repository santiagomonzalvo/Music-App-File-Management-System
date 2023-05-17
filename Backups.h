#ifndef BACKUPS_H_INCLUDED
#define BACKUPS_H_INCLUDED

//================COPIAS DE SEGURIDAD==================
bool CopiaCanciones(){
   Canciones obj;
   int pos=0;
   bool copio;
   FILE *Origen, *Destino;

   Origen=fopen("Canciones.dat","rb");
   if(Origen==NULL) return false;
   Destino=fopen("Canciones.bkp","wb");
   if(Destino==NULL) return false;

   while(obj.leerDeDisco(pos++)){

   copio=fwrite(&obj,sizeof(Canciones),1,Destino);

   }
   fclose(Origen);
   fclose(Destino);
   return copio;
}

bool CopiaInterpretes(){
   Interprete obj;
   int pos=0;
   bool copio;
   FILE *Origen, *Destino;

   Origen=fopen("Interpretes.dat","rb");
   if(Origen==NULL) return false;
   Destino=fopen("Interpretes.bkp","wb");
   if(Destino==NULL) return false;

   while(obj.leerDeDisco(pos++)){

   copio=fwrite(&obj,sizeof(Interprete),1,Destino);

   }
   fclose(Origen);
   fclose(Destino);
   return copio;
}

bool CopiaGeneros(){
   Genero obj;
   int pos=0;
   bool copio;
   FILE *Origen, *Destino;

   Origen=fopen("Generos.dat","rb");
   if(Origen==NULL) return false;
   Destino=fopen("Generos.bkp","wb");
   if(Destino==NULL) return false;

   while(obj.leerDeDisco(pos++)){

   copio=fwrite(&obj,sizeof(Genero),1,Destino);

   }
   fclose(Origen);
   fclose(Destino);
   return copio;
}


///===================RESTAURAR========================

bool RestaurarCanciones(){
   Canciones obj;

   bool copio;
   FILE *Origen, *Destino;

   Origen=fopen("Canciones.bkp","rb");
   if(Origen==NULL) return false;
   Destino=fopen("Canciones.dat","wb");
   if(Destino==NULL) return false;

   while(fread(&obj,sizeof(Canciones),1,Origen)==1){

   copio=fwrite(&obj,sizeof(Canciones),1,Destino);

   }
   fclose(Origen);
   fclose(Destino);
   return copio;
}

bool RestaurarInterpretes(){
   Interprete obj;

   bool copio;
   FILE *Origen, *Destino;

   Origen=fopen("Interpretes.bkp","rb");
   if(Origen==NULL) return false;
   Destino=fopen("Interpretes.dat","wb");
   if(Destino==NULL) return false;

   while(fread(&obj,sizeof(Interprete),1,Origen)==1){

   copio=fwrite(&obj,sizeof(Interprete),1,Destino);

   }
   fclose(Origen);
   fclose(Destino);
   return copio;
}


bool RestaurarGeneros(){
   Canciones obj;

   bool copio;
   FILE *Origen, *Destino;

   Origen=fopen("Generos.bkp","rb");
   if(Origen==NULL) return false;
   Destino=fopen("Generos.dat","wb");
   if(Destino==NULL) return false;

   while(fread(&obj,sizeof(Genero),1,Origen)==1){

   copio=fwrite(&obj,sizeof(Genero),1,Destino);

   }
   fclose(Origen);
   fclose(Destino);
   return copio;
}


void RestablecerDatosDeInicio(){
     system("copy CancionesInicio.bkp Canciones.dat");
     system("copy InterpretesInicio.bkp Interpretes.dat");
     system("copy GenerosInicio.bkp Generos.dat");


}


#endif // BACKUPS_H_INCLUDED
