

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Divisao{
	char nomeDiv[50];
	char Sensores[90];
	char Atuadores[90];	
};

struct Divisao casa[5];	//Variável Global array das divisões e respetivos sensores


void EstruturaCasa(FILE *f){
	
	char *str;
	char lido[100];
	int i=0, c;
	
	while(fgets(lido,100,f) != NULL){
		c=0;
		if (lido[strlen(lido)-1]=='\n')	//Confirma se último caracter é \n
			lido[strlen(lido)-1]='\0';	//Remove \n do fim da string lida
		
		str = strtok(lido, ":");
		while (str != NULL){
			//Faz coisas
			{
				switch (c){
					case 0:
						strcpy(casa[i].nomeDiv,str);
					break;
					case 1:
						strcpy(casa[i].Sensores,str);
					break;
					case 2:
						strcpy(casa[i].Atuadores,str);
					break;
					default:
					break;
				}
					
			}		
			str = strtok(NULL, ":");
			c++;
		}	
		i++;
	}		
}


int main(){
	
	char *filename1="SensorConfigurations.txt", *filename2="SensorRules.txt";

	FILE *f1, *f2;
	f1 = fopen(filename1, "r");
	f2 = fopen(filename2, "r");
	if(f1==NULL || f2==NULL){
		if(f1==NULL)
			printf("ERRO!! Ficheiro %s não existe.\n", filename1);
		else if(f2==NULL)
			printf("ERRO!! Ficheiro %s não existe.\n", filename2);
		return 0;
	}else
		printf("Ficheiros encontrados com sucesso!\n\n");
	
	EstruturaCasa(f1);
	
	
	return 1;
}
