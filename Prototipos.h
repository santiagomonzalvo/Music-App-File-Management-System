#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED


bool MenuCanciones();
bool MenuInterpretes();
bool MenuGeneros();
bool MenuReportes();
bool MenuConfiguracion();

int buscarIDCancion(int);
int buscarIDinterprete(int);
int VerificarEstadoInterprete(int);
int listarCancionID(int);
int contarCanciones();


bool CopiaCanciones();
bool CopiaInterpretes();
bool CopiaGeneros();
bool RestaurarCanciones();
bool RestaurarInterpretes();
bool RestaurarGeneros();
void RestablecerDatosDeInicio();

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


#endif // PROTOTIPOS_H_INCLUDED
