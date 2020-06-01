//---------------------------------------------------------------------------
#include <vcl.h>

#ifndef ConverterH
#define ConverterH
//---------------------------------------------------------------------------
struct Oper {
	char operat;
    Oper* next;
};

class Converter {
	private:
        static constexpr char opers[] = "-+/*";
		AnsiString outString;
		Oper* stack;
        void PushItem(char);
		char PopItem();
		int GetPrior(char);
	public:
		Converter();
		AnsiString RewriteMath(AnsiString);
		static bool IsLit(char);
		static bool IsOper(char);
};
#endif
