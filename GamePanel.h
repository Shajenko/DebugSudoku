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
        void WriteBoard(GameBoard &gb);
        void SetGuess(bool gsbd) {guess = gsbd;}

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
