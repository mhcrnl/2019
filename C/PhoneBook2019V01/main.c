/*=================================================================
FILE:       main.c
AUTHOR:     Mihai Cornel mhcrnl@gmail.com
COMPILE:    gcc main.c
===================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*==================================================================
Pastreaza datele aplicatiei
====================================================================*/
typedef struct _PhoneBook{
    char nume[30];
    char prenume[30];
    char telefon[30];
} PhoneBook;
/*===================================================================
Main
=====================================================================*/
int main()
{
    printf("Hello world!\n");

    PhoneBook phonebook[10];
    strcpy(phonebook->nume, "Mihai");
    printf("%s", phonebook->nume);
    return 0;
}
