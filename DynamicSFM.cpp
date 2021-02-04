#include <iostream>
#include <memory>
#include <string>
#include "DynamicFSM.h"

using namespace std;

void StateMachine::start()
{
	currentState = make_shared< Red >( *this );
	run();
}

void StateMachine::setState( shared_ptr< State > state )
{
	nextState = state;
}

void StateMachine::run()
{
	while( 1 )
	{
		currentState->entry();
		currentState->doDo();
		currentState->exit();
		updateState();
	}
}

shared_ptr< State > Red::getNextState( char c )
{
	if( c == 'n' )
		return static_pointer_cast< State >( make_shared< Green >( sm ) );
	return nullptr;
}

shared_ptr< State > Green::getNextState( char c )
{
	if( c == 'n' )
		return static_pointer_cast< State >( make_shared< Blue >( sm ) );

	if( c == 'p' )
		return static_pointer_cast< State >( make_shared< Green >( sm ) );
	return nullptr;
}

shared_ptr< State > Blue::getNextState( char c )
{
	if( c == 'n' )
		return static_pointer_cast< State >( make_shared< Red >( sm ) );
	if( c == 'p' )
		return static_pointer_cast< State >( make_shared< Green >( sm ) );
	return nullptr;
}

void StateMachine::updateState()
{
	swap( currentState, nextState );
}

int main()
{
	StateMachine sm;
	sm.start();
}