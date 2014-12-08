/*   Name: Ranigad
     Date: 12/7/14
	 Description: Allows users to update their information
*/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "user.h"
#include "functions.h"
using namespace std;

void displayMenu();
void saveInfo(User profile);

void updateData(User profile)
{
	char navigation = 'q';
	const char ALLCASE = '4';
	
	userInfo(profile);
	displayMenu();
	
	while (navigation == 'q')
	{
		navigation = _getch();
		cout << endl;
		
		switch(navigation) {
			case '4':
			case '1':
				profile.setLevel();
				profile.setExp();
				if (navigation != ALLCASE) break;
			case '2':
				profile.setLoveca();
				if (navigation != ALLCASE) break;
			case '3':
				profile.setEP();
				profile.setTokens();
				break;
			case 'q':
			break;
			default:
				cout << "That's not a valid entry. Please select one of the listed options: ";
				navigation = 'q';
		}
	}

	saveInfo(profile);
	
}

void displayMenu()
{
	cout << "*******************************************************************************" << endl
		<< "* _________________________                                             ___   *" << endl
		<< "* Current Level                                                               *" << endl
		<< "* & Current Exp                                                          1    *" << endl
		<< "*                                                                             *" << endl
		<< "* _________________________                                             ___   *" << endl
		<< "* Total Loveca                                                           2    *" << endl
		<< "* _________________________                                             ___   *" << endl
		<< "* Total Event Points                                                          *" << endl
		<< "* & Tokens Remaining                                                     3    *" << endl
		<< "*                                                                             *" << endl
		<< "* _________________________                                             ___   *" << endl
		<< "* All of the Above                                                       4    *" << endl
		<< "* _________________________                                             ___   *" << endl
		<< "*                                                                             *" << endl
		<< "* Return to Main Menu                                                    q    *" << endl
		<< "*                                                                             *" << endl
		<< "*******************************************************************************" << endl
		<< endl << "What would you like to update? ";
}

void saveInfo(User profile)
{
	ofstream saveFile;
	saveFile.open("sifUserData.txt");

	saveFile << setw(8) << left << profile.getLevel()
			 << setw(8) << left << profile.getExp()
			 << setw(8) << left << profile.getLoveca()
			 << setw(8) << left << profile.getEP()
			 << setw(8) << left << profile.getTokens()
			 << endl;
	
	saveFile << endl << "Level   |" << " Exp     |" << " Loveca  |" << " EPoints |" << " Tokens  |";
	saveFile.close();
}