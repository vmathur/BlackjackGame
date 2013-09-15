#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;


//Declaration of class "Player" is performed
class Card
{
   //Public members functions are declared   
   public:
       
        Card ();
        Card (int newID, string newName, int newSuit, int newValue);
    
        void setValue(int newValue);
        
        int getID();
        string getName();
        char getSuit();
        int getValue();       

   private:
        
        int ID;
        string name;
        char suit;
        int value;
        
};

#endif
