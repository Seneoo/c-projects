#include <stdlib.h>
#include <stdio.h>
#define NUMRECORD 2
struct s_alunno{
	unsigned int matricola;
	char cognome[20];
	unsigned int materie;
};
typedef struct s_alunno alunno;
int main()
{
	FILE *puntaFile;
	
	int x,num;
	alunno elemento;
	puntaFile=fopen("alunni.dat","wb");
	if(puntaFile)
	{
		for(x=0;x<NUMRECORD;x++)
		{
			printf("Inserosco la matricola");
			scanf("%u",&elemento.matricola);
			printf("Inserisci il cognome");
			scanf("%s",elemento.cognome);
			printf("Inserisci il numero dei debiti");
			scanf("%u",&elemento.materie);
			fwrite(&elemento,sizeof(elemento),1,puntaFile);
		}
		fclose(puntaFile);
	}
	else exit(1);
	puntaFile=fopen("alunni.dat","rb");
	if(puntaFile)
	{
		for(x=0;x<NUMRECORD;x++)
		{
			fread(&elemento,sizeof(elemento),1,puntaFile);
			printf("\nMatricola: %d ",elemento.matricola);
			printf("\nCognome: %s \t",elemento.cognome);
			printf("\n Debiti: %d \n",elemento.materie);
		}
		fclose(puntaFile);
	}
	else exit(1);
}
