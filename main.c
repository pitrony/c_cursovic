#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include "temp_functions.h"


int main(int argc, char *argv[])// char **argv
{
   int menu_func='1';
    
while ( (menu_func = getopt(argc,argv,"hm:")) != -1)
{
switch (menu_func)
    {
case 'm' :
    /* optarang ?? code */
    printf("found argument \"m = %s\".\n",optarg);
    break;
case 'h' :
    printf("Help");
    break;
case '?': 
    printf("Error found !\n");break;
default:
    break;
    } //swith
} //while

    return 0;
}
//while ( (rez = getopt(argc,argv,"hm:")) != -1){
 //switch (rez){
 //case 'h': printf("found argument \"h\".\n"); break;
 //case 'm': printf("found argument \"m = %s\".\n",optarg); break;
 //case '?': printf("Error found !\n");break;
 //};
 //};
