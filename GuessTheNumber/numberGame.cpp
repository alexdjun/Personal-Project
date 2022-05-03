#include "numberGame.hpp"

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Default constructor.
NumberGame::NumberGame() = default;

// Parameterized constructor.
NumberGame::NumberGame(int answer, int tries, int gameLevel) {
    this->playerMoney = 100.00;
    this->answer = answer;
    this->tries = tries;
    this->gameLevel = gameLevel;
}

// Gettters, return its value.
string NumberGame::getPlayerName() const { return this->playerName; }
double NumberGame::getPlayerMoney() const { return this->playerMoney; }
int NumberGame::getAnswer() const { return this->answer; }
int NumberGame::getGameLevel() const { return this->gameLevel; }
int NumberGame::getTries() const { return this->tries; }

// Setters, setting its values.
void NumberGame::setPlayerName(string name) {this->playerName = name; }
void NumberGame::setPlayerMoney(double money) {this->playerMoney += money; }
void NumberGame::setAnswer(int answer) {this->answer = answer; }
void NumberGame::setGameLevel(int level) {this->gameLevel = level; }
void NumberGame::setTries(int tries) {this->tries += tries; }

// Helper function to choose a game level.
int NumberGame::chooseLevel() const {
    int level;
    while(true) {
        // Menu.
        cout << "\nChoose from the following game level " << getPlayerName() << " : " << endl;
        cout << "1 : Easy." << endl;
        cout << "2 : Normal." << endl;
        cout << "3 : Hard." << endl;
        
        // Getting inputed from the user.
        cout << "Choice : ";
        cin >> level;

        // Making sure the input is valid.
        if (!cin || level > 3) {
            cout << "That is not a valid choice." << endl;
            cin.clear();
            cin.ignore(128, '\n');

        // Return the game level of user choice.
        } else 
            return level;
    }
}

// Helper function to createGame.
NumberGame NumberGame::createGame() {
    // Variables for the necessary data.
    int gameLevel = chooseLevel(), answer, tries = 5;

    // Setting the game level to the user's choice.
    setGameLevel(gameLevel);

    // Getting rid of the any tries that is left.
    setTries(-getTries());
    // Then set the tries back to 5.
    setTries(tries);

    // Generating the answers forr the corresponding game level..
    if (getGameLevel() == 1) {
        // If the game level is easy, number is between 1 and 10.
        answer = (rand() % 10) + 1;
        setAnswer(answer);
    } else if (getGameLevel() == 2) {
        // If the game level is, normal, number is between 1 and 25.
        answer = (rand() % 25) + 1;
        setAnswer(answer);
    } else {
        // If the game level is hard, number is between 1 and 100.
        answer = (rand() % 100) + 1;
        setAnswer(answer);
    }
    return NumberGame(answer, tries, gameLevel);
}

// Helper function to start the game.
void NumberGame::startGame(int level) {
    double bet;
    while (true) {
        // Asking and getting the amount of money user wants to bet.
        cout << "\nYour current money : $" << getPlayerMoney() << endl;
        cout << "How much do you want to bet? ";
        cin >> bet;
        
        // Making sure the input is valid.
        if (!cin) {
            cout << "That is not a valid amount." << endl;
            cin.clear();
            cin.ignore(128, '\n');
        } else if (bet < 0 || bet > getPlayerMoney()){
            cout << "That is not a valid amount." << endl;
            cin.clear();
            cin.ignore(128, '\n');
        } else {
            break;
        }
    }
    
    // Setting the player's money as money - bet.
    setPlayerMoney(-bet);

    int guess;

    // Getting the player's guess as long as he has tries left.'
    while (getTries() != 0) {  
        while (true) {
            // Explaining the rule.
            if (getGameLevel() == 1) cout << "\nGuess from 1 - 10" << endl; 
            if (getGameLevel() == 2) cout << "\nGuess from 1 - 25" << endl;
            if (getGameLevel() == 3) cout << "\nGuess from 1 - 100" << endl;
            cout << "What is your guess? ";
            cin >> guess;

            // Making sure the input is valid.
            if (!cin) {
                cout << "That is not a valid guess." << endl;
                cin.clear();
                cin.ignore(128, '\n');
            } else 
                break;
        }

        // If the guess is correct. 
        if (guess == getAnswer()) {
            // If the game level is easy, double the bet money.
            if (getGameLevel() == 1) {
                cout << "\nCongratulations " << getPlayerName() <<  "! You have successfully guessed the answer!" << endl;
                cout << "Your bet money has doubled!" << endl;
                setPlayerMoney(bet * 2);
                cout << "Your current money : $" << getPlayerMoney() << endl;
                break;

            // If the game level is normal, triple the bet money.
            } else if (getGameLevel() == 2) {
                cout << "\nCongratulations " << getPlayerName() <<  "! You have successfully guessed the answer!" << endl;
                cout << "Your bet money has tripled!" << endl;
                setPlayerMoney(bet * 3);
                cout << "Your current money : $" << getPlayerMoney() << endl;
                break;

            // If the game level is hard, quadruple the bet money.
            } else if (getGameLevel() == 3) {
                cout << "\nCongratulations " << getPlayerName() <<  "! You have successfully guessed the answer!" << endl;
                cout << "Your bet money has quadrupled!" << endl;
                setPlayerMoney(bet * 4);
                cout << "Your current money : $" << getPlayerMoney() << endl;
                break;
            }
        
        // If the guess is lower than the answer, print message and -1 from the tries.
        } else if (guess < getAnswer()) {
            cout << "\nGo higher!" << endl;
            setTries(-1);
            cout << "Tries remaining : " << getTries() << endl;

        // If the guess is higher than the answer, print message and -1 from the tries.
        } else {
            cout << "\nGo lower!" << endl;
            setTries(-1);
            cout << "Tries remaining : " << getTries() << endl;
        }
    }

    // Showing the correct answer after the game is over.
    cout << "\nThe answer was : " << getAnswer() << endl;

    // If the treis 0 and player no longer has the money : 
    if (getTries() == 0 && getPlayerMoney() == 0) {
        // Print message and return back to the original menu.
        cout << "You Lost!" << endl;
        cout << "Better luck next time." << endl;
        return;
    
    // If the tries 0 but player has the moeny : 
    } else {
        // Ask the user if they want to play the game again or leave. 
        int choice;

        // Menu.
        cout << "You lost, $" << bet << endl;
        cout << "Your current money : $" << getPlayerMoney() << endl;
        cout << "\nChoose from the following options " << getPlayerName() << " : " << endl;
        cout << "1 : Play Again." << endl;
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

        // If user wants to play, then create a new game. 
        if (choice == 1) {
            createGame();
            startGame(getGameLevel());
        } 

        // If user wants to leave, then go back to the main menu.
        if (choice == 2) {
            cout << "\nGood Bye!\n" << endl;
            return;
        }
    } 

}