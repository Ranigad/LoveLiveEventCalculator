/*   Name: Ranigad
     Date: 12/7/14
	 Description: Houses all the functions required by more than one calculator/other options that may be needed in the future
*/

#include <iostream>
#include <iomanip>
#include "user.h"
#include "functions.h"
using namespace std;

void stringFormatter(string& input)
{
	for (int i = 0; input[i] != '\0'; i++)
		input[i] = tolower(input[i]);

	input[0] = toupper(input[0]);
}

void userInfo(User profile)
{
	cout << endl << "\t\t Level | Experience | Loveca | Event Pts | Tokens" << endl << "\t\t"
		<< right << setw(6) << profile.getLevel() << " | "
		<< right << setw(4) << profile.getExp() << "/" << left << setw(5) << maxExp(profile.getLevel()) << " | "
		<< right << setw(6) << profile.getLoveca() << " | "
		<< left << setw(9) << profile.getEP() << " | "
		<< profile.getTokens() << endl << endl;

	return;

}

int maxExp(int level)
{
	return (34.45 * level - 551);
}


int pointsPerGame(string difficulty, char score, char combo, bool multiplierFlag)
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

	int multiplier = 1;
	if (multiplierFlag) multiplier = 4;

	if(!difficulty.compare("Easy")) 
		return easy[rankToInt(score)][rankToInt(combo)] * multiplier;
		
	else if(!difficulty.compare("Normal")) 
		return normal[rankToInt(score)][rankToInt(combo)] * multiplier;
		
	else if(!difficulty.compare("Hard")) 
		return hard[rankToInt(score)][rankToInt(combo)] * multiplier;
		
	else if(!difficulty.compare("Expert")) 
		return expert[rankToInt(score)][rankToInt(combo)] * multiplier;
		
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

