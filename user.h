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
	User(std::ifstream&);
	void setLevel();
	void setExp();
	void setLoveca();
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