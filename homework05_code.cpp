// TJ Liebsch 
// CSCI 201 Homework 5

#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

// Global varible
int players = 6;

// These are the function prototypes
int readFile(string[], string[], int[]);
string whoWon(string[], int[]);


int main() // The main function just creates the arrays and calls the 3 functions
{
  string name[players], team[players];
  int score[players];
  readFile(name, team, score);
  string winner = whoWon(team, score);
  printWinner(name, team, score, winner);

  return 0;
}

int readFile(string name[], string team[], int score[]) // This function fills every array with their corresponding data
{
  int i = 0;
  ifstream fin("scores.txt");

  while (fin >> name[i])
    {
      fin >> team[i] >> score[i];
      i++;
    }
  fin.close();
  return 0;
}

string whoWon(string team[], int score[]) // This function determines who won by adding each team member's score together and finding out which is higher.
{
  int blueTeamScore = 0;
  int whiteTeamScore = 0;
  for (int i = 0; i < players; i++)
    {
      if (team[i] == "Blue")
	blueTeamScore += score[i];
      else if (team[i] == "White")
	whiteTeamScore += score[i];
    }

  if (blueTeamScore > whiteTeamScore)
    return "Blue";
  return "White";

  cout << "We did it." << endl;
}

// This function prints which team won. It also prints the players of the winning team and their scores.
void printWinner(string name[], string team[], int score[], string winner)
{
  cout << "Winning Team: " << winner << endl;
  cout << "Player Score" << endl;

  for (int i = 0; i < players; i++)
    {
      if (team[i] == winner)
	cout << name[i] << " " << score[i] << endl;
    }
}
