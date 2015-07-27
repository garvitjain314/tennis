#Problem Statement:
For a given game of Tennis in the form of a string where each character represents the player/side who has scored the point at any point of time, the two sides being D and F, the programs calculates the score after any input number of services.

#Design

const int scoreEquivalece[] = {0,15,30,45,....}

Class TennisGame;

public:
  pair<int, int> scoreBoard[];

private:
  void updateScoreBoard(char scorer, pair<int, int> currentScore);

public:
  void displayScoreboard(int index);
