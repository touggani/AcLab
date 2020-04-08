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
	scanf("%[^\n]", str);
	pch = strtok (str," ");
	int i = 0;
	if(strncmp (pch,"end",2) != 0){
	while (pch != NULL)
	{
		printf("%s", pch);
		pch = strtok (NULL, " ");
		i++;
	}
	}
	/*char str[] = "Hello Welcome to WayToLearnX best online learning platform";
	int len = strlen(str);
	char d[] = " ";
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
