#pragma once

#include <string>
#include <vector>
#include <random>
#include <array>
#include <cctype>
#include <cstring>

class HangmanLogic {
public:
    HangmanLogic();

    void startNewGame(int minLen, int maxLen, int lives);

    bool guess(char letter);
    char hint();

    std::string getMasked() const;
    std::string getUsedLetters() const;

    int getLives() const;
    int getStage() const;

    int getHintUsed() const;
    void incrementHintUsed();
    void setHintUsed(const int amount);

    bool isWin() const;
    bool isLoss() const;

    std::string getWord() const;

    void setPlayerName(const std::string& name);
    const std::string& getPlayerName() const;

private:
    static char normalizeLetter(char c);
    std::string chooseWordInRange(int minLen, int maxLen) const;

    std::string word_;
    std::string mask_;
    std::array<bool, 26> used_{};
    int lives_ = 0;
    int stage_ = 0;
    int hintsUsed_ = 0;
    std::string playerName_;

    static const char* DICTIONARY[];
    static const int   DICTIONARY_SIZE;
};
