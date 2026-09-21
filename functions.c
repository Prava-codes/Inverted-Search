#include "main.h"

/* Function to initialize hash table */
void reset_HT(hash_t *arr)
{
    for (int i = 0; i < 27; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
}

/* Function to check whether file has .txt extension */
int is_txt_file(const char *filename)
{
    char *ext = strrchr(filename, '.');

    if (ext != NULL && strcmp(ext, ".txt") == 0)
        return 1;

    return 0;
}

/* Function to check duplicate filename */
int is_dupicate_file(file_t *head, const char *filename)
{
    while (head != NULL)
    {
        if (strcmp(head->f_name, filename) == 0)
            return 1;

        head = head->link;
    }

    return 0;
}

/* Function to check whether file is empty */
int is_file_empty(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);

    long size = ftell(fptr);

    rewind(fptr);

    if (size <= 0)
        return 1;

    return 0;
}

/* Function to validate command line files */
int validate_Files(file_t **file_name, int argc, char *argv[])
{
    if (argc < 2)
    {
        printf(RED "ERROR : No input files provided.\n" RESET);
        printf("Usage : ./a.out file1.txt file2.txt ...\n");
        return FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        /* Check .txt extension */
        if (!is_txt_file(argv[i]))
        {
            printf(RED "\nERROR : %s is not a .txt file.\n" RESET, argv[i]);
            continue;
        }

        /* Check duplicate file */
        if (is_dupicate_file(*file_name, argv[i]))
        {
            printf(RED "\nERROR : %s is repeated, so it will not store into sll\n" RESET, argv[i]);
            continue;
        }
        printf("\n");

        FILE *fptr = fopen(argv[i], "r");

        if (fptr == NULL)
        {
            printf(RED "ERROR : File '%s' does not exist in the current directory.\n" RESET, argv[i]);
            continue;
        }

        /* Check empty file */
        if (is_file_empty(fptr))
        {
            printf(RED "ERROR : File '%s' is empty.\n" RESET, argv[i]);
            fclose(fptr);
            continue;
        }

        fclose(fptr);

        /* Create new node */
        file_t *new = malloc(sizeof(file_t));

        if (new == NULL)
        {
            printf(RED "ERROR : Memory allocation failed.\n" RESET);
            return FAILURE;
        }

        new->f_name = malloc(strlen(argv[i]) + 1);

        if (new->f_name == NULL)
        {
            free(new);
            printf(RED "ERROR : Memory allocation failed.\n" RESET);
            return FAILURE;
        }

        strcpy(new->f_name, argv[i]);
        new->link = NULL;

        /* Insert node */
        if (*file_name == NULL)
        {
            *file_name = new;
        }
        else
        {
            file_t *temp = *file_name;

            while (temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = new;
        }

        printf(GREEN "\nINFO : File '%s' inserted into the file linked list successfully.\n" RESET, argv[i]);
    }
    
        if (*file_name == NULL)
    {
        printf(RED "\nERROR : No valid input files found. Database cannot be created.\n" RESET);
        return FAILURE;
    }

    printf(GREEN "\nSUCCESS :  All valid files have been added to the file linked list successfully.\n" RESET);

    return SUCCESS;
}


/* Function to free file linked list */
void free_file_list(file_t *head)
{
    file_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->link;

        free(temp->f_name);
        free(temp);
    }
}

/* Function to print file linked list */
void print_file_list(file_t *head)
{
    if (head == NULL)
    {
        printf(RED "INFO : File linked list is empty.\n" RESET);
        return;
    }

    file_t *temp = head;

    printf(CYAN "\nHead -> " RESET);

    while (temp != NULL)
    {
        printf(CYAN "%s -> " RESET, temp->f_name);
        temp = temp->link;
    }

    printf(CYAN "NULL\n" RESET);
}