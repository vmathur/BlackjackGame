#include "player.h"
#include <vector>
        
        Player :: Player ()
        {
             score =0;
             alive = true;
             choiceToPlay = true;
        }     

        void Player :: stay()
        {
             setChoiceToPlay(false);
        }
        
        void Player :: addCard(Card card)
        {
             hand.push_back(card);
             score = score + card.getValue();
             
             
             if (score>21)
                setAlive(false);

        }
        
        void Player :: printCards()
        {
             cout <<"My Cards"<<endl;
            
             for (int i = 0; i<hand.size(); i++)
             {
                 cout<<"Card "<<i+1<<": "<<hand[i].getName()<<hand[i].getSuit()<<endl;
             }               
             cout <<endl;
             
             cout<<"Score : "<<score<<endl;
             cout <<endl;
        }
        
        bool Player :: isPlaying ()
        {    
             if (choiceToPlay && alive)
                return true;
             else
                return false;
        }
        
        bool Player :: isAlive()
        {
             return alive;
        }
        
        bool Player :: decidedToPlay()
        {
             return choiceToPlay;
        }
        
        void Player:: setAlive (bool newAlive)
        {
             alive = newAlive;
        }
        
        void Player :: setChoiceToPlay(bool newChoiceToPlay)
        {
             choiceToPlay = newChoiceToPlay;
        }

        
        void Player :: printScore()
        {
             cout << score << endl;
        }
        
        int Player :: getScore()
        {
             return score;
        }
        
        vector<Card> Player :: getHand()
        {
             return hand;
        }
