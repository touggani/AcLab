#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OUT    0 
#define IN    1 



typedef struct
{
    float capaciteReservoir;
    float kilometreParGallon;
    float niveauReservoir;
} Voiture;

typedef struct
{
    float distanceStation;
    float prixGallon;   
} Station;

typedef struct
{
	float distanceVoyage;
    Station * stations;
    Voiture voiture;  
} Voyage;


Station* malloc_station(int nombreStation){
	Station *stations;
    stations = (Station *)malloc(sizeof(Station)*nombreStation);
    return stations;
}

void liberer_memoire(){}

/* Distance résalisable avec la quantite de gallon dans le reservoir */
float distance_faisable(Voiture voiture){
    return voiture.niveauReservoir * voiture.kilometreParGallon;
}





unsigned compterMotParLigne(char *str) 
{ 
    int etat = OUT; 
    unsigned nb = 0;
  
    while (*str){  
        if(*str == ' ' || *str == '\n' || *str == '\t') 
            etat = OUT; 
        else if (etat == OUT){ 
            etat = IN; 
            ++nb; 
        } 
        ++str; 
    } 
    return nb; 
} 

int getNombreVoyage(){
	FILE* fichier = NULL;
    fichier = fopen("DetailVoyage.txt","r");
    int cmp = 0;

    if (fichier != NULL)
    {
        char ligne[81] ;
		while ( fgets(ligne, 81, fichier) != NULL ){ 
			int nbmot = compterMotParLigne(ligne);
		    if(nbmot == 1){cmp += 1;}
        }
        fclose(fichier); 
    }
    return cmp;
}

int lecture_fichier(Voyage *listeVoyage, int nbVoyage){
	FILE* fichier = NULL;
    fichier = fopen("DetailVoyage.txt","r");
    const char * separators = " ";
    int i = 0;
    int y = 0;
    int istation = 0;
    
    if (fichier != NULL)
    {
        char ligne[81] ;
		while ( fgets(ligne, 81, fichier) != NULL ){ /*fin de fichier non atteinte*/
			int nbmot = compterMotParLigne(ligne);
		    char * strToken = strtok ( ligne, separators );
		    
	        if(nbmot == 1){
	        	listeVoyage[i].distanceVoyage = (float)strtod(strToken,NULL);
	        	istation = 0;
	        }
	        
	        

		        else if(nbmot == 2){
		        	listeVoyage[i].stations = malloc(sizeof(Station)*7);
		        	while ( strToken != NULL ) {
		        		printf("%f\n", (float)strtod(strToken,NULL));
		        		if(istation%2){listeVoyage[i].stations[istation].distanceStation = (float)strtod(strToken,NULL);}
		        		else{listeVoyage[i].stations[istation].prixGallon = (float)strtod(strToken,NULL);}
		        		strToken = strtok ( NULL, separators );
		        	}
		        	istation++;
		        }
		        else if(nbmot == 4){
		        	while ( strToken != NULL ) {
		        		if(y == 0){listeVoyage[i].voiture.capaciteReservoir = (float)strtod(strToken,NULL);}
		        		else if(y == 1){listeVoyage[i].voiture.kilometreParGallon = (float)strtod(strToken,NULL);}
		        		else if(y == 2){listeVoyage[i].voiture.niveauReservoir = (float)strtod(strToken,NULL);}
		        		strToken = strtok ( NULL, separators );
		        		y++;
		        	}
		        	y = 0;
		        }
	    	}
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }

    return 0;
}









int main()
{
    /*float distance;
	float coutEssenceOrigine[51];
	int nombreStation = 1;

    Station *stations = malloc_station(nombreStation);    
	
	printf("1: %f\n", stations[0].distanceStation);
	printf("2: %f\n", stations[0].prixGallon);
	printf("distance: %f\n", distance);*/
    /* Creation de la voiture */

    int nbVoyage = getNombreVoyage();
    Voyage *listeVoyage = malloc(sizeof(Voyage)*nbVoyage);
	lecture_fichier(listeVoyage, nbVoyage);

	printf("%f\n", listeVoyage[0].voiture.capaciteReservoir);
	printf("%f\n", listeVoyage[0].stations[0].distanceStation);
	printf("%f\n", listeVoyage[0].stations[0].prixGallon);


    return 0;
}







