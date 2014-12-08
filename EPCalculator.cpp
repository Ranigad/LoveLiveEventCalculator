/*	Name: Ranigad
Date: 12/7/14
Description: A calculator that will use information provided by the user to calculate 
a projected ending event point value. It is called by the main menu and will loop within
itself until the user decides to go back to the menu.

Values passed by the main: User Level, User Experience, User Loveca, 
User's current Event points, User Token Total.

Information needed for calculation: 
- Difficulty to grind for the event song. (String)
- Expected Score and Combo (_getch())
- Multiplier (_getch())

Function will do the following
- Ask for Difficulty and multiplier
- Ask for Score/Combo
- Calculate the expected ending EP
- Check if the given Score/Combo is below the efficiency thresh hold
- Display the values and message
- Offer to exit or go back to a certain part. << Most difficult,
	- Need to reset necessary values.
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include "user.h"
#include "functions.h"

using namespace std;

void getScoreCombo(char&, char&);
void scoreComboCheck(char&);
void getDifficulty(string&, bool&);
void difficultyCheck(string&);

int cost(string, bool);
bool efficient(string, char, char);

void printMenu();
void printResult(string, char, char, int, int, int);

void epCalculator(User profile)
{
	char navigation = '2';
	bool multiplier = false;
	string difficulty;
	char score, combo;
	int timesPlayed, eventEnd, tokenEnd;


	while (navigation != 'q')
	{
		switch (navigation) {
		case '1':
			// Input for Event points and tokens
			cout << "Enter your current total event points: ";
			profile.setEP();

			cout << "Enter your current tokens: ";
			profile.setTokens();

		case '2': // Default case
			// Input for Difficulty and multiplier
			getDifficulty(difficulty, multiplier);
			
		case '3':
			// Score/Combo
			getScoreCombo(score, combo);

		case 'c':
			// calculations
			timesPlayed = profile.getTokens() / cost(difficulty, multiplier);
			eventEnd = profile.getEP() + (pointsPerGame(difficulty, score, combo, multiplier) * timesPlayed);
			tokenEnd = profile.getTokens() - (cost(difficulty, multiplier) * timesPlayed);

			cout << endl << "********************************************************************" << endl;

			// Display
		case 'd':
			printResult(difficulty, score, combo, timesPlayed, tokenEnd, eventEnd);
			if (!efficient(difficulty, score, combo)) cout << "** Try a lower difficulty or higher Score/Combo to get more points per token **" << endl << endl;

			printMenu();

		case 'o':
			cout << endl << "Enter your selection: ";
			navigation = _getch();
			cout << endl << "********************************************************************" << endl;
			break;

		default:
			cout << endl << "Not a valid option. ";
			navigation = 'o';
		}
	}
}

void getScoreCombo(char& score, char& combo)
{

			cout << "Enter your expected score (s/a/b/c/n)" << endl;
			score = toupper(_getch());
			scoreComboCheck(score);
			
			cout << "Enter your expected combo (s/a/b/c/n)" << endl;
			combo = toupper(_getch());
			scoreComboCheck(combo);

}

void scoreComboCheck(char& check)
{
	while (check != 'S' && check != 'A' && check != 'B' && check != 'C' && check != 'N')
	{
		cout << endl << "Please enter a valid option" << endl;
		check = toupper(_getch());
	}
}

void getDifficulty(string& difficulty, bool& multiplier)
{	

	cout << endl << "Enter the Event Song difficulty (Easy, Normal, Hard, Expert): ";
	cin >> difficulty;
	stringFormatter(difficulty);
	difficultyCheck(difficulty);	// Loop in case bad entry
		
	cout << "Will you be playing the 4x Event Song to grind (y/n)" << endl;
	if (_getch() == 'y') multiplier = true;
	else multiplier = false;
}

void difficultyCheck(string& difficulty)
{	

		while ((difficulty.compare("Easy") && difficulty.compare("Normal") && difficulty.compare("Hard") && difficulty.compare("Expert")))
		{
			cout << "Not a valid difficulty! Please try again: " << endl; 
			cin >> difficulty;
			stringFormatter(difficulty);
		}
	
}

void printMenu() {
			cout << "Enter 1 to re-enter your current token and event point totals" << endl
				<< "Enter 2 to choose a different difficulty" << endl
				<< "Enter 3 to choose a different song score/combo level" << endl
				<< "Enter q to exit the calculator." << endl;
}

void printResult(string difficulty, char score, char combo, int timesPlayed, int tokenEnd, int eventEnd)
{
	cout << endl << endl << "Difficulty: " << difficulty << "\t" << "Score: " << score 
		 << "\t" << "Combo: " << combo << endl;
	cout << endl << "Plays: " << timesPlayed << "\t" << "Tokens Left: " << setw(3) << tokenEnd << "\t"
		 << "Event Points: " << eventEnd << endl << endl;
}

int cost(string difficulty, bool fourx) 
{
	int cost = 0;
	if(!difficulty.compare("Easy")) cost = 15;
	else if(!difficulty.compare("Normal")) cost = 30;
	else if(!difficulty.compare("Hard")) cost = 40;
	else if(!difficulty.compare("Expert")) cost = 75;
	else cost = -1;
	
	if (fourx) cost *= 4;
	
	return cost;
}

bool efficient(string difficulty, char score, char combo)
{
	int easy[5][5] = {  { 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 1, 1 } };
	int normal[5][5] = { { 1, 1, 1, 1 },
	{ 1, 1 } };
	int hard[5][5] = { { 1, 1, 1, 1, 1 },
	{ 1, 1 },
	{ 1 } };
	int expert[5][5] = { { 1, 1 } };
	
	if(!difficulty.compare("Easy")) return easy[rankToInt(score)][rankToInt(combo)];
	else if(!difficulty.compare("Normal")) return normal[rankToInt(score)][rankToInt(combo)];
	else if(!difficulty.compare("Hard")) return hard[rankToInt(score)][rankToInt(combo)];
	else if(!difficulty.compare("Expert")) return expert[rankToInt(score)][rankToInt(combo)];
	else exit(5);

}