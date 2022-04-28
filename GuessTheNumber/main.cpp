#include <iostream>
#include "numberGame.cpp"

using namespace std;

int main() {
    int choice; 

    while (true) {
        cout << "\nWelcome to the Number Game!" << endl;
        cout << "---------------------------" << endl;
        cout << "Please choose from the following options : " << endl;
        cout << "1 : Start." << endl;
        cout << "2 : Leave." << endl;
        
        cout << "Choice : ";
        cin >> choice;
        if (!cin) {
            cout << "That is not a valid choice." << endl;
            cin.clear();
            cin.ignore(128, '\n');
        }
        
        if (choice == 1) {
            NumberGame game;

            string name;
            cout << "\nWhat is your name?" << endl;
            cin.ignore();
            getline(cin, name);
            game.setPlayerName(name);
            game.setGameLevel(game.chooseLevel());
            game = game.createGame();
            game.startGame(game.getGameLevel());
            /***************************************************/
            /*
            cout << "\nName : " << game.getPlayerName() << endl;
            cout << "Money : " << game.getPlayerMoney() << endl;
            cout << "Answer : " << game.getAnswer() << endl;
            cout << "Level : " << game.getGameLevel() << endl;
            cout << "Tries : " << game.getTries() << endl;
            */
            /***************************************************/
        }

        if (choice == 2) {
            cout << "\nGood Bye!\n" << endl;
            break;
        };
    }
    
    return 0;
}