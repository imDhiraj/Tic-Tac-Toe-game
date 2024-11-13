//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

 char currentPlyerSymbol = 'x';
 bool TForm1 :: CheckisWinner() {

	   if (!Button1->Text.IsEmpty() && Button1->Text == Button2->Text && Button1->Text == Button3->Text				) {
		  return true;
	   }
	   if ( !Button4->Text.IsEmpty() && Button4->Text == Button5->Text && Button4->Text == Button6->Text				) {
		  return true;
	   }
	   if (!Button7->Text.IsEmpty() && Button7->Text == Button8->Text && Button7->Text == Button9->Text				) {
		  return true;
	   }
	   if (!Button1->Text.IsEmpty() && Button1->Text == Button4->Text && Button1->Text == Button7->Text				) {
		  return true;
	   }
	   if (!Button2->Text.IsEmpty() && Button2->Text == Button5->Text && Button2->Text == Button8->Text				) {
		  return true;
	   }
	   if (!Button3->Text.IsEmpty() && Button3->Text == Button6->Text && Button3->Text == Button9->Text				) {
		  return true;
	   }
	   if (!Button1->Text.IsEmpty() && Button1->Text == Button5->Text && Button1->Text == Button9->Text				) {
		  return true;
	   }
	   if (!Button4->Text.IsEmpty() && Button3->Text == Button5->Text && Button3->Text == Button7->Text				) {
		  return true;
	   }

	   return false;
 }

 bool TForm1 :: CheckisDraw(){
	  if (!Button1->Text.IsEmpty()&& !Button2->Text.IsEmpty()&&!Button3->Text.IsEmpty()&&!Button4->Text.IsEmpty()&&!Button5->Text.IsEmpty()&&!Button6->Text.IsEmpty()&&!Button7->Text.IsEmpty()&&!Button8->Text.IsEmpty()&&!Button9->Text.IsEmpty()) {

			 return true ;
			}
 }

 void TForm1 :: RestratGame(){
		 Button1  ->Enabled = true;
		 Button2  ->Enabled = true;
		 Button3   ->Enabled = true;
		 Button4  ->Enabled = true;
		 Button5   ->Enabled = true;
		 Button6   ->Enabled = true;
		 Button7   ->Enabled = true;
		 Button8  ->Enabled = true;
		 Button9  ->Enabled = true;
		 ReturnButton->Visible = false;
		 Button1  ->Text ="";
		 Button2  ->Text ="";
		 Button3   ->Text ="";
		 Button4  ->Text ="";
		 Button5   ->Text ="";
		 Button6   ->Text ="";
		 Button7   ->Text ="";
		 Button8  ->Text ="";
		 Button9  ->Text ="";
		WinnerLabel->Text ="";
 }

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	CurrentplayerLabel->Text = currentPlyerSymbol;
	ReturnButton->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	 TButton*clickedButton = dynamic_cast<TButton*>(Sender);
	 clickedButton->Text = currentPlyerSymbol;
	 if(CheckisWinner()){
	  WinnerLabel->Text ="You Have WON The Game  "  +  String(currentPlyerSymbol) ;

		 Button1  ->Enabled = false;
		 Button2  ->Enabled = false;
		 Button3   ->Enabled = false;
		 Button4  ->Enabled = false;
		 Button5   ->Enabled = false;
		 Button6   ->Enabled = false;
		 Button7   ->Enabled = false;
		 Button8  ->Enabled = false;
		 Button9  ->Enabled = false;
		 ReturnButton->Visible = true;
		return;
	 };
	 if (CheckisDraw()) {
		WinnerLabel->Text ="It's DRAW";

		 Button1  ->Enabled = false;
		 Button2  ->Enabled = false;
		 Button3   ->Enabled = false;
		 Button4  ->Enabled = false;
		 Button5   ->Enabled = false;
		 Button6   ->Enabled = false;
		 Button7   ->Enabled = false;
		 Button8  ->Enabled = false;
		 Button9  ->Enabled = false;
		  ReturnButton->Visible = true;
		 return;
	 }

	  if (currentPlyerSymbol=='x')
		 currentPlyerSymbol= 'o';

	  else
		  currentPlyerSymbol ='x';


	  CurrentplayerLabel->Text = currentPlyerSymbol;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ReturnButtonClick(TObject *Sender)
{
	   RestratGame();
}
//---------------------------------------------------------------------------

