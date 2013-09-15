#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "card.h"

using namespace std;


//Declaration of class "Player" is performed
class Player
{
   //Public members functions are declared   
   public:
       
        Player ();      
        
        void stay ();
        void addCard (Card card);
        void printCards(); 
                            
        void printScore();
        int getScore();
        
        vector<Card> getHand();
        
        bool isPlaying ();
        bool isAlive();
        bool decidedToPlay();
       
   
   //These members are declared as private because they are never directly 
   //accessed by the user     
   private:
   
         vector<Card> hand;
         
         int score;
         
         bool alive;
         bool choiceToPlay;
         bool playing;         
         
         void setAlive(bool newAlive);
         void setChoiceToPlay(bool newChoiceToPlay);         
};

        
#endif

