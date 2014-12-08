/*   Name: Ranigad
     Date: 12/6/14
	 Version: 1.0
	 Description: Recoded the program in order to start using GitHub for version saving.
		
	This is the menu page.
*/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "user.h"
#include "functions.h"
using namespace std;
	

int main()
{
	ifstream userData;
	char navigation = '0';
	int pageNum = 1;
	userData.open("sifUserData.txt");
	
	User profile;
	userData.close();
	
	while (navigation != 'q')
	{
		//mainMenu(pageNum); // Maybe a variable to keep track of pages;
		
		navigation = _getch();
		cout << endl;

		switch(navigation) {
		case '1':
			//updateData(profile);
			break;
		case '2':
			epCalculator(profile);
			break;
		case '3':
			//lovecaCalculator(profile);
			break;
		default:
			cout << "Not a valid entry " << endl;
		}
		cout << endl;
	}
	
	return 0;
}

void stringFormatter(string& input)
{
	for (int i = 0; input[i] != '\0'; i++)
		input[i] = tolower(input[i]);

	input[0] = toupper(input[0]);
}