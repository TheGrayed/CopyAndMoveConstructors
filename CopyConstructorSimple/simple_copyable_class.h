#pragma once
class simple_copyable_class
{
public:
	simple_copyable_class();		//Default constructor. Called when an object is declared in body of a function.
	simple_copyable_class(const simple_copyable_class& source);		//Copy constructor. Called for parameters. (And some times assignments.)
};

