//
// Created by tamas on 09.04.2021.
//

#ifndef SAPITRELLO_FUNCTIONS_H
#define SAPITRELLO_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


typedef struct {
    char* username;
    int id;
}User;

typedef struct {
    User user;
    char* description;
    int id;
    char* status;
}Card;

typedef struct {
    char* name;
    int numberOfUsers;
    int numberOfCards;
    User* users;
    Card* cards;
}Table;



void createUser(char*);
void printUser(char*);
void createTable(char*);
void printTable(char*);
void createCard(char*);
void addUserToTable(char*, char*);
void addCardToTable(char*, char*);
void addUserToCard(char*, char*);
void changeCardName(char*, char*);
void changeStatusDoing(char*, char*);
void changeStatusDone(char*, char*);
void changeStatusTodo(char*, char*);
void getCardStatus(char*);
void printCard(char*);
void init();
void removeCard(char*, char*);
void printAllUsers();
void printAllCards();











#endif //SAPITRELLO_FUNCTIONS_H
