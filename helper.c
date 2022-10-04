//helper.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"

void doProcess(char fileChar,int *size,char **tags,int *count){
    int pos=0;
    char* ntag=readNextTag(fileChar,&pos);
    while(ntag!=NULL){
        bool is=false;
        int i;
        for(i=0; i<*size; i++)
            if(strcmp(*(tags+i),ntag)==0){
                *(count+i)= *(count+i)+1;
                is=true;
                break;
            }
        if(!is){
            *(tags+*size)=ntag;
            *(count+*size)=1;
            *size=*size+1;
        }
        ntag=readNextTag(fileChar,&pos);
    }
}
char* readNextTag(char *fileChar, int *pos){
    bool read=false;
    //we can use folwing lines which are commented out if 100 is not enough for a tag size;
    char *s=(char*)malloc(101);//char s=(char)malloc(1001);
    int temp=0;
    while(*pos < (int)strlen(fileChar)){
        if(read==true){
            *(s+temp)=*(fileChar+*pos);
            temp++;
            if(*(fileChar+(*pos+1))=='>' || *(fileChar+(*pos+1))== ' ' || 
                    *(fileChar+(*pos+1)) == '/'){
                *pos = *pos+1;
                *(s+temp)='\0';
                //char* s1=malloc(strlen(s)+1);
                //s1=s;
                return s;//return s1;
            }
        }
    else if(*(fileChar+*pos)=='<' && ((*(fileChar+(*pos+1)))== '!') ){
        int a=1;
        while(a>0){
        *pos=*pos+1;
            if(*(fileChar+*pos)=='<')
            a++;
        else if(*(fileChar+*pos)=='>')
            a--;
        }
    }
        else if(*(fileChar+*pos)=='<' && !((*(fileChar+(*pos+1)))=='/')){
            read=true;
        }
        *pos = *pos+1;      
    }

    return NULL;
}
