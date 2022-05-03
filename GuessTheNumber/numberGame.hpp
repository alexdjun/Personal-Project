#ifndef NUMBERGAME_H
#define NUMBERGAME_H

#include <string>

class NumberGame {
    // Member variables for this game.
    private:
        std::string playerName;
        double playerMoney;
        int gameLevel;
        int answer;
        int tries;

    // Member functions for this game.
    public:
        // Constructors.
        NumberGame();
        NumberGame(int answer, int tries, int gameLevel);
        
        // Getters.
        std::string getPlayerName() const;
        double getPlayerMoney() const;
        int getAnswer() const;
        int getGameLevel() const;
        int getTries() const;
        
        // Setters.
        void setPlayerName(std::string playerName);
        void setPlayerMoney(double playerMoney);
        void setAnswer(int answer);
        void setGameLevel(int gameLevel);
        void setTries(int tries);

        // Helper functions.
        NumberGame createGame();
        void startGame(int level);
        int chooseLevel() const;
};

#endif // NUMBERGAME_H