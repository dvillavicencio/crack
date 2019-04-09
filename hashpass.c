#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "md5.h"
#include "sha256.h"

int main( int argc, char * argv[])
{
    FILE * in = fopen(argv[1], "r");
    FILE * out = fopen(argv[2], "w");
    
    char line[100];
    char word[100];
    char * hash;
    
    while(fgets(line, 100, in) != NULL)
    {
        for(int i = 0; i < strlen(line); i++)
        {
            if(line[i] != 10) word[i] = line[i];
        }
        hash = md5(word, strlen(word));
        fprintf(out, "%s\n", hash);
        memset(word, 0, strlen(word));
        free(hash);
        
    }
    fclose(in);
    fclose(out);
}