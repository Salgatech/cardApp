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