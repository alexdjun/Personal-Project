#include <iostream>
#include <ctime>
#include "numberGame.cpp"

using namespace std;

int main() {
    // To keep the random numbers to be different.
    srand(time(0));
    
    int choice; 

    while (true) {
        // Menu
        cout << "\n---------Main Menu---------" << endl;
        cout << "Welcometo the Number Game!" << endl;
        cout << "---------------------------" << endl;
        cout << "Please choose from the following options : " << endl;
        cout << "1 : Start." << endl;
        cout << "2 : Leave." << endl;
        
        // Getting input from the user.
        cout << "Choice : ";
        cin >> choice;

        // Making sure the input is valid.
        if (!cin) {
            cout << "That is not a valid choice." << endl;
            cin.clear();
            cin.ignore(128, '\n');
        }
        
        // If user wants to play : 
        if (choice == 1) {
            // Creating an instance of a game class.
            NumberGame game;

            // Getting a name from the user.
            string name;
            cout << "\nWhat is your name? ";
            cin.ignore();
            getline(cin, name);

            // Setting the name and actually creating and starting the game.
            game.setPlayerName(name);
            game = game.createGame();
            game.startGame(game.getGameLevel());
        }

        // If user wants to leave :
        if (choice == 2) {
            // Say a goodbye message and break out from the loop.
            cout << "\nGood Bye!\n" << endl;
            break;
        };
    }
    
    return 0;
}