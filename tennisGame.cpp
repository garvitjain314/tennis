#include <iostream>
#include <vector>
#include <map>
using namespace std;



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
};

int main() {
	TennisGame tennisGame;
	string playerScoreSequence = "DFFFDF";
	tennisGame.updateScoreBoard('F');
	tennisGame.updateScoreBoard('D');
	tennisGame.updateScoreBoard('F');
	tennisGame.updateScoreBoard('F');
	return 0; 
}
