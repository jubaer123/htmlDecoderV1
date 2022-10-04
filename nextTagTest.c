//nextTagTest.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

#define MAX_CHAR 100001

void loadChar(char* fileChar){
    int max_char=MAX_CHAR;
    char * buffer=fileChar;
    while (fgets(buffer, max_char, stdin) != NULL){
        buffer=(fileChar+strlen(fileChar));s
        max_char=MAX_CHAR-strlen(fileChar);
    }
}

int main(){
    char* fileChar=(char*) malloc(MAX_CHAR);
    loadChar(fileChar);
    if(fileChar==NULL)
        return EXIT_FAILURE;
    int pos=0;
    char* ntag=readNextTag(fileChar,&pos);
    while(ntag!=NULL){
        printf("%s\n",ntag);
        ntag=readNextTag(fileChar,&pos);
    }
    return EXIT_SUCCESS;
}