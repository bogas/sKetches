#pragma once
#include <memory>
#include <string>
#include <map>
#include <vector>

using namespace std;
class State
{
public:
	virtual void entry()
	{
		cout << "Entered  " << getName() << endl;
	}
	virtual void doDo()
	{
		cout << "Doing  " << getName() << endl;
	}
	virtual void exit()
	{
		cout << "Exiting  " << getName() << endl;
	}
	virtual string getName() = 0;
};
struct Red;
struct Green;
struct Blue;

struct Red : public State
{
	Red()
	{
		cout << "Creating " << name << "  " << this << endl;
	}
	~Red()
	{
		cout << "Destroying " << name << "  " << this << endl;
	}
	string name = "Red";
	string getName()
	{
		return name;
	}
};

struct Blue : public State
{
	~Blue()
	{
		cout << "Destroying " << name << "  " << this << endl;
	}
	Blue()
	{
		cout << "Creating " << name << "  " << this << endl;
	}
	string name = "Blue";
	string getName()
	{
		return name;
	}
};

struct Green : public State
{
	~Green()
	{
		cout << "Destroying " << name << "  " << this << endl;
	}
	Green()
	{
		cout << "Creating " << name << "  " << this << endl;
	}
	string name = "Green";
	string getName()
	{
		return name;
	}
};

struct StateMachine
{
	void start();

	void run();

	bool updateState( char c );

	static Red Red_state;
	static Blue Blue_state;
	static Green Green_state;

	map< State*, map< char, State* > > transitions
		= { { &Red_state, { { 'n', &Green_state } } },
			{ &Blue_state, { { 'n', &Red_state }, { 'p', &Green_state } } },
			{ &Green_state, { { 'n', &Blue_state }, { 'p', &Green_state } } } };

private:
	State* currentState;
};
