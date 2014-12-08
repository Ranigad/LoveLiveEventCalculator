#include "user.h"
#include <iostream>
using namespace std;

User::User(int lvl, int exp, int love, int eP, int tok)
{
	level = lvl;
	experience = exp;
	loveca = love;
	eventPoints = eP;
	tokens = tok;
}

void User::setLevel(int lvl) {
	level = lvl;
}
void User::setExp(int exp) { experience = exp; }
void User::setLoveca(int lvca) { loveca = lvca; }
void User::setEP(){ cin >> eventPoints; }
void User::setTokens() {
	cin >> tokens;
}
void setAll() {};

int User::getLevel() { return level; }
int User::getExp(){ return experience; }
int User::getLoveca(){ return loveca; }
int User::getEP(){ return eventPoints; }
int User::getTokens() { return tokens; }