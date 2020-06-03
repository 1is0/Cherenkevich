//---------------------------------------------------------------------------

#ifndef MyExceptionH
#define MyExceptionH
#include <exception>
//---------------------------------------------------------------------------
#endif

using namespace std;

class myexcep : public Exception
{
	public:
	myexcep(const char *msg, AnsiString code):Exception(msg)
	{
	  this -> code = code;
	  this -> msg = msg;
	}

	AnsiString GetMessage()
	{
	  AnsiString a = msg;
	  AnsiString b = code ;
	  AnsiString c = "";
	  c = "Error: " + a + "\n\nError Code : " + b;
	  return c;
	}

	private:
	AnsiString code;
	const char *msg;

};