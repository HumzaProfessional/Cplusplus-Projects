#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
extern void initialise_monitor_handles(void);

#define MAX_PATH 50 // max

typedef struct Node {
    char *description;         // General location description
    char *dialogue;            // Unique dialogue for this node
    struct Node *paths[MAX_PATHS]; // Paths forward
    int (*puzzle)();           // Pointer to a puzzle function (if any)
} Node;


Node* createNode(char *desc, char *dialogue, int (*puzzle)()) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->description = desc;
    newNode->dialogue = dialogue;
    newNode->puzzle = puzzle;

    for (int i = 0; i < MAX_PATHS; i++) {
        newNode->paths[i] = NULL;
    }
    return newNode;
}

void displayNode(Node *node) {
    if (node == NULL) return;

    printf("\n%s\n\n", node->description);

    // Print dialogue with pauses
    char *dialogue = node->dialogue;
    while (*dialogue) {
        putchar(*dialogue++);
        fflush(stdout);  // Ensure text appears immediately
        if (*dialogue == '\n') {
            getchar();  // Wait for user after each line
        }
    }
    printf("\n");
}


int main() {

  
// Create starting node
  Node *start = createNode(
        "You arrive at a fork in the road.",
        "Two figures stand before you.\n"
        "One grins mischievously, the other remains solemn.\n"
        "The grinning man smirks: \"A bright path ahead? Or just an illusion?\"\n"
        "The serious man nods: \"Shadows reveal the truth, but can you see it?\"\n"
        "Which path will you take?\n",
        NULL);

 // Left path: Grinning man (No puzzle yet)
    start->paths[0] = createNode(
        "You chose the left path.",
        "The grinning man chuckles: \"Did you choose wisely? We’ll see...\"\n",
        NULL);

    // Right path: Serious man (No puzzle yet)
    start->paths[1] = createNode(
        "You chose the right path.",
        "The serious man nods: \"Darkness guides the way. Tread carefully.\"\n",
        NULL);

  

while (1) {
        printf("\n%s\n", current->description);
        printf("%s\n", current->dialogue);

        // Run puzzle if applicable
        if (current->puzzle != NULL) {
            if (!current->puzzle()) {
                printf("Game Over! Try again.\n");
                break;
            }
        }

        // Display choices
        for (int i = 0; i < MAX_PATHS; i++) {
            if (current->paths[i] != NULL) {
                printf("(%d) %s\n", i + 1, current->paths[i]->description);
            }
        }

        // Get player choice
        int choice;
        printf("Choose a path (1) or enter 0 to quit: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        if (choice == 1 && current->paths[0] != NULL) {
            current = current->paths[0];  // Move to new node
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;



}

