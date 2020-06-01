//---------------------------------------------------------------------------
#include <vcl.h>

#ifndef CalcH
#define CalcH
//---------------------------------------------------------------------------

struct Nums {
	double num;
    Nums* next;
};

class Calcul {
	private:
		Nums* numStack;
		AnsiString toCalc;
		double* nums;
        void PushItem(double);
		double PopItem();
		double GetNum(char);
		double MakeOper(char);
		double Sum();
		double Div();
		double Mult();
        double Diff();
	public:
		Calcul(AnsiString, double*);
        AnsiString GetRes();
};

#endif
