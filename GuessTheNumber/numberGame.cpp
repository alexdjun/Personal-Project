#include "numberGame.hpp"

#include <iostream>
#include <string>
#include <ctime>

using namespace std;


NumberGame::NumberGame() = default;
NumberGame::NumberGame(int answer, int tries) {
    this->playerMoney = 100.00;
    this->answer = answer;
    this->tries = tries;
}
string NumberGame::getPlayerName() const { return this->playerName; }
double NumberGame::getPlayerMoney() const { return this->playerMoney; }
int NumberGame::getAnswer() const { return this->answer; }
int NumberGame::getGameLevel() const { return this->gameLevel; }
int NumberGame::getTries() const { return this->tries; }

void NumberGame::setPlayerName(string name) {this->playerName = name; }
void NumberGame::setPlayerMoney(double money) {this->playerMoney += money; }
void NumberGame::setAnswer(int answer) {this->answer = answer; }
void NumberGame::setGameLevel(int level) {this->gameLevel = level; }
void NumberGame::setTries(int tries) {this->tries += tries; }

int NumberGame::chooseLevel() const {
    int level;
    while(true) {
        cout << "\nChoose from the following game level " << getPlayerName() << " : " << endl;
        cout << "1 : Easy." << endl;
        cout << "2 : Normal." << endl;
        cout << "3 : Hard." << endl;
        
        cout << "Choice : ";
        cin >> level;
        if (!cin || level > 3) {
            cout << "That is not a valid choice." << endl;
            cin.clear();
            cin.ignore(128, '\n');
        } else 
            return level;
    }
}

NumberGame NumberGame::createGame() {
    int answer, tries;
    if (getGameLevel() == 1) {
        srand(time(NULL));
        answer = (rand() % 10) + 1; 
        tries = 5;
    } else if (getGameLevel() == 2) {
        srand(time(NULL));
        answer = (rand() % 25) + 1; 
        tries = 5;
    } else {
        srand(time(NULL));
        answer = (rand() % 100) + 1; 
        tries = 5;
    }
    return NumberGame(answer, tries);
}

void NumberGame::startGame(int level) {
    double bet;
    while (true) {
        cout << "\nHow much do you want to bet? " << endl;
        cout << "Your current money : " << getPlayerMoney() << endl;
        cin >> bet;
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
    setPlayerMoney(-bet);

    int guess;
    while (getTries() != 0) {  
        while (true) {
            cout << "\nWhat is your guess? " << endl;
            cin >> guess;
            if (!cin) {
                cout << "That is not a valid guess." << endl;
                cin.clear();
                cin.ignore(128, '\n');
            } else 
                break;
        }
        if (guess == getAnswer()) {
            cout << "\nCongratulations " << getPlayerName() <<  "! You have successfully guessed the answer!" << endl;
            cout << "Your bet money has doubled!" << endl;
            setPlayerMoney(bet * 2);
            cout << "Your current money : " << getPlayerMoney() << endl;
            break;
        } else if (guess < getAnswer()) {
            cout << "Go higher!" << endl;
            setTries(-1);
            cout << "Tries remaining : " << getTries() << endl;
        } else {
            cout << "Go lower!" << endl;
            setTries(-1);
            cout << "Tries remaining : " << getTries() << endl;
        }
    }

    if (getTries() == 0) {
        cout << "You Lost!" << endl;
        cout << "You lost, " << bet << endl;
        cout << "Your current money : " << getPlayerMoney() << endl;
        cout << "Better luck next time." << endl;
        return;
    } else {
        int choice;
        cout << "\nChoose from the following options " << getPlayerName() << " : " << endl;
        cout << "1 : Play Again." << endl;
        cout << "2 : Leave." << endl;
        cout << "Choice : ";
        cin >> choice;
        if (!cin) {
            cout << "That is not a valid choice." << endl;
            cin.clear();
            cin.ignore(128, '\n');
        } 

        if (choice == 1) {
            setGameLevel(chooseLevel());
            createGame();
            startGame(getGameLevel());
        } 

        if (choice == 2) {
            cout << "\nGood Bye!\n" << endl;
            return;
        }
    } 

}