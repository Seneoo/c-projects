#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
struct clienti
{
    int codiceC;
    char cognome[20];
    char nome[20];
    char data[20];
    char indirizzo[20];
    int telefono;
};
struct viaggi
{
    int codice;
    char datapart[20];
    char destinazione[20];
    char datarientro[20];
    float costo;
    int codiceV;
};
int main()
{
    struct clienti c;
    struct viaggi v;
    int nC,nV;
    FILE *fpc,*fpv;
    int i;  
    do
    {
        printf("Inserire il numero di clienti: ");
        scanf("%d",&nC);
    }while(nC>max);
    fpc=fopen("clienti.dat","wb");
    if(fpc==NULL)
    {
        printf("Errore nell'apertura dei file");
        exit(1);
    }
    for(i=0;i<nC;i++)
    {
        printf("Inserire il codice del cliente: ");
        scanf("%d",&c.codiceC);
        printf("Inserire il cognome del cliente: ");
        scanf("%s",c.cognome);
        printf("Inserire il nome del cliente: ");
        scanf("%s",c.nome);
        printf("Inserire la data di nascita del cliente: ");
        scanf("%s",c.data);
        printf("Inserire l'indirizzo del cliente: ");
        scanf("%s",c.indirizzo);
        printf("Inserire il numero di telefono del cliente: ");
        scanf("%d",&c.telefono);
        fwrite(&c,sizeof(struct clienti),1,fpc);
    }
    fclose(fpc);
    do
    {
        printf("Inserire il numero di viaggi: ");
        scanf("%d",&nV);
    }while(nV>max);
    fpv=fopen("viaggi.dat","wb");
    if(fpv==NULL)
    {
        printf("Errore nell'apertura dei file");
        exit(1);
    }
    for(i=0;i<nV;i++)
    {
        printf("Inserire il codice del viaggio: ");
        scanf("%d",&v.codice);
        printf("Inserire la data di partenza del viaggio: ");
        scanf("%s",v.datapart);
        printf("Inserire la destinazione del viaggio: ");
        scanf("%s",v.destinazione);
        printf("Inserire la data di rientro del viaggio: ");
        scanf("%s",v.datarientro);
        printf("Inserire il costo del viaggio: ");
        scanf("%f",&v.costo);
        printf("Inserire il codice del cliente associato al viaggio: ");
        scanf("%d",&v.codiceV);
        fwrite(&v,sizeof(struct viaggi),1,fpv);
    }
    fclose(fpv);
    int risp;
    do
    {
        printf("MENU'\n");
        printf("1. Visualizzare il numero di viaggi con destinazione Venezia\n");
        printf("2. Ricercare tramite codice i dati anagrafici\n");
        printf("3. Visualizzare il costo totale dei viaggi scelti\n");
        printf("4. Aggiungere un nuovo cliente in coda\n");
        printf("5. Visualizzare le informazioni del quarto viaggio presente nel file\n");
        printf("6. Uscire\n");
        printf("Inserire la scelta: ");
        scanf("%d",&risp);
        if(risp<1 || risp>6)
        {
            printf("Scelta non valida\n");
        }
        else
        {
            switch(risp)
            {
                case 1:
                {
                    int count=0;
                    fpv=fopen("viaggi.dat","rb");
                    if(fpv!=NULL)
                    {
                        while(fread(&v,sizeof(struct viaggi),1,fpv)>0)
                        {
                            if(strcmp(v.destinazione,"Venezia")==0)
                            { 
                                count++;
                            }
                        }
                        fclose(fpv);
                    }
                    printf("Il numero di viaggi con destinazione Venezia e': %d\n",count);
                    break;
                }
                case 2:
                {
                    int codice;
                    int counter=0;
                    printf("Inserire il codice del cliente da ricercare:\n");
                    scanf("%d",&codice);
                    fpc=fopen("clienti.dat","rb");
                    if(fpc!=NULL)
                    {
                        while(fread(&c,sizeof(struct clienti),1,fpc)>0)
                        {
                            if(c.codiceC==codice)
                            {
                                printf("Codice: %d\n",c.codiceC);
                                printf("Cognome: %s\n",c.cognome);
                                printf("Nome: %s\n",c.nome);
                                printf("Data di nascita: %s\n",c.data);
                                printf("Indirizzo: %s\n",c.indirizzo);
                                printf("Telefono: %d\n",c.telefono);
                                counter++;
                            }
                        }
                        fclose(fpc);
                    }
                    if(counter==0)
                    {
                        printf("Cliente non trovato\n");
                    }
                    break;
                }
                case 3:
                {
                    int codiceCliente;
                    float costoTotale=0;
                    printf("Inserire il codice cliente per calcolare il costo totale dei viaggi: ");
                    scanf("%d",&codiceCliente);
                    fpv=fopen("viaggi.dat","rb");
                    if(fpv!=NULL)
                    {
                        while(fread(&v,sizeof(struct viaggi),1,fpv)>0)
                        {
                            if(v.codiceV==codiceCliente)
                            {
                                costoTotale+=v.costo;
                            }
                        }
                        fclose(fpv);
                    }
                    printf("Il costo totale dei viaggi per il cliente con codice %d e': %f\n",codiceCliente,costoTotale);
                    break;
                }
                case 4:
                {
                    printf("Inserire il codice del nuovo cliente: ");
                    scanf("%d",&c.codiceC);
                    printf("Inserire il cognome del nuovo cliente: ");
                    scanf("%s",c.cognome);
                    printf("Inserire il nome del nuovo cliente: ");
                    scanf("%s",c.nome);
                    printf("Inserire la data di nascita del nuovo cliente: ");
                    scanf("%s",c.data);
                    printf("Inserire l'indirizzo del nuovo cliente: ");
                    scanf("%s",c.indirizzo);
                    printf("Inserire il numero di telefono del nuovo cliente: ");
                    scanf("%d",&c.telefono);
                    fpc=fopen("clienti.dat","ab");
                    if(fpc!=NULL)
                    {
                        fwrite(&c,sizeof(struct clienti),1,fpc);
                        fclose(fpc);
                    }
                    break;
                }
                case 5:
                {
                    fpv=fopen("viaggi.dat","rb");
                    if(fpv!=NULL)
                    {
                        fseek(fpv,3*sizeof(struct viaggi),0);
                        if(fread(&v,sizeof(struct viaggi),1,fpv)>0)
                        {
                            printf("Codice viaggio: %d\n",v.codice);
                            printf("Data di partenza: %s\n",v.datapart);
                            printf("Destinazione: %s\n",v.destinazione);
                            printf("Data di rientro: %s\n",v.datarientro);
                            printf("Costo: %f\n",v.costo);
                            printf("Codice cliente associato: %d\n",v.codiceV);
                        }
                        else
                        {
                            printf("Non ci sono abbastanza viaggi nel file\n");
                        }
                        fclose(fpv);
                    }
                    break;
                }
                case 6:
                {
                    printf("Uscita dal programma\n");
                    break;
                }
            }
        }
    }while(risp!=6);
    return 0;
}
