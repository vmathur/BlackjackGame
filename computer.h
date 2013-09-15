#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include "deck.h"
#include "player.h"
using namespace std;

class Computer : public Player
{
      public:      
        Computer ();        
        bool decision (Deck mainDeck);    
        void printCards ();
        void show();
};

#endif
