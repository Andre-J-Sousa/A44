

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Divisao{
	char nomeDiv[50];
	char Sensores[90];
	char Atuadores[90];	
};


void EstruturaCasa(FILE *f){
	
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
