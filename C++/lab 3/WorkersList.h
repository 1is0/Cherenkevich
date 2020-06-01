//---------------------------------------------------------------------------
#include "Visual.h"
#ifndef WorkersListH
#define WorkersListH
//---------------------------------------------------------------------------

struct Info {
	AnsiString name;
	int ID;
	int hours;
	double paymnt;
};

class Worker {
	private:
		Worker* prev;
		AnsiString name;
		int ID;
		int hours;
		double earning;
	public:
		Worker(Info);
		static Worker* AddItem(Worker*, Info);
		static Worker* DelItem(Worker* list, Worker* item);
		static Worker* GoSearch(Worker*, AnsiString);
		static void ShowList(TForm1*, Worker*);
        AnsiString LastWish();
		AnsiString MkNote();
		bool DelMe();
		bool CompName(AnsiString);
		static void ShowMatches(TForm1*, Worker*, void*, bool(*CompFunc)(Worker* p, void* ern));
		static bool CompEarn(Worker*, void*);
		static bool CompHrs(Worker*, void*);
		static bool CompOvertime(Worker*, void*);
};

#endif
