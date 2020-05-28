#include<string>
#include <stdarg.h>
using namespace std;

__declspec(dllexport)
 extern "C" __declspec(dllexport)int __stdcall Add(int a, int b)
{
	return a+b;
}

extern "C" __declspec(dllexport) int __stdcall Sub(int a, int b)
{
	return a - b;
}

extern "C" __declspec(dllexport)double __cdecl Average(int n, double a, ...)
{
	va_list p;             //--объявление указателя
	double sum = 0, count = 0;
	va_start(p, n);            //--инициализация указателя
	while (n--)
	{
		sum += va_arg(p, double);        //--перемещение указателя 
		count++;
	}
	va_end(p);                //--«закрытие» указателя
	return ((sum) ? sum / count : 0);
}
