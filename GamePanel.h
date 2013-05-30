#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include "..\Solving and Generating\GameBoard.h"
#include "wx/dcbuffer.h"
#include <vector>

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
        std::vector<GameSquare> GetGreenSquares() {return greenSquares;}
        std::vector<GameSquare> GetRedSquares() {return redSquares;}
        void ClearGreenSquares() {greenSquares.clear();}
        void ClearRedSquares() {redSquares.clear();}
        void PushGreenSquares(GameSquare grn) {greenSquares.push_back(grn);}
        void PushRedSquares(GameSquare rd) {redSquares.push_back(rd);}


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
        std::vector<GameSquare> redSquares;
        std::vector<GameSquare> greenSquares;
		//(*Handlers(GamePanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
