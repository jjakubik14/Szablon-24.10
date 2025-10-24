#pragma once

#include <string>
#include <algorithm>
#include <random>
#include <vector>
#include <cctype>
#include <cstring> // strlen

using namespace std;

class HangmanLogic {
public:
    HangmanLogic();

    // start nowej gry losuje slowo o d³ugoœci w minLen, maxLen, ustawia ¿ycia
    void NowaGra(int minLen, int maxLen, int zycia_);
    // ruch gracza
    bool Zgadnij(char litera);      // true gdy trafiona
    char Podpowiedz();              // '\0' gdy brak

    // odczyty do UI
    string PobierzMaskowane() const;
    string PobierzUzyteLitery() const;
    int z;
    int    PobierzZycia() const { return zycia; }
    int    PobierzEtap()  const { return etap; }
    int count_hint = 0; //przestaw
    bool   CzyWygrana()   const;
    bool   CzyPrzegrana() const;
    string PobierzHaslo() const { return haslo; }
    string nazwa_gracza_w_oknie;
    //wchar_t nazwa_gracza_w_oknie[64] = L"";

private:
    // pomocnicze
    static char Norm(char c);                   // A..Z lub 0 gdy nie litera
    string     LosujSlowoZZakresu(int minLen, int maxLen);

private:
    // stan gry
    string haslo;   // oryginalne s³owo
    string maska;   // maska z '_' i literami
    int    zycia = 0;
    int    etap = 0;   // liczba pomy³ek

    // s³ownik & u¿yte litery
    static const char* SLOWNIK[]; //string?
    static const int   SLOWNIK_SIZE; //string?
    bool uzyte[26];     // A..Z
    //imie gracza leci w powietrzu ma sie tutaj znajdowac 
};

// int count_hint;