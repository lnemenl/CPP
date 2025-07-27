#pragma once

class Base
{
	public:
		virtual ~Base();
};


/*
		Virtual Destructor:
		A virtual destructor in the base class (Base::~Base()) ensures that the correct destructor is called when deleting a derived object through a base pointer.
		Example: delete p; where p is a Base* pointing to an A object calls A’s destructor if ~Base() is virtual.
		Without a virtual destructor, only Base’s destructor would be called, causing undefined behavior (e.g., memory leaks in derived classes).
	
*/