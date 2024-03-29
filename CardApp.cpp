/*
 * 18/01/21 - Created by Salgatech
 *
 * Small Card application to develop
 * knowledge in C++.
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "dealer.h"
#include "deck.h"
#include "card.h"
#include "numOfCard.h"
#include "card.h"
using namespace std;

 /* DIAGS1 turns on command line processing to show
  * each shuffle of the deck when shuffle() is
  * called - 27/05/23 SAG
  */
#define DIAG1 0

 /* DIAGS2 turns on Diagnostic file output of before
  * and after calling shuffle - 27/05/23 SAG
  */
#define DIAG2 1

enum suit{
    hearts = 0,
    spades = 1,
    clubs = 2,
    diamonds = 3
};

enum numOfCard{
    one = 0,
    two = 1,
    three = 2,
    four = 3,
    five = 4,
    six = 5,
    seven = 6,
    eight = 7,
    nine = 8,
    ten = 9,
    jack = 10,
    queen = 11,
    king = 12,
    ace = 13
};

#define decksize 55

class card{
  public:
    card(void){};
    card(numOfCard cardNum, suit currSuit):number(cardNum),cardSuit(currSuit){};

    char* getCardSuit(void){
      switch(cardSuit){
        case hearts:
        {
          static char h[7] = {'H','E','A','R','T','S','\0'};
          return h;
        }
        case spades:
        {
          static char s[7] = {'S','P','A','D','E','S','\0'};
          return s;
        }
        case clubs:
        {
          static char c[6] = {'C','L','U','B','S','\0'};
          return c;
        }
        case diamonds:
        {
          static char d[9] = {'D','I','A','M','O','N','D','S','\0'};
          return d;
        }
        default:
        {
          static char e[6] = {'E','R','R','O','R','\0'};
          return e;
        }
      }
    }

    char* getCardNum(void){
      switch(number){
        case one:
        {
          static char o[4] = {'O','N','E','\0'};
          return o;
        }
        case two:
        {
          static char tw[4] = {'T','W','O','\0'};
          return tw;
        }
        case three:
        {
          static char th[6] = {'T','H','R','E','E','\0'};
          return th;
        }
        case four:
        {
          static char fo[5] = {'F','O','U','R','\0'};
          return fo;
        }
        case five:
        {
          static char fi[5] = {'F','I','V','E','\0'};
          return fi;
        }
        case six:
        {
          static char si[4] = {'S','I','X','\0'};
          return si;
        }
        case seven:
        {
          static char se[6] = {'S','E','V','E','N','\0'};
          return se;
        }
        case eight:
        {
          static char ei[6] = {'E','I','G','H','T','\0'};
          return ei;
        }
        case nine:
        {
          static char ni[5] = {'N','I','N','E','\0'};
          return ni;
        }
        case ten:
        {
          static char te[4] = {'T','E','N','\0'};
          return te;
        }
        case jack:
        {
          static char ja[5] = {'J','A','C','K','\0'};
          return ja;
        }
        case queen:
        {
          static char qu[6] = {'Q','U','E','E','N','\0'};
          return qu;
        }
        case king:
        {
          static char ki[5] = {'K','I','N','G','\0'};
          return ki;
        }
        case ace:
        {
          static char ac[4] = {'A','C','E','\0'};
          return ac;
        }
        default:
        {
          static char e[6] = {'E','R','R','O','R','\0'};
          return e;
        }
      }
    }
private:
  numOfCard number;
  suit cardSuit;
};

class deck{
  public:
    deck(void){
    unsigned int counter = 0;
      for(int j = 0;j<4;j++){
        for(int k = 0;k<=13;k++){
          curDeck[counter++]=card(numOfCard(k),suit(j));
        }
      }
    }

    card getDeckELMT(int index){
      return curDeck[index];
    }
	
//	void setDeckELMT(int index, vector<card>& vec){ // 09/12/21 SAG
//  Renamed parameter name to a more memorable name. // 27/05/23 SAG
    void setDeckELMT(int index, vector<card>& curnt_crd_elmt){
      curDeck[index] = curnt_crd_elmt[index];
    }

  private:
  card curDeck[decksize];
};

class dealer{
public:
    dealer()
    {
      dealerDeck=deck();
    }

    void printDeck(ofstream &d){
      for(int i=0;i<=decksize;i++){
#if DIAG2
        if(d){
          d << "The "<< dealerDeck.getDeckELMT(i).getCardNum() << " of "<< dealerDeck.getDeckELMT(i).getCardSuit() << endl;
        }
#endif
#if DIAG1
        cout << "The "<< dealerDeck.getDeckELMT(i).getCardNum() << " of "<< dealerDeck.getDeckELMT(i).getCardSuit() << endl;
#endif
      }
#if DIAG1
//      cout << "Size of deck = "<< (sizeof(getDeckELMT(i))/sizeof(getDeckELMT(i)) << endl;
#endif
    }

    void shuffle(void){
#if DIAG1
      cout << "\n" << "Shuffling... " << "\n" << endl;
#endif
      vector<card> tempDeckCopy;
      vector<card> tempDeck;
#if DIAG1
      cout << "Filling tempDec... " << endl;
#endif
      for(int i = 0;i<decksize;i++){
        tempDeck.push_back(dealerDeck.getDeckELMT(i));
      }
      for(int i = 0;i < decksize;i++){
#if DIAG1
        cout << "Iteration: " << i << endl;
        cout << "tempDeck size before shuffle = " << tempDeck.size() << endl;
        cout << "tempDeckCopy size before shuffle = " << tempDeckCopy.size() << endl;
#endif
        int randNum = (rand()%tempDeck.size());
#if DIAG1
        cout << "randNum = " << randNum << endl;
#endif
        tempDeckCopy.push_back(tempDeck[randNum]);
#if DIAG1
        cout << "randNum tempDeck[" << randNum<< "]= " << tempDeck[randNum].getCardNum() << "&" << tempDeck[randNum].getCardSuit() << endl;
#endif
        tempDeck.erase(tempDeck.begin()+randNum);
#if DIAG1
        cout << "tempDeck size after shuffle = " << tempDeck.size() << endl;
        cout << "tempDeckCopy size after shuffle = " << tempDeckCopy.size() << endl;
        cout << endl;
#endif
      }
      for(int i = 0;i < decksize;i++){
        dealerDeck.setDeckELMT(i,tempDeckCopy); // 09/12/21 SAG
      }
    }
private:
    deck dealerDeck;
};

int main(void){
    srand((unsigned) time(0));
    dealer Dan;
#if DIAG2 || DIAG1
    ofstream diagsBefore("diagsBefore.txt"); // 27/05/23 SAG
    ofstream diagsAfter("diagsAfter.txt");   // 27/05/23 SAG
    if(diagsBefore){
      diagsBefore << "\n" << "**Before Shuffling**" << "\n" << endl;
    }
    Dan.printDeck(diagsBefore);
    diagsBefore.close();
    Dan.shuffle();
    if(diagsAfter){
      diagsAfter << "\n" << "**After Shuffling**" << "\n" << endl;
    }
    Dan.printDeck(diagsAfter);
    diagsAfter.close();
#endif
    return 0;
}

/* END OF FILE COMMENTS
 * 09/12/21 SAG - Change to deck and dealer class
 *                to add a definition for and call
 *                to setDeckELMT(), in order to
 *                to change the dealer deck data
 *                member after being shuffled.
 * 27/05/23 SAG - Change to add comments for
 *                diagnostic macros at the top of
 *                files.
 *                Change to setDeckELMT to make
 *                second parameter more memorable
 *                simply "vec".
 *                Change to main() to edit
 *                extension of diagnositc files
 *                from "*.doc" to "*.txt".
 */
