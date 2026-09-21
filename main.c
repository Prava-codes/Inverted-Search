/*
Name: T.PRAVALLIKA
Roll_no: 25048_038
Submission Date: 10/07/2026
Project name : Inverted Search
Title : Design and Implementation of an Inverted Search Database Using Hash Tables and Linked Lists in C
*/


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
        
/*

1. PROJECT DESCRIPTION :

* The Inverted Search project is a command-line application developed in C using Data Structures. 
* It creates an inverted index from multiple text files, allowing users to search words efficiently without scanning every file repeatedly.
* The project uses a Hash Table, Main Linked List, and Sub Linked List to organize words, file names, and their occurrence counts.
* It also supports displaying, searching, saving, and restoring the database.

2. OBJECTIVE :

* Develop an efficient word searching system.
* Reduce search time using hashing.
* Store unique words along with file information.
* Support multiple text files.
* Implement database creation, display, search, save, and update operations.
* Understand the practical implementation of Data Structures in C.

3. PROBLEM STATEMENT :

Searching for a word by opening and scanning every text file is time-consuming, especially when the number of files is large. 
This project solves the problem by creating an inverted index, where each word stores the list of files in which it appears along with the number of occurrences. 
This significantly reduces search time and improves efficiency.

4. FEATURES :

* Validates input text files.
* Detects duplicate files.
* Ignores empty files.
* Creates an inverted database using hashing.
* Displays the complete database.
* Searches any word efficiently.
* Saves the database into a backup file.
* Restores the database from the backup file.
* Uses dynamic memory allocation.
* User-friendly menu-driven interface.

5. TECHNOLOGIES USED :

* C Language                --> Project implementation
* GCC Compiler              --> Code compilation
* File Handling	            --> Reading and writing files
* Dynamic Memory Allocation --> Creating nodes dynamically
* Hash Table                --> Fast indexing
* Linked Lists              --> Database storage
* VS Code                   --> Development environment

6. DATA STRUCTURES USED :

## HASH TABLE

* Contains 27 indexes (A–Z and Others).
* Stores pointers to the main linked list.
* Reduces searching time.

## FILE LINKED LIST

* Stores all validated input file names.
* Used while creating the database.

## MAIN LINKED LIST

Stores:
* Word
* Number of files containing the word
* Pointer to Sub List
* Pointer to next word

## SUB LINKEDLIST

Stores:
* File name
* Word occurrence count
* Pointer to next file

7. PROJECT ARCHITECTURE :

Input Files
│     
▼    
File Validation
│
▼
Create File List
│
▼
Read Words
│
▼
Generate Hash Index
│
▼
Create Inverted Database
│
▼
+----------------------------------+
| Display | Search | Save | Update |
+----------------------------------+


8. WORKING PRINCIPLE :

1. Read input text files through command-line arguments.
2. Validate all files.
3. Store valid filenames in a linked list.
4. Read each word from every file.
5. Calculate the hash index using the first character.
6. Insert the word into the hash table.
7. Update file information if the word already exists.
8. Display, search, save, or update the database based on user choice.


9. PROJECT STRUCTURE :

* main.c	         -->  Controls program execution, menu, and function calls.
* main.h	         -->  Contains structures, macros, and function prototypes.
* functions.c	     -->  Implements hash table initialization, file validation, linked list operations, and common utility functions.
* create_database.c	 -->  Reads words from files and builds the inverted database using hash table and linked lists.
* display_database.c -->  Displays the complete database in a formatted table.
* search_database.c	 -->  Searches a word and displays the files where it appears along with occurrence counts.
* save_database.c	 -->  Saves the database into a backup text file.
* update_database.c	 -->  Restores the database from a previously saved backup file.


10. SAMPLE EXECUTION :

## Step 1: Compile the Project

gcc *.c

## Step 2: Run the Project

./a.out file1.txt file2.txt file3.txt

## Step 3: Select Operations from the Menu

1. Create Database
2. Search Database
3. Display Database
4. Save Database
5. Update Database
6. Exit

## Step 4: Create Database

Enter your choice : 1

## Step 5: Search a Word

Enter your choice : 2
Enter the word to search : pravallika

## Step 6: Display Database

Enter your choice : 3

## Step 7: Save Database

Enter your choice : 4
Enter backup file name : database.txt

## Step 8: Update Database

Enter your choice : 5
Enter backup file name : database.txt

## Step 9: Exit

Enter your choice : 6


11. ADVANTAGES :

* Fast word searching.
* Efficient use of hashing.
* Supports multiple text files.
* Reduces repeated file scanning.
* Modular and easy to maintain.
* Backup and restore support.

12. APPLICATIONS :

* Search engines
* Digital libraries
* Document indexing
* File search utilities
* Log file analysis
* Text processing systems
* Information retrieval systems

13. CONCLUSION :

* The Inverted Search project demonstrates the practical use of Data Structures to build an efficient word indexing system. 
* By combining Hash Tables, Linked Lists, and File Handling, the project enables fast searching, organized storage, and efficient retrieval of words across multiple files. 
* It also provides backup and restore functionality, making it a complete and practical implementation of an inverted indexing system.

*/