#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Device structure
typedef struct {
    int id;
    char name[50];
    char status[20];
} Device;

// Graph structure (Adjacency Matrix)
typedef struct {
    Device devices[MAX];
    int adjMatrix[MAX][MAX];
    int count;
} Graph;

// Initialize graph
void initGraph(Graph *g) {
    g->count = 0;
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            g->adjMatrix[i][j] = 0;
}

// CREATE - Add Device
void addDevice(Graph *g, int id, char name[], char status[]) {
    if (g->count >= MAX) {
        printf("Device limit reached!\n");
        return;
    }

    g->devices[g->count].id = id;
    strcpy(g->devices[g->count].name, name);
    strcpy(g->devices[g->count].status, status);

    g->count++;
    printf("Device added successfully.\n");
}

// READ - Display Devices
void displayDevices(Graph *g) {
    printf("\nDevices List:\n");
    for (int i = 0; i < g->count; i++) {
        printf("ID: %d | Name: %s | Status: %s\n",
               g->devices[i].id,
               g->devices[i].name,
               g->devices[i].status);
    }
}

// UPDATE - Modify Device
void updateDevice(Graph *g, int id) {
    for (int i = 0; i < g->count; i++) {
        if (g->devices[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", g->devices[i].name);

            printf("Enter new status: ");
            scanf("%s", g->devices[i].status);

            printf("Device updated.\n");
            return;
        }
    }
    printf("Device not found!\n");
}

// DELETE - Remove Device
void deleteDevice(Graph *g, int id) {
    int index = -1;

    for (int i = 0; i < g->count; i++) {
        if (g->devices[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Device not found!\n");
        return;
    }

    // Shift devices
    for (int i = index; i < g->count - 1; i++) {
        g->devices[i] = g->devices[i + 1];
    }

    // Update adjacency matrix
    for (int i = index; i < g->count; i++) {
        for (int j = 0; j < g->count; j++) {
            g->adjMatrix[i][j] = g->adjMatrix[i + 1][j];
            g->adjMatrix[j][i] = g->adjMatrix[j][i + 1];
        }
    }

    g->count--;
    printf("Device deleted.\n");
}

// Add connection (Edge)
void addConnection(Graph *g, int id1, int id2) {
    int i1 = -1, i2 = -1;

    for (int i = 0; i < g->count; i++) {
        if (g->devices[i].id == id1) i1 = i;
        if (g->devices[i].id == id2) i2 = i;
    }

    if (i1 == -1 || i2 == -1) {
        printf("Invalid device IDs!\n");
        return;
    }

    g->adjMatrix[i1][i2] = 1;
    g->adjMatrix[i2][i1] = 1;

    printf("Connection added.\n");
}

// Display Graph
void displayGraph(Graph *g) {
    printf("\nNetwork Graph (Adjacency Matrix):\n");

    for (int i = 0; i < g->count; i++) {
        for (int j = 0; j < g->count; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main Menu
int main() {
    Graph g;
    initGraph(&g);

    int choice, id, id2;
    char name[50], status[20];

    while (1) {
        printf("\n--- Healthcare Device Network ---\n");
        printf("1. Add Device\n");
        printf("2. View Devices\n");
        printf("3. Update Device\n");
        printf("4. Delete Device\n");
        printf("5. Add Connection\n");
        printf("6. View Network\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Status: ");
                scanf("%s", status);
                addDevice(&g, id, name, status);
                break;

            case 2:
                displayDevices(&g);
                break;

            case 3:
                printf("Enter Device ID to update: ");
                scanf("%d", &id);
                updateDevice(&g, id);
                break;

            case 4:
                printf("Enter Device ID to delete: ");
                scanf("%d", &id);
                deleteDevice(&g, id);
                break;

            case 5:
                printf("Enter Device 1 ID: ");
                scanf("%d", &id);
                printf("Enter Device 2 ID: ");
                scanf("%d", &id2);
                addConnection(&g, id, id2);
                break;

            case 6:
                displayGraph(&g);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}