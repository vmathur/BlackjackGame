#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "card.h"
using namespace std;


class Deck
{
   public:
       
        Deck ();        
        Card takeCard ( int index );
        
        Card getCard(int index);
        
        void print();
        int getSize();

   private:
        
        vector<Card> cards;                 
        
        string initializeName(int tempID);
        int initializeSuit(int tempSuit);
        int initializeValue(int temptempID);
};

#endif
