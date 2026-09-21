# Inverted-Search-in-C

## DESCRIPTION

The Inverted Search project is a data-structure-based application developed in C to create and manage an inverted index from multiple text files.

The application accepts multiple .txt files through command-line arguments and stores information about the words present in those files. A hash table is used to organize words based on their first character, while linked lists are used to maintain words, filenames, and word-frequency information.

The project provides operations to create, search, display, save, and update the database. It also includes file validation, duplicate-file checking, dynamic memory allocation, and error handling.



## PROBLEM STATEMENT

Searching for a particular word across multiple text files can become inefficient when each file has to be searched separately every time.

The objective is to create an inverted index that stores information in the following form:

Word → Files containing the word → Number of occurrences

For example:

apple
  |
  ├── file1.txt → 3 occurrences
  
  ├── file2.txt → 2 occurrences
  
  └── file3.txt → 5 occurrences

This structure allows the application to directly access the information associated with a word instead of repeatedly scanning all input files.    



## OBJECTIVE

The main objectives of this project are:

- To implement an inverted index using C data structures.
  
- To use a hash table for organizing words.
  
- To use linked lists for storing word and file information.
  
- To maintain the frequency of each word in different files.
  
- To search words efficiently in the generated database.
  
- To save the database into a backup file.
  
- To restore the database from a previously saved backup file.
  
- To practice dynamic memory allocation and file handling.
  
- To implement a menu-driven database application.
  


## FEATURES

- Accepts multiple .txt files through command-line arguments.
  
- Validates input files before processing.

- Maintains valid input files using a file linked list.
  
- Creates an inverted database using a hash table.
  
- Stores unique words using linked lists.
  
- Stores filenames and word frequencies.
  
- Supports word searching.
  
- Displays the complete database in a formatted table.
  
- Saves the database to a backup .txt file.
  
- Restores the database from a backup file.
  
- Uses dynamic memory allocation.
  
- Provides error messages for invalid operations.
  
- Uses colored terminal output for better readability.



## TECHNOLOGIES USED

- C                          ->	Core programming language
  
- GCC	                       ->  Compilation
  
- File Handling              ->	Reading input files and storing database backups
  
- Dynamic Memory Allocation	 -> Creating linked-list nodes dynamically
  
- Command-Line Arguments	   -> Passing input text files to the program



## DATA STRUCTURES USED

### Hash Table

A hash table containing 27 indexes is used.

Index 0  → A/a

Index 1  → B/b

Index 2  → C/c

...

Index 25 → Z/z

Index 26 → Other characters

The first character of each word is used to determine its hash index.

### Main Linked List

Each hash-table index points to a linked list containing unique words.

Hash Index
    |
    v
 apple → ant → animal → NULL

Each main node stores:

- Word

- Number of files containing the word

- Pointer to the sub linked list

- Pointer to the next main node

### Sub Linked List

Each main node contains a sub linked list that stores file-related information.

apple
  |
  v
file1.txt → file2.txt → file3.txt
    |           |           |
    3           2           5

Each sub node stores:

- Filename

- Number of occurrences of the word

- Pointer to the next sub node

### File Linked List

The valid input files are maintained separately in a linked list.

file1.txt → file2.txt → file3.txt → NULL

This list is used while creating and updating the database.



## OPERATIONS

- Create Database
  
- search Database

- Display database

- Save Database

- Update Database



## PROJECT WORKFLOW

1. Accept input .txt files through command-line arguments.
   
2. Validate files – check extension, existence, duplicates, and empty files.

3. Store valid files in a file linked list.

4. Create the inverted database using a 27-index hash table.

5. Store unique words in the main linked list.

6. Store filename and word frequency in the sub linked list.

7. Search words using the hash index and linked-list traversal.

8. Display the database with word, file count, filename, and frequency.

9. Save the database into a backup .txt file.

10. Update/restore the database from the saved backup file.

11. Release allocated memory and exit safely.



## PROJECT STRUCTURE

Inverted-Search/ │ 

├── main.h 

├── main.c 

├── functions.c 

├── createdatabase.c 

├── searchdatabase.c 

├── displaydatabase.c 

├── savedatabase.c 

├── updatedatabase.c 

├── file1.txt 

├── file2.txt 

├── file3.txt 

│ └── README.md



## FILES DESCRIPTION

### main.h

Contains:

- Header files
  
- Return-value macros
  
- Terminal color macros
  
- Structure definitions
  
- Function declarations
  
### main.c

Contains : 

- Initializes the hash table.
  
- Validates command-line files.
  
- Displays the file linked list.
  
- Displays the main menu.
  
- Handles user choices.
  
- Calls database functions.

- Releases resources before exiting.
  
### functions.c

Contains common and file-validation functions.

- Hash-table initialization
  
- Checking whether the database is empty
  
- .txt file validation
  
- Duplicate-file checking
  
- Empty-file checking
  
- File-list creation
  
- File-list display
  
- File-list memory cleanup
  
### create database .c

Responsible for creating the inverted database.

- Reads words from input files.

- Calculates hash indexes.

- Creates main nodes.

- Creates sub nodes.

- Maintains file counts.

- Maintains word-frequency counts.

### search database .c

Responsible for searching words in the database.

It displays:

- Searched word

- Number of files containing the word

- Filename

- Number of occurrences

### display database .c

Responsible for displaying the complete database in a formatted table.

It traverses:

Hash Table
    ↓
Main Linked List
    ↓
Sub Linked List

### save database .c

Responsible for saving the generated database into a backup .txt file.

It stores:

- Hash index

- Word

- File count

- Filename

- Word count

### update database .c

Responsible for restoring the database from a saved backup file.

It:

- Validates the backup file.

- Reads stored database information.

- Recreates main nodes.

- Recreates sub nodes.

- Restores the hash table.

- Updates the file linked list.



## COMPILATION

### Compile all source files using GCC:

gcc *.C



## EXECUTION

Run the application by passing one or more .txt files through command-line arguments:

./a.out file1.txt file2.txt file3.txt

Example:

./a.out data1.txt data2.txt data3.txt

The program then validates the files and displays the Inverted Search Database menu.



## Sample Input

Command-Line Input

./a.out file1.txt file2.txt file3.txt

Suppose file1.txt contains:

apple mango apple

file2.txt contains:

apple orange mango

file3.txt contains:

mango apple apple

### Menu Input

Enter your choice : 1

To search:

Enter your choice : 2

Enter the word to search : apple



## Sample Output

File Linked List

Head -> file1.txt -> file2.txt -> file3.txt -> NULL

Search Output

The word apple is present in 3 file(s).

 In file: file1.txt  2 time(s)

 In file: file2.txt  1 time(s)

 In file: file3.txt  2 time(s)

### Display Output

### Index --> 0

### Word  --> apple

### File Count  --> 3

### File Name  --> file1.txt , file2.txt, file3.txt

### Word Count  --> 2,            1,          2
 
 
The exact index depends on the first character of the word.



## ADVANTAGES

- Efficient organization of word information.

- Avoids repeatedly scanning all files for every search.

- Uses a hash table for indexing words.

- Linked lists allow dynamic storage.

- Supports multiple input files.

- Maintains word frequency for each file.

- Database can be saved for later restoration.

- Demonstrates practical implementation of multiple data structures.

- Provides input validation and error handling.



## APPLICATIONS

The concepts implemented in this project can be applied to:

- Search engines

- Document indexing systems

- Text search applications

- Digital libraries

- Document management systems

- File-search utilities

- Keyword indexing

- Information retrieval systems



## FUTURE ENHANCEMENTS

- Case-insensitive word searching.

- Removal of punctuation from words.

- Support for larger input files.

- Improved search performance and phrase searching.

- Search for multiple words simultaneously.

- Improved backup-file validation.

- More efficient hash functions.

- Automatic database loading when the application starts.

- Support for updating an already-created database with new files.

- Improved memory cleanup for all dynamically allocated database nodes.



## LEARNING OUTCOMES

- Practical implementation of hash tables and linked lists.
  
- Improved understanding of pointers and dynamic memory allocation.

- Hands-on experience with file handling and command-line arguments.

- Working with multiple linked-list relationships.

- Managing dynamically allocated memory.

- Developing a menu-driven C application.

- Applying data structures to a real-world problem.



## CONCLUSION

The Inverted Search using Data Structures in C project demonstrates how hash tables and linked lists can be combined to build an efficient word-indexing system.

The project provides complete database operations including creation, searching, display, saving, and updating. It also demonstrates important C programming concepts such as structures, pointers, dynamic memory allocation, file handling, command-line arguments, and linked-list traversal.

Overall, the project provides practical experience in applying fundamental data structures to a real-world information retrieval and text indexing problem.






