#include "HangmanLogic.h"




// --- Definicja wbudowanego s³ownika ------
const char* HangmanLogic::SLOWNIK[] = 
{    // statyczna tablica wskaznikow
    "KOMPUTER","PROGRAM","INFORMATYKA","POLITECHNIKA",
    "ALGORYTM","GRA","SIEC","HASLO","KLASA",
    "OBIEKT","FUNKCJA","ZMIENNA","DEBUG","KOMPILATOR"
};
const int HangmanLogic::SLOWNIK_SIZE = static_cast<int>(sizeof(SLOWNIK) / sizeof(SLOWNIK[0])); // oblicza liczbe el w slowniku

// --- Konstruktor =====
HangmanLogic::HangmanLogic() 
{       // ustawia stan poczatkowy gry
    fill(begin(uzyte), end(uzyte), false);  //czysci tablice uzytych liter
    haslo.clear(); // pusty string z losowym haslem
    maska.clear();  // pusta maska
    zycia = 0; //zeruje zycia
    etap = 0;  // etap rysunku
}

// ----Pomocnicze---
char HangmanLogic::Norm(char c) {  
    unsigned char uc = static_cast<unsigned char>(c);
    if (isalpha(uc)) {
        return static_cast<char>(toupper(uc));
    }
    return 0;
}

string HangmanLogic::LosujSlowoZZakresu(int minLen, int maxLen) {    //wybiera slowo
    // zbierz pasujace
    vector<string> kandydaci;    // tyczmasowa liczba slow ktora spelnia warunek dlugosci
    kandydaci.reserve(SLOWNIK_SIZE);
    for (int i = 0; i < SLOWNIK_SIZE; ++i) {
        int d = static_cast<int>(strlen(SLOWNIK[i]));
        if (d >= minLen && d <= maxLen) kandydaci.emplace_back(SLOWNIK[i]);
    }

    // zrod³o do losowania
    vector<string> baza;     //baza z ktoej wyslosujemy slowo
    if (kandydaci.empty()) { //jesli nie bylo slow w podanym zakresie
        baza.assign(SLOWNIK, SLOWNIK + SLOWNIK_SIZE);  //uzyj calego slownika
    }
    else {
        baza = move(kandydaci);  // przenies liste kandydatow do bazy
    }

    // losowanie
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, static_cast<int>(baza.size()) - 1);
    return baza[dist(gen)];
}

//------Start gry--------
void HangmanLogic::NowaGra(int minLen, int maxLen, int zycia_) {
    haslo = LosujSlowoZZakresu(minLen, maxLen);
    maska.assign(haslo.size(), '_');
    zycia = zycia_;
    etap = 0;
    fill(begin(uzyte), end(uzyte), false);
}

// ------- rozgrywka ----
bool HangmanLogic::Zgadnij(char litera) 
{
    char L = Norm(litera);
    if (!L) return false; // nie-litera -pud³o

    int idx = L - 'A';
    if (idx < 0 || idx >= 26) return false;   //jakimœ cudem poza zakresem -odrzuc

    if (uzyte[idx]) 
    {
        // ju¿ byla – nie zmieniaj stanu zwroc czy litera wystêpuje w hasle
        return haslo.find(L) != string::npos;
    }
    uzyte[idx] = true;

    bool traf = false;

    for (size_t i = 0; i < haslo.size(); ++i) 
    {
        if (haslo[i] == L) 
        {
            maska[i] = L;
            traf = true;
        }
    }
    if (!traf) 
    {    // jesli oudlo
        if (zycia > 0) { zycia--; etap++; } // zabierz zycie
    }
    return traf;
}

char HangmanLogic::Podpowiedz() {
    // pierwsza nieodkryta litera
    for (size_t i = 0; i < haslo.size(); ++i) {
        if (maska[i] == '_') {
            char L = haslo[i];
            int idx = L - 'A';
            if (idx >= 0 && idx < 26) uzyte[idx] = true;
            maska[i] = L;
            return L;
        }
    }
    return '\0';
}

// ----- Odczyty ------
string HangmanLogic::PobierzMaskowane() const {
    // np. K _ O M P _ T E R
    string out;
    out.reserve(maska.size() * 2);
    for (size_t i = 0; i < maska.size(); ++i) {
        out.push_back(maska[i]);
        if (i + 1 < maska.size()) out.push_back(' ');
    }
    return out;
}

string HangmanLogic::PobierzUzyteLitery() const {
    string out;
    bool any = false;
    for (int i = 0; i < 26; ++i) {
        if (uzyte[i]) {
            any = true;
            out.push_back(static_cast<char>('A' + i));
            out.push_back(' ');
        }
    }
    return any ? out : string("-");
}

bool HangmanLogic::CzyWygrana() const {
    // wygrana jesli nie ma '_' w masce
    return maska.find('_') == string::npos;
}

bool HangmanLogic::CzyPrzegrana() const {
    return (zycia <= 0) && !CzyWygrana();
}

