#include "main.h"

/* Function to remove file already present in backup from file list */
void remove_file_from_SLL(file_t **head, const char *filename)
{
    if (head == NULL || *head == NULL)
        return;

    file_t *temp = *head;
    file_t *prev = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->f_name, filename) == 0)
        {
            if (prev == NULL)
            {
                *head = temp->link;
            }
            else
            {
                prev->link = temp->link;
            }

            free(temp->f_name);
            free(temp);

            return;
        }

        prev = temp;
        temp = temp->link;
    }
}

/* Function to update database using backup file */
int update_DB(hash_t *arr, file_t **files)
{
    char filename[100];

    printf(MAGENTA "\nEnter backup file name : " RESET);

    if (scanf("%99s", filename) != 1)
    {
        printf(RED "ERROR: Invalid input.\n" RESET);
        return FAILURE;
    }

    if (!is_txt_file(filename))
    {
        printf(RED "ERROR: %s is not a .txt file.\n" RESET, filename);
        return FAILURE;
    }

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf(RED "ERROR: Unable to open %s\n" RESET, filename);
        return FAILURE;
    }

    char ch;

    if (fscanf(fptr, "%c", &ch) != 1)
    {
        printf(RED "ERROR: Backup file is empty.\n" RESET);
        fclose(fptr);
        return FAILURE;
    }

    if (ch != '#')
    {
        printf(RED "ERROR: Invalid backup file.\n" RESET);
        fclose(fptr);
        return FAILURE;
    }

    rewind(fptr);

    reset_HT(arr);

    while (1)
    {
        int index;
        char word[100];
        size_t f_count;

        if (fscanf(fptr, " #%d;%99[^;];%zu;",
                   &index,
                   word,
                   &f_count) != 3)
        {
            break;
        }

        if (index < 0 || index > 26)
        {
            printf(RED "ERROR: Corrupted backup file.\n" RESET);
            fclose(fptr);
            return FAILURE;
        }

        main_t *new_main = malloc(sizeof(main_t));

        if (new_main == NULL)
        {
            printf(RED "ERROR: Memory allocation failed.\n" RESET);
            fclose(fptr);
            return FAILURE;
        }

        new_main->word = malloc(strlen(word) + 1);

        if (new_main->word == NULL)
        {
            free(new_main);

            printf(RED "ERROR: Memory allocation failed.\n" RESET);
            fclose(fptr);
            return FAILURE;
        }

        strcpy(new_main->word, word);

        new_main->f_count = f_count;
        new_main->slink = NULL;
        new_main->nlink = NULL;

        sub_t *last_sub = NULL;
                for (size_t i = 0; i < f_count; i++)
        {
            char f_name[100];
            size_t w_count;

            if (fscanf(fptr, "%99[^;];%zu;", f_name, &w_count) != 2)
            {
                printf(RED "ERROR: Corrupted backup file.\n" RESET);
                fclose(fptr);
                return FAILURE;
            }

            remove_file_from_SLL(files, f_name);

            sub_t *new_sub = malloc(sizeof(sub_t));

            if (new_sub == NULL)
            {
                printf(RED "ERROR: Memory allocation failed.\n" RESET);
                fclose(fptr);
                return FAILURE;
            }

            new_sub->f_name = malloc(strlen(f_name) + 1);

            if (new_sub->f_name == NULL)
            {
                free(new_sub);

                printf(RED "ERROR: Memory allocation failed.\n" RESET);
                fclose(fptr);
                return FAILURE;
            }

            strcpy(new_sub->f_name, f_name);

            new_sub->w_count = w_count;
            new_sub->link = NULL;

            if (new_main->slink == NULL)
            {
                new_main->slink = new_sub;
            }
            else
            {
                last_sub->link = new_sub;
            }

            last_sub = new_sub;
        }

        char end;

        if (fscanf(fptr, "%c", &end) != 1 || end != '#')
        {
            printf(RED "ERROR: Invalid backup file format.\n" RESET);
            fclose(fptr);
            return FAILURE;
        }

        if (arr[index].link == NULL)
        {
            arr[index].link = new_main;
        }
        else
        {
            main_t *temp = arr[index].link;

            while (temp->nlink != NULL)
            {
                temp = temp->nlink;
            }

            temp->nlink = new_main;
        }
            }

    fclose(fptr);

    printf(GREEN "\nDatabase restored successfully.\n" RESET);

    return SUCCESS;
}