#pragma once
#include <memory>
#include <string>
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

		char transition;

		cin >> transition;
		setStateNext( getNextState( transition ) );
	}
	virtual void exit()
	{
		cout << "Exiting  " << getName() << endl;
	}

	virtual void setStateNext( shared_ptr< State > )   = 0;
	virtual shared_ptr< State > getNextState( char c ) = 0;
	virtual string getName()						   = 0;
};

struct StateMachine
{
	void start();

	void setState( shared_ptr< State > state );

	void run();

	void updateState();

private:
	shared_ptr< State > currentState;
	shared_ptr< State > nextState;
};

struct Red : public State
{
	explicit Red( StateMachine& sm ) : sm( sm ) {}
	~Red()
	{
		cout << "Destroying " << name << "  " << this << endl;
	}
	string name = "Red";
	StateMachine& sm;
	string getName()
	{
		return name;
	}
	shared_ptr< State > getNextState( char c ) override;
	void setStateNext( shared_ptr< State > state )
	{
		if( state != nullptr )
			sm.setState( state );
	}
};

struct Blue : public State
{
	~Blue()
	{
		cout << "Destroying " << name << "  " << this << endl;
	}
	Blue( StateMachine& sm ) : sm( sm ) {}
	string name = "Blue";
	StateMachine& sm;
	string getName()
	{
		return name;
	}
	shared_ptr< State > getNextState( char c ) override;
	void setStateNext( shared_ptr< State > state )
	{
		if( state != nullptr )
			sm.setState( state );
	}
};

struct Green : public State
{
	~Green()
	{
		cout << "Destroying " << name << "  " << this << endl;
	}
	Green( StateMachine& sm ) : sm( sm ) {}
	string name = "Green";
	StateMachine& sm;
	string getName()
	{
		return name;
	}
	shared_ptr< State > getNextState( char c ) override;
	void setStateNext( shared_ptr< State > state )
	{
		if( state != nullptr )
			sm.setState( state );
	}
};