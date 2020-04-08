#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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

int initialisation_station(Station *stations, int nombreStation, float distance){
	char str[100];
	char * pch;

	scanf("%s", str);
	distance = atof(str);

	for(int y = 0;y<nombreStation;y++){
		scanf("%[^\n]", str);
		pch = strtok (str," ");
		int i = 0;
		while (pch != NULL)
		{
			if(i == 0){stations[y].distanceStation = atof(pch);}
			if(i == 1){stations[y].prixGallon = atof(pch);}
			pch = strtok (NULL, " ");
			i++;
		}

	}
	//stations[0].distanceStation = 11.3;
	return 0;
}

int main()
{
    float distance;
	float coutEssenceOrigine[51];
	int nombreStation = 1;

    Station *stations = malloc_station(nombreStation);
    initialisation_station(stations,nombreStation,distance);
    
	
	printf("1: %f\n", stations[0].distanceStation);
	printf("2: %f\n", stations[0].prixGallon);
	printf("distance: %f\n", distance);
    /* Creation de la voiture */
    Voiture voiture;


    return 0;
}







