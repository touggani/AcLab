#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    unsigned nb = 0;  // word count 
  
    // Scan all characters one by one 
    while (*str) 
    { 
        // If next character is a separator, set the  
        // state as OUT 
        if (*str == ' ' || *str == '\n' || *str == '\t') 
            etat = OUT; 
  
        // If next character is not a word separator and  
        // state is OUT, then set the state as IN and  
        // increment word count 
        else if (etat == OUT) 
        { 
            etat = IN; 
            ++nb; 
        } 
  
        // Move to next character 
        ++str; 
    } 
  
    return nb; 
} 

int lecture_fichier(){
	FILE* fichier = NULL;
    fichier = fopen("DetailVoyage.txt","r");
    const char * separators = " ";

    if (fichier != NULL)
    {
        char ligne[81] ;
		/* le fichier est supposé ouvert en mode "rt" */
		while ( fgets(ligne, 81, fichier) != NULL ){ /*fin de fichier non atteinte*/
			int nbmot = compterMotParLigne(ligne);
		    char * strToken = strtok ( ligne, separators );
		    while ( strToken != NULL ) {
		        if(nbmot == 1){

		        }
		        if(nbmot == 2){

		        }
		        if(nbmot == 4)
		        // On demande le token suivant.
		        strToken = strtok ( NULL, separators );
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
    Voyage voyage;


    lecture_fichier(voyage);


    return 0;
}







