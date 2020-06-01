//---------------------------------------------------------------------------

#pragma hdrstop

#include "Calc.h"
#include "Converter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Calcul::Calcul(AnsiString str, double* numss)
{
	nums = numss;
    toCalc = str;
    numStack = NULL;
}

AnsiString Calcul::GetRes()
{
	for (int i = 1, len = toCalc.Length(); i <= len; i++) {
		if (Converter::IsLit(toCalc[i])) {
			PushItem(GetNum(toCalc[i]));
            continue;
		}
		if (Converter::IsOper(toCalc[i])) {
			PushItem(MakeOper(toCalc[i]));
		}
	}
	return FloatToStr(PopItem()).SubString(0, 8);
}

void Calcul::PushItem(double num)
{
	Nums* item = new Nums();

	item->num = num;
	if (!numStack) {
		item->next = NULL;
		numStack = item;
		return;
	}
	item->next = numStack;
    numStack = item;
}

double Calcul::PopItem()
{
	Nums* p = numStack;
	double ans;

	ans = numStack->num;
	numStack = numStack->next;
	delete p;
    return ans;
}

double Calcul::GetNum(char ch)
{
    return nums[ch - 'a'];
}

double Calcul::MakeOper(char ch)
{
	switch (ch) {
		 case '/': return Div();
		 case '*': return Mult();
         case '-': return Diff();
    default:
		return Sum();
	}

}

double Calcul::Div()
{
	double num2 = PopItem(), num1 = PopItem();

    return num1 / num2;
}

double Calcul::Mult()
{
	double num2 = PopItem(), num1 = PopItem();

	return num1 * num2;
}

double Calcul::Diff()
{
	double num2 = PopItem(), num1 = PopItem();

	return num1 - num2;
}

double Calcul::Sum()
{
	double num1 = PopItem(), num2 = PopItem();

    return num1 + num2;
}