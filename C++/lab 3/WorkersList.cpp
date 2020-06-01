//---------------------------------------------------------------------------

#pragma hdrstop

#include "WorkersList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Worker::Worker(Info nn)
{
	name = nn.name;
	ID = nn.ID;
	hours = nn.hours;
	earning = nn.paymnt;
	prev = NULL;
}

Worker* Worker::AddItem(Worker* list, Info nn)
{
	Worker* nitem;

	nitem = new Worker(nn);
    nitem->prev = list;
	list = nitem;
    return list;
}

Worker* Worker::DelItem(Worker* list, Worker* item)
{
	Worker* p = list;

	if (!item) {
		return list;
	}
	if (item == list) {
		delete list;
        return NULL;
	}
	while (p) {
		if (p->prev == item) {
			p->prev = item->prev;
            break;
		}
		p = p->prev;
    }
	delete item;
    return list;
}

Worker* Worker::GoSearch(Worker* list, AnsiString nm)
{
	Worker* p = list;
	Worker* ans = NULL;

	while (p) {
		if (p->CompName(nm)) {
			ans = p;
			break;
		}
		p = p->prev;
	}
    return ans;
}

AnsiString Worker::LastWish()
{
	AnsiString note = name;

	note += " was deleted";
    return note;
}

bool Worker::DelMe()
{
	int ans;
	const WideChar* p;
	AnsiString note = "Are you sure you want delete ";

	note += name + "?";
	wchar_t *str = new wchar_t[note.WideCharBufSize()];
	p = note.WideChar(str, note.WideCharBufSize());
	ans = Application->MessageBox(p, L"Are you sure?", MB_YESNO);
	if (ans) {
		return true;
	} else {
		return false;
    }
}

AnsiString Worker::MkNote()
{
	AnsiString note = "";

	note += "-------------------\n";
	note += "Name - " + name + '\n';
	note += "ID - " + IntToStr(ID) + '\n';
	note += "Working hours - " + IntToStr(hours) + '\n';
	note += "Earn per hour - " + FloatToStr(earning);
	if (hours > 144) {
		note += " (2x)\n";
	} else {
        note += '\n';
    }
	note += "--------------------\n";

    return note;
}

void Worker::ShowMatches(TForm1* F, Worker* list, void* data, bool(*CompFunc)(Worker* p, void* data))
{
    Worker* p = list;
	Worker* ans = NULL;

	while (p) {
		if ((*CompFunc)(p, data)) {
			F->Info->Lines->Add(p->MkNote());
		}
		p = p->prev;
	}
}

void Worker::ShowList(TForm1* F, Worker* list)
{
	if (!list) {
        return;
	}
	Worker* p = list;

	while(p) {
		F->Info->Lines->Add(p->MkNote());
		p = p->prev;
    }
}

bool Worker::CompName(AnsiString nm)
{
	int len = nm.Length();

	for (int i = 0, nlen = name.Length(); nlen - i >= len; i++) {
		if (nm == name.SubString(i, len)) {
			return 1;
		}
	}
	return 0;
}

bool Worker::CompEarn(Worker* p, void* ern)
{
	if (*(double*)ern <= p->earning) {
        return 1;
	}
	return 0;
}

bool Worker::CompHrs(Worker* p, void* ern)
{
	if (*(int*)ern <= p->hours) {
        return 1;
	}
	return 0;
}

bool Worker::CompOvertime(Worker* p, void* ern)
{
	if (p->hours > 144) {
		return 1;
	}
	return 0;
}
