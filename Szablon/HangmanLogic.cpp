#include "HangmanLogic.h"

const char* HangmanLogic::DICTIONARY[] = {
    "KOMPUTER","PROGRAM","INFORMATYKA","POLITECHNIKA",
    "ALGORYTM","GRA","SIEC","HASLO","KLASA",
    "OBIEKT","FUNKCJA","ZMIENNA","DEBUG","KOMPILATOR"
};
const int HangmanLogic::DICTIONARY_SIZE =
static_cast<int>(sizeof(DICTIONARY) / sizeof(DICTIONARY[0]));

HangmanLogic::HangmanLogic() {
    used_.fill(false);
    word_.clear();
    mask_.clear();
    lives_ = 0;
    stage_ = 0;
    hintsUsed_ = 0;
}

char HangmanLogic::normalizeLetter(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    if (std::isalpha(uc)) {
        return static_cast<char>(std::toupper(uc));
    }
    return 0;
}

std::string HangmanLogic::chooseWordInRange(int minLen, int maxLen) const {
    std::vector<std::string> candidates;
    candidates.reserve(DICTIONARY_SIZE);
    for (int i = 0; i < DICTIONARY_SIZE; ++i) {
        int d = static_cast<int>(std::strlen(DICTIONARY[i]));
        if (d >= minLen && d <= maxLen) candidates.emplace_back(DICTIONARY[i]);
    }

    std::vector<std::string> pool;
    if (candidates.empty()) {
        pool.assign(DICTIONARY, DICTIONARY + DICTIONARY_SIZE);
    }
    else {
        pool = std::move(candidates);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(pool.size()) - 1);
    return pool[dist(gen)];
}

void HangmanLogic::startNewGame(int minLen, int maxLen, int lives) {
    word_ = chooseWordInRange(minLen, maxLen);
    mask_.assign(word_.size(), '_');
    lives_ = lives;
    stage_ = 0;
    used_.fill(false);
}

bool HangmanLogic::guess(char letter) {
    char L = normalizeLetter(letter);
    if (!L) return false;

    int idx = L - 'A';
    if (idx < 0 || idx >= 26) return false;

    if (used_[idx]) {
        return word_.find(L) != std::string::npos;
    }
    used_[idx] = true;

    bool hit = false;
    for (size_t i = 0; i < word_.size(); ++i) {
        if (word_[i] == L) {
            mask_[i] = L;
            hit = true;
        }
    }
    if (!hit) {
        if (lives_ > 0) { lives_--; stage_++; }
    }
    return hit;
}

char HangmanLogic::hint() {
    for (size_t i = 0; i < word_.size(); ++i) {
        if (mask_[i] == '_') {
            char L = word_[i];
            int idx = L - 'A';
            if (idx >= 0 && idx < 26) used_[idx] = true;
            mask_[i] = L;
            return L;
        }
    }
    return '\0';
}

std::string HangmanLogic::getMasked() const {
    std::string out;
    out.reserve(mask_.size() * 2);
    for (size_t i = 0; i < mask_.size(); ++i) {
        out.push_back(mask_[i]);
        if (i + 1 < mask_.size()) out.push_back(' ');
    }
    return out;
}

std::string HangmanLogic::getUsedLetters() const {
    std::string out;
    bool any = false;
    for (int i = 0; i < 26; ++i) {
        if (used_[i]) {
            any = true;
            out.push_back(static_cast<char>('A' + i));
            out.push_back(' ');
        }
    }
    return any ? out : std::string("-");
}

int HangmanLogic::getLives() const {
    return lives_;
}

int HangmanLogic::getStage() const {
    return stage_;
}

int HangmanLogic::getHintUsed() const
{
    return hintsUsed_;
}
void HangmanLogic::incrementHintUsed() {
    hintsUsed_++;
}
void HangmanLogic::setHintUsed(const int amount) {
    hintsUsed_ = amount;
}

bool HangmanLogic::isWin() const {
    return mask_.find('_') == std::string::npos;
}

bool HangmanLogic::isLoss() const {
    return (lives_ <= 0) && !isWin();
}

std::string HangmanLogic::getWord() const {
    return word_;
}

void HangmanLogic::setPlayerName(const std::string& name) {
    playerName_ = name;
}

const std::string& HangmanLogic::getPlayerName() const {
    return playerName_;
}
