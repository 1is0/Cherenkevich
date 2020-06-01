//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

 extern int color;
 extern void inc_max(float &a, float &b, float &c);
 extern void dec_min(float &a, float &b, float &c);
 extern void dec_max(float &a, float &b, float &c);
 extern void inc_min(float &a, float &b, float &c);
 extern void setColor(int color, TImage * Image1);





class Figure {
	 protected :
		   float area, per;
		   float X1, Y1, X2, Y2, gravCenterX, gravCenterY;
		   float width, height;
		   bool draw;
	 public :


		   virtual void Perimeter(TEdit *Edit){
		   };
		   virtual void Area(TEdit *Edit){
		   };
		   virtual void GravCenter(TEdit *Edit){
		   };
		   virtual void Draw(){
		   };
 };









 class Triangle : public Figure {
	   friend class RightTriangle;
	   private : float  X3, Y3;
	   public:




		   Triangle(float X1, float Y1, float X2, float Y2, float X3, float Y3) {
			   this->X1 = X1;
			   this->Y1 = Y1;
			   this->Y2 = Y2;
			   this->X2 = X2;
			   this->Y3 = Y3;
			   this->X3 = X3;
		   }


		   void Perimeter(TEdit *Edit)  {
				float S1 =  sqrt( pow(X1 - X2, 2) +  pow(Y1 - Y2, 2) );
				float S2 =  sqrt( pow(X3 - X2, 2) +  pow(Y3 - Y2, 2) );
				float S3 =  sqrt( pow(X1 - X3, 2) +  pow(Y1 - Y3, 2) );
				per = S1 + S2 + S3;
				Edit->Text = "P = " + FloatToStr(per);
		   }

		   void   Area (TEdit *Edit) {
				float S1 =  sqrt( pow(X1 - X2, 2) +  pow(Y1 - Y2, 2) );
				float S2 =  sqrt( pow(X3 - X2, 2) +  pow(Y3 - Y2, 2) );
				float S3 =  sqrt( pow(X1 - X3, 2) +  pow(Y1 - Y3, 2) );
				per = S1 + S2 + S3;
				float half_per = per / 2;
				area = sqrt(half_per * (half_per - S3) * (half_per - S2) *
				(half_per - S1));
				Edit->Text = "S = " + FloatToStr(area);
		   }



		   void GravCenter (TEdit *Edit) {
			   gravCenterX = (X1 + X2 + X3)/3;
			   gravCenterY = (Y1 + Y2 + Y3)/3;
			   Edit->Text = "Coordinates of gravity center: X = "
			   + FloatToStr(gravCenterX) + " Y = " + FloatToStr(gravCenterY);
		   }


		   void Draw(TImage *Image) {
                gravCenterX = (X1 + X2 + X3)/3;
				gravCenterY = (Y1 + Y2 + Y3)/3;
				Image->Canvas->Brush->Color = clWhite;
				Image->Canvas->Pen->Color = clWhite;
				Image->Canvas->Rectangle(0, 0, Image->Width, Image->Height);
				setColor(color, Image);
				Image->Canvas->MoveTo(X1, Y1);
				Image->Canvas->LineTo(X2, Y2);
				Image->Canvas->MoveTo(X2, Y2);
				Image->Canvas->LineTo(X3, Y3);
				Image->Canvas->MoveTo(X3, Y3);
				Image->Canvas->LineTo(X1, Y1);
				Image->Canvas->FloodFill(gravCenterX, gravCenterY, clWhite, fsSurface);
		   }


		   void GravCenterOffSet(TEdit *Edit10, TEdit * Edit11, TImage *Image, TEdit *Edit12) {
			   gravCenterX = (X1 + X2 + X3)/3;
			   gravCenterY = (Y1 + Y2 + Y3)/3;
			   float NewgravCenterX = StrToFloat(Edit10->Text);
			   float NewgravCenterY = StrToFloat(Edit11->Text);
			   float dx = gravCenterX - NewgravCenterX;
			   float dy = gravCenterY - NewgravCenterY;
			   X1 -= dx;
			   X2 -= dx;
			   X3 -= dx;
			   Y1 -= dy;
			   Y2 -= dy;
			   Y3 -= dy;
			   Draw(Image);
			   Edit12->Text = "OFFSET: DX = "
			   + FloatToStr(-dx) + " DY = " + FloatToStr(-dy);
		   }

		   void Move (TImage * Image, int x, int y) {
					float dx = x - gravCenterX;
					float dy = y - gravCenterY;
					X1 += dx;
					X2 += dx;
					X3 += dx;
					Y1 += dy;
					Y2 += dy;
					Y3 += dy;
					gravCenterX = (X1 + X2 + X3)/3;
					gravCenterY = (Y1 + Y2 + Y3)/3;
					Draw(Image);

		   }

		   void dec_and_inc (TImage * Image, bool inc) {


					  if (inc) {
							 inc_max(X1, X2, X3);
							 inc_max(Y1, Y2, Y3);
							 dec_min(Y1, Y2, Y3);
							 dec_min(X1, X2, X3);
							 Draw(Image);
					  }
					  else {
						  dec_max(X1, X2, X3);
						  dec_max(Y1, Y2, Y3);
						  inc_min(Y1, Y2, Y3);
						  inc_min(X1, X2, X3);
						  Draw(Image);
					  }


		   }



 };






 class Rectan : public Figure {
	   private :
			float gr = 15;
	   public:
			Rectan(float X1, float Y1, float X2, float Y2) {
					this->X1 = X1;
					this->X2 = X2;
					this->Y1 = Y1;
					this->Y2 = Y2;
			}



			 void Draw (TImage *Image) {
				 Image->Canvas->Brush->Color = clWhite;
				 Image->Canvas->Pen->Color = clWhite;
				 Image->Canvas->Rectangle(0, 0, Image->Width, Image->Height);
				 setColor(color, Image);
				 Image->Canvas->Rectangle(X1, Y1, X2, Y2);
				 width = fabs(X1 - X2);
				 height = fabs(Y1 - Y2);
			 }

			 void Perimeter (TEdit * Edit) {
				 per = abs( (X1 - X2) * 2  + (Y1 - Y2) * 2);
				 Edit->Text = "P = " +  FloatToStr(per);
			 }

			 void Area (TEdit * Edit) {
				 area = (X1 - X2) * (Y1 - Y2);
				 Edit->Text = " S = " + FloatToStr(area);
			 }

			 void GravCenter (TEdit * Edit) {
			   gravCenterX = (X1 + X2)/2;
			   gravCenterY = (Y1 + Y2)/2;
			   Edit->Text = "Coordinates of gravity center: X = "
			   + FloatToStr(gravCenterX) + " Y = " + FloatToStr(gravCenterY);
			 }

			 void GravCenterOffset (TEdit * Edit1, TEdit * Edit2, TImage * Image, TEdit * Edit) {
			   gravCenterX = (X1 + X2) / 2;
			   gravCenterY = (Y1 + Y2) / 2;
			   float NewgravCenterX = StrToFloat(Edit1->Text);
			   float NewgravCenterY = StrToFloat(Edit2->Text);
			   float dx = gravCenterX - NewgravCenterX;
			   float dy = gravCenterY - NewgravCenterY;
			   X1 -= dx;
			   X2 -= dx;
			   Y1 -= dy;
			   Y2 -= dy;
			   Draw(Image);
			   Edit->Text = "OFFSET: DX = "
			   + FloatToStr(-dx) + " DY = " + FloatToStr(-dy);
			 }


			 void Move (TImage * Image, int x, int y) {
					float dx = x - gravCenterX;
					float dy = y - gravCenterY;
					X1 += dx;
					X2 += dx;
					Y1 += dy;
					Y2 += dy;
					gravCenterX = (X1 + X2)/2;
					gravCenterY = (Y1 + Y2)/2;
					Draw(Image);
		   }





		   void dec_and_inc (TImage * Image,bool inc) {
				if (inc==true) {
					   X1 -= 20;
					   X2 += 20;
					   Y1 -= 20;
					   Y2 += 20;
				}
				else {
					   X1 += 20;
					   X2 -= 20;
					   Y1 += 20;
					   Y2 -= 20;
				}
				Draw(Image);
			}



			void Rotation (TImage * Image) {


				 float x = 0, y = 0;
				 X1 > X2? x = X2 : x = X1;
				 Y1 > Y2? y = Y2 : y = Y1;
				 float x1_old = x, x1_new;
				 float x2_old = x + width, x2_new;
				 float x3_old = x + width, x3_new;
				 float x4_old = x, x4_new;
				 float y1_old = y, y1_new;
				 float y2_old = y, y2_new;
				 float y3_old = y + height, y3_new;
				 float y4_old = y + height, y4_new;

				 if (gr > 360) {
							 gr -= 360;
				 }

				 double sina = sin(gr * (M_PI / 180));
				 double cosa = cos(gr * (M_PI / 180));

				 float xo = x + (width / 2);
				 float yo = y + (height / 2);

				 x1_new = ( (x1_old - xo) * cosa - (y1_old - yo) * sina) + xo;
				 y1_new = ( (x1_old - xo) * sina + (y1_old - yo) * cosa) + yo;


				 x2_new = ( (x2_old - xo) * cosa - (y2_old - yo) * sina) + xo;
				 y2_new = ( (x2_old - xo) * sina + (y2_old - yo) * cosa) + yo;

				 x3_new = ( (x3_old - xo) * cosa - (y3_old - yo) * sina) + xo;
				 y3_new = ( (x3_old - xo) * sina + (y3_old - yo) * cosa) + yo;

				 x4_new = ( (x4_old - xo) * cosa - (y4_old - yo) * sina) + xo;
				 y4_new = ( (x4_old - xo) * sina + (y4_old - yo) * cosa) + yo;





				Image->Canvas->Brush->Color = clWhite;
				Image->Canvas->Pen->Color = clWhite;
				Image->Canvas->Rectangle(0, 0, Image->Width, Image->Height);
				setColor(color, Image);
				Image->Canvas->MoveTo(x1_new, y1_new);
				Image->Canvas->LineTo(x2_new, y2_new);
				Image->Canvas->MoveTo(x2_new, y2_new);
				Image->Canvas->LineTo(x3_new, y3_new);
				Image->Canvas->MoveTo(x3_new, y3_new);
				Image->Canvas->LineTo(x4_new, y4_new);
				Image->Canvas->MoveTo(x4_new, y4_new);
				Image->Canvas->LineTo(x1_new, y1_new);
				Image->Canvas->FloodFill(gravCenterX, gravCenterY, clWhite, fsSurface);

				gr += 15;
			}

 };


 class Ellips : public Figure {
	 private :   float a, b;
	 public:
		  Ellips(int X1, int Y1, int X2, int Y2) {
			   this->X1 = X1;
			   this->X2 = X2;
			   this->Y1 = Y1;
			   this->Y2 = Y2;
		  }

		  void Draw (TImage *Image) {
				 Image->Canvas->Brush->Color = clWhite;
				 Image->Canvas->Pen->Color = clWhite;
				 Image->Canvas->Rectangle(0, 0, Image->Width, Image->Height);
				 setColor(color, Image);
				 Image->Canvas->Ellipse(X1, Y1, X2, Y2);
		  }

		  void Area (TEdit * Edit) {
				a = sqrt(pow((X1 - X2), 2)) / 2;
				b = sqrt(pow((Y1 - Y2), 2)) / 2;
				float area = a * b * 3.1415;
				Edit->Text = "Area : " + FloatToStr(area);
		  }

		  void Perimeter (TEdit * Edit) {
			   per = 4 * (3.1415 * a * b + (a - b) )/ (a + b);
			   Edit->Text = "Perimeter : " + FloatToStr(per);
		  }


          void GravCenter (TEdit * Edit) {
			   gravCenterX = (X1 + X2)/2;
			   gravCenterY = (Y1 + Y2)/2;
			   Edit->Text = "Coordinates of gravity center: X = "
			   + FloatToStr(gravCenterX) + " Y = " + FloatToStr(gravCenterY);
		  }



		   void GravCenterOffSet(TEdit *Edit10, TEdit * Edit11, TImage *Image, TEdit *Edit12) {
			   gravCenterX = (X1 + X2) / 2;
			   gravCenterY = (Y1 + Y2) / 2;
			   float NewgravCenterX = StrToFloat(Edit10->Text);
			   float NewgravCenterY = StrToFloat(Edit11->Text);
			   float dx = gravCenterX - NewgravCenterX;
			   float dy = gravCenterY - NewgravCenterY;
			   X1 -= dx;
			   X2 -= dx;
			   Y1 -= dy;
			   Y2 -= dy;
			   Draw(Image);
			   Edit12->Text = "OFFSET: DX = "
			   + FloatToStr(-dx) + " DY = " + FloatToStr(-dy);
		   }


           void Move (TImage * Image, int x, int y) {
					float dx = x - gravCenterX;
					float dy = y - gravCenterY;
					X1 += dx;
					X2 += dx;
					Y1 += dy;
					Y2 += dy;
					gravCenterX = (X1 + X2)/2;
					gravCenterY = (Y1 + Y2)/2;
					Draw(Image);
		   }


			void dec_and_inc (TImage * Image,bool inc) {
				if (inc) {
					   X1 -= 20;
					   X2 += 20;
					   Y1 -= 20;
					   Y2 += 20;
				}
				else {
					   X1 += 20;
					   X2 -= 20;
					   Y1 += 20;
					   Y2 -= 20;
				}
				Draw(Image);
			}




 };



 class Circle : public Ellips {
	   private:  float x, y, r;

	   public:


 };




