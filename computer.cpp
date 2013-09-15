#include "computer.h"
#include "deck.h"

Computer :: Computer ()
{

}

bool Computer :: decision (Deck deck)
{
    int maxVal = 21 - (Player :: getScore());
    int cardsOver=0;
        
    for (int i=0;i<deck.getSize();i++)
        if (deck.getCard(i).getValue()>maxVal)
           cardsOver++;
    
    if ((((double)cardsOver)/deck.getSize()) >0.50)
        return false;
    else
        return true;         
               
    /*
    cout <<"COMPUTER DECISION MAKING: "<<endl;
    cout <<endl;
    cout <<endl;
    cout <<"Score: "<<Player :: getScore ()<<endl;
    cout <<"maxVal: "<<maxVal<<endl;
    cout <<"deck size: "<<deck.getSize()<<endl; 
    cout <<"cards over :" <<cardsOver<<endl;
    */   
}

void Computer :: printCards()
{
    vector <Card> hand = Player :: getHand();
    
    cout <<"Dealer's Cards"<<endl;
    
    for (int i = 0; i<hand.size(); i++)
    {
         if (i == 0)
            cout << "Card 1: ????"<<endl;
         else  
            cout<<"Card "<<i+1<<": "<<hand[i].getName()<<hand[i].getSuit()<<endl;
    }         
    //cout<<endl;
    //cout<<"Score :"<<Player :: getScore()<<endl;
                    
    cout <<endl;
}

void Computer :: show()
{
    vector <Card> hand = Player :: getHand();
    
    cout <<"Dealer's Cards"<<endl;
    
    for (int i = 0; i<hand.size(); i++) 
            cout<<"Card "<<i+1<<": "<<hand[i].getName()<<hand[i].getSuit()<<endl;       
    cout<<endl;
    cout<<"Score :"<<Player :: getScore()<<endl;
    cout <<endl;
}
     
