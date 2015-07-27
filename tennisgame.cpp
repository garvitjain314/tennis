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
				scoreBoard.push_back(newScore);
				return;
			}
			cout << "The entered string does not represent a game" << endl;
			return;
		}
    void displayFullScoreboard ( ) {
        for ( int i = 0 ; i < scoreBoard.size() ; i++ ) {
            if (scoreBoard[i].first >= 3 &&  scoreBoard[i].second >=3) {
                if (scoreBoard[i].first==scoreBoard[i].second)
                    cout << "deuce" << endl;
                else if  ( (scoreBoard[i].first + 1) == scoreBoard[i].second )
                    cout << "F advantage" << endl;
                else if ( scoreBoard[i].first == (scoreBoard[i].second + 1 ))
                    cout << "D advantage" << endl;
                else if ( scoreBoard[i].first == (scoreBoard[i].second + 2)) {
                    cout << "D wins" << endl ;
                    return;
                }
                else if ( (scoreBoard[i].first + 2) == scoreBoard[i].second ) {
                    cout << "F wins" << endl;
                    return;
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
                cout << "D-" <<scoreEquivalence[scoreBoard[i].first] << " " << "F-" << scoreEquivalence[scoreBoard[i].second] << endl ;
        }
    }
        void displayCurrentScore ( int i ) {
            if (scoreBoard[i].first >= 3 &&  scoreBoard[i].second >=3) {
                if (scoreBoard[i].first==scoreBoard[i].second)
                    cout << "deuce" << endl;
                else if  ( (scoreBoard[i].first + 1) == scoreBoard[i].second )
                    cout << "F advantage" << endl;
                else if ( scoreBoard[i].first == (scoreBoard[i].second + 1 ))
                    cout << "D advantage" << endl;
                else if ( scoreBoard[i].first == (scoreBoard[i].second + 2))
                    cout << "D wins" << endl ;
                else if ( (scoreBoard[i].first + 2) == scoreBoard[i].second )
                    cout << "F wins" << endl ;
            }
            else if( scoreBoard[i].first > 3 || scoreBoard[i].second > 3 ) {
                if( scoreBoard[i].first - scoreBoard[i].second >= 2 )
                    cout << "D wins" << endl;
                else if ( scoreBoard[i].second - scoreBoard[i].first >= 2 )
                    cout << "F wins" << endl;
            }
            else
                cout << "D-" << scoreEquivalence[scoreBoard[i].first] << " F-" << scoreEquivalence[scoreBoard[i].second] << endl ;
        }
};

int main() {
	TennisGame tennisGame;
	string playerScoreSequence = "FFFDDDDFFFF";
	for(int i=0; i<playerScoreSequence.length(); i++) {
        tennisGame.updateScoreBoard(playerScoreSequence[i]);
	}
	tennisGame.displayFullScoreboard();
	tennisGame.displayCurrentScore(5);
	return 0;
}
