//---------------------------------------------------------------------------

#pragma hdrstop

#include "student.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Student::Sum()
{
	sum = phys + math + russian + sertif;
}


void Student::Extraction(wchar_t* str)
{
	char mtr[100];
	size_t len = wcstombs(mtr, str, wcslen(str));
	if(len > 0u)
	{
		mtr[len] = '\0';
	}
	puts(mtr);

	size_t i = 0, j = 0;
	for( ; mtr[i] != '\t'; i++)
	{
		FIO[i] = mtr[i];
	}
    FIO[i] = '\0';
	i++;

	for(j = 0; str[i] != '\t'; j++, i++)
	{
		speciality[j] = mtr[i];
	}
	speciality[j] = '\0';
	i++;

	for(j = 0; str[i] != '\t'; j++, i++)
	{
		sertif2[j] = str[i];
	}
	sertif2[j] = '\0';
	sertif = atoi(sertif2);
	i++;

    for(j = 0; str[i] != '\t'; j++, i++)
	{
		phys2[j] = str[i];
	}
	phys2[j] = '\0';
	phys = atoi(phys2);
	i++;

    for(j = 0; str[i] != '\t'; j++, i++)
	{
		math2[j] = str[i];
	}
	math2[j] = '\0';
	math = atoi(math2);
	i++;

	for(j = 0; i < wcslen(str); j++, i++)
	{
		russian2[j] = str[i];
	}
	russian2[j] = '\0';
	russian = atoi(russian2);

	Sum();
	strcat(string,FIO);
	int m = strlen(string);
	string[m] = '\t';
	string[m + 1] = '\0';

	strcat(string,speciality);
	m = strlen(string);
	string[m] = '\t';
	string[m + 1] = '\0';

	char str2[10] = "";
	itoa(sum, str2, 10);
	strcat(string,str2);
}

int Student::GetSum()
{
	Sum();
	return sum;
}

void Student::SetPh(int a)
{
	phys = a;
}

void Student::SetMa(int a)
{
	math = a;
}

void Student::SetRu(int a)
{
	russian = a;
}

void Student::SetSf(int a)
{
	sertif = a;
}
