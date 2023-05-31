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