#include "card.h"
    
     
     Card:: Card ()
     {
          ID=1;
          name = "undefined";
          suit = 10;
          value = 0; 
     }     
    
     Card ::Card (int newID, string newName, int newSuit, int newValue)
     {
          ID = newID;
          name = newName;
          suit = newSuit;
          value = newValue;
     }
     
     void Card:: setValue(int newValue)
     {
          value = newValue;
     }
   
    
     int Card :: getID()
     {
          return ID;
     }
     
     string Card :: getName()
     {
          return name;
     }
     
     char Card :: getSuit()
     {
          return suit;
     }
     
     int Card :: getValue()
     {
          return value;
     }

                   
