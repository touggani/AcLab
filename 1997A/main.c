#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    /*
    char test[2];
    char buff;
    int i = 0;
    char depend[2][8];
    int nb_espaces =1;
    char* stock = malloc(sizeof(char)*8);
    FILE* fichier = NULL;
    long position[2];
    fichier = fopen("depend.in","r");
    if(fichier == NULL)
        printf("loose");
    fgets(test,4,fichier);
    printf("%s\n",test);
    if(strcmp(test,"END")==0){
        printf("END\n");
        return 0;
    }if(strcmp(test,"DEP")==0){
        fseek(fichier, 7, SEEK_SET);
        while(buff != '\n'){
            buff=fgetc(fichier);
           // printf("%c\n",buff);
            if(buff==' '){
                position[0] = ftell(fichier)-7;
                fseek(fichier,-position,SEEK_CUR);
                fgets(depend[i],position,fichier);
                nb_espaces++;
                i++;
                fgetc(fichier);
                printf("%s\n",depend[0]);
            }
        }
    position = ftell(fichier);//22
    printf("%ld\n",position);
    }
    if(strcmp(test,"INS")){

    }*/
    FILE* fichier = NULL;
    fichier = fopen("depend.in","r");
    char buf;
    if(fichier == NULL)
        printf("loose");
    for(int i = 0;buf!=EOF;i++){

        buf = fgetc(fichier);

    }



}
