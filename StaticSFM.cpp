#include <iostream>
#include <memory>
#include <string>
#include "StaticFSM.h"

using namespace std;

void StateMachine::start()
{
	currentState = &Red_state;
	run();
}

Red StateMachine::Red_state;
Blue StateMachine::Blue_state;
Green StateMachine::Green_state;

void StateMachine::run()
{
	while( 1 )
	{
		currentState->entry();
		currentState->doDo();
		while( 1 )
		{
			char transition;
			cin >> transition;
			if( updateState( transition ) )
			{
				break;
			}
		}
		currentState->exit();
	}
}

bool StateMachine::updateState( char c )
{
	try
	{
		currentState = transitions[ currentState ].at( c );
		return true;
	}
	catch( ... )
	{
		cout << "No such transition" << endl;
		return false;
	}
}

int main()
{
	StateMachine sm;
	sm.start();
}