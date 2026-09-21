#include "main.h"

/* Function to check whether database is empty */
int Is_HT_empty(hash_t *arr)
{
    for (int i = 0; i < 27; i++)
    {
        if (arr[i].link != NULL)
        {
            return 1;
        }
    }

    return 0;
}

/* Function to display database */
void display_DB(hash_t *arr)
{
    if (Is_HT_empty(arr) == 0)
    {
        printf(RED "\nERROR: Database is empty.\n" RESET);
        return;
    }

    printf(CYAN "\n-----------------------------------------------------------------------------------------------\n" RESET);
    printf(YELLOW "%-8s %-22s %-15s %-22s %-12s\n" RESET,"Index",
                                          "Word",
                                          "File Count",
                                          "File Name",
                                          "Word Count");
    printf(CYAN "-----------------------------------------------------------------------------------------------\n" RESET);

    for (int i = 0; i < 27; i++)
    {
        if (arr[i].link != NULL)
        {
            main_t *m_temp = arr[i].link;

            while (m_temp != NULL)
            {
                sub_t *s_temp = m_temp->slink;

                int first = 1;

                while (s_temp != NULL)
                {
                    if (first)
                    {
                        printf("%-8d " GREEN "%-25s" RESET "%-15zu %-25s %-15zu\n",i,
                                                                m_temp->word,
                                                                m_temp->f_count,
                                                                s_temp->f_name,
                                                                s_temp->w_count);

                        first = 0;
                    }
                    else
                    {
                        printf("%-8s %-25s %-15s %-25s %-15zu\n","","","",
                               s_temp->f_name,
                               s_temp->w_count);
                    }

                    s_temp = s_temp->link;
                }

                printf(CYAN "\n-----------------------------------------------------------------------------------------------\n" RESET);
                m_temp = m_temp->nlink;
            }
        }
    }

    
}