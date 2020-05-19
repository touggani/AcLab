#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 80

typedef struct{
	char nom[TAILLE_MAX];
	char auteur[TAILLE_MAX];
	char etat[10];
}Livre; 

int lireFichier(Livre * livre){
	FILE* fichier = NULL;
    fichier = fopen("livre.txt","r");
    const char * separator1 = " ";const char * separator2 = " by ";
    int i = 0;int y = 0;
    char stck[TAILLE_MAX][TAILLE_MAX];
    
    if (fichier != NULL)
    {
        char ligne[81] ;
		while ( fgets(ligne, 81, fichier) != NULL ){ /*fin de fichier non atteinte*/
		    char * strToken = strtok ( ligne, separator1 );

		    if(strcmp(strToken, "BORROW") == 0 || strcmp(strToken, "RETURN") == 0 || strcmp(strToken, "SHELVE") == 0){
		    	//livre[i].etat = strToken;
		    	strncpy(livre[i].etat, strToken, 10);
		    	strToken = strtok ( NULL, separator1 );
		    	while ( strToken != NULL) {
		    		strncpy(stck[y], strToken, 10);
		    		strcat(livre[i].nom,stck[y]);
		    		strcat(livre[i].nom," ");
		    		strToken = strtok ( NULL, separator1 );
		    		y++;
		    	}
		    }	 
		    else{
		    	char * strToken = strtok ( ligne, separator1 );
		    	/*strncpy(stck[y], strToken, 10);
		    	strToken = strtok ( NULL, separator2 );*/
		    	while ( strToken != NULL) {
		    		/*strToken = strtok ( NULL, separator2 );
		    		strncpy(stck[y], strToken, 10);
		    		strcat(livre[i].auteur,stck[y]);*/
		    		printf("%s\n", strToken);
		    		strToken = strtok ( NULL, separator1 );
		    	}
		    } 
		    i++;      
    	}
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }

    return 0;
}

void get_informations_etat_livre(Livre * livre){
	
}


// void trier(Livre * livre){
// 	int y;
// 	Livre c;
// 	for (int i = 0; i < len(livre); ++i){
// 		y = i;
// 		while(y<len(livre)){
// 			if(strcmp(livre[i].auteur, livre[y].auteur) < 0){
// 				c = livre[i];
// 				livre[i] = livre[y];
// 				livre[y] = c;
// 			}
// 			y++;
// 		}
// 	}
// }


int main(){
	Livre livre [100];
	lireFichier(livre);
	/*get_informations_utilisateur(livre);
	printf("%s\n", livre[0].nom);
	printf("%s\n", livre[0].auteur);*/

	//printf("%s\n", livre[0].etat);
	//printf("%s\n", livre[0].nom);
	return 0;
}
