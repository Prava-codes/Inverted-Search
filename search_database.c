#include "main.h"

/* Function to search a word in the database */
void search_DB(hash_t *arr)
{
    char g_word[100];

    if (Is_HT_empty(arr) == 0)
    {
        printf(RED "\nERROR: Database is empty.\n" RESET);
        return;
    }

    printf(MAGENTA "\nEnter the word to search : " RESET);

    if (scanf("%99s", g_word) != 1)
    {
        printf(RED "ERROR: Invalid input.\n" RESET);
        return;
    }

    int index;

    /* Calculate hash index */
    if (g_word[0] >= 'a' && g_word[0] <= 'z')
    {
        index = g_word[0] - 'a';
    }
    else if (g_word[0] >= 'A' && g_word[0] <= 'Z')
    {
        index = g_word[0] - 'A';
    }
    else
    {
        index = 26;
    }

    if (arr[index].link == NULL)
    {
        printf("\nWord \"%s\" not found.\n", g_word);
        return;
    }

    main_t *m_temp = arr[index].link;

    while (m_temp != NULL)
    {
        if (strcmp(m_temp->word, g_word) == 0)
        {
            printf(CYAN "\n-----------------------------------------------\n" RESET);
            printf("The word " GREEN "%s" RESET " is present in " YELLOW "%zu" RESET " file(s).\n\n",m_temp->word,m_temp->f_count);

            sub_t *s_temp = m_temp->slink;

            while (s_temp != NULL)
            {
                printf(BLUE "In file: " RESET "%s  %zu time(s)\n",s_temp->f_name,s_temp->w_count);

                s_temp = s_temp->link;
            }

            printf(CYAN "-----------------------------------------------\n" RESET);

            return;
        }

        m_temp = m_temp->nlink;
    }

    printf("\nWord \"%s\" not found.\n", g_word);
}