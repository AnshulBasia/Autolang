#include "Logical.h"

/* Implementations for the methods in the class Logical. */

Logical::Logical() : Elem(LOGICAL)		// Default constructor.
{
	elem = false;
}

Logical::Logical(bool t_val) : Elem(LOGICAL)	// Another constructor with argument.
{
	elem = t_val;
}

Elem* Logical::deep_copy()			// Deep_copy method, which of course returns just a logical instance since it's atomic.
{
	return new Logical(elem);		// Return the address to a new Logical object, initialized with the same value as this.
}

const Logical& Logical::operator=(Logical &x)	// Overloaded assignment operator.
{
	this->elem = x.elem;			// Basically make the truth value of the this logical element equal to that of x.
	return this;				// Return a reference to this for cascading assignment.
}

Logical Logical::operator!()			// Overloaded negation operator.
{
	return Logical(!this->elem);		// Return a logical object constructed with the truth value negative of this.
}

Logical Logical::operator&&(Logical &x)		// Overloaded logical and. 
{
	return Logical(this->elem && x.elem);   // Return a logical object constructed with the truth value of (this->elem && x.elem).
}

Logical Logical::operator||(Logical &x)		// Overloaded logical or.
{
	return Logical(this->elem || x.elem);	// Return a logical object constructed with the truth value of (this->elem || x.elem).
}

string Logical::to_string()			// Virtual to_string method for display.
{
	return (elem == true) ? "True" : "False";
}
