#include <iostream>
#include <vector>
#include <map>
using namespace std;

const  int scoreEquivalence[] = { 0 , 15 , 30 , 40} ;

class TennisGame {
	vector< pair<int, int> > scoreBoard;
	//first->D, second->F
	bool tie;

	bool isValid(pair<int, int> score) {
		return true;
	}

	public:
		TennisGame() {
			scoreBoard.push_back(pair<int,int>(0,0));
		}

		void updateScoreBoard(char scorer) {
			pair<int, int> currentScore = scoreBoard[scoreBoard.size() - 1];
			pair<int, int> newScore = scorer == 'D' ? pair<int, int> (currentScore.first + 1, currentScore.second) : pair<int, int> (currentScore.first, currentScore.second + 1);
			if(isValid(newScore)){
				cout << newScore.first << " ";
				cout << newScore.second << endl ;
				scoreBoard.push_back(newScore);
				return;
			}
			cout << "The entered string does not represent a game" << endl;
			return;
		}
		void displayWholeScoreboard ( int index ) {
        for ( int i = 0 ; i <= index ; i++ ) {

            if (scoreBoard[i].first >= 3 &&  scoreBoard[i].second >=3) {
                if (scoreBoard[i].first==scoreBoard[i].second)
                    cout << "deuce" << endl;
                else if  ( (scoreBoard[i].first + 1) == scoreBoard[i].second )
                    cout << "F advantage" << endl;
                else if ( scoreBoard[i].first == (scoreBoard[i].second + 1 ))
                    cout << "D advantage" << endl;
                else if ( scoreBoard[i].first == (scoreBoard[i].second + 2)) {
                    cout << "D wins" << endl ;
                    break;
                }

                else if ( (scoreBoard[i].first + 2) == scoreBoard[i].second ) {
                    cout << "F wins" << endl;
                    break;
                }

            }
            else if( scoreBoard[i].first > 3 || scoreBoard[i].second > 3 ) {
                if( scoreBoard[i].first - scoreBoard[i].second >= 2 ) {
                    cout << "D wins" << endl;
                    break;
                }

                else if ( scoreBoard[i].second - scoreBoard[i].first >= 2 ) {
                    cout << "F wins" << endl;
                }

            }
            else
                    cout << scoreEquivalence[scoreBoard[i].first] << " " << scoreEquivalence[scoreBoard[i].second] << endl ;
        }
        }
        void displayCurrentScore ( int i ) {
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
                cout << scoreEquivalence[scoreBoard[i].first] << " " << scoreEquivalence[scoreBoard[i].second] << endl ;
        }
};

int main() {
	TennisGame tennisGame;
	string playerScoreSequence = "FFFDDDDFFFF";
	for(int i=0; i<playerScoreSequence.length(); i++) {
        tennisGame.updateScoreBoard(playerScoreSequence[i]);
	}
	tennisGame.displayWholeScoreboard(11);
	return 0;
}
