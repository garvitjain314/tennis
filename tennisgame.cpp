
#include <iostream>
#include <vector>
using namespace std;

const  int scoreEquivalence[] = { 0 , 15 , 30 , 40} ;

class TennisGame {
    vector < pair< int , int > > scoreBoard  ;
    bool tie ;
private :
    TennisGame() {
        scoreBoard.push_back(make_pair(0,0)) ;
        tie = false ;
    }
public :
    void displayWholeScoreboard ( int index ) {
        for ( int i = 0 ; i <= index ; i++ ) {
            if( scoreBoard[i].first > 3 || scoreBoard[i].second > 3 ) {
                if( scoreBoard[i].first - scoreBoard[i].second >= 2 )
                    cout << "D wins" ;
                else if ( scoreBoard[i].second - scoreBoard[i].first >= 2 )
                    cout << "F wins" ;
            }
            else if (scoreBoard[i].first >= 4 &&  scoreBoard[i].second >=4) {
                if (scoreBoard[i].first==scoreBoard[i].second)
                    cout << "deuce" ;
                else if  (scoreBoard[i].first  + 1==scoreBoard[i].second )
                    cout << "F advantage" ;
                else if (scoreBoard[i].first == scoreBoard[i].second + 1 )
                    cout << "D advantage" ;
                else if ( scoreBoard[i].first == scoreBoard[i].second + 2)
                    cout << "D wins" ;
                else if ( scoreBoard[i].first + 2 == scoreBoard[i].second )
                    cout << "F wins" ;
            }
            else
                cout << scoreEquivalence[scoreBoard[i].first] << " " << scoreEquivalence[scoreBoard[i].second] ;
        }
    }
};

int main() {
cout < "done";

}
