#include <stdlib.h>
#include <stdio.h>

#define max_char 20

struct quotas
{
    char * primeiroNome;
    char * ultimoNome;
    char * montantePago;
    struct quotas * next;
} * head;

FILE * fpointer;

void addEntry(char * pn, char * un, char * mp);

int main()
{
    head = NULL;
    addEntry("Test1", "Name1", "0001");
    addEntry("Test2", "Name2", "0002"); // These entries will work as intended

    int i;
    fpointer = fopen("addressbook.txt", "a+b");
    if(fpointer == NULL)
    {
        printf("Erro.\n");
    }

    char primeiro[max_char];
    char ultimo[max_char];
    char montante[max_char];

    while (!feof(fpointer))
    {
        fgets(primeiro, max_char, fpointer);
        fgets(ultimo, max_char, fpointer);
        fgets(montante, max_char, fpointer);

        //Removes newline characters from the ends of the names
        i = 0;
        while(primeiro[i] != '\n')
        {
            i++;
        }
        primeiro[i] = '\0';
        i = 0;
        while(ultimo[i] != '\n')
        {
             i++;
        }
        ultimo[i] = '\0';

        // Adds the entry from the strings with the file data in them
        addEntry(primeiro, ultimo, montante);
    }
    fclose(fpointer);


    return EXIT_SUCCESS;
}

void addEntry(char * pn, char * un, char * mp)
{
    struct quotas *tempNode, *iterator;
    tempNode = malloc(sizeof *tempNode);
    tempNode->primeiroNome = malloc(strlen(pn) + 1);
    tempNode->ultimoNome = malloc(strlen(un) + 1);
    tempNode->montantePago = malloc(strlen(mp) + 1);

    strcpy(tempNode->primeiroNome, pn);
    strcpy(tempNode->ultimoNome, un);
    strcpy(tempNode->montantePago, pn);

    if (head == NULL)
    {
        head = tempNode;
        head->next = NULL;
    }

    else
    {
        while(iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        tempNode->next = NULL;
        iterator->next = tempNode;
    }
}