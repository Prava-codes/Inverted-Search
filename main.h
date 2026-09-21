#ifndef INVERT_SEARCH_H
#define INVERT_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Return Values */
#define SUCCESS         0
#define FAILURE        -1
#define LIST_EMPTY     -2
#define DATA_NOT_FOUND -3

/* Text Colors */
#define RESET   "\033[0m"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

/* File Linked List */
typedef struct file_node
{
    char *f_name;
    struct file_node *link;
} file_t;

/* Sub Node */
typedef struct sub_node
{
    char *f_name;
    size_t w_count;
    struct sub_node *link;
} sub_t;

/* Main Node */
typedef struct main_node
{
    char *word;
    size_t f_count;
    struct sub_node *slink;
    struct main_node *nlink;
} main_t;

/* Hash Table */
typedef struct hash_table
{
    size_t index;
    struct main_node *link;
} hash_t;

/* Common Functions */
void reset_HT(hash_t *arr);
int Is_HT_empty(hash_t *arr);

/* File Validation Functions */
int validate_Files(file_t **file_name, int argc, char *argv[]);
int is_txt_file(const char *filename);
int is_dupicate_file(file_t *head, const char *filename);
int is_file_empty(FILE *fptr);
void print_file_list(file_t *head);
void free_file_list(file_t *head);
void remove_file_from_SLL(file_t **head, const char *filename);


/* Database Functions */
int create_DB(hash_t *arr, file_t *file_head);
void display_DB(hash_t *arr);
void search_DB(hash_t *arr);
void save_DB(hash_t *arr);
int update_DB(hash_t *arr, file_t **files);

#endif