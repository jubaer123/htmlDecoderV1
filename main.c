//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

#define MAX_CHAR 100001

void loadChar(char* fileChar){
    int max_char=MAX_CHAR;
    char * buffer=fileChar;
    while (fgets(buffer, max_char, stdin) != NULL){
        buffer=(fileChar+strlen(fileChar));
        max_char=MAX_CHAR-strlen(fileChar);
    }
}

int main(){
    char* fileChar=(char*) malloc(MAX_CHAR);
    loadChar(fileChar);
    char** tags=(char**)malloc(100001);
    int* count=(int*)calloc(100,sizeof(int));
    int size=0;
    doProcess(fileChar, &size,tags,count);  //******HERE (fileChar, &size,&tags,&count)****
    free(fileChar);
    for(int i=0; i<size; i++)
        printf("%s\t\t\t%d\n",*(tags+i),*(count+i));
    free(tags);
    free(count);
    return EXIT_SUCCESS;
}