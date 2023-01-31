#include <iostream>
using namespace std;

#ifndef STACKT_H
#define STACKT_H

template <class Type>

class Stackt
{
public:
	Stackt(int nelements = 128);
	~Stackt();
	void push(Type);
	int pop(Type&);
	void stackTop(Type&) const;
	bool stackIsEmpty() const;
	bool stackIsFull() const;
	
private:
	Type* stack;
	int top, MaxSize;

};
template <class Type>

Stackt <Type> ::Stackt(int nelements)
{
	MaxSize = nelements;
	stack = new Type[MaxSize];
	top = -1;
}

template <class Type>
Stackt <Type> :: ~Stackt()
{
	delete[] stack;
}

template <class Type>

void Stackt <Type>::push(Type v)
{
	if (stackIsFull()) cout << "Stack overflow";
	else stack[++top] = v;
}

template <class Type>

int Stackt <Type>::pop(Type& v)
{
	if (stackIsEmpty()) return -1;
	else { v = stack[top--]; return v; }
}

template <class Type>

void Stackt<Type>::stackTop(Type& v) const
{
	if (stackIsEmpty()) cout << "Stack Underflow";
	else v = stack[top];
}

template <class Type>

bool Stackt<Type>::stackIsEmpty() const
{
	return (top < 0);
}

template <class Type>

bool Stackt<Type>::stackIsFull() const
{
	return (top >= (MaxSize - 1));
}



#endif

