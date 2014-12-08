/*   Name: Ranigad
     Date: 12/7/14
	 Description: Houses the "user" class. Used to practice classes. Holds all the user information.
*/

#include <fstream>
#include <iostream>
#include "user.h"
using namespace std;

User::User(int lvl, int exp, int love, int eP, int tok)
{
	level = lvl;
	experience = exp;
	loveca = love;
	eventPoints = eP;
	tokens = tok;
}

User::User(ifstream& savedInfo)
{
	savedInfo >> level >> experience >> loveca >> eventPoints >> tokens;
}

void User::setLevel() {cout << "Enter your current level: "; cin >> level;}
void User::setExp() { cout << "Enter your current total experience: "; cin >> experience; }
void User::setLoveca() { cout << "Enter your current loveca total: "; cin >> loveca; }
void User::setEP(){ cout << "Enter your current event point total: "; cin >> eventPoints; }
void User::setTokens() {cout << "Enter your current event token total: "; cin >> tokens;}
void setAll() {};

int User::getLevel() { return level; }
int User::getExp(){ return experience; }
int User::getLoveca(){ return loveca; }
int User::getEP(){ return eventPoints; }
int User::getTokens() { return tokens; }