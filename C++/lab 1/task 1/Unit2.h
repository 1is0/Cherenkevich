//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include "Unit1.h"
#include <Windows.h>
class MRectangle
{
	public:
	int XSize = 200;
	int YSize = 100;
	int XCord = 500 ;
	int YCord = 280;
	void TrainMove(int a,int b)
	{
		XCord += a;
		YCord += b;
		return ;
	}
	void Delete()
	{
		Form1->Canvas->Pen->Color = clWhite;
		Form1->Canvas->Brush->Color = clWhite;
		Form1->Canvas->Rectangle(0,0,1920,1080);
	}
	void Drow()
	{
		Form1->Canvas->Pen->Color = clBlue;
		Form1->Canvas->Brush->Color = clBlue;
		Form1->Canvas->Rectangle(XCord,YCord,XCord+XSize,YCord+YSize);
		Form1->Canvas->Rectangle(XCord-(XSize+40),YCord,XCord-40,YCord+YSize);
		Form1->Canvas->Pen->Color = clBlack;
		Form1->Canvas->Brush->Color = clBlack;
		Form1->Canvas->Rectangle(XCord-40,YCord+50,XCord,YCord+70);
		Form1->Canvas->Rectangle(XCord + XSize -50,YCord - 60, XCord + XSize - 20, YCord);
		Form1->Canvas->Ellipse(XCord+XSize-50,YCord+YSize,XCord+XSize-10,YCord+YSize+40);
		Form1->Canvas->Ellipse(XCord+10,YCord+YSize,XCord+50,YCord+YSize+40);
		Form1->Canvas->Ellipse(XCord-90,YCord+YSize,XCord-50,YSize+YCord+40);
		Form1->Canvas->Ellipse(XCord-230,YCord+YSize,XCord-190,YCord+YSize+40);
	}

	void Smoke()
	{
		Form1->Canvas->Pen->Color = clBlack;
		Form1->Canvas->Brush->Color = clBlack;
		Form1->Canvas->Ellipse(XCord+XSize-60,YCord-110,XCord+XSize-10,YCord-60);
		Sleep(100);
		Form1->Canvas->Ellipse(XCord+XSize-100,YCord-160,XCord+XSize-50,YCord-110);
		Sleep(100);
		Form1->Canvas->Ellipse(XCord+XSize-150,YCord-210,XCord+XSize-100,YCord-160);
		Sleep(100);
		//Form1->Canvas->Ellipse(XCord+XSize-200,YCord-300,XCord+XSize-150,YCord-250);
	}

	void MCanvaClean ()
	{
		Form1->Canvas->Pen->Color = clWhite;
		Form1->Canvas->Brush->Color = clWhite;
		Form1->Canvas->Rectangle(0,0,1920,1080);
    }
};
//---------------------------------------------------------------------------
#endif
