#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 100

struct Player {
    char name[50];
    int age;
    int level;
    int score;
};

struct Player players[MAX_PLAYERS];
int playerCount = 0;

// Function prototypes
void addPlayer();
void displayPlayers();
void searchPlayer();
void updateScore();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    loadFromFile();

    do {
        printf("\n====== PLAYER PROFILE SYSTEM ======\n");
        printf("1. Add New Player\n");
        printf("2. Display All Players\n");
        printf("3. Search Player by Name\n");
        printf("4. Update Player Score\n");
        printf("5. Save Profiles to File\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPlayer(); break;
            case 2: displayPlayers(); break;
            case 3: searchPlayer(); break;
            case 4: updateScore(); break;
            case 5: saveToFile(); break;
            case 6: printf("Exiting Program...\n"); break;
            default: printf("Invalid Choice! Try Again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addPlayer() {
    if (playerCount >= MAX_PLAYERS) {
        printf("Cannot add more players! Storage full.\n");
        return;
    }

    printf("\n--- Add New Player ---\n");
    printf("Enter Name: ");
    scanf("%49s", players[playerCount].name);
    printf("Enter Age: ");
    scanf("%d", &players[playerCount].age);
    printf("Enter Level: ");
    scanf("%d", &players[playerCount].level);
    printf("Enter Score: ");
    scanf("%d", &players[playerCount].score);

    playerCount++;
    printf("Player added successfully!\n");
}

void displayPlayers() {
    if (playerCount == 0) {
        printf("No players available!\n");
        return;
    }

    printf("\n--- All Player Details ---\n");
    for (int i = 0; i < playerCount; i++) {
        printf("\nPlayer %d:\n", i + 1);
        printf("Name  : %s\n", players[i].name);
        printf("Age   : %d\n", players[i].age);
        printf("Level : %d\n", players[i].level);
        printf("Score : %d\n", players[i].score);
    }
}

void searchPlayer() {
    char searchName[50];
    int found = 0;

    printf("\nEnter Name to Search: ");
    scanf("%49s", searchName);

    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, searchName) == 0) {
            printf("\nPlayer Found!\n");
            printf("Name  : %s\n", players[i].name);
            printf("Age   : %d\n", players[i].age);
            printf("Level : %d\n", players[i].level);
            printf("Score : %d\n", players[i].score);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Player not found.\n");
}

void updateScore() {
    char searchName[50];
    int found = 0;

    printf("\nEnter Player Name to Update Score: ");
    scanf("%49s", searchName);

    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, searchName) == 0) {
            printf("Enter New Score: ");
            scanf("%d", &players[i].score);
            printf("Score Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Player not found.\n");
}

void saveToFile() {
    FILE *file = fopen("players.txt", "w");

    if (!file) {
        printf("Error saving file!\n");
        return;
    }

    for (int i = 0; i < playerCount; i++) {
        fprintf(file, "%s %d %d %d\n",
                players[i].name,
                players[i].age,
                players[i].level,
                players[i].score);
    }

    fclose(file);
    printf("Data saved to players.txt successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("players.txt", "r");
    if (!file) return;

    while (fscanf(file, "%49s %d %d %d",
                  players[playerCount].name,
                  &players[playerCount].age,
                  &players[playerCount].level,
                  &players[playerCount].score) == 4) {
        playerCount++;
    }
    fclose(file);
}
