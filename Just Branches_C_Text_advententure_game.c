#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
extern void initialise_monitor_handles(void);

// Declar assembly function
extern int fast_choice(int input);  // Handles branching in assembly
extern int check_riddle(int puzzle_id, char *answer);  // Checks puzzle in assembly


#define MAX_PATH 50 // max

typedef struct Node {
    char *description;         // General location description
    char *dialogue;            // Unique dialogue for this node
    struct Node *paths[MAX_PATHS]; // Paths forward
    int puzzle_id;          // Id to call puzzle in assembly
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
        fflush(stdout);
        if (*dialogue == '\n') {
            getchar();  // Pause after each line
        }
    }
    printf("\n");

    // Run puzzle if present
    if (node->puzzle != NULL) {
        if (!node->puzzle()) {
            printf("\nGame Over! Try again.\n");
            exit(0);  // Exit game if puzzle fails
        }
    }
}


int main() {
    // Define game nodes
    Node start = {
        "You arrive at a fork in the road.",
        "Two figures stand before you.\n"
        "One grins mischievously, the other remains solemn.\n"
        "The grinning man smirks: \"A bright path ahead? Or just an illusion?\"\n"
        "The serious man nods: \"Shadows reveal the truth, but can you see it?\"\n"
        "Which path will you take?",
        {NULL, NULL}, 0
    };

    // Left path (No puzzle)
    Node left_path = {
        "You chose the left path.",
        "The grinning man chuckles: \"Did you choose wisely? We’ll see...\"\n",
        {NULL, NULL}, 0
    };

    // Right path (Riddle puzzle)
    Node right_path = {
        "You chose the right path.",
        "The serious man nods: \"Darkness guides the way. Answer wisely.\"\n"
        "Riddle: 'I have keys but open no locks. What am I?'",
        {NULL, NULL}, 1  // Puzzle ID 1 (calls assembly)
    };

    // Link paths
    start.paths[0] = &left_path;
    start.paths[1] = &right_path;

    // Start game
    Node *current = &start;
    displayNode(current);

    while (1) {
        // Display choices
        printf("\n(1) %s\n(2) %s\n", left_path.description, right_path.description);
        printf("Choose a path (1-2) or enter 0 to quit: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 0) break; // Exit

        // Use assembly for optimized branching
        int index = fast_choice(choice);
        if (index == -1) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        // Move to the new node
        current = start.paths[index];
        displayNode(current);
    }

    return 0;
}

int right_riddle(){

}

