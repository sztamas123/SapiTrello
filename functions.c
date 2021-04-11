//
// Created by tamas on 09.04.2021.
//
#include "functions.h"


User * createUser(char* username){
    User* user = (User*)calloc(1,sizeof(User));
    user->username = (char*)calloc(50,sizeof(char));
    srand(time(0));
    user->id = rand() % 100;
    user->username = username;
}

void printUser(User* user){
    printf("%s", user->username);
    printf("\n");
    printf("%d", user->id);
    printf("\n");
}

Table* createTable(char* tableName){
    Table* table = (Table*)calloc(1,sizeof(Table));
    table->name = (char*)calloc(50,sizeof(char));
    table->name = tableName;
    table->users = (User*)calloc(50,sizeof(User));
    table->cards = (Card*)calloc(50,sizeof(Card));
    table->numberOfUsers = (int*)calloc(100,sizeof(int));
    table->numberOfCards = (int*)calloc(100,sizeof(int));
    table->numberOfUsers = 0;
    table->numberOfCards = 0;
}

void addUserToTable(User* user, Table* table){
    table->users[table->numberOfUsers].username = user->username;
    table->users[table->numberOfUsers].id = user->id;
    table->numberOfUsers++;
}

void printTable(Table* table){
    printf("Table details: ");
    printf("\n");
    printf("Name: %s", table->name);
    printf("\n");
    printf("Nr. of users: %i", table->numberOfUsers);
    printf("\n");
    printf("Users: ");
    printf("\n");
    for(int i = 0;i < table->numberOfUsers ; i++){
        printf("Name: %s ", table->users[i].username);
        printf("Id: %i ", table->users[i].id);
        printf(",");
    }


    printf("\n");
    printf("Number of cards on this table: %i", table->numberOfCards);
    printf("\n");

    for (int i = 0; i < table->numberOfCards; ++i) {
        printf("Card description: %s ", table->cards[i].description);
        printf("\n");
        printf("Card status: %s", table->cards[i].status);
        printf("\n");
       // printf("User working on this card: %s", table->cards[i].user->username ); nem megy ez a sor

    }
    printf("\n");

}


Card* createCard(char* description){
    Card* card = (Card*)calloc(1,sizeof(Card));
    card->user = (User*)calloc(1,sizeof(User));
    card->description = (char*)calloc(50,sizeof(char));
    card->status = (char*)calloc(15,sizeof(char));
    card->id = (int*)calloc(100,sizeof(int));
    card->description = description;
    card->status = "TO DO";
}

void changeStatusDoing(Card* card){
    card->status = "DOING";
}

void changeStatusDone(Card* card){
    card->status = "DONE";
}

void changeStatusTodo(Card* card){
    card->status = "TO DO";
}

void getCardStatus(Card* card){
    printf("Status of the card: %s", card->status);
    printf("\n");
}


void addCardToTable(Card* card, Table* table){
    table->cards[table->numberOfCards].description = card->description;
    table->cards[table->numberOfCards].status = card->status;
    table->numberOfCards++;

}



void addUserToCard(User* user, Card* card){
    if(card->user->id == NULL){
        card->user->username = user->username;
        card->user->id = user->id;
    }
    return;
}

void printCard(Card* card){
    printf("Card description: %s", card->description);
    printf("\n");
    printf("User working on this card: %s", card->user->username);
    printf(" %i ", card->user->id);
    printf("\n");
    printf("Card status: %s", card->status);
    printf("\n");
}