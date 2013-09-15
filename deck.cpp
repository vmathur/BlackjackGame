#include "deck.h"
#include "card.h"
#include <stdio.h>
#include <math.h>    
#include <vector>
     
     Deck :: Deck ()
     {
          int tempID=1;
          string tempName="undefined";
          char tempSuit=5;
          int tempValue=0;
          
          for (int i=0; i<=51; i++)
          {
              tempID = i+1;
              tempName = initializeName(tempID);
              tempSuit  = initializeSuit(tempSuit);
              tempValue = initializeValue(tempID);  
                            
              Card card(tempID, tempName, tempSuit, tempValue);
              cards.push_back(card);         
          }
     }
     
     Card Deck :: takeCard ( int index )
     {
          Card tempCard;
          tempCard = cards[index];
          
          cards.erase(cards.begin() + (index-1));         
          
          return tempCard;           
     }
     
     Card Deck :: getCard(int index)
     {
          return cards[index];
     }
     
     
     void Deck::print ()
     {
          for (int i=0;i<cards.size();i++)
          {
              cout<<"ID   : "<<cards[i].getID()<<endl;
              cout<<"Name : "<<cards[i].getName()<<endl;
              cout<<"Suit : "<<cards[i].getSuit()<<endl;
              cout<<"Value: "<<cards[i].getValue()<<endl;
              cout<<endl;  
          }   
          
     }
     
     int Deck :: getSize()
     {
         return cards.size();
     }
     
     string Deck ::initializeName(int tempID)
     {
            if (tempID>=1&&tempID<=4)
               return "Ace";
            else if (tempID>=5&&tempID<=8)
               return "2";
            else if (tempID>=9&&tempID<=12)
               return "3";
            else if (tempID>=13&&tempID<=16)
               return "4";
            else if (tempID>=17&&tempID<=20)
               return "5";
            else if (tempID>=21&&tempID<=24)
               return "6";
            else if (tempID>=25&&tempID<=28)
               return "7";
            else if (tempID>=29&&tempID<=32)
               return "8";
            else if (tempID>=33&&tempID<=36)
               return "9";
            else if (tempID>=37&&tempID<=40)
               return "10";
            else if (tempID>=41&&tempID<=44)
               return "Jack";
            else if (tempID>=45&&tempID<=48)
               return "Queen";
            else if (tempID>=49&&tempID<=52)
               return "King";
            else
               return "Undefined";            
     }
     
     int  Deck ::initializeSuit(int tempSuit)
     {
         if (tempSuit==6)
                 return 3;
         else
         {
             tempSuit++;
             return tempSuit++;
         }
     }
   
     int  Deck :: initializeValue(int tempID)
     {
          double temptempID = tempID;
          double tempDouble;
          int tempValue;
          
          if (tempID>37)
             tempValue= 10;
          else
          {
              tempDouble = ceil (temptempID/4.0);
              tempValue = tempDouble;
          }
          
          return tempValue;          
     }
