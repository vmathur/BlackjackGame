#include "player.h"
#include "computer.h"
#include "card.h"
#include "deck.h"
#include <cstdlib> 
#include <ctime> 

#include <iostream>
using namespace std;

int randomNumberGenerator(int max);

int main()
{
  int playgame = 1;
  int choiceNum = 1;

  bool valid = true;
  bool roundContinue = true;     
  
  int gamesPlayed=0;
  int gamesWon=0;
  int gamesLost=0;
   
  
  cout <<"Welcome to Blackjack"<<endl; 
     
  do
  {
      cout <<"Starting a game..."<<endl; 
      cout<<endl;    
      gamesPlayed++;
      
      Deck mainDeck;
      Player human; 
      Computer dealer;      

      human.addCard(mainDeck.takeCard(randomNumberGenerator(mainDeck.getSize())));
      human.addCard(mainDeck.takeCard(randomNumberGenerator(mainDeck.getSize())));
      
      dealer.addCard(mainDeck.takeCard(randomNumberGenerator(mainDeck.getSize())));
      dealer.addCard(mainDeck.takeCard(randomNumberGenerator(mainDeck.getSize())));
         
      human.printCards();
      dealer.printCards();

      do
      {
         if (human.isPlaying())
         {                                   
             do
             {
                cout<<"Select 1 to hit and 0 to stay"<<endl;                 
                cin  >> choiceNum;

                 if (choiceNum==1||choiceNum==0)
                       valid = true;
                 else
                 {
                       valid = false;
                       cout <<"Invalid selection! Try again"<<endl;
                 }                 
             }while (!valid);
             
             if (choiceNum==1)
             {
                cout<<"YOU DECIDED ON HIT"<<endl;
                cout<<endl;             
                human.addCard(mainDeck.takeCard(randomNumberGenerator(mainDeck.getSize())));
             }
             else
             {
                cout<<"YOU DECIDED ON STAY"<<endl;
                cout<<endl;           
                human.stay();      
             }       
             
             human.printCards();
         }
         
         
         if (dealer.isPlaying())
         {
             if (dealer.decision(mainDeck))
             {
                   cout<<"DEALER DECIDED ON HIT"<<endl;
                   dealer.addCard(mainDeck.takeCard(randomNumberGenerator(mainDeck.getSize())));
             }
             else
             {
                   cout<<"DEALER DECIDED ON STAY"<<endl;
                   dealer.stay();                   
             }             
             dealer.printCards();
         }

         if (human.decidedToPlay() || dealer.decidedToPlay())
           roundContinue = true;
         else
           roundContinue = false;
         
         if (!human.isAlive() || !dealer.isAlive())
           roundContinue= false;
         
                 
      }while (roundContinue);
      
      cout <<"Show cards!"<<endl;
      cout<<endl;   
      dealer.show();
      
      if (human.isAlive() && !dealer.isAlive())
      {
         cout <<"Dealer went over!"<<endl;
         cout <<"You win!"<<endl;
         gamesWon++;
      }
      else if (!human.isAlive() && dealer.isAlive())  
      {
         cout <<"You went over!"<<endl;
         cout <<"You lose!"<<endl;
         gamesLost++;
      }
      else if (!human.isAlive() && !dealer.isAlive())
      {
         cout <<"You both went over!"<<endl;
         cout <<"Draw!"<<endl;
      }
      else
      {
          if (human.getScore()>dealer.getScore())
          {
             cout<<"You are closer to 21"<<endl;
             cout<<"You win!"<<endl;
             gamesWon++;
          }
          else if (human.getScore()<dealer.getScore())
          {
             cout<<"Dealer is closer to 21"<<endl;
             cout<<"You lose!"<<endl;
             gamesLost++;
          }    
          else 
          {
             cout<<"You are both equally close to 21"<<endl;
             cout<<"Draw!"<<endl;
          }          
      }
       cout<<endl; 
       cout<<endl;     
       cout<<"Select 1 to play again or anything else to quit"<<endl;  
       cin >>playgame;
             
  }while (playgame==1);
  
  cout<<endl;     
  cout<<endl;      
  cout << "Thanks for playing!" << endl;       
    
  system ("pause");
  return 0;

}

int randomNumberGenerator(int max) //http://www.daniweb.com/software-development/cpp/threads/1769/c-random-numbers
{
    srand((unsigned)time(0)); 
    int random_integer;   
    random_integer = (rand()%max)+1; 
    
    return random_integer;
}
