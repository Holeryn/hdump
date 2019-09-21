#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILEM argv[1]
#define LENGTH 10

int main(int argc, char *argv[])
{
    FILE *fp;
    int i,j,z;
    int ch;
    int offset = 0;
    char characters[LENGTH];

    printf(" Offset               Bytes              Characters\n");
    printf("-------- ------------------------------ -----------\n");

    
    if((fp = fopen(FILEM,"rb")) == NULL){
        printf("failed");
        exit(EXIT_FAILURE);
    }

    ch = getc(fp);
    for(i = 0;ch != EOF;i++,characters[i] = ch){
        printf("%.8X ",offset);
        for(i = 0; i < 10 && ch != EOF; i++){
            printf("%.2X ",ch);
            characters[i] = ch;
            ch = getc(fp);
        }
        z = i;
        for(; i < 10; i++)
            printf("    ");
        printf(" ");

        for(j = 0; j < z; j++){
            if(!isprint(characters[j]))
                printf(".");
            else
                printf("%c",characters[j]);
        }

        printf("\n");
        offset += 10;
    }

    printf("\n");

    fclose(fp);

    return 0;
}