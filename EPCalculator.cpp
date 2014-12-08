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

int rankToInt(char);

int pointsPerGame(string difficulty, char score, char combo)
{
	int easy[5][5] = { { 65, 64, 62, 61, 60 },
	{ 64, 62, 61, 60, 59 },
	{ 62, 61, 60, 59, 58 },
	{ 59, 58, 57, 56, 55 },
	{ 56, 55, 54, 53, 52 } };
	int normal[5][5] = { { 140, 138, 135, 132, 130 },
	{ 135, 133, 130, 127, 125 },
	{ 130, 128, 125, 123, 120 },
	{ 124, 121, 119, 116, 114 },
	{ 117, 115, 113, 110, 108 } };
	int hard[5][5] = { { 233, 227, 220, 216, 211 },
	{ 223, 216, 210, 206, 202 },
	{ 212, 206, 200, 196, 192 },
	{ 201, 196, 190, 186, 182 },
	{ 191, 185, 180, 176, 173 } };
	int expert[5][5] = { { 404, 393, 371, 363, 356 },
	{ 386, 375, 354, 347, 340 },
	{ 364, 354, 334, 327, 321 },
	{ 346, 336, 317, 311, 305 },
	{ 328, 319, 301, 295, 289 } };

	if(difficulty.compare("Easy")) return easy[rankToInt(score)][rankToInt(combo)];
	else if(difficulty.compare("Normal")) return normal[rankToInt(score)][rankToInt(combo)];
	else if(difficulty.compare("Hard")) return hard[rankToInt(score)][rankToInt(combo)];
	else if(difficulty.compare("Expert")) return expert[rankToInt(score)][rankToInt(combo)];
	else return -1;
}

int cost(string difficulty, bool fourx) 
{
	int cost = 0;
	if(difficulty.compare("Easy")) cost = 15;
	else if(difficulty.compare("Normal")) cost = 30;
	else if(difficulty.compare("Hard")) cost = 40;
	else if(difficulty.compare("Expert")) cost = 75;
	else cost = -1;
	
	if (fourx) cost *= 4;
	
	return cost;
}

bool tooHard(string difficulty, char score, char combo)
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
	
	if(difficulty.compare("Easy")) return easy[rankToInt(score)][rankToInt(combo)];
	else if(difficulty.compare("Normal")) return normal[rankToInt(score)][rankToInt(combo)];
	else if(difficulty.compare("Hard")) return hard[rankToInt(score)][rankToInt(combo)];
	else if(difficulty.compare("Expert")) return expert[rankToInt(score)][rankToInt(combo)];
	else return -1;

}

int rankToInt(char rank)
{
	int intConversion;
	
	if (rank == 'S') intConversion = 0;
	else if (rank == 'A') intConversion = 1;
	else if (rank == 'B') intConversion = 2;
	else if (rank == 'C') intConversion = 3;
	else if (rank == 'N') intConversion = 4;

	return intConversion;
}

void printMenu();
void scoreComboCheck(char&);
void getScoreCombo(char&, char&);
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

			cout << endl << "Enter the Event Song difficulty (Easy, Normal, Hard, Expert): ";
			cin >> difficulty;
			stringFormatter(difficulty);

			if ((difficulty.compare("Easy") && difficulty.compare("Normal")) && (difficulty.compare("Hard") && difficulty.compare("Expert")))
			{
				cout << "Not a valid difficulty! Please try again." << endl << endl;
				navigation = '2';
				continue;
			}
			// Loop in case bad entry

			cout << "Will you be playing the 4x Event Song to grind (y/n)" << endl;
			if (_getch() == 'y') multiplier = true;
			else multiplier = false;

		case '3':
			// Score/Combo
			getScoreCombo(score, combo);

		case 'c':
			// calculations
			timesPlayed = profile.getTokens() / cost(difficulty, multiplier);
			eventEnd = profile.getEP() + (pointsPerGame(difficulty, score, combo) * timesPlayed);
			tokenEnd = profile.getTokens() - (cost(difficulty, multiplier) * timesPlayed);

			cout << "\n********************************************************************";

			// Display
		case 'd':
			printResult(difficulty, score, combo, timesPlayed, tokenEnd, eventEnd);
			if (tooHard(difficulty, score, combo)) cout << endl << "** Try a lower difficulty or higher Score/Combo to get more points per token **" << endl << endl;

			printMenu();

		case 'o':
			cout << endl << "Enter your selection: ";
			navigation = _getch();
			cout << "\n********************************************************************\n";
			break;

		default:
			cout << "Not a valid option. ";
			navigation = 'o';
		}
	}
}

void printMenu() {
			cout << "Enter 1 to re-enter your current token and event point totals" << endl
				<< "Enter 2 to choose a different difficulty" << endl
				<< "Enter 3 to choose a different song score/combo level" << endl
				<< "Enter q to exit the calculator." << endl;
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
		cout << endl << "Please enter a valid option: ";
		check = _getch();
	}
}

void printResult(string difficulty, char score, char combo, int timesPlayed, int tokenEnd, int eventEnd)
{
}

