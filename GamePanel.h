#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include "..\Solving and Generating\GameBoard.h"
#include "wx/dcbuffer.h"

#ifndef WX_PRECOMP
	//(*HeadersPCH(GamePanel)
	//*)
#endif
//(*Headers(GamePanel)
//*)

class GamePanel: public wxPanel
{
	public:

		GamePanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, long style = wxTAB_TRAVERSAL|wxNO_BORDER);
		virtual ~GamePanel();
        void DrawBoardBackground(wxBufferedDC &dc);
        void DrawBoardNumbers(wxBufferedDC &dc);
        void CopyBoard(GameBoard &gb);
        void CopyToTrue();
        void WriteBoard(GameBoard &gb);
        void SetGuess(bool gsbd) {guess = gsbd;}
        void SetRow(unsigned int r) {row = r;}
        void SetCol(unsigned int c) {col = c;}

		//(*Declarations(GamePanel)
		//*)

	protected:

        void OnPaint( wxPaintEvent& event );
		//(*Identifiers(GamePanel)
		//*)

	private:
        GameBoard * bd, trueBd;
        bool guess;
        unsigned int row, col;
		//(*Handlers(GamePanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
