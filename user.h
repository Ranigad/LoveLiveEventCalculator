#ifndef USER_H
#define USER_H

class User {
private:
	int level;
	int experience;
	int loveca;
	int eventPoints;
	int tokens;

public:
	User(int = 0, int = 0, int = 0, int = 0, int = 0);
	void setLevel(int);
	void setExp(int);
	void setLoveca(int);
	void setEP();
	void setTokens();
	void setAll();

	int getLevel();
	int getExp();
	int getLoveca();
	int getEP();
	int getTokens();
};


#endif