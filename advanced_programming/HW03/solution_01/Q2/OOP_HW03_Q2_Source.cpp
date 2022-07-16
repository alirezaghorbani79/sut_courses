#include <iostream>

using namespace std;


class Tool
{
public:
	Tool();
	Tool(int strength)
	{
		setStrength(strength);
	}
	void setStrength(int strength)
	{
		this->strength = strength;
	}
	int getStrength(void)
	{
		return strength;
	}
	char getType(void)
	{
		return type;
	}

protected:
	int strength;
	char type;
};


class Rock;
class Paper;


class Scissors : public Tool
{
public:
	Scissors();
	Scissors(int strength) : Tool(strength)
	{
		Tool::type = 's';
	}
	bool fight(Tool t)
	{
		float adjStrength = 1;
		if (t.getType() == 'p')
			adjStrength *= 2;
		if (t.getType() == 'r')
			adjStrength /= 2;
		return (adjStrength * this->getStrength() > t.getStrength());
		return 0;
	}
private:

};

class Paper : public Tool
{
public:
	Paper();
	Paper(int strength) : Tool(strength)
	{
		type = 'p';
	}
	bool fight(Tool t)
	{
		float adjStrength = 1;
		if (t.getType() == 'r')
			adjStrength *= 2;
		if (t.getType() == 's')
			adjStrength /= 2;
		return (adjStrength * this->getStrength() > t.getStrength());
	}
private:

};


class Rock : public Tool
{
public:
	Rock();
	Rock(int strength) : Tool(strength) 
	{
		type = 'r';
	}
	bool fight(Tool t)
	{
		float adjStrength = 1;
		if (t.getType() == 's')
			adjStrength *= 2;
		if (t.getType() == 'p')
			adjStrength /= 2;
		return (adjStrength * this->getStrength() > t.getStrength());
	}
private:
};


int main() 
{
	
	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);


	cout << s1.fight(p1) << " " << p1.fight(s1) << endl;
	cout << p1.fight(r1) << " " << r1.fight(p1) << endl;
	cout << r1.fight(s1) << " " << s1.fight(r1) << endl;
}