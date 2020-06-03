//---------------------------------------------------------------------------

#ifndef studentH
#define studentH
//---------------------------------------------------------------------------
#endif

class Student
{
private:
	char sertif2[100];
	char phys2[100];
	char math2[100];
	char russian2[100];
	int sertif;
	int phys;
	int math;
	int russian;
	int sum;
    void Sum();

public:
	char FIO[100];
	char speciality[100];
	char string[100] = "";

	void Extraction(wchar_t* str);
	int GetSum();
	void SetPh(int);
	void SetMa(int);
	void SetRu(int);
	void SetSf(int);

	~Student(){};
};
