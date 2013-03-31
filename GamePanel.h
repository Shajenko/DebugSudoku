#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include "..\sudokusolver\src\GameBoard.h"

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
        void DrawBoardBackground(wxPaintDC &dc);
        void DrawBoardNumbers(wxPaintDC &dc);

		//(*Declarations(GamePanel)
		//*)

	protected:

        void OnPaint( wxPaintEvent& event );
		//(*Identifiers(GamePanel)
		//*)

	private:
        GameBoard * bd;
        unsigned int row, col;
		//(*Handlers(GamePanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
