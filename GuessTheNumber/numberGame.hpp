#ifndef NUMBERGAME_H
#define NUMBERGAME_H

#include <string>

class NumberGame {
    private:
        std::string playerName;
        double playerMoney;
        int gameLevel;
        int answer;
        int tries;
    public:
        NumberGame();
        NumberGame(int answer, int tries);
        
        std::string getPlayerName() const;
        double getPlayerMoney() const;
        int getAnswer() const;
        int getGameLevel() const;
        int getTries() const;
        
        void setPlayerName(std::string playerName);
        void setPlayerMoney(double playerMoney);
        void setAnswer(int answer);
        void setGameLevel(int gameLevel);
        void setTries(int tries);

        NumberGame createGame();
        void startGame(int level);
        int chooseLevel() const;
};

#endif // NUMBERGAME_H