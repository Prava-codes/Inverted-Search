#include "main.h"

/* Function to save database into backup file */
void save_DB(hash_t *arr)
{
    char file_store[100];

    /* Check whether database is empty */
    if (Is_HT_empty(arr) == 0)
    {
        printf(RED "\nERROR: Database is empty.\n" RESET);
        return;
    }

    printf(MAGENTA "\nEnter backup file name : " RESET);

    if (scanf("%99s", file_store) != 1)
    {
        printf(RED "ERROR: Invalid input.\n" RESET);
        return;
    }

    /* Check whether it is a .txt file */
    if (!is_txt_file(file_store))
    {
        printf(RED "ERROR: %s is not a .txt file.\n" RESET, file_store);
        return;
    }

    FILE *fptr = fopen(file_store, "w");

    if (fptr == NULL)
    {
        printf(RED "ERROR: Unable to create %s.\n" RESET, file_store);
        return;
    }

    /* Traverse hash table */
    for (int i = 0; i < 27; i++)
    {
        if (arr[i].link != NULL)
        {
            main_t *m_temp = arr[i].link;

            while (m_temp != NULL)
            {
                fprintf(fptr, "#%d;%s;%zu;", i,
                        m_temp->word,
                        m_temp->f_count);

                sub_t *s_temp = m_temp->slink;

                while (s_temp != NULL)
                {
                    fprintf(fptr,
                            "%s;%zu;",
                            s_temp->f_name,
                            s_temp->w_count);

                    s_temp = s_temp->link;
                }

                fprintf(fptr, "#\n");

                m_temp = m_temp->nlink;
            }
        }
    }

    fclose(fptr);

    printf(GREEN "\nDatabase saved successfully.\n" RESET);
}