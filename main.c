#include "main.h"

int main(int argc, char *argv[])
{
    hash_t arr[27];
    reset_HT(arr);

    file_t *file_name = NULL;


    if (validate_Files(&file_name, argc, argv) == FAILURE)
    {
        return FAILURE;
    }

    /* Print File Linked List */
    print_file_list(file_name);

    int create_flag = 0;
    int update_flag = 0;

    int choice;
    char option;

    do
    {
        printf("\n");
        printf(BLUE "=========================================\n");
        printf("      INVERTED SEARCH DATABASE\n");
        printf("=========================================\n" RESET);
        printf(YELLOW "1. Create Database\n");
        printf("2. Search Database\n");
        printf("3. Display Database\n");
        printf("4. Save Database\n");
        printf("5. Update Database\n");
        printf("6. Exit\n" RESET);
        printf(BLUE "=========================================\n" RESET);

        printf(MAGENTA "Enter your choice : " RESET);

        if (scanf("%d", &choice) != 1)
        {
            printf(RED "ERROR : Invalid input.\n" RESET);

            while (getchar() != '\n');

            continue;
        }

        switch (choice)
        {
            case 1:

                if (create_flag)
                {
                    printf(RED "\nERROR : Database already created.\n" RESET);
                    break;
                }

                if (create_DB(arr, file_name) == SUCCESS)
                {
                    create_flag = 1;
                }

                break;

            case 2:

                search_DB(arr);

                break;

            case 3:

                display_DB(arr);

                break;

            case 4:

                save_DB(arr);

                break;
            case 5:

              /* Database already updated */
              if (update_flag)
              {
                  printf(RED "\nERROR : Database already updated.\n" RESET);
                  break;
              }

              /* Database already created */
              if (create_flag)
              {
                  printf(RED "\nERROR : Database already created. Update operation is not allowed.\n" RESET);
                  break;
              }

              if (update_DB(arr, &file_name) == SUCCESS)
              {
                  update_flag = 1;
              }

              break;
            case 6:

                free_file_list(file_name);

                printf(GREEN "\nSUCCESS : All resources released successfully. Exiting Inverted Search Database...\n\n" RESET);


                return SUCCESS;

            default:

                printf(RED "\nERROR : Invalid choice.\n" RESET);
        }

        printf(MAGENTA "\nDo you want to continue? (Y/N) : " RESET);

        scanf(" %c", &option);

        while (option != 'Y' && option != 'y' &&
               option != 'N' && option != 'n')
        {
            printf(RED "ERROR : Enter only Y or N : " RESET);
            scanf(" %c", &option);
        }
            } while (option == 'Y' || option == 'y');

    free_file_list(file_name);

    return SUCCESS;
}
        
