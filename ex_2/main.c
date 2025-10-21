#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * get_file(FILE * fp)
{
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL)
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char));
        content = strcat(content, buffer);
    }

    return content;
}

int main()
{
    FILE *fp = fopen("exercice2.txt", "w+");
    char * file_content;

    if (fp == NULL)
    {
        printf("Le fichier n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    
    file_content = get_file(fp);
    fprintf(fp, "Frêre Jacques, frêre Jacques\nDormez-vous, dormez-vous ?\n");
    printf("%s", file_content);

    fclose(fp);
    return 0;
}