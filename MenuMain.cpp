/*   Name: Ranigad
     Date: 12/6/14
	 Version: 1.0
	 Description: Recoded the program in order to start using GitHub for version saving. Features include:
	 
	 1. A main menu with unbuffered menu selection
	 2. Ability to save data for retention across program runs
	 3. An option to update/change your data.
	 4. The classic event point calculator.
		
	 Future option: 
	 1. A calculator to approximate how much loveca needed to reach a target amount of event points
	 2. A separate display page for details on an option
	 This is the menu page.
*/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "user.h"
#include "functions.h"
using namespace std;
	
void mainMenu(int);

int main()
{
	ifstream userData;
	char navigation = '0';
	int pageNum = 1;
	
	while (navigation != 'q')
	{
		userData.open("sifUserData.txt");
		User profile(userData);
		userData.close();

		userInfo(profile);
		mainMenu(pageNum); 
		
		navigation = _getch();
		cout << endl;

		switch(navigation) {
		case '1':
			updateData(profile);
			break;
		case '2':
			epCalculator(profile);
			break;
		case '3':
			//lovecaCalculator(profile);
			break;
		case 'q': continue;
		default:
			cout << "Not a valid entry " << endl;
		}
		cout << endl;
	}
	
	return 0;
}

void mainMenu(int pageNumber)
{

	if (pageNumber == 1)
	{
	cout << "*******************************************************************************" << endl
		<< "* Change User Information                                                     *" << endl
		<< "*                                                                        1    *" << endl
		<< "*    [Update the values for your level, exp, eventpoints, etc.]               *" << endl
		<< "* _________________________                                             ___   *" << endl
		<< "* Event Point Calculator                                                      *" << endl
		<< "*                                                                        2    *" << endl
		<< "*    [Calculates your end event point total after using your tokens]          *" << endl
		<< "* _________________________                                             ___   *" << endl
		<< "* Loveca Needed Calculator                                                    *" << endl
		<< "*                                                                             *" << endl
		<< "*    [Calculates approximately how much loveca you need                  3    *" << endl
		<< "*       to reach a target event point total]                                  *" << endl
		<< "* _________________________                                             ___   *" << endl
		<< "*                                                                             *" << endl
		<< "* Exit the program                                                       q    *" << endl
		<< "*                                                                             *" << endl
		<< "*******************************************************************************" << endl
		<< endl << endl << "Enter the key corresponding to the desired option: ";
	}
	return;
}



