#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 80

typedef struct{
	char nom[TAILLE_MAX];
	char auteur[TAILLE_MAX];
	int etat;
}Livre; 

void get_informations_livre(Livre * livre){
	
	char str[100];
	char * pch;
	int i = 0;
	int info = 0;
	do{ 
		scanf("%s", str);
		pch = strtok (str," ");
		int len = strlen(pch);
		char d[] = " by ";
		char *p = strtok(pch, d);
		
		while(p != NULL)
		{
			//printf("%s\n", p);
			if(info%2 == 0){strcpy(livre[i].nom, p);}
			else{strcpy(livre[i].auteur, p);}
			p = strtok(NULL, d);
			info++;
		}
	}while(strncmp(pch, "end", 3) != 0);


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

void get_informations_etat_livre(Livre * livre){
	char str[100];
	char * pch;
	int i = 0;
	do{ 
		scanf("%s", str);
		pch = strtok (str," ");
		int len = strlen(pch);

		char *p = strtok(pch, d);
		
		while(p != NULL)
		{
			//printf("%s\n", p);
			if(info%2 == 0){strcpy(livre[i].nom, p);}
			else{strcpy(livre[i].auteur, p);}
			p = strtok(NULL, d);
			info++;
		}
	}while(strncmp(pch, "end", 3) != 0);
}


void trier(Livre * livre){
	int y;
	for (int i = 0; i < len(livre); ++i){
		y = i
		while(y<len(livre)){
			if(strcmp(livre[i].auteur, livre[y].auteur) < 0){
				c = livre[i];
				livre[i] = livre[y];
				livre[y] = c;
			}
			y++;
		}
	}
}


int main(){
	Livre livre [100];

	/*get_informations_utilisateur(livre);
	printf("%s\n", livre[0].nom);
	printf("%s\n", livre[0].auteur);*/



	return 0;
}
