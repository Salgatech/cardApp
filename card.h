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