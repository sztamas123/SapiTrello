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
    User* user;
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
Table* createTable(char*);
void printTable(Table*);
Card* createCard(char*);
void addUserToTable(User*, Table*);
void addCardToTable(Card*, Table*);
void addUserToCard(char*, char*);
void changeStatusDoing(char*);
void changeStatusDone(char*);
void changeStatusTodo(char*);
void getCardStatus(char*);
void printCard(char*);
void init();












#endif //SAPITRELLO_FUNCTIONS_H
