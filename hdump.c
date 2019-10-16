#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define FILEM argv[1]
#define LENGTH 10

int main(int argc, char *argv[])
{
    FILE *fp;
    int i,j,z,t;
    int ch;
    int offset = 0;
    char characters[LENGTH];

/*  Get Screen REsolution */
    struct winsize ws;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    int heigth = ws.ws_col;

    printf(" Offset               Bytes              Characters\n");
    printf("-------- ------------------------------ -----------\n");

    
    if((fp = fopen(FILEM,"rb")) == NULL){
        printf("failed");
        exit(EXIT_FAILURE);
    }

    ch = getc(fp);
    for(i = 0,t = 0;ch != EOF;i++,characters[i] = ch,t++){

        if(t == heigth){
            t = 0;
            printf("Premi un tast per continuare : ");
            getc(stdin);
        }

        printf("\033[0;32m");
        printf("%.8X ",offset);
        printf("\033[0m");
        for(i = 0; i < 10 && ch != EOF; i++){
            printf("\033[0;34m");
            printf("%.2X ",ch);
            printf("\033[0m");
            characters[i] = ch;
            ch = getc(fp);
        }
        z = i;
        for(; i < 10; i++)
            printf("    ");
        printf(" ");

        for(j = 0; j < z; j++){
            printf("\033[0;36m");
            if(!isprint(characters[j]))
                printf(".");
            else
                printf("%c",characters[j]);
            printf("\033[0m");
        }

        printf("\n");
        offset += 10;
    }

    printf("\n");

    fclose(fp);

    return 0;
}
