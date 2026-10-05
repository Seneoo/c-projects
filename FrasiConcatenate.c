#include <stdio.h>
#include <string.h>
int main()
{
FILE *p1,*p2,*p3;
char f1[120],f2[120],f3[120];
printf("Inserisci la prima frase:\n");
scanf(" %[^\n]",f1);
printf("Inserisci la seconda frase\n");
scanf(" %[^\n]",f2);
printf("Inserisci la terza frase:\n");
scanf(" %[^\n]",f3);
p1=fopen("file1.txt","w");
p2=fopen("file2.txt","w");
p3=fopen("file3.txt","w");
fprintf(p1,"%s\n",f1);
fprintf(p2,"%s\n",f2);
fprintf(p3,"%s\n",f3);
fclose(p1);
fclose(p2);
fclose(p3);
//lettura file
p1=fopen("file1.txt","r");
p2=fopen("file2.txt","r");
p3=fopen("file3.txt","r");
fscanf(p1," %[^\n]",f1);
fscanf(p2," %[^\n]",f2);
fscanf(p3," %[^\n]",f3);
printf("Primo file:\n%s",f1);
printf("\nSecondo file:\n%s",f2);
printf("\nTerzo file:\n%s",f3);
fclose(p1);
fclose(p2);
fclose(p3);
//riempire un quarto file
FILE *p4;
p4=fopen("file4.txt","w");
char temp[120];
fprintf(p4,"%s\n",f1);
fprintf(p4,"%s\n",f2);
fprintf(p4,"%s\n",f3);
fclose(p4);
//visualizzazione 4file
p4=fopen("file4.txt","r");
for(int i=0;i<3;i++)
{
    fscanf(p4," %[^\n]",temp);
    printf("\nFILE 4 frase:\n %s",temp);
}
fclose(p4);
//potenziamento 1:conta numero virgole
p1=fopen("file1.txt","r");
int c,conta=0;
while((c=getc(p1))!=EOF)
{
    if(c==',')
    {
        conta++;
    }
}
fclose(p1);
printf("\nVirgole nel file1:%d",conta);
//potenziamento 2:conta spazi
p3=fopen("file3.txt","r");
conta=0;
while((c=getc(p3))!=EOF)
{
    if(c==32)
    {
        conta++;
    }
}
fclose(p3);
printf("\nSpazi nel file3:%d",conta);
//potenziamento 3:conta la parola "di"
p3=fopen("file3.txt","r");
conta=0;
char parola[120];
while(fscanf(p3,"%s",parola)!=EOF)
{
    if(strcmp(parola,"di")==0)
    {
        conta++;
    }
}
fclose(p3);
printf("\nOccorrenze di 'di' nel file3:%d",conta);
}