#include <stdio.h>
#include "functions.h"
int main() {
    int choice;
    srand(time(0));
    setbuf(stdout, 0);
    init();

    createCard("card");
    createCard("card2");
    createUser("user1");
    createUser("user2");
    createTable("table");

    addUserToCard("user1", "card");
    addCardToTable("card", "table");
    addUserToTable("user1", "table");
    //addUserToTable("user2", "table");

    //changeCardName("card", "kartya")

    removeCard("card", "table");

    while(1){
        system("CLS");
        printf("Press 0. to exit.\n");
        printf("Press 1. to create a user.\n");
        printf("Press 2. to create a card.\n");
        printf("Press 3. to create a table.\n");
        printf("Press 4. to see a table.\n");
        printf("Press 5. to see a card.\n");
        printf("Press 6. to see details about an user.\n");
        printf("Press 7. to add user to a card.\n");
        printf("Press 8. to change card status to doing.\n");
        printf("Press 9. to change card status to done.\n");
        printf("Press 10. to change card status to to do.\n");
        printf("Press 11. to add user to table.\n");


        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(1);
                break;
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
            case 5:
                printf("Enter the description of the card you are looking for.\n");
                char description[50];
                scanf("%s", description);
                printCard(description);
                break;
            case 6:
                printf("Enter the username u are looking for.\n");
                char unam[50];
                scanf("%s", unam);
                printUser(unam);
                break;
            case 4:
                printf("Enter table name.");
                char t1[50];
                scanf("%s", t1);
                printTable(t1);
                break;
            case 7:
                printf("Enter the username of the user that you want to add.\n");
                char u1[50];
                scanf("%s", u1);
                printf("Enter card name.\n");
                char c1[50];
                scanf("%s", c1);
                addUserToCard(u1,c1);
                break;
            case 8:
                printf("Enter card name that you want to change.\n");
                char cna[25];
                scanf("%s", cna);
                changeStatusDoing(cna);
                break;
            case 9:
                printf("Enter card name that you want to change.\n");
                char cnam[25];
                scanf("%s", cnam);
                changeStatusDone(cnam);
                break;
            case 10:
                printf("Enter card name that you want to change.\n");
                char cnm[25];
                scanf("%s", cnm);
                changeStatusDone(cnm);
                break;
            case 11:
                printf("Enter username.");
                char u2[50];
                scanf("%s", u2);
                printf("Enter table name.");
                char t2[50];
                scanf("%s", t2);
                addUserToTable(u2, t2);
                break;
            default:
                printf("\nInvalid Choice :-(\n");
                system("pause");


        }
    }


    return 0;
}
