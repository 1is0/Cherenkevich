//---------------------------------------------------------------------------

#pragma hdrstop

#include "Converter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Converter::Converter() {
	outString = "";
    stack = NULL;
}

AnsiString Converter::RewriteMath(AnsiString wat) {
	AnsiString str = "";

	for (int i = 1, len = wat.Length(); i <= len; i++) {
		if (IsLit((char)wat[i])) {
			str += wat[i];
			continue;
		}
		if (wat[i] == '(') {
			PushItem((char)wat[i]);
			continue;
		}
		if (wat[i] == ')') {
			while(stack->operat != '(') {
				str += PopItem();
			}
            PopItem();
			continue;
		}
		if (IsOper(wat[i])) {
			while (stack && ((GetPrior(stack->operat) - GetPrior(wat[i])) >= 0)) {
				str += PopItem();
			}
			PushItem((char)wat[i]);
		}
	}
	while (stack) {
        str += PopItem();
	}
	return str;
}
bool Converter::IsLit(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		return true;
	}
	return false;
}

bool Converter::IsOper(char ch) {
	for (int i = 0; i < 4; i++) {
		if (ch == opers[i]) {
			return true;
		}
	}
    return false;
}

void Converter::PushItem(char ch)
{
	Oper* item = new Oper();

	item->operat = ch;
	if (!stack) {
		item->next = NULL;
		stack = item;
        return;
	}
	item->next = stack;
    stack = item;
}

char Converter::PopItem() {
	char ans;
    Oper* p = stack->next;

	ans = stack->operat;
	delete stack;
    stack = p;
    return ans;
}

int Converter::GetPrior(char ch) {
	switch (ch) {
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
        case '-': return 1;
		default: return 0;
	}

}