//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

#include <vcl.h>
//---------------------------------------------------------------------------
#endif


class StackChar
{
	public:
		char ch;
		StackChar* next;
};


class StackDouble
{
	public:
		double value;
		StackDouble* next;
};


double GetSymbol(char);
int SearchForSymbol(AnsiString, char);

StackChar* Add(StackChar*, char);
StackDouble* Add(StackDouble*, double);

StackChar* Read(StackChar*, char*);
StackDouble* Read(StackDouble*, double*);

int Operation(char);
AnsiString ToOPZ(AnsiString);
double Calculate(AnsiString s);
