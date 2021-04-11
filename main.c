#include <stdio.h>
#include "functions.h"
int main() {
    int choice;

    while(1){
        system("cls");
        printf("Press 1. to create a user.\n");
        printf("Press 2. to create a card.\n");
        printf("Press 3. to create a table.\n");
        printf("Press 4. to see a table.\n");
        printf("Press 5. to see a card.\n");
        printf("Press 6. to see details about an user.\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username.\n");
                char username[50];
                scanf("%s", username);
                createUser(username);
                break;
            case 2:
                printf("Enter card name.\n");
                char cname[50];
                scanf("%s", cname);
                createCard(cname);
                break;
            case 3:
                printf("Enter table name.\n");
                char table[50];
                scanf("%s", table);
                createTable(table);
                break;
            case 6:
                printf("Enter the username u are lokking for.\n");
                char uname[50];
                scanf("%s", uname);
                printUser(uname);
                break;
            case 4:
                printf("Enter the username of the user that you want to add to a card.\n");
                char u[50];
                scanf("%s", u);
                printf("Enter the name of the card.\n");
                char cardname[50];
                scanf("%s", cardname);
                addUserToCard(u, cardname);
        }
    }


/*
    User* u = createUser("createUser("Jhon");
    createUser("Tom");
    createUser("BEn");
    createUser("Bill");

    printUser("Bill");Tamas");
    User* u2 = createUser("Jon");
    Table* t = createTable("First");
    addUserToTable(u, t);
    addUserToTable(u2, t);
    Card* card = createCard("Card1");
    Card* card2 = createCard("Cardd2");
    printf("\n");
    addUserToCard(u2, card);
    addUserToCard(u, card2);

    addCardToTable(card, t);
    addCardToTable(card2, t);
    changeStatusDoing(card);
    changeStatusDone(card2);
    printTable(t);
    printf("\n");
    printCard(card);
*/






    return 0;
}
