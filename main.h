#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SUCCESS 0; //macro to represent success
#define FAILURE -1; //macro to represent failure

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}Dlist;

/*insert_at_first function*/
int insert_at_first(Dlist **, Dlist **, int);

/*insert_at_last function*/
int insert_at_last(Dlist **, Dlist **, int);

/*print_list function*/
void print_list(Dlist *);

/*delete_list function*/
int delete_list(Dlist **, Dlist **);

/*delete_first function*/
int delete_first(Dlist **, Dlist **);

/*addition function*/
int do_addition(Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **);

/*subtraction function*/
int do_subtraction(Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **);

/*Division function*/
int do_division(Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **);

/*Multiplication function*/
int do_multiplication(Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **, Dlist **);

/*Validate argument is number*/
int is_number(const char *str);

/*Validate operator*/
int is_valid_operator(const char *op);

#endif