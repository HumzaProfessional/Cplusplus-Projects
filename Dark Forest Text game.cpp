#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Define the game world as a 2D matrix of integers
    vector<vector<int>> world = {
        {1, 2, 3, 4, 5, 0},
        {6, 7, 8, 9, 10, 1},
        {11, 12, 13, 14, 15, 2},
        {16, 17, 18, 19, 20, 3},
        {21, 22, 23, 24, 25, 4},
        {26, 27, 28, 29, 30, 5},
        {31}, // 0: Start in a dark forest
        {32}, // 1: nothing
        {33}, // 2: Find a treasure chest
        {34}, // 3: Find a cave entrance
        {35}, // 4: Reach the end of the forest
        {36}, // 5: Discover a secret path
        {37}, // 6: Fight the dragon
        {38}, // 7: Run from the dragon
        {39}, // 8: Open the treasure chest
        {40}, // 9: Enter the cave
        {41}, // 10: Ignore the treasure chest
        {42}, // 11: Continue exploring the forest
        {43}, // 12: Enter the cave and find a secret garden
        {44}, // 13: Decide not to enter the cave
        {45}, // 14: Find a hidden path to the top of a hill
        {46}, // 15: Climb the hill
        {47}, // 16: Discover a beautiful waterfall
        {48}, // 17: Explore behind the waterfall
        {49}, // 18: Return to the forest
        {50}, // 19: Find a pond with a boat
        {51}, // 20: Row the boat across the pond
        {52}, // 21: Reach the other side of the pond
        {53}, // 22: Encounter a friendly squirrel
        {54}, // 23: Follow the squirrel to a hidden glade
        {55}, // 24: Rest in the glade and gain health
        {56}, // 25: Continue exploring the forest
        {57}, // 26: Encounter a group of elves
        {58}, // 27: Join the elves in a feast
        {59}, // 28: Receive a magical amulet from the elves
        {60}, // 29: Return to the forest
        {61}, // 30: Find an abandoned cabin
        {62}, // 31: Enter the cabin and find a dusty book
        {63}, // 32: Read the book and learn a new spell
        {64}, // 33: Leave the cabin
        {65}, // 34: Encounter a pack of wolves
        {66}, // 35: Fight the wolves
        {67}, // 36: Run from the wolves
        {68}, // 37: Find a hidden path leading to a meadow
        {69}, // 38: Explore the meadow and find a rare flower
        {70}, // 39: Pick the flower and gain a special ability
        {71}, // 40: Return to the forest
        {72}, // 41: Encounter a talking tree
        {73}, // 42: Listen to the tree's stories
        {74}, // 43: Learn about the history of the forest
        {75}, // 44: Receive a blessing from the tree
        {76}, // 45: Continue exploring the forest
        {77}, // 46: Find a clearing with a circle of stones
        {78}, // 47: Investigate the stones and discover a portal
        {79}, // 48: Enter the portal and find yourself in a different realm
        {80}, // 49: Explore the realm and find a valuable artifact
        {81}, // 50: Return to the forest
        {82}, // 51: Encounter a group of goblins
        {83}, // 52: Negotiate with the goblins
        {84}, // 53: Fight the goblins
        {85}, // 54: Run from the goblins
        {86}, // 55: Find a hidden path to a mountain
        {87}, // 56: Climb the mountain
        {88}, // 57: Reach the summit and enjoy the view
        {89}, // 58: Find a magical crystal at the summit
        {90}, // 59: Return to the forest
        {91}, // 60: Encounter a group of fairies
        {92}, // 61: Dance with the fairies
        {93}, // 62: Receive a gift from the fairies
        {94}, // 63: Return to the forest
        {95}, // 64: Find a mysterious portal
        {96}, // 65: Enter the portal and find yourself in a different time
        {97}, // 66: Explore the past and witness historical events
        {98}, // 67: Return to the present
        {99}, // 68: Encounter a lost traveler
        {100}, // 69: Help the traveler find their way
        {101}, // 70: Receive a reward from the traveler
        {102}, // 71: Return to the forest
        {103}, // 72: Find a hidden path to a cave
        {104}, // 73: Enter the cave and find a treasure
        {105}, // 74: Take the treasure and become rich
        {0}    // 75: Return to the forest
    };

    int currentLocation = 0;
  int health = 100;
    bool hasSword = false;
  bool haveMap = false;

    cout << "You are lost in a dark forest. It seems calm right now. Where would you like to go?" << endl;

    // Game loop
    while (true) {
        cout << "Current location: " << currentLocation << endl;

        // Determine the options based on the current location
        vector<int> options = world[currentLocation];
        cout << "Options:";
        for (int i = 0; i < options.size(); i++) {
            cout << " " << options[i];
        }
        cout << endl;

        // Prompt the player for input
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        // Validate the choice
        bool validChoice = false;
        for (int i = 0; i < options.size(); i++) {
            if (choice == options[i]) {
                validChoice = true;
                break;
            }
        }

        // Update the current location based on the player's choice
        if (validChoice) {
            currentLocation = choice;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }

        // Check if the player has the sword
        if (currentLocation == 38 && !hasSword) { // Location 38 is the dragon encounter
            cout << "You encounter a forest dragon! You need a sword to defeat it. You die instantly." << endl;
            break;
        } else if (currentLocation == 38 && hasSword) {
            cout << "You use the sword to defeat the dragon! Congratulations, you have slain the dragon." << endl;
          haveMap = true;
        }

        // Check for game over condition
        if (currentLocation == 0) {
            cout << "You sense the calmness again. You must be back at where you started...Where would you like to go?" << endl;
        }
        else if (currentLocation == 1){
            cout << "You go deeper into the forest, and sense some places..." << endl;
        }
          else if (currentLocation == 3) {
          cout << "You find a cave entrance. Would you like to enter the cave (enter 1) or go elsewhere (enter 0)?" << endl;
          int caveChoice;
          cin >> caveChoice;
          if (caveChoice == 1) {
              cout << "You enter the cave." << endl;
              currentLocation = 40; // Move to the cave
          } else {
              cout << "You decide not to enter the cave and continue exploring the forest." << endl;
          }
          }
         else if (currentLocation == 75) {
            cout << "Congratulations! You have reached the end of the forest and completed the game." << endl;
            break;
        }
    }

    return 0;
}
