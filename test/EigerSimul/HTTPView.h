//---------------------------------------------------------------------------

#ifndef HTTPViewH
#define HTTPViewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm_HTTPView : public TForm
{
__published:	// Composants g�r�s par l'EDI
   TRichEdit *RichEdit;
private:	// D�clarations utilisateur
public:		// D�clarations utilisateur
   __fastcall TForm_HTTPView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_HTTPView *Form_HTTPView;
//---------------------------------------------------------------------------
#endif
