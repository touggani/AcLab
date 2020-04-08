#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 80

typedef struct{
	char nom[TAILLE_MAX];
	char auteur[TAILLE_MAX];
	int etat;
}Livre; 

void get_informations_utilisateur(){
	
	char str[100];
	char * pch;

	
	
	do{ 
		scanf("%s", str);
		scanf("%[^\n]", str);
		pch = strtok (str," ");
		int len = strlen(pch);
		char d[] = " ";
		char *p = strtok(pch, d);
		while(p != NULL)
		{
			printf("'%s'\n", p);
			p = strtok(NULL, d);
		}
	}while(strncmp(pch, "end", 2) != 0);


	/*char str[] = "Hello by Welcome";
	int len = strlen(str);
	char d[] = " by ";
	char *p = strtok(str, d);
	while(p != NULL)
	{
		printf("'%s'\n", p);
		p = strtok(NULL, d);
	}*/
}


int main(){

	get_informations_utilisateur();

	return 0;
}
