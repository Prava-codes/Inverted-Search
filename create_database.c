#include "main.h"

/* Function to create database using file list */
int create_DB(hash_t *arr, file_t *file_head)
{
    if (file_head == NULL)
    {
        printf(RED "ERROR: File list is empty.\n" RESET);
        return FAILURE;
    }

    file_t *f_temp = file_head;

    while (f_temp != NULL)
    {
        FILE *fptr = fopen(f_temp->f_name, "r");

        if (fptr == NULL)
        {
            printf(RED "ERROR: Unable to open %s\n" RESET, f_temp->f_name);
            f_temp = f_temp->link;
            continue;
        }

        char word[100];

        while (fscanf(fptr, "%99s", word) == 1)
        {
            if (strlen(word) == 0)
                continue;

            int index;

            if (word[0] >= 'a' && word[0] <= 'z')
            {
                index = word[0] - 'a';
            }
            else if (word[0] >= 'A' && word[0] <= 'Z')
            {
                index = word[0] - 'A';
            }
            else
            {
                index = 26;
            }

            main_t *m_temp = arr[index].link;
            main_t *prev_main = NULL;

            while (m_temp != NULL)
            {
                if (strcmp(m_temp->word, word) == 0)
                    break;

                prev_main = m_temp;
                m_temp = m_temp->nlink;
            }

            if (m_temp == NULL)
            {
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

                new_main->f_count = 1;
                new_main->nlink = NULL;
                                sub_t *new_sub = malloc(sizeof(sub_t));

                if (new_sub == NULL)
                {
                    free(new_main->word);
                    free(new_main);

                    printf(RED "ERROR: Memory allocation failed.\n" RESET);
                    fclose(fptr);
                    return FAILURE;
                }

                new_sub->f_name = malloc(strlen(f_temp->f_name) + 1);

                if (new_sub->f_name == NULL)
                {
                    free(new_sub);
                    free(new_main->word);
                    free(new_main);

                    printf(RED "ERROR: Memory allocation failed.\n" RESET);
                    fclose(fptr);
                    return FAILURE;
                }

                strcpy(new_sub->f_name, f_temp->f_name);

                new_sub->w_count = 1;
                new_sub->link = NULL;

                new_main->slink = new_sub;

                if (prev_main == NULL)
                {
                    arr[index].link = new_main;
                }
                else
                {
                    prev_main->nlink = new_main;
                }
            }
            else
            {
                sub_t *s_temp = m_temp->slink;
                sub_t *prev_sub = NULL;

                while (s_temp != NULL)
                {
                    if (strcmp(s_temp->f_name, f_temp->f_name) == 0)
                    {
                        break;
                    }

                    prev_sub = s_temp;
                    s_temp = s_temp->link;
                }

                if (s_temp == NULL)
                {
                    sub_t *new_sub = malloc(sizeof(sub_t));

                    if (new_sub == NULL)
                    {
                        printf(RED "ERROR: Memory allocation failed.\n" RESET);
                        fclose(fptr);
                        return FAILURE;
                    }

                    new_sub->f_name = malloc(strlen(f_temp->f_name) + 1);

                    if (new_sub->f_name == NULL)
                    {
                        free(new_sub);

                        printf(RED "ERROR: Memory allocation failed.\n" RESET);
                        fclose(fptr);
                        return FAILURE;
                    }

                    strcpy(new_sub->f_name, f_temp->f_name);

                    new_sub->w_count = 1;
                    new_sub->link = NULL;
                                        if (prev_sub == NULL)
                    {
                        m_temp->slink = new_sub;
                    }
                    else
                    {
                        prev_sub->link = new_sub;
                    }

                    m_temp->f_count++;
                }
                else
                {
                    /* Word already exists in same file */
                    s_temp->w_count++;
                }
            }
        }

        fclose(fptr);

        printf(GREEN "\nINFO : Successful : Creation of DATABASE for file: %s\n" RESET,f_temp->f_name);

        f_temp = f_temp->link;
    }

    printf(GREEN "\nDatabase created successfully.\n" RESET);

    return SUCCESS;
}